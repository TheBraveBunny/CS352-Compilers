
%{
#include"y.tab.h"
%}

%option yylineno


%%
"<" {
	return OPENCARROT;
}

">" {
	return CLOSECARROT;
}

"script type=" {
	return OPENING;
}

"/script" {
	return CLOSING;
}

"var" {
	return VAR;
}

"=" {
	return EQUAL;
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

"document.write" {
	return WRITE;
}

[0-9]+ {
	return NUMBER;
}

\"[^\n\"]*\" {
	return QUOTE;
}

[a-zA-Z][_a-zA-Z0-9]* {
	return ID;
}

"\n" {
	return NEWLINE;
}

[ \t] 	{
		/* Discard spaces and tabs */
}

.	{
	yyerror("syntax error");
	exit(0);
}

