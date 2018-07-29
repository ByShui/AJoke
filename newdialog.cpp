#include "newdialog.h"
#include "ui_newdialog.h"
#include <QMessageBox>
#include <QCloseEvent>

newDialog::newDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDialog)
{
    ui->setupUi(this);

    toInstallEventFilter();
    setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);
}

newDialog::~newDialog()
{
    delete ui;
}

void newDialog::closeEvent(QCloseEvent *event)
{
    this->hide();

    QMessageBox button(QMessageBox::NoIcon, "提示", "关闭窗口也改变不了你是煞笔的事实！");
    button.setButtonText(QMessageBox::Ok,QString(tr("确认")));
    button.exec();
}

void newDialog::toInstallEventFilter()
{
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
}

bool newDialog::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->pushButton)
    {
        if(event->type() == QEvent::Enter)
        {
            ui->pushButton->setStyleSheet("QPushButton#pushButton{border-image: url(:/png/img/sd.png);background-color: rgb(186, 189, 182);}");
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border-image: url(:/png/img/bs.png);background-color: rgb(211, 215, 207);}");
        }
        ui->pushButton->show();
        ui->pushButton_2->show();
    }
    if(target == ui->pushButton_2)
    {
        if(event->type() == QEvent::Enter)
        {
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border-image: url(:/png/img/sd.png);background-color: rgb(211, 215, 207);}");
            ui->pushButton->setStyleSheet("QPushButton#pushButton{border-image: url(:/png/img/bs.png);background-color: rgb(186, 189, 182);}");
        }
        ui->pushButton->show();
        ui->pushButton_2->show();
    }

    return QDialog::eventFilter(target, event);
}

void newDialog::on_pushButton_clicked()
{
    this->hide();

    QMessageBox button(QMessageBox::NoIcon, "提示", "我就知道你会选是的");
    button.setButtonText(QMessageBox::Ok,QString(tr("确认")));
    button.exec();
}

void newDialog::on_pushButton_2_clicked()
{
    on_pushButton_clicked();
}
