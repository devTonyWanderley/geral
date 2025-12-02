#include "mascara.h"
#include "ui_mascara.h"

Mascara::Mascara(QWidget *parent): QDialog(parent), ui(new Ui::Mascara)
{
    ui->setupUi(this);
    QStringList tipos;
    tipos << "Texto" << "Real" << "Inteiro";
    ui->cbTipo->addItems(tipos);
    ui->pbAdd->setEnabled(false);
    ui->pbRemove->setEnabled(false);
}

void Mascara::on_leTtl_textChanged(const QString &arg1)
{
    QString tx = arg1;
    if(tx.length())
    {
        QChar ch = tx.back();
        if(!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
            tx = tx.left((tx.length() - 1));
    }
    ui->leTtl->setText(tx);
}

void Mascara::on_leTam_textChanged(const QString &arg1)
{
    QString tx = arg1;
    if(tx.length())
    {
        QChar ch = tx.back();
        if(!(ch >= '0' && ch <= '9'))
            tx = tx.left((tx.length() - 1));
    }
    ui->leTam->setText(tx);
}

void Mascara::on_cbTipo_currentIndexChanged(int index)
{}

Mascara::~Mascara()
{
    delete ui;
}
