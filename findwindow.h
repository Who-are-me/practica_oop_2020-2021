#ifndef FINDWINDOW_H
#define FINDWINDOW_H

#include "database.h"
#include "mainwindow.h"
#include "vacancyviewwindow.h"

#include <QDialog>
#include <QSqlQueryModel>
#include <QString>

namespace Ui {
class FindWindow;
}

class MainWindow;

class FindWindow : public QDialog {
    Q_OBJECT

public:
    explicit FindWindow(QWidget *parent = nullptr);
    ~FindWindow();

private slots:
    void on_view_vacancy_button_clicked();
    void on_tableView_doubleClicked();
    void on_find_button_clicked();
    void on_menu_button_clicked();  

private:
    Ui::FindWindow      *ui;
    DataBase            *database;
    QSqlQueryModel      *query_model;
    MainWindow          *main_window;
    VacancyViewWindow   *vacancy_view_window;

    void update_table_view(QString where = "");
};

#endif // FINDWINDOW_H
