#include "exposewindow.h"
#include "ui_exposewindow.h"

ExposeWindow::ExposeWindow(QString login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExposeWindow)
{
    this->login = login;

    ui->setupUi(this);

    database = new DataBase;
    database->connectToDataBase();

    ui->groupBox->setTitle(login);

    QPalette palette;
    palette.setColor(QPalette::Base, Qt::yellow);
    palette.setColor(QPalette::Text, Qt::black);

    ui->city_lineEdit->setPalette(palette);
    ui->position_lineEdit->setPalette(palette);
    ui->experiense_lineEdit->setPalette(palette);
    ui->number_lineEdit->setPalette(palette);
    ui->salary_lineEdit->setPalette(palette);
    ui->information_plainTextEdit->setPalette(palette);

    query_model = new QSqlQueryModel;
    update_table_view();
}

ExposeWindow::~ExposeWindow() {
    delete ui;
}

void ExposeWindow::update_table_view() {

    if (login == "Administrator") {
        query_model->setQuery("SELECT * FROM " TABLE );
    }
    else {
        query_model->setQuery("SELECT * FROM " TABLE " WHERE " TABLE_ACCOUNT " = '" + login + "' ");
    }

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

void ExposeWindow::on_add_button_clicked() {

    if (    ui->city_lineEdit->text() != "" &&
            ui->position_lineEdit->text() != "" &&
            ui->number_lineEdit->text() != "" &&
            ui->experiense_lineEdit->text() != "" &&
            ui->salary_lineEdit->text() != "" &&
            ui->information_plainTextEdit->toPlainText() != "")
    {
        QVariantList data;

        data.append(ui->city_lineEdit->text());
        data.append(ui->position_lineEdit->text());
        data.append(ui->number_lineEdit->text());
        data.append(ui->experiense_lineEdit->text());
        data.append(ui->salary_lineEdit->text());
        data.append(ui->information_plainTextEdit->toPlainText());
        data.append(login);

        database->insertIntoTable(data);
        QMessageBox::information(this, "Informayion", "Vacancy added.");
        update_table_view();
    }
    else {
        QMessageBox::critical(this, "Error", "Fill in all fields.");
    }
}

void ExposeWindow::on_delete_button_clicked() {   
    int del_index = query_model->data(query_model->index(ui->tableView->currentIndex().row(), 0)).toInt();

    database->deleteFromTable(del_index);
    update_table_view();
}

void ExposeWindow::on_re_verification_button_clicked() {
    hide();
    verification = new Verification(this);
    verification->setWindowTitle("Verification");
    verification->resize(400, 300);
    verification->show();
}

void ExposeWindow::on_menu_button_clicked() {
    hide();
    wi = new MainWindow(this);
    wi->setWindowTitle("Menu");
    wi->resize(610, 430);
    wi->show();
}

void ExposeWindow::on_view_vacancy_button_clicked() {
    vvw = new VacancyViewWindow(query_model->data(query_model->index(ui->tableView->currentIndex().row(),0)).toInt(), this);
    vvw->setWindowTitle("Vacancy");
    vvw->resize(700, 500);
    vvw->show();
}

void ExposeWindow::on_tableView_doubleClicked() {
    vvw = new VacancyViewWindow(query_model->data(query_model->index(ui->tableView->currentIndex().row(),0)).toInt(), this);
    vvw->setWindowTitle("Vacancy");
    vvw->resize(700, 500);
    vvw->show();
}
