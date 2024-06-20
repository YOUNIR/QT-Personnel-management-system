#include "salary_m.h"
#include "ui_salary_m.h"

salary_m::salary_m(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::salary_m)
{
    ui->setupUi(this);
}

salary_m::~salary_m()
{
    delete ui;
}

void salary_m::on_save_Button_clicked()
{
    QString name=ui->namelineEdit->text();
    QString salary=ui->salarylineEdit->text();
    QSqlQuery query(db);
    query.prepare("update employee set salary = :salary WHERE name = :name");
    query.bindValue(":name", name);
    query.bindValue(":salary", salary.toDouble());
    if (query.exec()) {
        QMessageBox::information(this, "修改提示", "成功修改");
    } else {
        QMessageBox::warning(this, "修改提示", "修改失败: ");
    }
}
void salary_m::on_return_Button_clicked()
{
    emit returnToMainWindow(); // 发射返回主窗口的信号
}

