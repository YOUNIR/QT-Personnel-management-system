#ifndef PERSON_M_H
#define PERSON_M_H

#include "person_data_maintenance.h"
#include "person_data_query.h"

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class Person_m;
}

class Person_m : public QWidget
{
    Q_OBJECT

public:
    explicit Person_m(QSqlDatabase d,QWidget *parent = nullptr);
    ~Person_m();
signals:
    void returnToMainWindow(); // 定义返回主窗口的信号
private slots:
    void on_return_button_clicked();

    void returnToMain(); // 返回主窗口的槽函数

    void returnToMain1();

    void on_per_data_man_clicked();

    void on_per_in_que_clicked();

private:
    Ui::Person_m *ui;
    person_data_maintenance *pm;
    person_data_query* pq;
    QSqlDatabase db;
};

#endif // PERSON_M_H
