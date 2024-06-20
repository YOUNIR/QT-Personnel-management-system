#ifndef USER_V_H
#define USER_V_H

#include <QWidget>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QSqlTableModel>
namespace Ui {
class user_v;
}

class user_v : public QWidget
{
    Q_OBJECT

public:
    explicit user_v(QSqlDatabase d,QWidget *parent = nullptr);
    ~user_v();
signals:
    void returnToMainWindow(); // 定义返回主窗口的信号
private slots:
    void on_query_Button_clicked();

    void on_return_Button_clicked();

private:
    Ui::user_v *ui;
    QSqlTableModel * m;
    QSqlDatabase db;
};

#endif // USER_V_H
