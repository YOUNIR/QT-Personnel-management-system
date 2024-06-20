#ifndef DEPT_V_H
#define DEPT_V_H

#include <QWidget>
#include <depart_m.h>
namespace Ui {
class dept_v;
}

class dept_v : public QWidget
{
    Q_OBJECT

public:
    explicit dept_v(QSqlDatabase d,QWidget *parent = nullptr);
    ~dept_v();

private slots:
    void on_query_Button_clicked();

    void on_return_Button_clicked();

private:
    Ui::dept_v *ui;
    QSqlDatabase db;
    QSqlQueryModel * m;
};

#endif // DEPT_V_H
