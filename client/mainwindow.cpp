#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(NetWork& network, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkInstance(network)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_save_clicked()
{
    if (ui->radioButton_Headphones->isChecked()) {
        string choice = "headphones";
        DialogDevices dialog(networkInstance, choice);
        dialog.setModal(true);
        dialog.exec();
    } else if (ui->radioButton_Microphone->isChecked()) {
        string choice = "microphone";
        DialogDevices dialog(networkInstance, choice);
        dialog.setModal(true);
        dialog.exec();
    } else if (ui->radioButton_Keyboard->isChecked()) {
        string choice = "keyboard";
        DialogDevices dialog(networkInstance, choice);
        dialog.setModal(true);
        dialog.exec();
    } else if (ui->radioButton_all->isChecked()) {
        DialogAll dialog(networkInstance);
        dialog.setModal(true);
        dialog.exec();
    } else {
       QMessageBox::warning(this, "Ошибка", "Не выбран тип устройства!");
    }
}

