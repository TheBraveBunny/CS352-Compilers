#include <stdio.h>
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "cgraph.h"
#include "hashtab.h"
#include "langhooks.h"
#include "tree-iterator.h"

void goThroughGlobalVars();
void goThroughFunctions();
tree extractBody(struct cgraph_node *node);
void goThroughBody(tree node);
void evaluateStatement(tree node);
void writeToFile();

void initDebugFile();
void printToDebugFile();
void closeDebugFile();

int numFunctions;
int numGlobalVars;
int numLocalVars;
int numStatements;

FILE *debugF;
int breakCheck;

void cs352_proj3()
{
	//initialize
	numFunctions = 0;
	numGlobalVars = 0;
	numLocalVars = 0;
	numStatements = 0;
	breakCheck = 0;
	initDebugFile();

	//get counts
	goThroughGlobalVars();
	goThroughFunctions();

	//write to file
	writeToFile();

	closeDebugFile();
}

void goThroughGlobalVars() {
	struct varpool_node *node;

	for (node = varpool_nodes; node; node = node->next) {
		tree decl = node->decl;
		numGlobalVars++;
	}
}

void goThroughFunctions() {
	struct cgraph_node *node;
	tree fn;

	for (node = cgraph_nodes; node; node = node->next) {
		fn = extractBody(node);
		goThroughBody(fn);
		numFunctions++;
	}
}

tree extractBody(struct cgraph_node *node) {
	tree fn = node->decl;
	fn = DECL_SAVED_TREE(fn);
	return BIND_EXPR_BODY(fn);
}

void goThroughBody(tree node) {
	if (TREE_CODE(node) == STATEMENT_LIST) {
		tree_stmt_iterator si;

		//go through each statement in body
		for (si = tsi_start (node); !tsi_end_p (si); tsi_next (&si)) {
			evaluateStatement(tsi_stmt(si));
		}
	} else {
		evaluateStatement(node);
	}
}

void evaluateStatement(tree node) {
	fprintf(debugF, "TREE_CODE %d == ", TREE_CODE(node));
	tree n;
	char *name;
	switch (TREE_CODE(node)) {
		//function call
		case CALL_EXPR:
			printToDebugFile("CALL_EXPR\n");
			numStatements++;
			break;

		//return statement
		case RETURN_EXPR:
			printToDebugFile("RETURN_EXPR\n");
			numStatements++;
			break;

		case BIND_EXPR:
			printToDebugFile("BIND_EXPR\n");
			goThroughBody(BIND_EXPR_BODY(node));
			break;

		//if statement
		case COND_EXPR:
			printToDebugFile("COND_EXPR\n");
			numStatements++;
			n = COND_EXPR_THEN(node);
			if (TREE_CODE(n) == GOTO_EXPR) {
				if (breakCheck == 2) {
					numStatements -= 3;
				}
			}
			goThroughBody(COND_EXPR_THEN(node));
			if (COND_EXPR_ELSE(node)) {
				goThroughBody(COND_EXPR_ELSE(node));
			}
			break;

		//switch statement
		case SWITCH_EXPR:
			printToDebugFile("SWITCH_EXPR\n");
			numStatements++;
			goThroughBody(SWITCH_BODY(node));
			
			break;

		//while statement
		case LOOP_EXPR:
			printToDebugFile("LOOP_EXPR\n");
			numStatements++;
			goThroughBody(LOOP_EXPR_BODY(node));
			break;

		//block
		case BLOCK:
			printToDebugFile("block\n");
			break;

		//local vars
		case VAR_DECL:
			printToDebugFile("VAR_DECL\n");
			numLocalVars++;
			numStatements++;
			break;

		case DECL_EXPR:
			printToDebugFile("DECL_EXPR\n");
			numLocalVars++;
			numStatements++;
			break;

		case ADDR_EXPR:
			printToDebugFile("ADDR_EXPR\n");
			numStatements++;
			break;

		case MODIFY_EXPR:
			printToDebugFile("MODIFY_EXPR\n");
			numStatements++;
			break;

		case GOTO_EXPR:
			printToDebugFile("GOTO_EXPR\n");
			numStatements++;
			break;

		case LABEL_EXPR:
			printToDebugFile("LABEL_EXPR\n");
			if (breakCheck == 0) {
				breakCheck++;
			} else if (breakCheck == 1) {
				breakCheck++;
			}
			break;
	}
	printToDebugFile("\n");
}

void writeToFile() {
	//create file
	char *fileName = "output.txt";
	FILE *fp = fopen(fileName, "w+");

	//print stats
	fprintf(fp, "#functions: %d\n", numFunctions);
	fprintf(fp, "#global vars: %d\n", numGlobalVars);
	fprintf(fp, "#local vars: %d\n", numLocalVars);
	fprintf(fp, "#statements: %d\n", numStatements);

	//close file
	fclose(fp);
}

void initDebugFile() {
	//create file
	char *fileName = "debug.txt";
	debugF = fopen(fileName, "w+");
}

void printToDebugFile(char *message) {
	fprintf(debugF, message);
}

void closeDebugFile() {
	//close file
	fclose(debugF);
}















