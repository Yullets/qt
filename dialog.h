#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
//    ~Dialog();

private slots:
    void on_pushButton_clicked();


private:
    std::shared_ptr<Ui::Dialog> ui;
    QStandardItemModel *model;
    std::shared_ptr<QDialog> window;
};

#endif // DIALOG_H
