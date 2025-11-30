#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QByteArray buf;
    if(!LerArquivo(IDIR, "Todos (*.*)", buf))
    {
        qDebug() << "Erro";
        return;
    }
    qDebug() << buf;
}

MainWindow::~MainWindow()
{
    delete ui;
}
