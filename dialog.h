#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <math.h>
#include <QDebug>
#include <cmath>

#include "planeta.h"
#include "aviso.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    Aviso *aviso;
    QGraphicsScene *scene;
    Planeta *sol;
    Planeta *planeta1;
    Planeta *planeta2;
    QTimer *actualizar;
    QList <Planeta*> planetas;

signals:
public slots:
    void posicion( );
private slots:
    void on_pushButton_clicked();
    void on_radioButton_clicked();
};
#endif // DIALOG_H
