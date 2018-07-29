#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <newdialog.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    newDialog *newdialog;
};

#endif // DIALOG_H
