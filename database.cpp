#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent) {}

DataBase::~DataBase() { this->closeDataBase();}

void DataBase::connectToDataBase() {
    if (!QFile(DATABASE_NAME).exists() ) {
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase() {
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

bool DataBase::openDataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);

    if (db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase() {
    db.close();
}

bool DataBase::createTable() {
    QSqlQuery query;
    if (!query.exec( "CREATE TABLE " TABLE " ( id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_CITY              " VARCHAR(35)           NOT NULL, "
                            TABLE_POSITION          " VARCHAR(35)           NOT NULL, "
                            TABLE_NUMBER            " VARCHAR(10)           NOT NULL, "
                            TABLE_EXPERIENSE        " INT                   NOT NULL, "
                            TABLE_SALARY            " INT                   NOT NULL, "
                            TABLE_INFO              " TEXT                  NOT NULL, "
                            TABLE_ACCOUNT           " VARCHAR(50)           NOT NULL ) "
    )) {
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }

    return false;
}

bool DataBase::insertIntoTable(const QVariantList &data) {

    QSqlQuery query;

    query.prepare("INSERT INTO " TABLE " ( "   TABLE_CITY " , "
                                                TABLE_POSITION " , "
                                                TABLE_NUMBER " , "
                                                TABLE_EXPERIENSE " , "
                                                TABLE_SALARY " , "
                                                TABLE_INFO " , "
                                                TABLE_ACCOUNT " ) "
    " VALUES ( :city, :position, :number, :experiense, :salary, :infor, :account ) " );

    query.bindValue(":city",                data[0] );
    query.bindValue(":position",            data[1] );
    query.bindValue(":number",              data[2] );
    query.bindValue(":experiense",          data[3].toInt() );
    query.bindValue(":salary",              data[4].toInt() );
    query.bindValue(":infor",               data[5] );
    query.bindValue(":account",             data[6] );

    if (!query.exec()) {
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }

    return false;
}

void DataBase::deleteFromTable(int index) {
    QSqlQuery query_m;
    query_m.prepare("DELETE FROM " TABLE " WHERE id = :index");
    query_m.bindValue(":index", index);
    query_m.exec();
}
