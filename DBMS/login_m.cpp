#include "login_m.h"
#include "ui_login_m.h"
#include "widget.h"
#include "user.h"
login_m::login_m(QSqlDatabase d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_m)
{
    ui->setupUi(this);
    QSqlDatabase db;
}

login_m::~login_m()
{
    delete ui;
}

void login_m::on_return_Button_2_clicked()
{
    QString name=ui->namelineEdit->text();
    QSqlQuery query(db);
    query.prepare("select password FROM users WHERE name = :name");
    query.bindValue(":name", name);

    QString password=ui->passwardlineEdit->text();

    query.exec(); //执行查询
    query.next();
    QString correct_password=query.value(0).toString();
    if (password==correct_password) {
        QMessageBox::information(this, "登录提示", "成功登录");
        if(name=="张三"){
            Widget* w=new Widget(db);
            this->close();
            w->show();
        }
        else{
            user* u=new user(name,db,NULL);
            this->close();
            u->show();
        }
    } else {
        QMessageBox::warning(this, "登录提示", "密码错误");
    }
}
