#ifndef AVISO_H
#define AVISO_H

#include <QDialog>

namespace Ui {
class Aviso;
}

class Aviso : public QDialog
{
    Q_OBJECT

public:
    explicit Aviso(QWidget *parent = nullptr);
    ~Aviso();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Aviso *ui;
};

#endif // AVISO_H
