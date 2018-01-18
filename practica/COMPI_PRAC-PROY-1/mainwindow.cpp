#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QDir>
#include <fstream>
#include <QDirIterator>
#include <QTreeView>
#include <QDirModel>
#include <QFileSystemModel>
#include <QString>
#include <QFileDialog>
#include <iostream>
#include <string>
#include <QMessageBox>
#include <sstream>
#include <QStringList>

#include "_Nodo.h"
#include "NodoLex.h"

using namespace std;

extern int yyrestart(FILE *archivo);
extern int yyparse();
extern Nodo *GetRaiz();
extern void NullRaiz();
extern QList<ErrLex *> lstErrores();
extern void reiniciar();
extern void limpiarErrores();
extern void limpirarLex();
extern QList<ErrLex *> getErrLex();

extern QList<InfoCls*> getClases();
extern void limpiarGeneral();

QFileSystemModel *model = new QFileSystemModel;
QString rutaSelected = "";
QString rutaActual = "";
QList<string> rutasArch;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeView->setModel(model);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRutaTree_clicked()//definir ruta para treeview
{
    QString ruta = QFileDialog::getExistingDirectory(this, tr("Establecer Directorio"),
                                                    "C:",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    rutaActual = ruta;
    actualizar();
}

void MainWindow::actualizar(){
    QDirIterator dirIt(rutaActual,QDirIterator::Subdirectories);
    if(!rutasArch.isEmpty())
        rutasArch.clear();

    while(dirIt.hasNext()){
        dirIt.next();
        if(QFileInfo(dirIt.filePath()).isFile())
            if(QFileInfo(dirIt.filePath()).suffix()=="java")
                rutasArch.push_back(dirIt.filePath().toStdString());
    }

    QModelIndex index = model->setRootPath(rutaActual);
    QStringList filters;
    filters<<"*.java";
    model->setNameFilters(filters);
    model->setNameFilterDisables(false);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(index);
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)//doble click treeview
{
    rutaSelected = model->filePath(index);
    this->ui->plainTextEdit->clear();
    QFile file;
            file.setFileName(model->filePath(index).toStdString().c_str());
            file.open(QIODevice::ReadOnly | QIODevice::Text);

    this->ui->plainTextEdit->appendPlainText(file.readAll());
}

void MainWindow::on_pushButton_clicked()//guardar archivo
{
    QString ruta = QFileDialog::getSaveFileName(
                this,
                tr("Guardar Pdf"),
                "C://",
                "Java File(*.java)"
                );

    ofstream graph;
    graph.open(ruta.toStdString().c_str(),ios::out);
    graph<<this->ui->plainTextEdit->toPlainText().toStdString().c_str();
    graph.close();
    rutaSelected = "";
    actualizar();
}

void MainWindow::on_pushButton_2_clicked()//modificar archivo
{
    if(!rutaSelected.isEmpty()){
        ofstream graph;
        graph.open(rutaSelected.toStdString().c_str(),ios::out);
        graph<<this->ui->plainTextEdit->toPlainText().toStdString().c_str();
        graph.close();        
        actualizar();


        QMessageBox::warning(this,"Informacion","Archivo Modificado :)");
    }else{
        QMessageBox::warning(this,"Informacion","Seleccione un archivo. >:v");
    }
}

void MainWindow::on_pushButton_3_clicked()//eliminar Archivo
{        
    for(int a=0;a<rutasArch.length();a++){
        if(rutaSelected.toStdString().compare(rutasArch.at(a))==0){
            rutasArch.removeAt(a);
            QFile file (rutaSelected);
            file.remove();
            actualizar();
            rutaSelected = "";
            QMessageBox::warning(this,"Informacion","Archivo Eliminado :)");
            for(int i =0;i<rutasArch.length();i++)
                cout<<rutasArch.at(i)<<endl;
            return;
        }
    }
    QMessageBox::warning(this,"Informacion","No se pudo eliminar el archivo :(");
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)//seleccion treeview
{
    rutaSelected = model->filePath(index);
}

void MainWindow::on_btnAnalizar_clicked()
{    
    if(!rutaSelected.isEmpty()){
        QList<ErrLex *> generalError;
        QList<ErrLex *> lexicosError;
        QList<ErrLex *> control;

            FILE *archivoInput;
            archivoInput = fopen(rutaSelected.toStdString().c_str(), "r");
            if(archivoInput!=NULL){
                limpiarGeneral();
                limpiarErrores();
                limpirarLex();
                reiniciar();
                yyrestart(archivoInput);
                yyparse();
                generalError = lstErrores();
                lexicosError = getErrLex();
                for(int b=0;b<generalError.size();b++){
                    generalError.at(b)->archivo = rutaSelected.toStdString();
                }
                for(int b=0;b<lexicosError.size();b++){
                    lexicosError.at(b)->archivo = rutaSelected.toStdString();
                }
            }else{
                QMessageBox::warning(this,"Informacion","Archivo no encontrado :(");
            }


        if(generalError.isEmpty() && lexicosError.isEmpty()){            
            QList<InfoCls*> clss = getClases();
            //EXTENDS
            for (int a = 0; a < clss.size(); ++a) {//buscar extends
                if(!clss.at(a)->extendss.empty()){
                    for (int b = 0;  b < clss.size(); ++ b) {
                        if(clss.at(a)->extendss.compare(clss.at(b)->id)==0){
                            break;
                        }else if(b==clss.size()-1){
                            ErrLex* nuevo = new ErrLex("Error en EXTENDS, no existe la clase.",0,clss.at(a)->fila);
                            control.append(nuevo);
                            break;
                        }
                    }
                }
            }
            //ATRIBUTOS
            for (int a = 0; a < clss.size(); ++a) {
                for (int b = 0; b < clss.at(a)->atributos.size(); ++b) {
                    string tipo = clss.at(a)->atributos.at(b)->tipo;
                    if(tipo!="int" && tipo!="String" && tipo!="boolean" && tipo!="double" && tipo!="char"){
                        for (int c = 0; c < clss.size(); ++c) {
                            if(tipo.compare(clss.at(c)->id)==0){
                                break;
                            }else if(c==clss.size()-1){
                                ErrLex* nuevo = new ErrLex("Error en TIPO de atributo, no existe la clase.",0,clss.at(a)->atributos.at(b)->fila);
                                control.append(nuevo);
                                break;
                            }
                        }
                    }
                }
            }
            //OVERRIDES
            for (int a = 0; a < clss.size(); ++a) {
                for (int b = 0; b < clss.at(a)->overrides.size(); ++b) {
                    if(clss.at(a)->extendss.empty()){
                        ErrLex* nuevo = new ErrLex("Error en SOBRESCRITURA, la clase no posee herencia.",0,clss.at(a)->overrides.at(b)->fila);
                        control.append(nuevo);
                    }else{
                        //buscar la clase a la que hereda
                        InfoCls* temp = 0;
                        for (int x = 0; x < clss.size(); ++x) {
                            if(clss.at(x)->id.compare(clss.at(a)->extendss)==0){
                                temp = clss.at(x);
                                break;
                            }
                        }
                        if(temp!=0){
                            bool resultado = false;
                            bool bandera = true;
                            while (bandera) {

                                if(temp!=0){
                                    if(clss.at(a)->overrides.at(b)->tipo=="void"){
                                        for (int y = 0; y < temp->metodos.size(); ++y) {
                                            if(temp->metodos.at(y)->id.compare(clss.at(a)->overrides.at(b)->id)==0){//nombres iguales
                                                if(temp->metodos.at(y)->tipo.compare(clss.at(a)->overrides.at(b)->tipo)==0){//tipos iguales
                                                    if(temp->metodos.at(y)->parametros.size()==clss.at(a)->overrides.at(b)->parametros.size()){//numero de parametros iguales
                                                        for (int h = 0; h < clss.at(a)->overrides.at(b)->parametros.size(); ++h) {
                                                            if(clss.at(a)->overrides.at(b)->parametros.at(h)->tipo.compare(temp->metodos.at(y)->parametros.at(h)->tipo)!=0){//si no son del mismo tipo
                                                                resultado = false;
                                                                break;
                                                            }else if(h==clss.at(a)->overrides.at(b)->parametros.size()-1){
                                                                resultado = true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }else if(!clss.at(a)->overrides.at(b)->tipo.empty()){
                                        for (int y = 0; y < temp->funciones.size(); ++y) {
                                            if(temp->funciones.at(y)->id.compare(clss.at(a)->overrides.at(b)->id)==0){//nombres iguales
                                                if(temp->funciones.at(y)->tipo.compare(clss.at(a)->overrides.at(b)->tipo)==0){//tipos iguales
                                                    if(temp->funciones.at(y)->parametros.size()==clss.at(a)->overrides.at(b)->parametros.size()){//numero de parametros iguales
                                                        for (int h = 0; h < clss.at(a)->overrides.at(b)->parametros.size(); ++h) {
                                                            if(clss.at(a)->overrides.at(b)->parametros.at(h)->tipo.compare(temp->funciones.at(y)->parametros.at(h)->tipo)!=0){//si no son del mismo tipo
                                                                resultado = false;
                                                                break;
                                                            }else if(h==clss.at(a)->overrides.at(b)->parametros.size()-1){
                                                                resultado = true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }else{
                                        ErrLex* nuevo = new ErrLex("Error en SOBRESCRITURA, falta el tipo de retorno.",0,clss.at(a)->overrides.at(b)->fila);
                                        control.append(nuevo);
                                    }
                                    //SALIDA, SI LA CLASE A LA QUE EXTIENDE NO EXTIENDE DE OTRA
                                    if(temp->extendss.empty()){
                                        bandera=false;
                                    }else{
                                        for (int x = 0; x < clss.size(); ++x) {
                                            if(clss.at(x)->id.compare(temp->extendss)==0){
                                                temp = clss.at(x);
                                                break;
                                            }else if(x==clss.size()-1){
                                                bandera=false;
                                            }
                                        }
                                    }
                                }else{
                                    bandera = false;
                                }
                            }
                            if(resultado==false){
                                ErrLex* nuevo = new ErrLex("Error en SOBRESCRITURA, no coincide con ningun metodo o funcion.",0,clss.at(a)->overrides.at(b)->fila);
                                control.append(nuevo);
                            }
                        }
                    }
                }
            }
            //CORRECTO??
            if(control.isEmpty()){
                generarImagen(clss);
                QMessageBox::warning(this,"Informacion","Archivo sin errores.");
            }else{
                QMessageBox::warning(this,"Informacion","Existe uno o mas errores en el archivo.");
            }
        }else{
            QMessageBox::warning(this,"Informacion","Existe uno o mas errores en el archivo.");
        }
        reporte(generalError,lexicosError,control);
    }else{
        QMessageBox::warning(this,"Informacion","Seleccione un archivo >:v");
    }

}

void MainWindow::reporte(QList<ErrLex *> errores,QList<ErrLex *> lex,QList<ErrLex *> control){
    string texto = "<!DOCTYPE html>\n<html>\n<head>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n<title>Errores</title>\n</head>\n<body>\n";
    texto+="<h2>Errores Lexicos y Sintacticos</h2>\n<table border=1 cellsapacing=0 cellpadding=2>\n<thead>\n<tr>\n<th>No.</th>\n<th>Descripcion</th>\n<th>Token Recibido</th>\n<th>Token(s) esperado(s)</th>\n<th>Linea</th>\n<th>Columna</th>\n<th>Archivo</th>\n</tr>\n</thead>\n<tbody>\n";
    for(int a=0;a<errores.size();a++){
        stringstream convert;
        convert<<a;
        stringstream convert1;
        convert1<<errores.at(a)->fila;
        stringstream convert2;
        convert2<<errores.at(a)->columna;

        QString textoW = errores.at(a)->archivo.c_str();
        QStringList n = textoW.split("/");
        string ruta = textoW.split("/").at(n.size()-1).toStdString();

        QString nuevo = errores.at(a)->error.c_str();
        nuevo.replace("syntax error,","Error Sintactico,");
        nuevo.replace("unexpected","");
        nuevo.replace("expecting","");

        QStringList desc = nuevo.split(",");

        texto+="<tr>\n";
        texto+="<td>"+convert.str()+"</td>\n";
        texto+="<td>"+desc.at(0).toStdString()+"</td>\n";
        texto+="<td>"+desc.at(1).toStdString()+"</td>\n";
        if(desc.size()>2){
            texto+="<td>"+desc.at(2).toStdString()+"</td>\n";
        }else{
            texto+="<td> </td>\n";
        }
        texto+="<td>"+convert1.str()+"</td>\n";
        texto+="<td>"+convert2.str()+"</td>\n";
        texto+="<td>"+ruta+"</td>\n";
        texto+="</tr>\n";
    }

    for (int a = 0; a < lex.size(); ++a) {
        stringstream convert;
        convert<<a;
        stringstream convert1;
        convert1<<lex.at(a)->fila;
        stringstream convert2;
        convert2<<lex.at(a)->columna;

        QString textoW = lex.at(a)->archivo.c_str();
        QStringList n = textoW.split("/");
        string ruta = textoW.split("/").at(n.size()-1).toStdString();

        texto+="<tr>\n";
        texto+="<td>"+convert.str()+"</td>\n";
        texto+="<td>Error Lexico: "+lex.at(a)->error+"</td>\n";
        texto+="<td> </td>\n";
        texto+="<td> </td>\n";
        texto+="<td>"+convert1.str()+"</td>\n";
        texto+="<td>"+convert2.str()+"</td>\n";
        texto+="<td>"+ruta+"</td>\n";
        texto+="</tr>\n";
    }

    texto+= "</tbody>\n</table>\n";
    texto+= "<h2>Excepciones de control</h2>\n<table border=1 cellsapacing=0 cellpadding=2>\n<thead>\n<tr>\n<th>No.</th>\n<th>Descripcion</th>\n<th>Linea</th>\n</tr>\n</thead>\n<tbody>";
    for (int a = 0; a < control.size(); ++a) {
        stringstream convert;
        convert<<a;
        stringstream convert1;
        convert1<<control.at(a)->fila;
        texto+="<tr>\n";
        texto+="<td>"+convert.str()+"</td>\n";
        texto+="<td>"+control.at(a)->error+"</td>\n";
        texto+="<td>"+convert1.str()+"</td>\n";
        texto+="</tr>\n";
    }
    texto+= "</tbody>\n</table>\n</body>\n</html>";
    //cout<<texto<<endl;
    ofstream graph;
    graph.open("errores.html",ios::out);
    graph<<texto;
    graph.close();
}

void MainWindow::on_pushButton_4_clicked()//ver reporte de errores
{
    system("errores.html");
}

void MainWindow::on_pushButton_5_clicked()//generar imagen y visualizarla
{
    system("clases.png");

}

void MainWindow::generarImagen(QList<InfoCls *> clases){
    ofstream graph;
    graph.open("clases.txt",ios::out);

    string datos = "digraph structs{\nnode [shape=record];\n";
    for (int a = 0; a < clases.size(); ++a) {
        datos+="\""+clases.at(a)->id+"\" [shape=record,label=\"{"+clases.at(a)->id+"|";
        //AGREGAR ATRIBUTOS
        for (int m = 0; m < clases.at(a)->atributos.size(); ++m) {
            datos+=clases.at(a)->atributos.at(m)->visibilidad+" "+clases.at(a)->atributos.at(m)->tipo+" "+clases.at(a)->atributos.at(m)->id+"\\l";
        }
        datos+="|";

        //CONSTRUCTORES
        for (int m = 0; m < clases.at(a)->constructores.size(); ++m) {
            datos+=clases.at(a)->constructores.at(m)->visibilidad+" "+clases.at(a)->constructores.at(m)->id+"( ";
            for (int n = 0; n < clases.at(a)->constructores.at(m)->parametros.size(); ++n) {
                datos+=clases.at(a)->constructores.at(m)->parametros.at(n)->tipo+" "+clases.at(a)->constructores.at(m)->parametros.at(n)->id;
                if (n!=clases.at(a)->constructores.at(m)->parametros.size()-1) {
                    datos+=",";
                }
            }
            datos+=" )\\l";
        }
        //AGREGAR FUNCIONES        
        for (int m = 0; m < clases.at(a)->funciones.size(); ++m) {
            datos+=clases.at(a)->funciones.at(m)->visibilidad+" "+clases.at(a)->funciones.at(m)->tipo+" "+clases.at(a)->funciones.at(m)->id+"(";
            for (int n = 0; n < clases.at(a)->funciones.at(m)->parametros.size(); ++n) {
                datos+=clases.at(a)->funciones.at(m)->parametros.at(n)->tipo+" "+clases.at(a)->funciones.at(m)->parametros.at(n)->id;
                if (n!=clases.at(a)->funciones.at(m)->parametros.size()-1) {
                    datos+=",";
                }
            }
            datos+=" )\\l";
        }
        //AGREGAR METODOS
        for (int m = 0; m < clases.at(a)->metodos.size(); ++m) {
            datos+=clases.at(a)->metodos.at(m)->visibilidad+" "+clases.at(a)->metodos.at(m)->tipo+" "+clases.at(a)->metodos.at(m)->id+"(";
            for (int n = 0; n < clases.at(a)->metodos.at(m)->parametros.size(); ++n) {
                datos+=clases.at(a)->metodos.at(m)->parametros.at(n)->tipo+" "+clases.at(a)->metodos.at(m)->parametros.at(n)->id;
                if (n!=clases.at(a)->metodos.at(m)->parametros.size()-1) {
                    datos+=",";
                }
            }
            datos+=" )\\l";
        }
        //AGREGAR OVERRIDES
        for (int m = 0; m < clases.at(a)->overrides.size(); ++m) {
            datos+=clases.at(a)->overrides.at(m)->visibilidad+" "+clases.at(a)->overrides.at(m)->tipo+" "+clases.at(a)->overrides.at(m)->id+"(";
            for (int n = 0; n < clases.at(a)->overrides.at(m)->parametros.size(); ++n) {
                datos+=clases.at(a)->overrides.at(m)->parametros.at(n)->tipo+" "+clases.at(a)->overrides.at(m)->parametros.at(n)->id;
                if (n!=clases.at(a)->overrides.at(m)->parametros.size()-1) {
                    datos+=",";
                }
            }
            datos+=" )\\l";
        }
        datos+="}\"];\n";
    }

    //RELACION DE HERENCIA
    for (int a = 0; a < clases.size(); ++a) {
        if(!clases.at(a)->extendss.empty()){
            datos+="\""+clases.at(a)->id+"\"->\""+clases.at(a)->extendss+"\" [arrowhead=\"onormal\"];\n";
        }
    }

    //RELACION DE AGREGACION
    for (int a = 0; a < clases.size(); ++a) {
        for (int b = 0; b < clases.at(a)->atributos.size(); ++b) {
            string tipo = clases.at(a)->atributos.at(b)->tipo;
            if(tipo!="int" && tipo!="String" && tipo!="boolean" && tipo!="double" && tipo!="char"){
                datos+="\""+clases.at(a)->atributos.at(b)->tipo+"\"->\""+clases.at(a)->id+"\" [arrowhead=\"odiamond\"];\n";
            }
        }
    }
    datos+="\n}";
    graph<<datos;
    graph.close();
    system("dot -Tpng clases.txt -o clases.png");
}





