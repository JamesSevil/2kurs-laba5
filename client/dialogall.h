#ifndef DIALOGALL_H
#define DIALOGALL_H

#include <QDialog>
#include "network.h"

namespace Ui {
class DialogAll;
}

class DialogAll : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAll(NetWork& network, QWidget *parent = nullptr);
    ~DialogAll();

private slots:
    void on_pushButton_exit_clicked();

private:
    Ui::DialogAll *ui;
    NetWork &networkInstance;
};

#endif // DIALOGALL_H
