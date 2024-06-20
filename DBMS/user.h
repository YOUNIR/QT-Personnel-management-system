#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

public:
    explicit user(QString name,QSqlDatabase d,QWidget *parent = nullptr);
    ~user();

private slots:
    void on_return_Button_clicked();

    void on_pushButton_clicked();

private:
    Ui::user *ui;
    QSqlDatabase db;
    QSqlQueryModel * m;
    QString name;
};

#endif // USER_H
