%{
#include<stdio.h>
%}

%token <number_val> NUMBER 
%token <string_val> ID
%token <string_val> QUOTE
%token OPENCARROT CLOSECARROT OPENING CLOSING
%token VAR EQUAL PLUS MINUS MULTIPLY DIVIDE
%token OPENPAR CLOSEPAR WRITE NEWLINE SEMICOLON COMMA DOCUMENT
%token OPENCURLY CLOSECURLY COLON DOT PRINTNEWLINE

%type <node_val> expression pm_expr pm_expr_tail dm_expr dm_expr_tail base_value sub_dm
%type <node_val> declare declare_tail declare_tail_tail assign
%type <node_val> fields fields_tail field field_tail id_list

%union	{
	char *string_val;
	int number_val;
	struct var_node *node_val;
}


%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yydebug = 1;
int lineno = 1;

enum NODE_TYPE
{
	NUMBER_NODE,
	OP_NODE,
	EMPTY_NODE,
	EMPTY_FIELD_NODE,
	FIELD_NODE,
	OBJECT_NODE,
	QUOTE_NODE,
	NEWLINE_NODE
};

struct var_node
{
	int declared;
	int initialized;

	enum NODE_TYPE type;
	char *id;

	int number;
	char *quote;
	char op;

	struct var_node * next;
};

struct var_node* find_variable(char *id);
struct var_node* find_variable_declare(char *id);
struct var_node* find_field(struct var_node* node, char *id);
void replace_variable(struct var_node *originalNode, struct var_node *newNode);
void make_variable(struct var_node * newNode);
void print_error();
void print_debug(char *s);

struct var_node *variables[50][100];
int numInst = 0;
int numVars[50];


%}

%% 

program:
	opening {
		numVars[0] = 0;
	} middle closing ending
;

opening:
	OPENCARROT OPENING QUOTE CLOSECARROT
;

middle:
	statements
|
	NEWLINE {
		++lineno;
	} middle_tail
;

middle_tail:
	lines
|
	/* can be empty */
;

lines:
	line
|
	line lines
;

line:
	statements NEWLINE {
		++lineno;
	}
;

statements:
	statement statement_tail
|
	/* can be empty */
;

statement_tail:
	SEMICOLON statement_tail_tail
|
	/* can be empty */
;

statement_tail_tail:
	statement statement_tail
|
	/* can be empty */
;

statement:
	DOCUMENT write
|
	VAR declare
|
	OPENCURLY {
		numVars[++numInst] = 0;
	} middle CLOSECURLY {
		--numInst;
	}
|
	assign
;

write:
	DOT WRITE OPENPAR param_list CLOSEPAR
;

param_list:
	param param_tail
;

param:
	expression {
		struct var_node *node = $1;
		if (node->type == NUMBER_NODE) {
			printf("%d", node->number);
			//free(node);
		} else if (node->type == QUOTE_NODE) {
			print_debug("is a quote node");
			printf("%s", node->quote);
		} else if (node->type == NEWLINE_NODE) {
			printf("\n");
		} else {
			print_debug("params error");
			print_error();
		}
	}
;

param_tail:
	COMMA param param_tail
|
	/* can be empty */
;

declare:
	ID declare_tail {
		struct var_node *idNode = find_variable_declare($1);
		struct var_node *assignment = $2;

			print_debug($1);

		if (idNode == NULL) {
			print_debug("declare new var");
			assignment->id = strdup($1);
			make_variable(assignment);
		} else if (idNode->type == assignment->type) {
			print_debug("declare error");
			print_error();
		} else {
			print_debug("replacing with new declare");
			replace_variable(idNode, assignment);
		}
	}
;

declare_tail:
	EQUAL declare_tail_tail {
		$$ = $2;
	}
|
	/* can be empty */ {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		$$ = node;
	}
;

declare_tail_tail:
	expression {
		$$ = $1;
	}
|
	OPENCURLY NEWLINE fields NEWLINE CLOSECURLY {
		lineno = lineno + 2;
		$$ = $3;
	}
;

fields:
	field fields_tail {
		print_debug("found fields");
		struct var_node *object = (struct var_node*)malloc(sizeof(struct var_node));
		object->type = OBJECT_NODE;
		
		struct var_node *left = $1;
		struct var_node *right = $2;

		if (right->type == EMPTY_NODE) {
			//free(right);
		} else {
			left->next = right;
		}

		object->next = left;
		$$ = object;
	}
;

fields_tail:
	COMMA field fields_tail {
		struct var_node *left = $2;
		struct var_node *right = $3;

		if (right->type == EMPTY_NODE) {
			//free(right);
		} else {
			left->next = right;
		}

		$$ = left;
	}
|
	/* can be empty */ {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		$$ = node;
	}
;

field:
	ending ID field_tail {
		struct var_node *node = $3;
		node->id = $2;
		$$ = node;
	}
;

field_tail:
	COLON expression {
		print_debug("found field tail");
		struct var_node *node = $2;
		if (node->type == NUMBER_NODE) {
			print_debug("number node");
		}
		$$ = $2;
	}
