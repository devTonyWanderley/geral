#include "mascara.h"
#include "ui_mascara.h"

Mascara::Mascara(QWidget *parent): QDialog(parent), ui(new Ui::Mascara)
{
    ui->setupUi(this);
}

Mascara::~Mascara()
{
    delete ui;
}
