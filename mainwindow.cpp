#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    msc = new Mascara;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    msc->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    //for(uint i = 0; i < msc->TxMsc.length(); i++)
    //    qDebug()
    //        << msc->TxMsc.at(i);
    arquivo arq(msc->TxMsc);
    arq.testes(IDIR, "todos (*.*)", "Abrir arquivo");
}

