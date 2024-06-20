#include "dept_v.h"
#include "ui_dept_v.h"

dept_v::dept_v(QSqlDatabase d,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dept_v)
{
    ui->setupUi(this);
    db=d;
    m = new QSqlQueryModel;
}

dept_v::~dept_v()
{
    delete ui;
}

void dept_v::on_query_Button_clicked()
{
    QSqlQuery query(db);
    query.prepare("select * FROM department");
    if (query.exec()) {
        QMessageBox::information(this, "查询提示", "成功查询");
        m->setQuery(query);
        ui->tableView->setModel(m);
    } else {
        QMessageBox::warning(this, "查询提示", "查询失败: ");
    }
}

void dept_v::on_return_Button_clicked()
{
    depart_m* d=new depart_m(db);
    this->close();
    d->show();
}

