#include "dialogdevices.h"
#include "ui_dialogdevices.h"
#include <QString>
#include <QStandardItemModel>
#include <QVector>
#include <QDebug>
#include <sstream>

DialogDevices::DialogDevices(NetWork& network, string& vibor, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogDevices)
    , networkInstance(network)
    , choice(vibor)
{
    ui->setupUi(this);

    string message;
    if (choice == "headphones") {
        ui->label->setText("<font color='#e01b24' size='4'><b>Наушники</b></font>");
        message = "selectheadphones";
    } else if (choice == "microphone") {
        ui->label->setText("<font color='#e01b24' size='4'><b>Микрофоны</b></font>");
        message = "selectmicrophone";
    } else if (choice == "keyboard") {
        ui->label->setText("<font color='#e01b24' size='4'><b>Клавиатуры</b></font>");
        message = "selectkeyboard";
    }
    ui->label->setAlignment(Qt::AlignCenter);

    QString result = network.sendAndAccept(message);
    qDebug() << result;

    QStringList devices = result.split('\n');
    QVector<QVector<QString>> data;

    for (const QString &device : devices) {
        QStringList parts = device.split(' ');

        if (parts.size() < 6) {
            continue; // Пропускаем, если недостаточно данных
        }

        QString brand = parts[1]; // Бренд
        QString number = parts[2]; // Номер
        QString price = parts[3]; // Цена
        QString parametr1 = parts[4] + "\n" + parts[5];

        QVector<QString> column;
        column.push_back(brand);
        column.push_back(number);
        column.push_back(price);
        column.push_back(parametr1);

        data.push_back(column);
    }

    QStandardItemModel *model = new QStandardItemModel();
    QStringList headers;
    headers << "Бренд" << "Номер" << "Цена" << "Параметры";
    model->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < data.size(); ++row) {
        for (int column = 0; column < data[row].size(); ++column) {
            QStandardItem *item = new QStandardItem(data[row][column]);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable); // Запретить редактирование
            item->setTextAlignment(Qt::AlignCenter); // выравнивание по центру
            item->setSizeHint(QSize(100, 100)); // Установка размера ячейки

            // Включаем перенос текста
            item->setData(true, Qt::UserRole + 1); // Используем пользовательский рол для включения переноса текста
            model->setItem(row, column, item);
        }
    }

    ui->device->setModel(model);
    ui->device->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->device->verticalHeader()->setVisible(false);

    // Устанавливаем высоту строк для автоматического подбора
    ui->device->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

}

DialogDevices::~DialogDevices()
{
    delete ui;
}

void DialogDevices::on_pushButton_exit_clicked()
{
    this->close();
}

