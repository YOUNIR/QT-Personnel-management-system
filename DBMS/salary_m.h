#ifndef SALARY_M_H
#define SALARY_M_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class salary_m;
}

class salary_m : public QWidget
{
    Q_OBJECT

public:
    explicit salary_m(QWidget *parent = nullptr);
    ~salary_m();
signals:
    void returnToMainWindow(); // 定义返回主窗口的信号
private slots:
    void on_save_Button_clicked();

    void on_return_Button_clicked();

    void on_save_Button_2_clicked();

private:
    Ui::salary_m *ui;
    QSqlDatabase db;
};

#endif // SALARY_M_H
