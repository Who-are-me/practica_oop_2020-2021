#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "findwindow.h"
#include "verification.h"

#include <QMainWindow>
#include <QPixmap>

class FindWindow;
class Verification;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_expose_button_clicked();
    void on_find_button_clicked();

private:
    Ui::MainWindow  *ui;
    FindWindow      *find_window;
    Verification    *verification;
};

#endif // MAINWINDOW_H
