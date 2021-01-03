#include "verification.h"
#include "ui_verification.h"

Verification::Verification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Verification)
{
    ui->setupUi(this);

    adb = new AccountDataBase;
    adb->connectToDataBase();

    QPalette palette;
    palette.setColor(QPalette::Base, Qt::yellow);
    palette.setColor(QPalette::Text, Qt::black);

    ui->login_line_edit->setPalette(palette);
    ui->password_line_edit->setPalette(palette);
}

Verification::~Verification() {
    delete ui;
}

void Verification::on_create_button_clicked() {

    if (ui->login_line_edit->text() == "" || ui->password_line_edit->text() == "") {
        QMessageBox::critical(this, "Error", "Login or password is empty.");
    }
    else {

        if (ui->login_line_edit->text().size() >= 8 && ui->password_line_edit->text().size() >= 8) {
            query_model = new QSqlQueryModel;
            query_model->setQuery("SELECT COUNT( " TABLE_LOGIN " ) FROM " TABLE_IS_ACCOUNT);

            int counts_login = query_model->data(query_model->index(0,0)).toInt();

            query_model = new QSqlQueryModel;
            query_model->setQuery("SELECT " TABLE_LOGIN " FROM " TABLE_IS_ACCOUNT);

            bool check = true;

            for (int i = 0; i < counts_login; i++) {
                QString test_login = query_model->data(query_model->index(i,0)).toString();

                if (test_login == ui->login_line_edit->text()) {
                    check = false;
                    break;
                }
            }

            if (check) {
                QVariantList data;
                data.append(ui->login_line_edit->text());
                data.append(ui->password_line_edit->text());
                adb->insertIntoTable(data);

                QMessageBox::information(this, "Infotmation", "Account is add!");
            }
            else { QMessageBox::warning(this, "Error", "Login is busy!"); }
        }
        else { QMessageBox::critical(this, "Error", "Login/password is short."); }
    }
}

void Verification::on_enter_button_clicked() {
    if (ui->login_line_edit->text() == "Administrator" && ui->password_line_edit->text() == "password") {

        hide();
        expose_window = new ExposeWindow(ui->login_line_edit->text(), this);
        expose_window->setWindowTitle("Expose vacancy");
        expose_window->resize(1000, 600);
        expose_window->show();
    }
    else {
        if (ui->login_line_edit->text() == "" || ui->password_line_edit->text() == "") {
            QMessageBox::critical(this, "Error", "Login or password is empty.");
        }
        else {

            bool check = true;

            query_model = new QSqlQueryModel;
            query_model->setQuery("SELECT COUNT( " TABLE_LOGIN " ) FROM " TABLE_IS_ACCOUNT);

            int counts_login = query_model->data(query_model->index(0,0)).toInt();

            query_model = new QSqlQueryModel;
            query_model->setQuery("SELECT " TABLE_LOGIN " , " TABLE_PASSWORD " FROM " TABLE_IS_ACCOUNT);

            for (int i = 0; i < counts_login && check; i++) {
                QString test_login = query_model->data(query_model->index(i,0)).toString();
                QString test_password = query_model->data(query_model->index(i,1)).toString();

                if (test_login == ui->login_line_edit->text() && test_password == ui->password_line_edit->text()) {

                    hide();
                    expose_window = new ExposeWindow(ui->login_line_edit->text(), this);
                    expose_window->setWindowTitle("Expose vacancy");
                    expose_window->resize(1000, 600);
                    expose_window->show();

                    check = false;
                }
            }

            if (check) {
                QMessageBox::critical(this, "Error", "Wrong login/password.");
            }
        }
    }
}

/*


    if (ui->login_line_edit->text() == "" || ui->password_line_edit->text() == "") {
        QMessageBox::critical(this, "Error", "Login or password is empty.");
    }
    else {

        bool check = true;

        query_model = new QSqlQueryModel;
        query_model->setQuery("SELECT COUNT( " TABLE_LOGIN " ) FROM " TABLE_IS_ACCOUNT);

        int counts_login = query_model->data(query_model->index(0,0)).toInt();

        query_model = new QSqlQueryModel;
        query_model->setQuery("SELECT " TABLE_LOGIN " , " TABLE_PASSWORD " FROM " TABLE_IS_ACCOUNT);

        for (int i = 0; i < counts_login && check; i++) {
            QString test_login = query_model->data(query_model->index(i,0)).toString();
            QString test_password = query_model->data(query_model->index(i,1)).toString();

            if (test_login == ui->login_line_edit->text() && test_password == ui->password_line_edit->text()) {
                hide();

                expose_window = new ExposeWindow(ui->login_line_edit->text(), this);
                expose_window->setWindowTitle("Expose vacancy");
                expose_window->resize(1000, 600);
                expose_window->show();

                check = false;
            }
        }

        if (check) {
            QMessageBox::critical(this, "Error", "Wrong login/password.");
        }
    }

*/
