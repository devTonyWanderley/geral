#include "mascara.h"
#include "ui_mascara.h"

Mascara::Mascara(QWidget *parent): QDialog(parent), ui(new Ui::Mascara)
{
    ui->setupUi(this);
    TxMsc.clear();
    ui->pbAdd->setEnabled(false);
    ui->pbRemove->setEnabled(false);
    ui->leTam->setEnabled(false);
    ui->cbMasc->setVisible(false);
    ui->leTtl->setFocus();
}

QString Mascara::Valida(QString arg, uint op)
{
    QString r = arg;
    if(!r.length()) return r;
    QChar ch = r.back();
    if(!op)
    {
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return r;
        return r.left(r.length() - 1);
    }
    if(ch >= '0' && ch <= '9') return r;
    return r.left(r.length() - 1);
}

void Mascara::on_leTtl_textChanged(const QString &arg1)
{
    ui->leTtl->setText(Valida(arg1, 0));
    ui->leTam->setEnabled(ui->leTtl->text().length());
    ui->pbAdd->setEnabled(ui->leTam->text().length() && ui->leTtl->text().length());
    ui->cbMasc->setVisible(ui->leTam->text().length() && ui->leTtl->text().length());
}

void Mascara::on_leTtl_editingFinished()
{
    ui->leTam->setFocus();
    ui->leTam->selectAll();
}

void Mascara::on_leTam_textChanged(const QString &arg1)
{
    ui->leTam->setText(Valida(arg1, 1));
    ui->pbAdd->setEnabled(ui->leTam->text().length() && ui->leTtl->text().length());
    ui->cbMasc->setVisible(ui->leTam->text().length() && ui->leTtl->text().length());
}
void Mascara::on_leTam_editingFinished()
{
    ui->pbAdd->setFocus();
}

void Mascara::on_cbMasc_activated(int index)
{
    ui->pbRemove->setEnabled(true);
}

void Mascara::on_pbAdd_clicked()
{
    QString ln = ui->leTtl->text() + ' ' + ui->leTam->text();
    TxMsc.push_back(ln);
    ui->cbMasc->clear();
    ui->cbMasc->addItems(TxMsc);
    ui->cbMasc->setCurrentIndex(TxMsc.length()-1);
    ui->leTtl->setFocus();
    ui->leTtl->selectAll();
}

void Mascara::on_pbRemove_clicked()
{
    if(!TxMsc.length()) return;
    QStringList copia = TxMsc;
    TxMsc.clear();
    for(uint i = 0; i < copia.length(); i++)
    {
        if(i != ui->cbMasc->currentIndex()) TxMsc.push_back(copia.at(i));
    }
    ui->cbMasc->clear();
    ui->cbMasc->addItems(TxMsc);
}

void Mascara::on_pbOk_clicked()
{
    this->hide();
}

Mascara::~Mascara()
{
    delete ui;
}
