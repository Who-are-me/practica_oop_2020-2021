#ifndef VERIFICATION_H
#define VERIFICATION_H

#include "accountdatabase.h"
#include "exposewindow.h"

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QSqlQueryModel>

namespace Ui {
class Verification;
}

class ExposeWindow;

class Verification : public QDialog {
    Q_OBJECT

public:
    explicit Verification(QWidget *parent = nullptr);
    ~Verification();

private slots:
    void on_create_button_clicked();
    void on_enter_button_clicked();

private:
    Ui::Verification        *ui;
    ExposeWindow            *expose_window;
    AccountDataBase         *adb;
    QSqlQueryModel          *query_model;
};

#endif // VERIFICATION_H
