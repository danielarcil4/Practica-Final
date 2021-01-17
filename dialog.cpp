#include "dialog.h"
#include "ui_dialog.h"
int t=0;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->Mapa->setScene(scene);
    setFixedSize(1000,1000);
    ui->Mapa->rotate(180);

    sol = new Planeta(20);
    sol->setPos(0,0);
    sol->setBrush(Qt::yellow);

    planeta1 = new Planeta(7);
    planeta1->setPos(0,-5000);

    planeta2 = new Planeta(7);
    planeta2->setPos(0,5000);

    scene->addItem(sol);
    scene->addItem(planeta1);
    scene->addItem(planeta2);
    actualizar = new QTimer();
    planetas.push_back(planeta1);
    planetas.push_back(planeta2);
    planetas.push_back(sol);

    actualizar->start(200);

    connect(actualizar,SIGNAL(timeout()),this,SLOT(posicion()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::posicion()
{
    double g = 1;
    planeta1->setVx0(2);
    planeta1->setVy0(0);
    planeta2->setVx0(-1.6);
    planeta2->setVy0(1.2);

    t++;
    planeta1->setDistancia(sqrt(pow(sol->x()-planeta1->x(),2)+pow(sol->y()-planeta1->y(),2)));

    planeta1->setAngulo(atan((sol->y()-planeta1->y())/(sol->x()-planeta1->x()))*57.2958);

    if(sol->x()-planeta1->x()<0)
        planeta1->setAngulo(planeta1->getAngulo()+180);

    if(sol->x()-planeta1->x()>0 and sol->y()-planeta1->y()<0)
        planeta1->setAngulo(planeta1->getAngulo()+360);

    planeta1->setAx((g*70000/pow(planeta1->getDistancia(),2))*cos(planeta1->getAngulo()/57.2958));
    planeta1->setAy(((g*70000/pow(planeta1->getDistancia(),2))*sin(planeta1->getAngulo()/57.2958)));
    planeta1->setVx(planeta1->getVx0() + planeta1->getAx() *t);
    planeta1->setVy(planeta1->getVy0() + planeta1->getAy() *t);

    planeta1->setPos(planeta1->x() + planeta1->getVx() *t +(( planeta1->getAx() /2)*t*t) , planeta1->y() + planeta1->getVy() *t+(( planeta1->getAy() /2)*t*t));

    planeta2->setDistancia(sqrt(pow(sol->x()-planeta2->x(),2)+pow(sol->y()-planeta2->y(),2)));
    planeta2->setAngulo((atan2(planeta2->y()-sol->y(),planeta2->x()-sol->x()))*57.2958);

    if(sol->x()-planeta2->x()<0)
        planeta2->setAngulo(planeta2->getAngulo()+180);

    if(sol->x()-planeta2->x()>0 and sol->y()-planeta2->y()<0)
        planeta2->setAngulo(planeta2->getAngulo()+360);

    planeta2->setAx((g*70000/pow(planeta2->getDistancia(),2))*cos(planeta2->getAngulo()/57.2958));
    planeta2->setAy((g*70000/pow(planeta2->getDistancia(),2))*sin(planeta2->getAngulo()/57.2958));
    planeta2->setVx(planeta2->getVx0() + planeta2->getAx() *t);
    planeta2->setVy(planeta2->getVy0() + planeta2->getAy() *t);

    planeta2->setPos(planeta2->x() + planeta2->getVx() *t+( planeta2->getAx() /2)*t*t , planeta2->y() + planeta2->getVy() *t+( planeta2->getAy() /2)*t*t);

    if(planetas.length()>3){
        if(ui->checkBox->isChecked() and ui->comboBox->currentText() == "Planeta 3")
            qDebug() <<"Ax ("<<planetas.at(3)->getAx()<<") Ay ("<<planetas.at(3)->getAy()<<")  ";
        if(ui->checkBox_2->isChecked() and ui->comboBox->currentText() == "Planeta 3")
            qDebug() <<"Vx ("<<planetas.at(3)->getVx()<<") Vy ("<<planetas.at(3)->getVy()<<")  ";
        if(ui->checkBox_3->isChecked() and ui->comboBox->currentText() == "Planeta 3")
            qDebug() <<"X ("<<planetas.at(3)->x()<<") Y ("<<planetas.at(3)->y()<<")  ";
        planetas.at(3)->setVx0(2);
        planetas.at(3)->setVy0(0);

        planetas.at(3)->setDistancia(sqrt(pow(sol->x()-planetas.at(3)->x(),2)+pow(sol->y()-planetas.at(3)->y(),2)));
        planetas.at(3)->setAngulo((atan2(planetas.at(3)->y()-sol->y(),planetas.at(3)->x()-sol->x()))*57.2958);

        if(sol->x()-planetas.at(3)->x()<0)
            planetas.at(3)->setAngulo(planetas.at(3)->getAngulo()+180);

        if(sol->x()-planetas.at(3)->x()>0 and sol->y()-planetas.at(3)->y()<0)
            planetas.at(3)->setAngulo(planetas.at(3)->getAngulo()+360);

        planetas.at(3)->setAx((g*70000/pow(planetas.at(3)->getDistancia(),2))*cos(planetas.at(3)->getAngulo()/57.2958));
        planetas.at(3)->setAy((g*70000/pow(planetas.at(3)->getDistancia(),2))*sin(planetas.at(3)->getAngulo()/57.2958));
        planetas.at(3)->setVx(planetas.at(3)->getVx0() + planetas.at(3)->getAx() *t);
        planetas.at(3)->setVy(planetas.at(3)->getVy0() + planetas.at(3)->getAy() *t);

        planetas.at(3)->setPos(planetas.at(3)->x() + planetas.at(3)->getVx() *t+( planetas.at(3)->getAx() /2)*t*t , planetas.at(3)->y() + planetas.at(3)->getVy() *t+( planetas.at(3)->getAy() /2)*t*t);
    }
    if(planetas.length()>4){

        if(ui->checkBox->isChecked() and ui->comboBox->currentText() == "Planeta 4")
            qDebug() <<"Ax ("<<planetas.at(4)->getAx()<<") Ay ("<<planetas.at(4)->getAy()<<")  ";
        if(ui->checkBox_2->isChecked() and ui->comboBox->currentText() == "Planeta 4")
            qDebug() <<"Vx ("<<planetas.at(4)->getVx()<<") Vy ("<<planetas.at(4)->getVy()<<")  ";
        if(ui->checkBox_3->isChecked() and ui->comboBox->currentText() == "Planeta 4")
            qDebug() <<"X ("<<planetas.at(4)->x()<<") Y ("<<planetas.at(4)->y()<<")  ";

        planetas.at(4)->setVx0(-2);
        planetas.at(4)->setVy0(0);

        planetas.at(4)->setDistancia(sqrt(pow(sol->x()-planetas.at(4)->x(),2)+pow(sol->y()-planetas.at(4)->y(),2)));
        planetas.at(4)->setAngulo((atan2(planetas.at(4)->y()-sol->y(),planetas.at(4)->x()-sol->x()))*57.2958);

        if(sol->x()-planetas.at(4)->x()<0)
            planetas.at(4)->setAngulo(planetas.at(4)->getAngulo()+180);

        if(sol->x()-planetas.at(4)->x()>0 and sol->y()-planetas.at(4)->y()<0)
            planetas.at(4)->setAngulo(planetas.at(4)->getAngulo()+360);

        planetas.at(4)->setAx((g*70000/pow(planetas.at(4)->getDistancia(),2))*cos(planetas.at(4)->getAngulo()/57.2958));
        planetas.at(4)->setAy((g*70000/pow(planetas.at(4)->getDistancia(),2))*sin(planetas.at(4)->getAngulo()/57.2958));
        planetas.at(4)->setVx(planetas.at(4)->getVx0() + planetas.at(3)->getAx() *t);
        planetas.at(4)->setVy(planetas.at(4)->getVy0() + planetas.at(3)->getAy() *t);

        planetas.at(4)->setPos(planetas.at(4)->x() + planetas.at(4)->getVx() *t+( planetas.at(4)->getAx() /2)*t*t , planetas.at(4)->y() + planetas.at(4)->getVy() *t+( planetas.at(4)->getAy() /2)*t*t);
    }


    sol->setDistancia(sqrt(pow(planeta1->x()-planeta2->x(),2)+pow(planeta1->y()-planeta2->y(),2)));
    sol->setAngulo(atan((planeta1->y()-planeta2->y())/(planeta1->x()-planeta2->x()))*57.2958);

    if(planeta1->x()-planeta2->x()<0)
        sol->setAngulo(sol->getAngulo()+180);

    if(planeta1->x()-planeta2->x()>0 and planeta1->y()-planeta2->y()<0)
        sol->setAngulo(sol->getAngulo()+360);

    sol->setAx((g*140/pow(sol->getDistancia(),2))*cos(sol->getAngulo()/57.2958));
    sol->setAy(((g*140/pow(sol->getDistancia(),2))*sin(sol->getAngulo()/57.2958)));

    sol->setPos(sol->x() +( sol->getAx() /2)*t*t , sol->y() +( sol->getAy() /2)*t*t);

    if(ui->checkBox->isChecked() and ui->comboBox->currentText() == "Planeta 1")
        qDebug() <<"Ax ("<<planeta1->getAx()<<") Ay ("<<planeta1->getAy()<<")  ";
    if(ui->checkBox->isChecked() and ui->comboBox->currentText() == "Planeta 2")
        qDebug() <<"Ax ("<<planeta2->getAx()<<") Ay ("<<planeta2->getAy()<<")  ";
    if(ui->checkBox->isChecked() and ui->comboBox->currentText() == "Sol")
        qDebug() <<"Ax ("<<sol->getAx()<<") Ay ("<<sol->getAy()<<")  ";

    if(ui->checkBox_2->isChecked() and ui->comboBox->currentText() == "Planeta 1")
        qDebug() <<"Vx ("<<planeta1->getVx()<<") Vy ("<<planeta1->getVy()<<")  ";
    if(ui->checkBox_2->isChecked() and ui->comboBox->currentText() == "Planeta 2")
        qDebug() <<"Vx ("<<planeta2->getVx()<<") Vy ("<<planeta2->getVy()<<")  ";
    if(ui->checkBox_2->isChecked() and ui->comboBox->currentText() == "Sol")
        qDebug() <<"Vx ("<<sol->getVx()<<") Vy ("<<sol->getVy()<<")  ";

    if(ui->checkBox_3->isChecked() and ui->comboBox->currentText() == "Planeta 1")
        qDebug() <<"x ("<<planeta1->x()<<" )  y ("<<planeta1->y()<<") ";
    if(ui->checkBox_3->isChecked() and ui->comboBox->currentText() == "Planeta 2")
        qDebug() << "x ("<<planeta2->x()<<" )  y ("<<planeta2->y()<<") ";
    if(ui->checkBox_3->isChecked() and ui->comboBox->currentText() == "Sol")
        qDebug() << "x ("<<sol->x()<<" )  y ("<<sol->y()<<") ";

}



void Dialog::on_pushButton_clicked()
{
    if(planetas.length()<5){
        ui->comboBox->addItem(QString("Planeta ") + QString::number(planetas.length()));
        planetas.push_back(new Planeta(7));
        scene->addItem(planetas.back());
        planetas.back()->setPos(5000,0);
        if(planetas.length()==5)
            planetas.back()->setPos(-5000,0);
    }

    else{
        aviso =new Aviso;
        aviso->setModal(true);
        aviso->exec();
    }


}
