#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<Person_m.h>
#include<salary_m.h>
#include<depart_m.h>
#include<login_m.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QSqlDatabase d,QWidget *parent = nullptr);
    ~Widget();

private slots:
    void returnToMain(); // 返回主窗口的槽函数
    void returnToMain1();
    void returnToMain2();

    void on_person_m_clicked();
    void on_salary_m_clicked();
    void on_department_m_clicked();

    void on_login_m_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    Person_m* p;
    salary_m* s;
    depart_m* d;
    login_m* l;
};
#endif // WIDGET_H
