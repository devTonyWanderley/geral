/**     @date       30/11/25    13:01
 *      @author     Tony
 *      @brief      Iniciar controle de versão
 *      @version    local da chave: C:\Users\micro\.ssh
 *                  nome da chave:  id_rsa
 *      Segmento    30/11/25    17:40
 *          ->anexar pasta e arquivos de classe ok;
 *          ->revisar classe 'Quadro'   ..  CONTINUA    ..
 *      ->  Criar o registro de navegação através dos quadros no próprio
 *          quadro usando uma pilha de endereços, principalmente quando
 *          precisa-se percorrer todo quadro e seus sub-quadros.
 *          Talvez elimina a necessidade da classe 'Locus'
 *          *** fazer um commit pq devo fazer modificações profundas    ***
 *
 *          remover os 'navega's de 'quadro'
 *
 *      @date       01/12/25    8:23
 *      ->Revisão profunda e rigorosa das 'estruturas gabarito'
 *      @date       01/12/25    13:48
 *      ->Funcional pra gerar o quadro
 *          Criar ancora pra limpar os excessos.
 *
 *      mapa:
 *          main.cpp:
 *              "mainwindow.h"
 *              <QApplication>
 *              <QLocale>
 *              <QTranslator>
 *
 *          mainwindow.cpp:
 *              "mainwindow.h"
 *              "./ui_mainwindow.h"
 *
 *          caderneta.cpp:
 *              "caderneta.h"
 *
 *          edpontos.cpp:
 *              "edpontos.h"
 *
 *          mainwindow.h
 *              <QMainWindow>
 *              "Recicla/caderneta.h"
 *
 *          caderneta.h:
 *              "edpontos.h"
 *              <QString>
 *              <QFile>
 *              <QFileDialog>
 *              <QDebug>
 *
 *          edpontos.h:
 *              "edpontos.h"
 *              <QString>
 *              <cmath>
 *              "edgabarito.h"
 *
 *          edgabarito.h:
 *
 *
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "Recicla/caderneta.h"
#include "Recicla/mascara.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Mascara *msc;
};
#endif // MAINWINDOW_H
