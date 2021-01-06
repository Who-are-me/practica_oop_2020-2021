#include "vacancyviewwindow.h"
#include "ui_vacancyviewwindow.h"

VacancyViewWindow::VacancyViewWindow(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VacancyViewWindow)
{
    ui->setupUi(this);

    database = new DataBase;
    database->connectToDataBase();

    query_model = new QSqlQueryModel;

    query_model->setQuery("SELECT * FROM " TABLE " WHERE id = " + QString::number(id));

    ui->label_city->setText(query_model->data(query_model->index(0, 1)).toString());
    ui->label_position->setText(query_model->data(query_model->index(0, 2)).toString());
    ui->label_number->setText(query_model->data(query_model->index(0, 3)).toString());
    ui->label_experiense->setText(query_model->data(query_model->index(0, 4)).toString());
    ui->label_salary->setText(query_model->data(query_model->index(0, 5)).toString());
    ui->information_textBrowser->setText(query_model->data(query_model->index(0, 6)).toString());
    ui->label_account->setText(query_model->data(query_model->index(0, 7)).toString());
}

VacancyViewWindow::~VacancyViewWindow() {

    delete ui;
    delete database;
    delete query_model;
}
