#ifndef MASCARA_H
#define MASCARA_H

#include <QDialog>
#include "caderneta.h"

namespace Ui {class Mascara;}

class Mascara : public QDialog
{
    Q_OBJECT

public:
    explicit Mascara(QWidget *parent = nullptr);
    ~Mascara();

private slots:
private:
    Ui::Mascara *ui;
};

#endif // MASCARA_H
