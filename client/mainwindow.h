#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"
#include "dialogall.h"
#include "dialogdevices.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(NetWork& network, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::MainWindow *ui;
    NetWork &networkInstance;
};
#endif // MAINWINDOW_H
