#include "findwindow.h"
#include "ui_findwindow.h"

FindWindow::FindWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindWindow)
{
    ui->setupUi(this);

    database = new DataBase;
    database->connectToDataBase();

    query_model = new QSqlQueryModel;
    update_table_view();

    QPalette palette;
    palette.setColor(QPalette::Base, Qt::yellow);
    palette.setColor(QPalette::Text, Qt::black);

    ui->city_lineEdit->setPalette(palette);
    ui->position_lineEdit->setPalette(palette);
    ui->experiense_lineEdit->setPalette(palette);
    ui->number_lineEdit->setPalette(palette);
    ui->salary_lineEdit->setPalette(palette);
}

FindWindow::~FindWindow() {

    delete ui;
    delete database;
    delete main_window;
    delete query_model;
    delete vacancy_view_window;
}

void FindWindow::on_find_button_clicked() {

    QString where = "where ";

    if (ui->city_lineEdit->text() != "") {
        where = where + TABLE_CITY " LIKE '%" + ui->city_lineEdit->text() + "%' AND ";
    }
    if (ui->position_lineEdit->text() != "") {
        where = where + TABLE_POSITION " LIKE '%" + ui->position_lineEdit->text() + "%' AND ";
    }
    if (ui->number_lineEdit->text() != "") {
        where = where + TABLE_NUMBER " LIKE '%" + ui->number_lineEdit->text() + "%' AND ";
    }
    if (ui->experiense_lineEdit->text() != "") {
        where = where + TABLE_EXPERIENSE " <= " + ui->experiense_lineEdit->text() + " AND ";
    }
    if (ui->salary_lineEdit->text() != "") {
        where = where + TABLE_SALARY " >= " + ui->salary_lineEdit->text() + " AND ";
    }

    where = where + "id > 0";

    update_table_view(where);
}

void FindWindow::on_menu_button_clicked() {

    close();
    main_window = new MainWindow(this);
    main_window->setWindowTitle("Menu");
    main_window->resize(610, 430);
    main_window->show();
}

void FindWindow::on_view_vacancy_button_clicked() {

    vacancy_view_window = new VacancyViewWindow(query_model->data(query_model->index(ui->tableView->currentIndex().row(),0)).toInt(), this);
    vacancy_view_window->setWindowTitle("Vacancy");
    vacancy_view_window->resize(700, 500);
    vacancy_view_window->show();
}

void FindWindow::on_tableView_doubleClicked() {

    vacancy_view_window = new VacancyViewWindow(query_model->data(query_model->index(ui->tableView->currentIndex().row(),0)).toInt(), this);
    vacancy_view_window->setWindowTitle("Vacancy");
    vacancy_view_window->resize(700, 500);
    vacancy_view_window->show();
}

void FindWindow::update_table_view(QString where) {

    query_model->setQuery("SELECT * FROM " TABLE " " + where );

    query_model->setHeaderData(0,Qt::Horizontal,  tr("id"));
    query_model->setHeaderData(1,Qt::Horizontal,  tr("city"));
    query_model->setHeaderData(2,Qt::Horizontal,  tr("position"));
    query_model->setHeaderData(3,Qt::Horizontal,  tr("number"));
    query_model->setHeaderData(4,Qt::Horizontal,  tr("experiense"));
    query_model->setHeaderData(5,Qt::Horizontal,  tr("salary"));
    query_model->setHeaderData(6,Qt::Horizontal,  tr("information"));
    query_model->setHeaderData(7,Qt::Horizontal,  tr("account"));

    ui->tableView->setModel(query_model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}













































