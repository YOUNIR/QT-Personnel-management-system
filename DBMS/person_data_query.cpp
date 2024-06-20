#include "person_data_query.h"
#include "ui_person_data_query.h"

person_data_query::person_data_query(QSqlDatabase d,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::person_data_query)
{
    ui->setupUi(this);
    db=d;
    m = new QSqlTableModel;
    m->setTable("employee");
    ui->tableView->setModel(m);
}
person_data_query::~person_data_query()
{
    delete ui;
}
void person_data_query::on_pushButton_2_clicked()
{
    emit returnToMainWindow(); // 发射返回主窗口的信号
}
void person_data_query::on_pushButton_clicked()
{
    m->select();
}

