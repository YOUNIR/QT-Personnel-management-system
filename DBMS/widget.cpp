#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QSqlDatabase d,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    db=d;
}

Widget::~Widget()
{
    delete ui;
}
//界面跳转
void Widget::on_person_m_clicked()
{
    this->hide();
    p=new Person_m(db);
    connect(p,&Person_m::returnToMainWindow,this,&Widget::returnToMain);
    p->show();
}
void Widget::returnToMain(){
    p->hide();
    this->show();
}

void Widget::on_salary_m_clicked()
{
    this->hide();
    s=new salary_m(NULL);
    connect(s,&salary_m::returnToMainWindow,this,&Widget::returnToMain1);
    s->show();
}
void Widget::returnToMain1(){
    s->hide();
    this->show();
}

void Widget::on_department_m_clicked()
{
    this->hide();
    d=new depart_m(db);
    connect(d,&depart_m::returnToMainWindow,this,&Widget::returnToMain2);
    d->show();
}
void Widget::returnToMain2(){
    d->hide();
    this->show();
}
void Widget::on_login_m_clicked()
{
    login_m* l=new login_m(db);
    this->close();
    l->show();
}

