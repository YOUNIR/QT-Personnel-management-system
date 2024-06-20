#ifndef DEPART_M_H
#define DEPART_M_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
namespace Ui {
class depart_m;
}

class depart_m : public QWidget
{
    Q_OBJECT

public:
    explicit depart_m(QSqlDatabase d,QWidget *parent = nullptr);
    ~depart_m();
signals:
    void returnToMainWindow(); // 定义返回主窗口的信号

private slots:
    void on_return_Button_clicked();

    void on_query_Button_clicked();

    void on_query_Button_2_clicked();

    void on_dept_Button_clicked();

private:
    Ui::depart_m *ui;
    QSqlQueryModel * m;
    QSqlDatabase db;
};

#endif // DEPART_M_H
