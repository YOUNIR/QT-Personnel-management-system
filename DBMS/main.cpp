#include "widget.h"
#include "login_m.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db;
    //连接数据库
    db=QSqlDatabase::addDatabase("QODBC");  //加载MySQL数据库驱动
    db.setDatabaseName("xc");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Luozhen924");
    if(db.open()){
        QMessageBox::information(nullptr,"连接提示","连接成功");
    }
    else{
        QMessageBox::warning(nullptr,"连接提示","连接失败");
    }
    login_m m(db);
    m.show();
    return a.exec();
}
