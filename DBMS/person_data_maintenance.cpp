#include "person_data_maintenance.h"
#include "ui_person_data_maintenance.h"

person_data_maintenance::person_data_maintenance(QSqlDatabase d, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::person_data_maintenance)
{
    ui->setupUi(this);
    db=d;
}

person_data_maintenance::~person_data_maintenance()
{
    delete ui;
}

void person_data_maintenance::on_insert_Button_clicked()
{
    QString name=ui->namelineEdit->text();
    QString position=ui->positionlineEdit->text();
    QString department=ui->dapartmentlineEdit->text();
    QString date=ui->dateLineEdit->text();
    QString salary=ui->salaryLineEdit->text();

    QSqlQuery query(db);
    query.prepare("INSERT INTO employee (name, position, department, date, salary) "
                  "VALUES (:name, :position, :department, :date, :salary)");
    query.bindValue(":name", name);
    query.bindValue(":position", position);
    query.bindValue(":department", department);
    query.bindValue(":date", date);
    query.bindValue(":salary", salary.toDouble());
    if (query.exec()) {
        QMessageBox::information(this, "插入提示", "成功插入");
    } else {
        QMessageBox::warning(this, "插入提示", "插入失败: ");
    }
}
void person_data_maintenance::on_return_Button_clicked()
{
    emit returnToMainWindow(); // 发射返回主窗口的信号
}

void person_data_maintenance::on_delete_Button_clicked()
{
    QString name=ui->namelineEdit_2->text();
    QSqlQuery query(db);
    query.prepare("DELETE FROM employee WHERE name = :name");
    query.bindValue(":name", name);

    if (query.exec()) {
        QMessageBox::information(this, "删除提示", "成功删除");
    } else {
        QMessageBox::warning(this, "删除提示", "删除失败: ");
    }
}

