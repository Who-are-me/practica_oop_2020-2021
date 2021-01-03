#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME           "ExampleDataBase"
#define ADATABASE_NAME              "AccountDataBase.db"

#define TABLE_IS_ACCOUNT            "TableAccount"
#define TABLE_LOGIN                 "login"
#define TABLE_PASSWORD              "password"

class AccountDataBase : public QObject {
    Q_OBJECT

private:
    QSqlDatabase adb;

    bool openDataBase();
    bool restoreDataBase();
    bool createTable();

public:
    explicit AccountDataBase(QObject *parent = 0);
    ~AccountDataBase();

    void connectToDataBase();
    void closeDataBase();
    bool insertIntoTable(const QVariantList &data);
    void deleteFromTable(int index);
};

#endif // ACCOUNTDATABASE_H
