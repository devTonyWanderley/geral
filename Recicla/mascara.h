#ifndef MASCARA_H
#define MASCARA_H

#include <QDialog>
#include "caderneta.h"

namespace Ui {class Mascara;}

class Mascara : public QDialog
{
    Q_OBJECT

public:
    QStringList TxMsc;
    explicit Mascara(QWidget *parent = nullptr);
    ~Mascara();

private slots:
    void on_leTtl_textChanged(const QString &arg1);
    void on_leTam_textChanged(const QString &arg1);
    void on_cbTipo_currentIndexChanged(int index);

    void on_pbAdd_clicked();

    void on_cbMasc_activated(int index);

    void on_pbRemove_clicked();

private:
    Ui::Mascara *ui;

    QString Valida(QString arg, uint op);   //  op: 0 -> Título, 1 -> Inteiro
};

#endif // MASCARA_H
