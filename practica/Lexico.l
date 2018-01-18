%option noyywrap
%{

#include <iostream>
#include <QList>
#include <QString>
#include <QStringList>
#include "Sintactico.h"
#include "NodoLex.h"

using namespace std;

int yyfila = 1;
int yycolumna = 0;
QList<ErrLex *> errores;

void limpirarLex(){
	errores.clear();
}

QList<ErrLex *> getErrLex(){
	return errores;
}

%}


Letra			[a-zA-ZñÑ]
number			[0-9]
entero			{number}+

real			{number}+("."{number}*)?

id				{Letra}({Letra}|{number}|_)*
comentarioML	[/][*][*][^*]*[*]+([^**/][^*]*[*]+)*[*][/]
comentarioL		"//".*	
cadena			\"[^"\n]*\"
caracter		"'"."'"

%%

" "				{ yycolumna+=yyleng; /*'{*/ }
"\t"			{ yycolumna+=yyleng;}
"\n"			{ yycolumna=0; yyfila+=1;}
"\r\n"			{ yycolumna=0; yyfila+=1;}
"EOF"			{ yycolumna+=yyleng;}

{comentarioL}	{ yycolumna+=yyleng;}

{comentarioML}	{ QString a = yytext; QStringList saltos = a.split("\n"); yyfila+= saltos.size()-1;}

"public"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknPublic;}
"private"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknPrivate;}
"protected"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknProtected;}
"class"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknClass;}
"int"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknInt;}
"String"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknString;}
"boolean"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknBoolean;}
"double"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknDouble;}
"char"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknChar;}
"new"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknNew;}
"="				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknIgual;}
"("				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknParA;}
")"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknParC;}
"{"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknLlaveA;}
"}"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknLlaveC;}
","				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknComa;}
";"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknPtoComa;}
"void"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknVoid;}
"@Override"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknOverride;}
"this"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknThis;}
"if"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknIf;}
"else"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknElse;}
"switch"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknSwitch;}
"case"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknCase;}
":"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknDosPts;}
"break"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknBreak;}
"default"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknDefault;}
"while"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknWhile;}
"do"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknDo;}
"for"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknFor;}
"continue"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknContinue;}
"null"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknNull;}
"."				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknPto;}
"--"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMeMe;}
"++"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMaMa;}
"&&"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknAnd;}
"||"			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknOr;}
"!"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknNot;}
"<"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMenor;}
">"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMayor;}
"<="			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMenorQ;}
">="			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMayorQ;}
"=="			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknIgualIgual;}
"!="			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknDiferente;}
"+"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMas;}
"-"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknMenos;}
"*"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknPor;}
"/"				{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknDiv;}
"return"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknReturn;}
"extends"		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknExtends;}

{id}			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknId;}

{cadena}		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknCadena;}

{caracter}		{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknCaracter;}

{real}			{ yycolumna+=yyleng; strcpy(yylval.cadena,yytext); return tknNumero;}

.				{
					ErrLex* nuevo = new ErrLex(yytext,yycolumna,yyfila);
					errores.append(nuevo);
					yycolumna+=yyleng;
					//cout<<"\n\nError Lexico:\nToken no reconocido "<<yytext<<"\n\n";
				}
%%