|
	/* can be empty */ {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_FIELD_NODE;
		$$ = node;
	}
;

closing:
	OPENCARROT CLOSING CLOSECARROT
;

assign:
	id_list EQUAL expression {
		struct var_node *idNode = $1;
		struct var_node *assignment = $3;

		if (idNode == NULL) {
			print_error();
		}

		if ((idNode->type == EMPTY_NODE) | (idNode->type == EMPTY_FIELD_NODE)) {
			idNode->type = assignment->type;
			if (assignment->type == NUMBER_NODE) {
				idNode->number = assignment->number;
				//free(assignment);
			} else if (assignment->type == QUOTE_NODE) {
				idNode->quote = strdup(assignment->quote);
				//free(assignment);
			} else if (assignment->type == NEWLINE_NODE) {
				//nothing
			} else {
				print_debug("assign error");
				print_error();
			}
		} else if(idNode->type != assignment->type) {
			if ((idNode->type == NEWLINE_NODE) && (assignment->type == QUOTE_NODE)) {
				idNode->type = QUOTE_NODE;
				idNode->quote = strdup(assignment->quote);
				//free(assignment);
			} else if ((idNode->type == QUOTE_NODE) && (assignment->type == NEWLINE_NODE)) {
				idNode->type = NEWLINE_NODE;
				//free(assignment);
			} else {
				print_debug("assign error");
				print_error();
			}
		} else {
			if (assignment->type == NUMBER_NODE) {
				idNode->number = assignment->number;
				//free(assignment);
			} else if (assignment->type == QUOTE_NODE) {
				idNode->quote = strdup(assignment->quote);
				//free(assignment);
			} else if (assignment->type == NEWLINE_NODE) {
				//nothing
			} else {
				print_debug("assign error");
				print_error();
			}
		}
	}
;

id_list:
	ID DOT ID {
		struct var_node *node = find_variable($1);
		if (node == NULL) {
			print_debug("idlist error");
			print_error();
		}

		$$ = find_field(node, $3);
	}
|
	ID {
		$$ = find_variable($1);
	}
;

expression:
	pm_expr {
		$$ = $1;
	}
;

pm_expr:
	dm_expr pm_expr_tail {
		struct var_node *left = $1;
		struct var_node *right = $2;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("pmexpr error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if(right->op == '+') {
					left->number += right->number;
				} else if (right->op == '-') {
					left->number -= right->number;
				} else {
					print_debug("pmexpr error");
					print_error();
				}
			} else if (left->type == QUOTE_NODE) {
				if(right->op == '+') {
					strcat(left->quote, right->quote);
				} else {
					print_debug("pm expr error");
					print_error();
				}
			} else {
				print_debug("pmexpr error");
				print_error();
			}
		}
		//free(right);
		$$ = left;
	}
;

pm_expr_tail:
	PLUS dm_expr pm_expr_tail {
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '+';
		struct var_node *left = $2;
		struct var_node *right = $3;
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("pmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '+') {
					left->number += right->number;
				} else if (right->op == '-') {
					left->number -= right->number;
				} else {
					print_debug("pmexprtail error");
					print_error();
				}
			} else if (left->type == QUOTE_NODE) {
				if (right->op == '+') {
					strcat(left->quote, right->quote);
				} else {
					print_debug("pmexprtail error");
					print_error();
				}
				
			} else {
				print_debug("pmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else if (nextOp->type == QUOTE_NODE) {
			nextOp->quote = strdup(left->quote);
		} else {
			print_debug("pmexprtail error");
			print_error();
		}
		//free(left);
		$$ = nextOp;
	}
|
	MINUS dm_expr pm_expr_tail {
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '-';
		struct var_node *left = $2;
		struct var_node *right = $3;
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("pmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '+') {
					left->number -= right->number;
				} else if (right->op == '-') {
					left->number += right->number;
				} else {
					print_debug("pmexprtail error");
					print_error();
				}
			} else {
				print_debug("pmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else {
			print_debug("pmexprtail error");
			print_error();
		}
		//free(left);
		$$ = nextOp;
	}
|
	/* can be empty */ {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		$$ = node;
	}
;

dm_expr:
	sub_dm dm_expr_tail {
		struct var_node *left = $1;
		struct var_node *right = $2;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("dmexpr error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if(right->op == '*') {
					left->number = left->number * right->number;
				} else if (right->op == '/') {
					if (right->number == 0) {
						print_debug("dmexpr error");
						print_error();
					} else {
						left->number = left->number / right->number;
					}
				} else {
					print_debug("dmexpr error");
					print_error();
				}
			} else {
				print_debug("dmexpr error");
				print_error();
			}
		}
		//free(right);
		$$ = left;
	}
;

dm_expr_tail:
	MULTIPLY sub_dm dm_expr_tail {
		print_debug("found * symbol");
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '*';
		struct var_node *left = $2;
		struct var_node *right = $3;
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("dmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '*') {
					left->number = left->number * right->number;
				} else if (right->op == '/') {
					if (right->number == 0) {
						print_debug("dmexprtail error");
						print_error();
					} else {
						left->number = left->number / right->number;
					}
				} else {
					print_debug("dmexprtail error");
					print_error();
				}
			} else {
				print_debug("dmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else {
			print_debug("dmexprtail error");
			print_error();
		}
		//free(left);
		$$ = nextOp;
	}
