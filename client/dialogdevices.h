#ifndef DIALOGDEVICES_H
#define DIALOGDEVICES_H

#include <QDialog>
#include "network.h"

namespace Ui {
class DialogDevices;
}

class DialogDevices : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDevices(NetWork& network, string& vibor, QWidget *parent = nullptr);
    ~DialogDevices();

private slots:
    void on_pushButton_exit_clicked();

private:
    Ui::DialogDevices *ui;
    NetWork &networkInstance;
    string &choice;
};

#endif // DIALOGDEVICES_H
