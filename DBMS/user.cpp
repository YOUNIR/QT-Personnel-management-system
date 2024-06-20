#include "user.h"
#include "ui_user.h"
#include "login_m.h"
user::user(QString name,QSqlDatabase d,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    db=d;
    m = new QSqlQueryModel;
    this->name=name;
}

user::~user()
{
    delete ui;
}

void user::on_return_Button_clicked()
{
    login_m* l=new login_m(db);
    this->close();
    l->show();
}


void user::on_pushButton_clicked()
{
    QSqlQuery query(db);
    query.prepare("select * FROM employee WHERE name = :name");
    query.bindValue(":name", name);
    if (query.exec()) {
        QMessageBox::information(this, "查询提示", "成功查询");
        m->setQuery(query);
        ui->tableView->setModel(m);
    } else {
        QMessageBox::warning(this, "查询提示", "查询失败: ");
    }
}

