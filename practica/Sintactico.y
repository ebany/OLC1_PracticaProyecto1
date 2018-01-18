%{
#include <iostream>
#include <QMessageBox>
#include <QList>
#include "Lexico.h"
#include "_Nodo.h"
#include "NodoLex.h"

using namespace std;

extern int yylineno;
extern char *yytext;
extern int yyfila;
extern int yycolumna;

QList<ErrLex *> erroresS;

//general
QList<InfoCls*> clases;

//temporal
QList<Gnrc*> metodos;
QList<Gnrc*> funciones;
QList<Gnrc*> atributos;
QList<Gnrc*> constructores;
QList<Gnrc*> overrides;

//global
Gnrc* varGlobal;

QList<InfoCls*> getClases(){
	return clases;
}

void limpiarClss(){
	metodos.clear();
	funciones.clear();
	atributos.clear();
	constructores.clear();
	overrides.clear();
}

void limpiarGeneral(){
	limpiarClss();
	clases.clear();
}

Nodo *raiz = NULL;

void reiniciar(){
	yyfila=1;
	yycolumna=0;
}

Nodo *GetRaiz(){
	return raiz;
}

void NullRaiz(){
	raiz = NULL;
}

QList<ErrLex *> lstErrores(){
	return erroresS;
}

void limpiarErrores(){
	erroresS.clear();
}

int yyerror(const char *error){	 	
	/*yycolumna =0;
	cout<<"\n\nError Sintactico:\n"<<error<<"\n\n"<<yyfila<<"--"<<yycolumna<<endl;*/
	raiz = NULL;

	ErrLex* nuevo = new ErrLex(error,yycolumna,yyfila);
	erroresS.append(nuevo);

	return 0;
}

%}

%error-verbose

%union {	
	char cadena[256];
	struct Nodo* NODO;
}

%token <cadena> tknPublic
%token <cadena> tknPrivate
%token <cadena> tknProtected
%token <cadena> tknClass
%token <cadena> tknInt
%token <cadena> tknString
%token <cadena> tknBoolean
%token <cadena> tknDouble
%token <cadena> tknChar
%token <cadena> tknNew
%token <cadena> tknIgual
%token <cadena> tknParA
%token <cadena> tknParC
%token <cadena> tknLlaveA
%token <cadena> tknLlaveC
%token <cadena> tknComa
%token <cadena> tknPtoComa
%token <cadena> tknVoid
%token <cadena> tknOverride
%token <cadena> tknThis
%token <cadena> tknIf
%token <cadena> tknElse
%token <cadena> tknSwitch
%token <cadena> tknCase
%token <cadena> tknDosPts
%token <cadena> tknBreak
%token <cadena> tknDefault
%token <cadena> tknWhile
%token <cadena> tknDo
%token <cadena> tknFor
%token <cadena> tknContinue
%token <cadena> tknNull
%token <cadena> tknPto
%token <cadena> tknMeMe
%token <cadena> tknMaMa
%token <cadena> tknAnd
%token <cadena> tknOr
%token <cadena> tknNot
%token <cadena> tknMenor
%token <cadena> tknMayor
%token <cadena> tknMenorQ
%token <cadena> tknMayorQ
%token <cadena> tknIgualIgual
%token <cadena> tknDiferente
%token <cadena> tknMas
%token <cadena> tknMenos
%token <cadena> tknPor
%token <cadena> tknDiv
%token <cadena> tknReturn
%token <cadena> tknExtends
%token <cadena> tknNumero
%token <cadena> tknId
%token <cadena> tknCadena
%token <cadena> tknCaracter

%left tknMenos tknMas
%left tknDiv tknPor 
%left tknOr
%left tknAnd
//%left tknParA
// %right tPotencia

%type <NODO> S
%type <NODO> CLS
%type <NODO> CL
%type <NODO> EXT
%type <NODO> EPS
%type <NODO> LST_CUERPO_CL
%type <NODO> CUERPO_CL
%type <NODO> DECL
%type <NODO> TIPO
%type <NODO> LST_ID
%type <NODO> DEC_ASIGN
%type <NODO>	OPC_EXP
%type <NODO>	PARAMETROS_1
%type <NODO>	LST_PARAM
%type <NODO>	PARAMETROS_2
%type <NODO>	LST_PARAM_2
%type <NODO>	CAJAS
%type <NODO>	OPC_CAJAS
%type <NODO>	CONSTRUCTOR
%type <NODO>	FUNC
%type <NODO>	MET
%type <NODO>	SOBRESC
%type <NODO>	OPC_SOBRESC
%type <NODO>	PRE_OBJ
%type <NODO>	LST_ACC
%type <NODO>	ACC_OBJ
%type <NODO>	OPC_ACC
%type <NODO>	ASIGN
%type <NODO>	INC_DEC
%type <NODO>	OPC_INCDEC
%type <NODO>	PRE_LLAMADA
%type <NODO>	LLAMADA
%type <NODO>	EXPRESION
%type <NODO>	REL
%type <NODO>	ART
%type <NODO>	IFF
%type <NODO>	OPC_IFF
%type <NODO>	LST_IFF
%type <NODO>	IF_ELSEF
%type <NODO>	FIN_IFF
%type <NODO>	SWITCHF
%type <NODO>	CASEF
%type <NODO>	LST_CASEF
%type <NODO>	DEFAULTF
%type <NODO>	CUERPO_SWITCHF
%type <NODO>	WHILEF
%type <NODO>	DO_WHILEF
%type <NODO>	OPC_FOR1
%type <NODO>	OPC_FOR2
%type <NODO>	FORF
%type <NODO>	PRE_CUERPOF
%type <NODO>	CUERPO_F
%type <NODO>	PRE_CUERPOFC
%type <NODO>	CUERPO_CICLOF
%type <NODO>	IFM
%type <NODO>	OPC_IFM
%type <NODO>	LST_IFM
%type <NODO>	IF_ELSEM
%type <NODO>	FIN_IFM
%type <NODO>	SWITCHM
%type <NODO>	CASEM
%type <NODO>	LST_CASEM
%type <NODO>	DEFAULTM
%type <NODO>	CUERPO_SWITCHM
%type <NODO>	WHILEM
%type <NODO>	DO_WHILEM
%type <NODO>	FORM
%type <NODO>	PRE_CUERPOM
%type <NODO>	CUERPO_M
%type <NODO>	PRE_CUERPOMC
%type <NODO>	CUERPO_CICLOM

