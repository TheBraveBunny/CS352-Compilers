
%{
#include <string.h>
#include"y.tab.h"
%}

%option yylineno


%%
"<br />" {
	return PRINTNEWLINE;
}

\""<br />"\" {
	return PRINTNEWLINE;
}

"<" {
	//printf("opencarrot\n");
	return OPENCARROT;
}

">" {
	//printf("closecarrot\n");
	return CLOSECARROT;
}

"script type=" {
	//printf("opening\n");
	return OPENING;
}

"/script" {
	//printf("closing\n");
	return CLOSING;
}

"var" {
	return VAR;
}

"=" {
	return EQUAL;
}

"." {
	return DOT;
}

":" {
	return COLON;
}

";" {
	return SEMICOLON;
}

"," {
	return COMMA;
}

"+" {
	return PLUS;
}

"-" {
	return MINUS;
}

"*" {
	return MULTIPLY;
}

"/" {
	return DIVIDE;
}

"(" {
	return OPENPAR;
}

")" {
	return CLOSEPAR;
}

"{" {
	return OPENCURLY;
}

"}" {
	return CLOSECURLY;
}

"document" {
	return DOCUMENT;
}

"write" {
	//printf("write\n");
	return WRITE;
}

[0-9]+ {
	yylval.number_val = atoi(yytext);
	return NUMBER;
}

\"[^\n\"]*\" {
	int length = strlen(yytext) - 2;
	char quote[length + 1];
	int i;
	for (i = 0; i < length; i++) {
		quote[i] = yytext[i+1];
	}
	quote[length] = '\0';
	yylval.string_val = strdup(quote);

	//printf("quote = %s\n", quote);
	return QUOTE;
}

[a-zA-Z][_a-zA-Z0-9]* {
	yylval.string_val = strdup(yytext);
	return ID;
}

("\n") {
	//printf("newline\n");
	return NEWLINE;
}

[ \t\r] {
		/* Discard spaces and tabs */
}

.	{
	yyerror("syntax error");
	exit(0);
}

