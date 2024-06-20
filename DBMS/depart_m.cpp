#include "depart_m.h"
#include "ui_depart_m.h"
#include "dept_v.h"
#include "widget.h"
depart_m::depart_m(QSqlDatabase d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::depart_m)
{
    ui->setupUi(this);
    db=d;
    m = new QSqlQueryModel;
}

depart_m::~depart_m()
{
    delete ui;
}

void depart_m::on_return_Button_clicked()
{
    Widget* w=new Widget(db);
    this->close();
    w->show();
}


void depart_m::on_query_Button_clicked()
{
    QString name=ui->dapartmentlineEdit->text();
    QSqlQuery query(db);
    query.prepare("select * FROM employee WHERE department = :name");
    query.bindValue(":name", name);
    if (query.exec()) {
        QMessageBox::information(this, "查询提示", "成功查询");
        m->setQuery(query);
        ui->tableView->setModel(m);
    } else {
        QMessageBox::warning(this, "查询提示", "查询失败: ");
    }
}

void depart_m::on_query_Button_2_clicked()
{
    QString name=ui->dapartmentlineEdit->text();
    QSqlQuery query(db);
    query.prepare("delete from department where name = :name");
    query.bindValue(":name", name);
    if (query.exec()) {
        QMessageBox::information(this, "删除提示", "成功删除");
    } else {
        QMessageBox::warning(this, "删除提示", "删除失败: ");
    }
}

void depart_m::on_dept_Button_clicked()
{
    dept_v* d=new dept_v(db);
    this->close();
    d->show();
}

