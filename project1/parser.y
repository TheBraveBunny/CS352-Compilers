%{
#include<stdio.h>
%}

%token NUMBER ID QUOTE
%token OPENCARROT CLOSECARROT OPENING CLOSING
%token VAR EQUAL PLUS MINUS MULTIPLY DIVIDE
%token OPENPAR CLOSEPAR WRITE NEWLINE SEMICOLON COMMA



%% 

program:
	opening middle closing ending
;

opening:
	OPENCARROT OPENING QUOTE CLOSECARROT
;

middle:
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
	statements NEWLINE
;

statements:
	statement statement_tail
|
	/* can be empty */
;

statement:
	write
|
	assign
|
	declare
;

statement_tail:
	SEMICOLON statements
|
	/* can be empty */
;

write:
	WRITE OPENPAR param_list CLOSEPAR
;

param_list:
	param param_tail
|
	/* can be empty */
;

param_tail:
	COMMA param param_tail
|
	/* can be empty */
;

param:
	expression
;

expression:
	OPENPAR expression CLOSEPAR right_side
|
	expr
;

expr:
	left_side right_side
;

left_side:
	ID
|
	QUOTE
|
	NUMBER
;

right_side:
	op expression
|
	/* can be empty */
;

op:
	PLUS
|
	MINUS
|
	MULTIPLY
|
	DIVIDE
;

assign:
	ID EQUAL expression
;

declare:
	VAR ID declare_right_side
;

declare_right_side:
	EQUAL expression
|
	/* can be empty */
;

closing:
	OPENCARROT CLOSING CLOSECARROT
;

ending:
	NEWLINE ending
|
	/* can be empty */
;

%%

FILE *yyin;
int yylineno;
yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
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