%type <NODO>	AUX_A


%type <NODO> IFFC
%type <NODO> OPC_IFFC
%type <NODO> LST_IFFC
%type <NODO> IF_ELSEFC
%type <NODO> FIN_IFFC
%type <NODO> SWITCHFC
%type <NODO> CASEFC
%type <NODO> LST_CASEFC
%type <NODO> DEFAULTFC
%type <NODO> CUERPO_SWITCHFC

%type <NODO> IFMC
%type <NODO> OPC_IFMC
%type <NODO> LST_IFMC
%type <NODO> IF_ELSEMC
%type <NODO> FIN_IFMC
%type <NODO> SWITCHMC
%type <NODO> CASEMC
%type <NODO> LST_CASEMC
%type <NODO> DEFAULTMC
%type <NODO> CUERPO_SWITCHMC

%start S%%

S:				CLS
				{
					Nodo* nPadre = new Nodo("S","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				;

CLS:			CLS CL
				{
					Nodo* nPadre = new Nodo("CLS","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CL
				{
					Nodo* nPadre = new Nodo("CLS","",yyfila,yycolumna);
					$$ = nPadre;
				}								
				;

CL:				 AUX_A tknClass tknId EXT tknLlaveA LST_CUERPO_CL tknLlaveC
				{
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					$$ = nPadre;
					
					//cout<<"cls: "<<$4->fila<<endl;

					InfoCls* nClase = new InfoCls();
					nClase->metodos = metodos;
					nClase->funciones = funciones;
					nClase->atributos = atributos;
					nClase->constructores = constructores;
					nClase->overrides = overrides;
					nClase->id = $3;
					if($4->token=="EXT")
						nClase->extendss = $4->hijos.at(1)->lexema;
					nClase->fila = $4->fila;
					clases.append(nClase);
					limpiarClss();
				}
				| tknClass tknId EXT tknLlaveA LST_CUERPO_CL tknLlaveC
				{
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					$$ = nPadre;
					
					//cout<<"cls: "<<$3->fila<<endl;

					InfoCls* nClase = new InfoCls();
					nClase->metodos = metodos;
					nClase->funciones = funciones;
					nClase->atributos = atributos;
					nClase->constructores = constructores;
					nClase->overrides = overrides;
					nClase->id = $2;
					if($3->token=="EXT")
						nClase->extendss = $3->hijos.at(1)->lexema;
					nClase->fila = $3->fila;
					clases.append(nClase);
					limpiarClss();
				}
				| error tknId EXT tknLlaveA LST_CUERPO_CL tknLlaveC
				{
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					$$ = nPadre;					
				}
				| AUX_A error tknId EXT tknLlaveA LST_CUERPO_CL tknLlaveC
				{
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					$$ = nPadre;					
				}															
				;

AUX_A:			 tknPublic
				{
					Nodo* nPadre = new Nodo("tknPublic","+",yyfila,yycolumna);					
					$$ = nPadre;
				}
				| tknPrivate
				{
					Nodo* nPadre = new Nodo("tknPrivate","-",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknProtected
				{
					Nodo* nPadre = new Nodo("tknProtected","#",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

EXT:			tknExtends tknId
				{
					Nodo* nPadre = new Nodo("EXT","",yyfila,yycolumna);
					Nodo* tknExtends = new Nodo("tknExtends",$1,yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",$2,yyfila,yycolumna);
					nPadre->addHijo(tknExtends);
					nPadre->addHijo(tknId);
					$$ = nPadre;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("EPS","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

EPS:			{}
				;


LST_CUERPO_CL:	LST_CUERPO_CL CUERPO_CL
				{
					Nodo* nPadre = new Nodo("LST_CUERPO_CL","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CUERPO_CL
				{
					Nodo* nPadre = new Nodo("LST_CUERPO_CL","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				;

CUERPO_CL:		CAJAS
				{
					Nodo* nPadre = new Nodo("CUERPO_CL","",yyfila,yycolumna);
					$$ = nPadre;

					if(varGlobal->tipo.empty()){//constructor						
						constructores.append(varGlobal);
					}else if(varGlobal->tipo=="void"){//metodo						
						metodos.append(varGlobal);
					}else{//funcion						
						funciones.append(varGlobal);
					}
				}
				| DECL
				{
					Nodo* nPadre = new Nodo("CUERPO_CL","",yyfila,yycolumna);					
					$$ = nPadre;

					string acceso = "+";
					string tipo = "int";
					if($1->hijos.size()>3){//trae su acceso
						acceso = $1->hijos.at(0)->lexema;
						tipo = $1->hijos.at(1)->lexema;
						bool bandera = true;
						Nodo* temp = $1->hijos.at(2);
						while(bandera){
							Gnrc* atributo = new Gnrc();
							atributo->tipo = tipo;
							atributo->visibilidad = acceso;							
							if(temp->hijos.size()==1){
								atributo->id = temp->hijos.at(0)->lexema;	
								atributo->fila = temp->hijos.at(0)->fila;								
								bandera = false;
							}else{
								atributo->id = temp->hijos.at(2)->lexema;							
								atributo->fila = temp->hijos.at(2)->fila;
							}							
							atributos.append(atributo);							
							temp = temp->hijos.at(0);
						}
					}else{//es publico
						tipo = $1->hijos.at(0)->lexema;
						bool bandera = true;
						Nodo* temp = $1->hijos.at(1);
						while(bandera){
							Gnrc* atributo = new Gnrc();
							atributo->tipo = tipo;
							atributo->visibilidad = acceso;							
							if(temp->hijos.size()==1){
								atributo->id = temp->hijos.at(0)->lexema;
								atributo->fila = temp->hijos.at(0)->fila;								
								bandera = false;
							}else{
								atributo->id = temp->hijos.at(2)->lexema;							
								atributo->fila = temp->hijos.at(2)->fila;
							}
							atributos.append(atributo);							
							temp = temp->hijos.at(0);
						}
					}
				}
				| SOBRESC
				{
					Nodo* nPadre = new Nodo("CUERPO_CL","",yyfila,yycolumna);
					$$ = nPadre;
					overrides.append(varGlobal);
					//cout<<"override "<<varGlobal->visibilidad<<" "<<varGlobal->tipo<<" "<<varGlobal->id<<endl;
				}				
				;

DECL:			AUX_A TIPO LST_ID DEC_ASIGN
				{
					Nodo* nPadre = new Nodo("DECL","",yyfila,yycolumna);
					nPadre->addHijo($1);
					nPadre->addHijo($2);
					nPadre->addHijo($3);
					nPadre->addHijo($4);
					$$ = nPadre;
				} 
				| TIPO LST_ID DEC_ASIGN 
				{
					Nodo* nPadre = new Nodo("DECL","",yyfila,yycolumna);
					nPadre->addHijo($1);
					nPadre->addHijo($2);
					nPadre->addHijo($3);
					$$ = nPadre;
				}
				;

TIPO:			 tknId
				{					
					Nodo* tknTipo = new Nodo("tknTipo",$1,yyfila,yycolumna);
					$$ = tknTipo;					
				}
				| tknString
				{					
					Nodo* tknTipo = new Nodo("tknTipo",$1,yyfila,yycolumna);
					$$ = tknTipo;
				}

				| tknBoolean
				{					
					Nodo* tknTipo = new Nodo("tknTipo",$1,yyfila,yycolumna);
					$$ = tknTipo;
				}

				| tknDouble
				{					
					Nodo* tknTipo = new Nodo("tknTipo",$1,yyfila,yycolumna);
					$$ = tknTipo;
				}

				| tknChar
				{					
					Nodo* tknTipo = new Nodo("tknTipo",$1,yyfila,yycolumna);
					$$ = tknTipo;
				}

				| tknInt				
				{					
					Nodo* tknTipo = new Nodo("tknTipo",$1,yyfila,yycolumna);
					$$ = tknTipo;										
				}
				;

LST_ID:			LST_ID tknComa tknId
				{
					Nodo* nPadre = new Nodo("LST_ID","",yyfila,yycolumna);
					Nodo* tknComa = new Nodo("tknComa",$2,yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",$3,yyfila,yycolumna);
					nPadre->addHijo($1);
					nPadre->addHijo(tknComa);
					nPadre->addHijo(tknId);
					$$ = nPadre;
				}
				| tknId
				{
					Nodo* nPadre = new Nodo("LST_ID","",yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",$1,yyfila,yycolumna);
					nPadre->addHijo(tknId);
					$$ = nPadre;
				}
				;

DEC_ASIGN:		tknIgual OPC_EXP tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIgual error tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIgual OPC_EXP error
				{
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| error
				{
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				;

OPC_EXP:		EXPRESION
				{
					Nodo* nPadre = new Nodo("OPC_EXP","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknNew tknId tknParA PARAMETROS_1 tknParC		
				{
					Nodo* nPadre = new Nodo("OPC_EXP","",yyfila,yycolumna);
					$$ = nPadre;
				}		
				;

PARAMETROS_1:	LST_PARAM
				{
					Nodo* nPadre = new Nodo("PARAMETROS_1","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("PARAMETROS_1","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LST_PARAM:		LST_PARAM tknComa EXPRESION
				{
					Nodo* nPadre = new Nodo("LST_PARAM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EXPRESION
				{
					Nodo* nPadre = new Nodo("LST_PARAM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

PARAMETROS_2:	LST_PARAM_2
				{					
					$$ = $1;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("EPS","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LST_PARAM_2:	LST_PARAM_2 tknComa TIPO tknId
				{
					Nodo* nPadre = new Nodo("LST_PARAM_2","",yyfila,yycolumna);
					nPadre->addHijo($1);//mas id's
					nPadre->addHijo($3);//tipo nuevo id
					Nodo* id = new Nodo("tknId",$4,yyfila,yycolumna);
					nPadre->addHijo(id);
					$$ = nPadre;
				}
				| TIPO tknId
				{
					Nodo* nPadre = new Nodo("LST_PARAM_2","",yyfila,yycolumna);
					nPadre->addHijo($1);//tipo
					Nodo* id = new Nodo("tknId",$2,yyfila,yycolumna);
					nPadre->addHijo(id);
					$$ = nPadre;
				}
				;				

CAJAS:			AUX_A OPC_CAJAS
				{
					Nodo* nPadre = new Nodo("CAJAS","",yyfila,yycolumna);
					nPadre->addHijo($1);
					nPadre->addHijo($2);
					$$ = nPadre;

					Gnrc* nuevo = new Gnrc();
					nuevo->visibilidad = $1->lexema;
					if($2->token=="CONSTRUCTOR"){//es  CONSTRUCTOR
						nuevo->id = $2->hijos.at(0)->lexema;
						if($2->hijos.at(2)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = $2->hijos.at(2);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}						
						//constructores.append(nuevo);
						nuevo->fila = $2->hijos.at(0)->fila;
						varGlobal = nuevo;
						/*cout<<nuevo->id<<endl;					
						for(int a=0;a<nuevo->parametros.size();a++){
							cout<<nuevo->parametros.at(a)->tipo<<" "<<nuevo->parametros.at(a)->id<<endl;
						}*/
					}else{//es FUNCION o METODO
						nuevo->tipo = $2->hijos.at(0)->lexema;
						nuevo->id = $2->hijos.at(1)->lexema;
						if($2->hijos.at(3)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = $2->hijos.at(3);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}
						/*if($2->token=="FUNC"){//es FUNCION
							funciones.append(nuevo);
						}else{
							metodos.append(nuevo);
						}*/		
						nuevo->fila = $2->hijos.at(1)->fila;
						varGlobal = nuevo;										
					}
				}
				| OPC_CAJAS
				{
					Nodo* nPadre = new Nodo("CAJAS","",yyfila,yycolumna);					
					nPadre->addHijo($1);
					$$ = nPadre;

					Gnrc* nuevo = new Gnrc();
					if($1->token=="CONSTRUCTOR"){
						nuevo->id = $1->hijos.at(0)->lexema;
						if($1->hijos.at(2)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = $1->hijos.at(2);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}						
						//constructores.append(nuevo);
						nuevo->fila = $1->hijos.at(0)->fila;
						varGlobal = nuevo;
					}else{
						nuevo->tipo = $1->hijos.at(0)->lexema;
						nuevo->id = $1->hijos.at(1)->lexema;
						if($1->hijos.at(3)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = $1->hijos.at(3);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}
						/*if($1->token=="FUNC"){//es FUNCION
							funciones.append(nuevo);
						}else{
							metodos.append(nuevo);
						}*/
						nuevo->fila = $1->hijos.at(1)->fila;
						varGlobal = nuevo;
					}
				}				
				;

OPC_CAJAS:		CONSTRUCTOR
				{
					$$ = $1;
				}
				| FUNC
				{					
					$$ = $1;
				}
				| MET
				{
					$$ = $1;
				}				
				;

CONSTRUCTOR:	tknId tknParA PARAMETROS_2 tknParC tknLlaveA PRE_CUERPOM tknLlaveC
				{
					Nodo* nPadre = new Nodo("CONSTRUCTOR","",yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",$1,yyfila,yycolumna);					
					Nodo* tknParA = new Nodo("tknParA",$2,yyfila,yycolumna);										
					Nodo* tknParC = new Nodo("tknParC",$4,yyfila,yycolumna);					
					Nodo* tknLlaveA = new Nodo("tknLlaveA",$5,yyfila,yycolumna);										
					Nodo* tknLlaveC = new Nodo("tknLlaveC",$7,yyfila,yycolumna);					
					nPadre->addHijo(tknId);
					nPadre->addHijo(tknParA);	
					nPadre->addHijo($3);
					nPadre->addHijo(tknParC);
					nPadre->addHijo(tknLlaveA);
					nPadre->addHijo($6);
					nPadre->addHijo(tknLlaveC);
					$$ = nPadre;
				}
				| tknId tknParA PARAMETROS_2 tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("CONSTRUCTOR","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknId tknParA error tknParC tknLlaveA PRE_CUERPOM tknLlaveC
				{
					Nodo* nPadre = new Nodo("CONSTRUCTOR","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

FUNC:			TIPO tknId tknParA PARAMETROS_2 tknParC tknLlaveA PRE_CUERPOF tknLlaveC
				{
					Nodo* nPadre = new Nodo("FUNC","",yyfila,yycolumna);					
					Nodo* tknId = new Nodo("tknId",$2,yyfila,yycolumna);					
					Nodo* tknParA = new Nodo("tknParA",$3,yyfila,yycolumna);										
					Nodo* tknParC = new Nodo("tknParC",$5,yyfila,yycolumna);					
					Nodo* tknLlaveA = new Nodo("tknLlaveA",$6,yyfila,yycolumna);										
					Nodo* tknLlaveC = new Nodo("tknLlaveC",$8,yyfila,yycolumna);
					nPadre->addHijo($1);
					nPadre->addHijo(tknId);
					nPadre->addHijo(tknParA);	
					nPadre->addHijo($4);
					nPadre->addHijo(tknParC);
					nPadre->addHijo(tknLlaveA);
					nPadre->addHijo($7);
					nPadre->addHijo(tknLlaveC);
					$$ = nPadre;					
				}
				| TIPO tknId tknParA error tknParC tknLlaveA PRE_CUERPOF tknLlaveC
				{
					Nodo* nPadre = new Nodo("FUNC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| TIPO tknId tknParA PARAMETROS_2 tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("FUNC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

MET:			tknVoid tknId tknParA PARAMETROS_2 tknParC tknLlaveA PRE_CUERPOM tknLlaveC
				{
					Nodo* nPadre = new Nodo("MET","",yyfila,yycolumna);
					Nodo* tknVoid = new Nodo("tknVoid",$1,yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",$2,yyfila,yycolumna);					
					Nodo* tknParA = new Nodo("tknParA",$3,yyfila,yycolumna);										
					Nodo* tknParC = new Nodo("tknParC",$5,yyfila,yycolumna);					
					Nodo* tknLlaveA = new Nodo("tknLlaveA",$6,yyfila,yycolumna);										
					Nodo* tknLlaveC = new Nodo("tknLlaveC",$8,yyfila,yycolumna);
					nPadre->addHijo(tknVoid);
					nPadre->addHijo(tknId);
					nPadre->addHijo(tknParA);	
					nPadre->addHijo($4);
					nPadre->addHijo(tknParC);
					nPadre->addHijo(tknLlaveA);
					nPadre->addHijo($7);
					nPadre->addHijo(tknLlaveC);
					$$ = nPadre;					
				}
				| tknVoid tknId tknParA error tknParC tknLlaveA PRE_CUERPOM tknLlaveC
				{
					Nodo* nPadre = new Nodo("MET","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknVoid tknId tknParA PARAMETROS_2 tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("MET","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

SOBRESC:		tknOverride AUX_A OPC_SOBRESC
				{
					Nodo* nPadre = new Nodo("SOBRESC","",yyfila,yycolumna);
					$$ = nPadre;
					
					//cout<<$2->fila<<endl;
					Gnrc* nuevo = new Gnrc();
					nuevo->visibilidad = $2->lexema;
					nuevo->tipo = $3->hijos.at(0)->lexema;
					nuevo->id = $3->hijos.at(1)->lexema;
					if($3->hijos.at(3)->token!="EPS"){//si hay parametros
						bool bandera = true;
						Nodo* temp = $3->hijos.at(3);
						while(bandera){
							if(temp->hijos.size()>2){
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(1)->lexema;
								parametro->id = temp->hijos.at(2)->lexema;
								nuevo->parametros.push_front(parametro);
							}else{
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(0)->lexema;
								parametro->id = temp->hijos.at(1)->lexema;
								nuevo->parametros.push_front(parametro);
								bandera = false;
							}		
							temp = temp->hijos.at(0);						
						}
					}
					/*if($1->token=="FUNC"){//es FUNCION
						funciones.append(nuevo);
					}else{
						metodos.append(nuevo);
					}*/
					nuevo->fila = $2->fila;
					varGlobal = nuevo;					
				}
				| tknOverride OPC_SOBRESC
				{
					Nodo* nPadre = new Nodo("SOBRESC","",yyfila,yycolumna);
					$$ = nPadre;

					Gnrc* nuevo = new Gnrc();
					nuevo->visibilidad = "+";
					nuevo->tipo = $2->hijos.at(0)->lexema;
					nuevo->id = $2->hijos.at(1)->lexema;
					if($2->hijos.at(3)->token!="EPS"){//si hay parametros
						bool bandera = true;
						Nodo* temp = $2->hijos.at(3);
						while(bandera){
							if(temp->hijos.size()>2){
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(1)->lexema;
								parametro->id = temp->hijos.at(2)->lexema;
								nuevo->parametros.push_front(parametro);
							}else{
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(0)->lexema;
								parametro->id = temp->hijos.at(1)->lexema;
								nuevo->parametros.push_front(parametro);
								bandera = false;
							}		
							temp = temp->hijos.at(0);						
						}
					}
					nuevo->fila = $2->hijos.at(0)->fila;
					varGlobal = nuevo;					
				}
				;

OPC_SOBRESC:	FUNC
				{
					//Nodo* nPadre = new Nodo("OPC_SOBRESC","",yyfila,yycolumna);
					$$ = $1;
				}
				| MET
				{
					//Nodo* nPadre = new Nodo("OPC_SOBRESC","",yyfila,yycolumna);
					$$ = $1;
				}
				;

PRE_OBJ:		tknThis tknPto LST_ACC
				{
					Nodo* nPadre = new Nodo("PRE_OBJ","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknId tknPto LST_ACC
				{
					Nodo* nPadre = new Nodo("PRE_OBJ","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LST_ACC:		LST_ACC tknPto tknId
				{
					Nodo* nPadre = new Nodo("LST_ACC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknId
				{
					Nodo* nPadre = new Nodo("LST_ACC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

ACC_OBJ:		PRE_OBJ OPC_ACC
				{
					Nodo* nPadre = new Nodo("ACC_OBJ","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				 								

OPC_ACC:		tknParA PARAMETROS_1 tknParC
				{
					Nodo* nPadre = new Nodo("OPC_ACC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("OPC_ACC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

ASIGN:			tknId DEC_ASIGN
				{
					Nodo* nPadre = new Nodo("ASIGN","",yyfila,yycolumna);
					$$ = nPadre;					
				}
				| PRE_OBJ DEC_ASIGN
				{
					Nodo* nPadre = new Nodo("ASIGN","",yyfila,yycolumna);
					$$ = nPadre;					
				}
				| error DEC_ASIGN
				{
					Nodo* nPadre = new Nodo("ASIGN","",yyfila,yycolumna);
					$$ = nPadre;					
				}								
				;

INC_DEC:		tknId OPC_INCDEC
				{
					Nodo* nPadre = new Nodo("INC_DEC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| PRE_OBJ OPC_INCDEC
				{
					Nodo* nPadre = new Nodo("INC_DEC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

OPC_INCDEC:		tknMaMa
				{
					Nodo* nPadre = new Nodo("OPC_INCDEC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknMeMe
				{
					Nodo* nPadre = new Nodo("OPC_INCDEC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

PRE_LLAMADA:	tknParA PARAMETROS_1 tknParC
				{
					Nodo* nPadre = new Nodo("PRE_LLAMADA","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LLAMADA:		tknId PRE_LLAMADA tknPtoComa
				{
					Nodo* nPadre = new Nodo("LLAMADA","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| PRE_OBJ PRE_LLAMADA tknPtoComa
				{
					Nodo* nPadre = new Nodo("LLAMADA","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| PRE_OBJ PRE_LLAMADA error
				{
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknId PRE_LLAMADA error
				{
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;


EXPRESION:		EXPRESION tknAnd EXPRESION
				{
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EXPRESION tknOr EXPRESION
				{
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknNot EXPRESION		
				{
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					$$ = nPadre;
				}		
				| ART REL ART
				{
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknMenos ART
				{
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ART
				{
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ART EXPRESION
				{
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

REL:			tknMenor
				{
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknMayor
				{
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknMenorQ
				{
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknMayorQ
				{
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIgualIgual
				{
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDiferente
				{
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				

ART:			ART tknMas ART
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ART tknMenos ART
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ART tknPor ART
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ART tknDiv ART	
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}			
				| tknParA EXPRESION tknParC	
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}			
				| tknNumero
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCadena
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCaracter
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknId
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ACC_OBJ
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknId tknParA PARAMETROS_1 tknParC
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknNull
				{
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				






IFF:			tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOF tknLlaveC OPC_IFF
				{
					Nodo* nPadre = new Nodo("IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC OPC_IFF
				{
					Nodo* nPadre = new Nodo("IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA error tknParC tknLlaveA PRE_CUERPOF tknLlaveC OPC_IFF
				{
					Nodo* nPadre = new Nodo("IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

OPC_IFF:		LST_IFF FIN_IFF
				{
					Nodo* nPadre = new Nodo("OPC_IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FIN_IFF
				{
					Nodo* nPadre = new Nodo("OPC_IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				

LST_IFF:		LST_IFF IF_ELSEF
				{
					Nodo* nPadre = new Nodo("LST_IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IF_ELSEF
				{
					Nodo* nPadre = new Nodo("LST_IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

IF_ELSEF:		tknElse tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOF tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA error tknParC tknLlaveA PRE_CUERPOF tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

FIN_IFF:		tknElse tknLlaveA PRE_CUERPOF tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("FIN_IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

SWITCHF:		tknSwitch tknParA EXPRESION tknParC tknLlaveA CUERPO_SWITCHF tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA error tknParC tknLlaveA CUERPO_SWITCHF tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CASEF:			tknCase ART tknDosPts PRE_CUERPOF tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts PRE_CUERPOF tknBreak error
				{
					Nodo* nPadre = new Nodo("CASEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LST_CASEF:		LST_CASEF CASEF
				{
					Nodo* nPadre = new Nodo("LST_CASEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CASEF
				{
					Nodo* nPadre = new Nodo("LST_CASEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

DEFAULTF:		tknDefault tknDosPts PRE_CUERPOF tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts PRE_CUERPOF tknBreak error
				{
					Nodo* nPadre = new Nodo("DEFAULTF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CUERPO_SWITCHF:	LST_CASEF DEFAULTF
				{
					Nodo* nPadre = new Nodo("CUERPO_SWITCHF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

WHILEF:			tknWhile tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("WHILEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknWhile tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("WHILEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknWhile tknParA error tknParC tknLlaveA PRE_CUERPOFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("WHILEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

DO_WHILEF:		tknDo tknLlaveA PRE_CUERPOFC tknLlaveC tknWhile tknParA EXPRESION tknParC tknPtoComa
				{
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDo tknLlaveA PRE_CUERPOFC tknLlaveC tknWhile tknParA error tknParC tknPtoComa
				{
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDo tknLlaveA error tknLlaveC tknWhile tknParA EXPRESION tknParC tknPtoComa
				{
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDo tknLlaveA PRE_CUERPOFC tknLlaveC tknWhile tknParA EXPRESION tknParC error
				{
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

OPC_FOR1:		DECL
				{
					Nodo* nPadre = new Nodo("OPC_FOR1","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ASIGN
				{
					Nodo* nPadre = new Nodo("OPC_FOR1","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				;

OPC_FOR2:		tknId tknIgual OPC_EXP
				{
					Nodo* nPadre = new Nodo("OPC_FOR2","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| INC_DEC
				{
					Nodo* nPadre = new Nodo("OPC_FOR2","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				

FORF:			tknFor tknParA OPC_FOR1  EXPRESION tknPtoComa OPC_FOR2 tknParC tknLlaveA PRE_CUERPOFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("FORF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknFor tknParA OPC_FOR1  EXPRESION tknPtoComa OPC_FOR2 tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("FORF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknFor tknParA OPC_FOR1  EXPRESION error OPC_FOR2 tknParC tknLlaveA PRE_CUERPOF tknLlaveC
				{
					Nodo* nPadre = new Nodo("FORF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

PRE_CUERPOF:	PRE_CUERPOF CUERPO_F
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CUERPO_F
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CUERPO_F:		DECL		
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| LLAMADA
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IFF
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| SWITCHF
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| WHILEF
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| INC_DEC tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| DO_WHILEF
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FORF
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ASIGN
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknReturn EXPRESION tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknReturn error tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				| tknReturn EXPRESION error
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| INC_DEC error
				{
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;	


PRE_CUERPOFC:	PRE_CUERPOFC CUERPO_CICLOF
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CUERPO_CICLOF
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CUERPO_CICLOF:	DECL		
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| LLAMADA
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IFFC
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| SWITCHFC
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| INC_DEC tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| WHILEF
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| DO_WHILEF
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FORF
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ASIGN
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknReturn EXPRESION tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknContinue tknPtoComa				
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknContinue error				
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknBreak error
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknReturn EXPRESION error
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				| INC_DEC error
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

IFFC:			tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOFC tknLlaveC OPC_IFFC
				{
					Nodo* nPadre = new Nodo("IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC OPC_IFFC
				{
					Nodo* nPadre = new Nodo("IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA error tknParC tknLlaveA PRE_CUERPOFC tknLlaveC OPC_IFFC
				{
					Nodo* nPadre = new Nodo("IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

OPC_IFFC:		LST_IFFC FIN_IFFC
				{
					Nodo* nPadre = new Nodo("OPC_IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FIN_IFFC
				{
					Nodo* nPadre = new Nodo("OPC_IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				

LST_IFFC:		LST_IFFC IF_ELSEFC
				{
					Nodo* nPadre = new Nodo("LST_IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IF_ELSEFC
				{
					Nodo* nPadre = new Nodo("LST_IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

IF_ELSEFC:		tknElse tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA error tknParC tknLlaveA PRE_CUERPOFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

FIN_IFFC:		tknElse tknLlaveA PRE_CUERPOFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("FIN_IFFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

SWITCHFC:		tknSwitch tknParA EXPRESION tknParC tknLlaveA CUERPO_SWITCHFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA error tknParC tknLlaveA CUERPO_SWITCHFC tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CASEFC:			tknCase ART tknDosPts PRE_CUERPOFC tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts PRE_CUERPOFC tknBreak error
				{
					Nodo* nPadre = new Nodo("CASEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LST_CASEFC:		LST_CASEFC CASEFC
				{
					Nodo* nPadre = new Nodo("LST_CASEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CASEFC
				{
					Nodo* nPadre = new Nodo("LST_CASEFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

DEFAULTFC:		tknDefault tknDosPts PRE_CUERPOFC tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts PRE_CUERPOFC tknBreak error
				{
					Nodo* nPadre = new Nodo("DEFAULTFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CUERPO_SWITCHFC:	LST_CASEFC DEFAULTFC
				{
					Nodo* nPadre = new Nodo("CUERPO_SWITCHFC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;





IFM:			tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOM tknLlaveC OPC_IFM
				{
					Nodo* nPadre = new Nodo("IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC OPC_IFM
				{
					Nodo* nPadre = new Nodo("IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA error tknParC tknLlaveA PRE_CUERPOM tknLlaveC OPC_IFM
				{
					Nodo* nPadre = new Nodo("IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

OPC_IFM:		LST_IFM FIN_IFM
				{
					Nodo* nPadre = new Nodo("OPC_IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FIN_IFM
				{
					Nodo* nPadre = new Nodo("OPC_IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				

LST_IFM:		LST_IFM IF_ELSEM
				{
					Nodo* nPadre = new Nodo("LST_IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IF_ELSEM
				{
					Nodo* nPadre = new Nodo("LST_IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

IF_ELSEM:		tknElse tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOM tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA error tknParC tknLlaveA PRE_CUERPOM tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

FIN_IFM:		tknElse tknLlaveA PRE_CUERPOM tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("FIN_IFM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

SWITCHM:		tknSwitch tknParA EXPRESION tknParC tknLlaveA CUERPO_SWITCHM tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA error tknParC tknLlaveA CUERPO_SWITCHM tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CASEM:			tknCase ART tknDosPts PRE_CUERPOM tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts PRE_CUERPOM tknBreak error
				{
					Nodo* nPadre = new Nodo("CASEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LST_CASEM:		LST_CASEM CASEM
				{
					Nodo* nPadre = new Nodo("LST_CASEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CASEM
				{
					Nodo* nPadre = new Nodo("LST_CASEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

DEFAULTM:		tknDefault tknDosPts PRE_CUERPOM tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts PRE_CUERPOM tknBreak error
				{
					Nodo* nPadre = new Nodo("DEFAULTM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CUERPO_SWITCHM:	LST_CASEM DEFAULTM
				{
					Nodo* nPadre = new Nodo("CUERPO_SWITCHM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

WHILEM:			tknWhile tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("WHILEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknWhile tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("WHILEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknWhile tknParA error tknParC tknLlaveA PRE_CUERPOMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("WHILEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

DO_WHILEM:		tknDo tknLlaveA PRE_CUERPOMC tknLlaveC tknWhile tknParA EXPRESION tknParC tknPtoComa
				{
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDo tknLlaveA PRE_CUERPOMC tknLlaveC tknWhile tknParA error tknParC tknPtoComa
				{
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDo tknLlaveA error tknLlaveC tknWhile tknParA EXPRESION tknParC tknPtoComa
				{
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDo tknLlaveA PRE_CUERPOMC tknLlaveC tknWhile tknParA EXPRESION tknParC error
				{
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

FORM:			tknFor tknParA OPC_FOR1 EXPRESION tknPtoComa OPC_FOR2 tknParC tknLlaveA PRE_CUERPOMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("FORM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknFor tknParA OPC_FOR1 EXPRESION tknPtoComa OPC_FOR2 tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("FORM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknFor tknParA OPC_FOR1 EXPRESION error OPC_FOR2 tknParC tknLlaveA PRE_CUERPOMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("FORM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

PRE_CUERPOM:	PRE_CUERPOM CUERPO_M
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CUERPO_M
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOM","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				;

CUERPO_M:		DECL		
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| LLAMADA
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IFM
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| SWITCHM
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| WHILEM
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				|INC_DEC tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| DO_WHILEM
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FORM
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ASIGN
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknReturn tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				|INC_DEC error
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				| tknReturn error
				{
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;	


PRE_CUERPOMC:	PRE_CUERPOMC CUERPO_CICLOM
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CUERPO_CICLOM
				{
					Nodo* nPadre = new Nodo("PRE_CUERPOMC","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				;

CUERPO_CICLOM:	DECL
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| LLAMADA
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IFMC
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| SWITCHMC
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| WHILEM
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| DO_WHILEM
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| INC_DEC tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FORM
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| ASIGN
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknReturn tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknContinue tknPtoComa
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| INC_DEC error
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}				
				| tknReturn error
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknBreak error
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknContinue error
				{
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;




IFMC:			tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOMC tknLlaveC OPC_IFMC
				{
					Nodo* nPadre = new Nodo("IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC OPC_IFMC
				{
					Nodo* nPadre = new Nodo("IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknIf tknParA error tknParC tknLlaveA PRE_CUERPOMC tknLlaveC OPC_IFMC
				{
					Nodo* nPadre = new Nodo("IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

OPC_IFMC:		LST_IFMC FIN_IFMC
				{
					Nodo* nPadre = new Nodo("OPC_IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| FIN_IFMC
				{
					Nodo* nPadre = new Nodo("OPC_IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;				

LST_IFMC:		LST_IFMC IF_ELSEMC
				{
					Nodo* nPadre = new Nodo("LST_IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| IF_ELSEMC
				{
					Nodo* nPadre = new Nodo("LST_IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

IF_ELSEMC:		tknElse tknIf tknParA EXPRESION tknParC tknLlaveA PRE_CUERPOMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknIf tknParA error tknParC tknLlaveA PRE_CUERPOMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("IF_ELSEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

FIN_IFMC:		tknElse tknLlaveA PRE_CUERPOMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknElse tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("FIN_IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| EPS
				{
					Nodo* nPadre = new Nodo("FIN_IFMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

SWITCHMC:		tknSwitch tknParA EXPRESION tknParC tknLlaveA CUERPO_SWITCHMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA EXPRESION tknParC tknLlaveA error tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknSwitch tknParA error tknParC tknLlaveA CUERPO_SWITCHMC tknLlaveC
				{
					Nodo* nPadre = new Nodo("SWITCHMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CASEMC:			tknCase ART tknDosPts PRE_CUERPOMC tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("CASEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknCase ART tknDosPts PRE_CUERPOMC tknBreak error
				{
					Nodo* nPadre = new Nodo("CASEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

LST_CASEMC:		LST_CASEMC CASEMC
				{
					Nodo* nPadre = new Nodo("LST_CASEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| CASEMC
				{
					Nodo* nPadre = new Nodo("LST_CASEMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

DEFAULTMC:		tknDefault tknDosPts PRE_CUERPOMC tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts error tknBreak tknPtoComa
				{
					Nodo* nPadre = new Nodo("DEFAULTMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				| tknDefault tknDosPts PRE_CUERPOMC tknBreak error
				{
					Nodo* nPadre = new Nodo("DEFAULTMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

CUERPO_SWITCHMC:	LST_CASEMC DEFAULTMC
				{
					Nodo* nPadre = new Nodo("CUERPO_SWITCHMC","",yyfila,yycolumna);
					$$ = nPadre;
				}
				;

%%

