#include "dialogall.h"
#include "ui_dialogall.h"
#include <QString>
#include <QStandardItemModel>
#include <QVector>
#include <QDebug>
#include <sstream>

DialogAll::DialogAll(NetWork& network, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAll)
    , networkInstance(network)
{
    ui->setupUi(this);

    string message = "all";
    QString result = networkInstance.sendAndAccept(message);
    qDebug() << result;

    QStringList devices = result.split('\n');
    QVector<QVector<QString>> data;

    for (const QString &device : devices) {
        QStringList parts = device.split(' ');

        if (parts.size() < 6) {
            continue; // Пропускаем, если недостаточно данных
        }

        QString type = parts[0]; // Тип устройства
        QString brand = parts[1]; // Бренд
        QString number = parts[2]; // Номер
        QString price = parts[3]; // Цена
        QString parametr1 = parts[4] + "\n" + parts[5];

        QVector<QString> column;
        column.push_back(type);
        column.push_back(brand);
        column.push_back(number);
        column.push_back(price);
        column.push_back(parametr1);

        data.push_back(column);
    }

    QStandardItemModel *model = new QStandardItemModel();
    QStringList headers;
    headers << "Тип устройства" << "Бренд" << "Номер" << "Цена" << "Параметры";
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

    ui->alldevices->setModel(model);
    ui->alldevices->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->alldevices->verticalHeader()->setVisible(false);

    // Устанавливаем высоту строк для автоматического подбора
    ui->alldevices->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

DialogAll::~DialogAll()
{
    delete ui;
}

void DialogAll::on_pushButton_exit_clicked()
{
    this->close();
}

