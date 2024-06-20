#ifndef PERSON_DATA_QUERY_H
#define PERSON_DATA_QUERY_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QSqlTableModel>
namespace Ui {
class person_data_query;
}

class person_data_query : public QWidget
{
    Q_OBJECT

public:
    explicit person_data_query(QSqlDatabase d,QWidget *parent = nullptr);
    ~person_data_query();
signals:
    void returnToMainWindow(); // 定义返回主窗口的信号
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::person_data_query *ui;
    QSqlTableModel * m;
    QSqlDatabase db;
};

#endif // PERSON_DATA_QUERY_H
