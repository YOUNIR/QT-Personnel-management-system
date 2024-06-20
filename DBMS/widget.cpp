#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //连接数据库
    db=QSqlDatabase::addDatabase("QODBC");  //加载MySQL数据库驱动
    db.setDatabaseName("xc");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Luozhen924");
    if(db.open()){
        QMessageBox::information(this,"连接提示","连接成功");
    }
    else{
        QMessageBox::warning(this,"连接提示","连接失败");
    }
}

Widget::~Widget()
{
    delete ui;
}
//界面跳转
void Widget::on_person_m_clicked()
{
    this->hide();
    p=new Person_m(NULL);
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
    this->hide();
    l=new login_m(db);
    connect(l,&login_m::returnToMainWindow,this,&Widget::returnToMain3);
    l->show();
}
void Widget::returnToMain3(){
    l->hide();
    this->show();
}
