#include "person_m.h"
#include "ui_person_m.h"

Person_m::Person_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Person_m)
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

Person_m::~Person_m()
{
    delete ui;
}


//界面跳转
void Person_m::on_return_button_clicked()
{
    emit returnToMainWindow(); // 发射返回主窗口的信号
}
void Person_m::on_per_data_man_clicked()
{
    this->close();
    pm=new person_data_maintenance(db);
    connect(pm,&person_data_maintenance::returnToMainWindow,this,&Person_m::returnToMain);
    pm->show();
}
void Person_m::returnToMain(){
    pm->close();
    this->show();
}
void Person_m::returnToMain1(){
    pq->close();
    this->show();
}

void Person_m::on_per_in_que_clicked()
{
    this->close();
    pq=new person_data_query(db);
    connect(pq,&person_data_query::returnToMainWindow,this,&Person_m::returnToMain1);
    pq->show();
}

