#ifndef PERSON_DATA_MAINTENANCE_H
#define PERSON_DATA_MAINTENANCE_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class person_data_maintenance;
}

class person_data_maintenance : public QWidget
{
    Q_OBJECT

public:
    explicit person_data_maintenance(QSqlDatabase d,QWidget *parent = nullptr);
    ~person_data_maintenance();
signals:
    void returnToMainWindow(); // 定义返回主窗口的信号
private slots:

    void on_return_Button_clicked();

    void on_insert_Button_clicked();

    void on_delete_Button_clicked();

private:
    Ui::person_data_maintenance *ui;
    QSqlDatabase db;
};

#endif // PERSON_DATA_MAINTENANCE_H
