#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix_logo(":/img/img/img_logo.png");
    QPixmap pix_find(":/img/img/find_b_0.png");
    QPixmap pix_expose(":/img/img/expose_b_0.png");\

    int w1 = ui->image->width();
    int w2 = ui->find_button->width();
    int w3 = ui->expose_button->width();

    int h1 = ui->image->height();
    int h2 = ui->find_button->height();
    int h3 = ui->expose_button->height();

    ui->image->setPixmap(pix_logo.scaled(w1, h1, Qt::KeepAspectRatio));
    ui->find_button->setIcon(pix_find.scaled(w2, h2, Qt::KeepAspectRatio));
    ui->expose_button->setIcon(pix_expose.scaled(w3, h3, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_expose_button_clicked() {
    hide();
    verification = new Verification(this);
    verification->setWindowTitle("Verification");
    verification->resize(400, 300);
    verification->show();
}

void MainWindow::on_find_button_clicked() {
    hide();
    find_window = new FindWindow(this);
    find_window->setWindowTitle("Find vacancy");
    find_window->resize(800, 500);
    find_window->show();
}
