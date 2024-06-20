#include "user_v.h"
#include "ui_user_v.h"
#include "login_m.h"
user_v::user_v(QSqlDatabase d,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_v)
{
    ui->setupUi(this);
    db=d;
    m = new QSqlTableModel;
    m->setTable("users");
    ui->tableView->setModel(m);
}

user_v::~user_v()
{
    delete ui;
}

void user_v::on_query_Button_clicked()
{
    m->select();
}


void user_v::on_return_Button_clicked()
{
    emit returnToMainWindow();
}

