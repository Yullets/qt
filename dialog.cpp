#include "dialog.h"
#include "ui_dialog.h"
#include <vector>
#include <qedit.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QStandardItemModel(5, 6, this);


    ui->tableView->setModel(model);

    std::vector<QString> data = {"Имя   Фамилия   ", "09.03", "12.03", "15.03", "21.03", "Средний балл"};

    for(int j = 0; j < model->columnCount(); j++) {
        model->setHeaderData(j, Qt::Horizontal, data[j]);
    }

    std::vector<QString> data1 = {"Бобров Иван", "Белых Анна", "Гринина Олеся", "Соловьев Егор", "Тишина Ирина"};

    QModelIndex index;
    for(int i = 0; i < model->rowCount(); i++) {
        index = model->index(i, 0);
        model->setData(index, data1[i]);
    }
}

//Dialog::~Dialog()
//{
//    delete ui;
//}

void Dialog::on_pushButton_clicked()
{
    QModelIndex index;

    for(int i = 0; i < model->rowCount(); i++) {
        int sum = 0;
        int markCount = 0;
        for(int j = 1; j < model->columnCount() - 1; j++) {
            index = model->index(i, j);
            int val = model->data(index).toInt();
            if(val != 0) {
                sum += val;
                markCount++;
            }
        }
        index = model->index(i, model->columnCount() - 1);
        double dif;
        if(markCount != 0) {
            dif = (double) sum / markCount;
        } else {
            dif = 0;
        }
        model->setData(index, dif);

    }
}


