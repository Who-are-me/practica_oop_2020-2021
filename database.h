#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME           "ExampleDataBase"
#define DATABASE_NAME               "DataBase.db"

#define TABLE                       "TableVacansia"
#define TABLE_CITY                  "city"
#define TABLE_POSITION              "position"
#define TABLE_NUMBER                "number"
#define TABLE_EXPERIENSE            "experiense"
#define TABLE_SALARY                "salary"
#define TABLE_INFO                  "information"
#define TABLE_ACCOUNT               "account"

class DataBase : public QObject {
    Q_OBJECT

private:
    QSqlDatabase db;

    bool openDataBase();
    bool restoreDataBase();
    bool createTable();

public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    void closeDataBase();
    bool insertIntoTable(const QVariantList &data);
    void deleteFromTable(int index);
};

#endif // DATABASE_H