|
	DIVIDE sub_dm dm_expr_tail {
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '/';
		struct var_node *left = $2;
		struct var_node *right = $3;
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("dmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '/') {
					if (right->number == 0) {
						print_error();
					}
					left->number = left->number / right->number;
				} else if (right->op == '*') {
					left->number = right->number * left->number;
				} else {
					print_debug("dmexprtail error");
					print_error();
				}
			} else {
				print_debug("dmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else {
			print_debug("dmexprtail error");
			print_error();
		}
		//free(left);
		$$ = nextOp;
	}
|
	/* can be empty */ {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		$$ = node;
	}
;

sub_dm:
	base_value {
		$$ = $1;
	}
|
	OPENPAR expression CLOSEPAR {
		$$ = $2;
	}
;

base_value:
	NUMBER {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = NUMBER_NODE;
		node->number = $1;
		$$ = node;
	}
|
	QUOTE {
		print_debug("found quote");
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = QUOTE_NODE;
		node->quote = strdup($1);
		$$ = node;
	}
|
	ID DOT ID {
		struct var_node *node = find_variable($1);
		print_debug("looking for object");
		print_debug($1);
		if (node == NULL) {
			print_error();
			print_debug("basevalue error");
		}

		node = find_field(node, $3);
		if (node == NULL) {
			print_debug("basevalue error");
			print_error();
		}
		
		struct var_node *copy = (struct var_node*)malloc(sizeof(struct var_node));
		copy->type = node->type;
		if (node->type == NUMBER_NODE) {
			copy->number = node->number;
		} else if (node->type == QUOTE_NODE) {
			copy->quote = strdup(node->quote);
		} else if (node->type == NEWLINE_NODE) {
			//nothing
		} else {
			print_debug("basevalue error");
			print_error();
		}
		$$ = copy;
	}
|
	ID {
		print_debug("looking for variable");
		print_debug($1);
		struct var_node *node = find_variable($1);
		if (node == NULL) {
			print_debug("basevalue error");
			print_error();
		}

		struct var_node *copy = (struct var_node*)malloc(sizeof(struct var_node));
		copy->type = node->type;
		if (node->type == NUMBER_NODE) {
			copy->number = node->number;
		} else if (node->type == QUOTE_NODE) {
			copy->quote = strdup(node->quote);
		} else if (node->type == NEWLINE_NODE) {
			//nothing
		} else {
			print_debug("basevalue error");
			print_error();
		}
		$$ = copy;
	}
|
	PRINTNEWLINE {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = NEWLINE_NODE;
		$$ = node;
	}
;

ending:
	NEWLINE {
		++lineno;
	} ending
|
	/* can be empty */
;

%%

struct var_node* find_variable(char *name)
{
	//printf("numInst=%d\n", numInst);
    int i;
    int j;
	for (j = numInst; j>=0; j--) {
		for (i=0; i<numVars[j]; i++) {
			if (! strcmp(variables[j][i]->id, name)) {
				//printf("instance %d\tvar %d\n", j, i);
				return variables[j][i];
			}
		}
	}
	return NULL;
} 

struct var_node* find_variable_declare(char *name)
{
	//printf("numInst=%d\n", numInst);
	int i;
	int j = numInst;
	for (i=0; i<numVars[j]; i++) {
		if (! strcmp(variables[j][i]->id, name)) {
			//printf("instance %d\tvar %d\n", j, i);
			return variables[j][i];
		}
	}
	return NULL;
} 

void replace_variable(struct var_node *originalNode, struct var_node *newNode) 
{
	int i;
   	int j = numInst;
	for (i=0; i<numVars[j]; i++) {
		if (! strcmp(variables[j][i]->id, originalNode->id)) {
			variables[j][i] = newNode;
			//free(originalNode);
		}
	}
}

struct var_node* find_field(struct var_node *node, char *name)
{
    	struct var_node *ptr = node;
	while ((ptr=ptr->next) != NULL) {
		if (! strcmp(ptr->id, name)) {
			//printf("found field: %s\n", name);
			return ptr;
		}
	}
	return NULL;
} 

void make_variable(struct var_node *newVar) {
	variables[numInst][numVars[numInst]++] = newVar;
}

FILE *yyin;
int yylineno;
yyerror(char *s)
{
    printf("%s\n", s);
}

void print_debug(char *s) {
	//printf("%s\n", s);
}

void print_error() {
	printf("Line %d, type violation\n", lineno);
	exit(0);
}

main(int argc, char *argv[])
{
    //yydebug = 1;
    if (argc == 2) {
        FILE *file;

        file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "could not open %s\n", argv[1]);
        } else{
            yyin = file;
            //yyparse() will call yylex()
            yyparse();
        }
    } else{
        fprintf(stderr, "format: ./yacc_example [filename]");
    }
}
