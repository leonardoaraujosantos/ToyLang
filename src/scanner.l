/*
	Flex definition file
*/

%{
#include <string>

#include "Ast/Node.hpp"
#include "Ast/NBlock.hpp"
#include "Ast/NStatement.hpp"
#include "Ast/NExpression.hpp"
#include "Ast/NIdentifier.hpp"
#include "Ast/NVariableDeclaration.hpp"

#include "parser.gen.hpp"

// Different ways to set the token value (yytext contains the matched text)
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)

extern "C" int yywrap() { }
%}

/* Regexp definition of each token*/
%%
[ \t\n] ;
[a-zA-Z_][a-zA-Z0-9_]* 		SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]* 				SAVE_TOKEN; return TDOUBLE;
[0-9]+ 						SAVE_TOKEN; return TINTEGER;
"=" 						return TOKEN(TEQUAL);
"==" 						return TOKEN(TCEQ);
"!=" 						return TOKEN(TCNE);
"<" 						return TOKEN(TCLT);
"<=" 						return TOKEN(TCLE);
">" 						return TOKEN(TCGT);
">=" 						return TOKEN(TCGE);
"(" 						return TOKEN(TLPAREN);
")" 						return TOKEN(TRPAREN);
"{" 						return TOKEN(TLBRACE);
"}" 						return TOKEN(TRBRACE);
"." 						return TOKEN(TDOT);
"," 						return TOKEN(TCOMMA);
"+" 						return TOKEN(TPLUS);
"-" 						return TOKEN(TMINUS);
"*" 						return TOKEN(TMUL);
"/" 						return TOKEN(TDIV);
. 							printf("Unknown token!\n"); yyterminate();	// Everything else is unknown

%%
