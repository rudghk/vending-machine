#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
   changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
   changeMoney(-100);
}


void Widget::on_pdChanges_clicked()
{
    QMessageBox msgBox;
    std::string changesStr = "";
    int curMoney = money;
    int moneyCount[4] = {500, 100, 50, 10};
    int q;
    for (int i=0;i<4;i++){
        q = int(curMoney / moneyCount[i]);
        if(q>0){
            curMoney = curMoney % moneyCount[i];
            changesStr = changesStr+std::to_string(moneyCount[i])+"원 "+std::to_string(q)+"개\n";
        }
    }
    changeMoney(-money);
    msgBox.information(this, "잔돈 반환", QString::fromStdString(changesStr));
}

