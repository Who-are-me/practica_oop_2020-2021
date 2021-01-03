#ifndef EXPOSEWINDOW_H
#define EXPOSEWINDOW_H

#include "database.h"
#include "verification.h"
#include "mainwindow.h"
#include "vacancyviewwindow.h"

#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class ExposeWindow;
}

class Verification;
class MainWindow;
class VacancyViewWindow;

class ExposeWindow : public QDialog {
    Q_OBJECT

public:
    explicit ExposeWindow(QString login, QWidget *parent = nullptr);
    ~ExposeWindow();

private slots:

    void on_add_button_clicked();
    void on_delete_button_clicked();

    void on_re_verification_button_clicked();
    void on_menu_button_clicked();
    void on_view_vacancy_button_clicked();

    void on_tableView_doubleClicked();

private:
    QString             login;
    Ui::ExposeWindow    *ui;
    DataBase            *database;
    QSqlQueryModel      *query_model;
    Verification        *verification;
    MainWindow          *wi;
    VacancyViewWindow   *vvw;

    void update_table_view();
};

#endif // EXPOSEWINDOW_H
