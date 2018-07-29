#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class newDialog;
}

class newDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newDialog(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    void toInstallEventFilter();
    bool eventFilter(QObject *target, QEvent *event);
    ~newDialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::newDialog *ui;
};

#endif // NEWDIALOG_H
