#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "L 7";
    Quadro qd;
    if(!LerCaderneta(qd)) return;
    ImprimeQuadro(qd);
    qDebug()
        << "Centro: "
        << qd.GetXc()
        << ' '
        << qd.GetYc()
        << "\nSemi largura: "
        << qd.GetSl()
        << "\nSemi altura: "
        << qd.GetSa()
        << "\nPontos na raiz: "
        << qd.Lp.Length();
}

MainWindow::~MainWindow()
{
    delete ui;
}
