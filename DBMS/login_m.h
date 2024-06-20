#ifndef LOGIN_M_H
#define LOGIN_M_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <user_v.h>
namespace Ui {
class login_m;
}

class login_m : public QWidget
{
    Q_OBJECT
signals:
    void returnToMainWindow(); // 定义返回主窗口的信号
public:
    explicit login_m(QSqlDatabase d,QWidget *parent = nullptr);
    ~login_m();

private slots:
    void on_return_Button_clicked();

    void on_return_Button_2_clicked();

    void on_user_Button_3_clicked();

    void returnToMain();

private:
    Ui::login_m *ui;
    QSqlDatabase db;
    user_v* v;
};

#endif // LOGIN_M_H
