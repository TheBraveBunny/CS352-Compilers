REPORT: by Emma Caraher

I should have everything implemented. All student provided tests cases pass, including 
	the one specified in the handout.

I wrote everything in the csproj3.c file. I find useful function names and variable
names important, so I hope they can help you understand my code better. However, I will
go over them anyway.
	goThroughGlobalVars() iterates over all global vars
	goThroughFunctions() iterates over all functions, sends each to extractBody(),
		and then sends each extracted body to be analyzed in the goThroughBody() function
	extractBody() extracts the body from the function using the DECL_SAVED_TREE and BIND_EXPR_BODY macros
	goThroughBody() goes through all statements and sends each stmt to evaluateStatement()
	evaluateStatement() determines how to change the current number of stuff based
		on what kind of statement it is
	writeToFile() writes all data we've collected to "output.txt" in the format desired

I have written all debug comments to understand each statement into "debug.txt"