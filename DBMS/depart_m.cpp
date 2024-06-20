#include "depart_m.h"
#include "ui_depart_m.h"

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
    emit returnToMainWindow(); // 发射返回主窗口的信号
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

















