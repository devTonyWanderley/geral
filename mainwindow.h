/**     @date       30/11/25    13:01
 *      @author     Tony
 *      @brief      Iniciar controle de versão
 *      @version    local da chave: C:\Users\micro\.ssh
 *                  nome da chave:  id_rsa
 *      Segmento    30/11/25    17:40
 *          ->anexar pasta e arquivos de classe ok;
 *          ->revisar classe 'Quadro'
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
