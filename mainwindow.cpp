#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}


//void MainWindow::on_pushButton_clicked()
//{
//    QMessageBox::StandardButton st = QMessageBox::question(this, "Напоминание", "?", QMessageBox::Yes | QMessageBox::No);

//    if(st == QMessageBox::Yes) {
//        QApplication::quit();
//    }
//}


void MainWindow::on_pushButton_clicked()
{
        QString login = ui->lineEdit->text();
        QString pass = ui->lineEdit_2->text();

    if(login == "Teacher" && pass == "English") {
        hide();
        Dialog window;
        window.setModal(true);
        window.exec();
    } else {
        QMessageBox::StandardButton st = QMessageBox::information(this, "Ошибка", "Логин или пароль введены неверно");
    }

//    if(ui->radioButton->isChecked()) {
//        ui->statusbar->showMessage("Выбран ответ да");
//    }

//    QString login = ui->lineEdit->text();
//    QString pass = ui->lineEdit_2->text();

//    if(login == "Corgi" && pass == "C") {
//    hide();
//    Dialog window;
//    window = new Dialog(this);
//    window.show();
//    }
}

