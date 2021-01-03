#ifndef VACANCYVIEWWINDOW_H
#define VACANCYVIEWWINDOW_H

#include "database.h"

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class VacancyViewWindow;
}

class VacancyViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VacancyViewWindow(int id, QWidget *parent = nullptr);
    ~VacancyViewWindow();

private:
    Ui::VacancyViewWindow   *ui;
    DataBase                *database;
    QSqlQueryModel          *query_model;
};

#endif // VACANCYVIEWWINDOW_H
