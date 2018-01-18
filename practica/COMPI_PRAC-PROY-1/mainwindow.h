#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QList>
#include "NodoLex.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void actualizar();
    void reporte(QList<ErrLex*> errores,QList<ErrLex*> lex,QList<ErrLex*> control);
    void generarImagen(QList<InfoCls*> clases);

private slots:
    void on_btnRutaTree_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_btnAnalizar_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
