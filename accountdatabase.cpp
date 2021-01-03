#include "accountdatabase.h"

AccountDataBase::AccountDataBase(QObject *parent) : QObject(parent) {}

AccountDataBase::~AccountDataBase() { this->closeDataBase();}

void AccountDataBase::connectToDataBase() {
    if (!QFile(ADATABASE_NAME).exists() ) {
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool AccountDataBase::restoreDataBase() {
    if (this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Error: is not create database";
        return false;
    }

    return false;
}

bool AccountDataBase::openDataBase() {
    adb = QSqlDatabase::addDatabase("QSQLITE");
    adb.setHostName(DATABASE_HOSTNAME);
    adb.setDatabaseName(ADATABASE_NAME);

    if (adb.open()){
        return true;
    } else {
        return false;
    }
}

void AccountDataBase::closeDataBase() {
    adb.close();
}

bool AccountDataBase::createTable() {
    QSqlQuery query;
    if (!query.exec( "CREATE TABLE "    TABLE_IS_ACCOUNT " ( id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                        TABLE_LOGIN                 " VARCHAR(50)           NOT NULL, "
                                        TABLE_PASSWORD              " VARCHAR(50)           NOT NULL ) "

    )) {
        qDebug() << "DataBase: error of create " << TABLE_IS_ACCOUNT;
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }

    return false;
}

bool AccountDataBase::insertIntoTable(const QVariantList &data) {

    QSqlQuery query;

    query.prepare(" INSERT INTO " TABLE_IS_ACCOUNT " ( "    TABLE_LOGIN " , "
                                                            TABLE_PASSWORD " ) "

    " VALUES ( :login, :password ) " );

    query.bindValue(":login",               data[0] );
    query.bindValue(":password",            data[1] );


    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE_IS_ACCOUNT;
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }

    return false;
}

void AccountDataBase::deleteFromTable(int index) {
    QSqlQuery query_m;
    query_m.prepare("DELETE FROM " TABLE_IS_ACCOUNT " WHERE id = :index");
    query_m.bindValue(":index", index);
    query_m.exec();
}
