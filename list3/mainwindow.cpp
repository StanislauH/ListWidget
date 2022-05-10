#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->button1->setText("<--");
    ui->button2->setText("-->");

    ui->list1->addItem("item1");
    ui->list1->addItem("item2");
    ui->list1->addItem("item3");
    ui->list1->addItem("item4");
    ui->list1->addItem("item5");

    ui->list2->addItem("num1");
    ui->list2->addItem("num2");
    ui->list2->addItem("num3");
    ui->list2->addItem("num4");
    ui->list2->addItem("num5");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button2_clicked()
{
    QListWidgetItem *x = ui->list1->currentItem();

    ui->list1->takeItem(ui->list1->currentRow());

    ui->list2->addItem(x);

    ui->list2->sortItems(order2);

    ui->list1->currentItem()->setSelected(0);
}




void MainWindow::on_button1_clicked()
{
    QListWidgetItem *x = ui->list2->currentItem();

    ui->list2->takeItem(ui->list2->currentRow());

    ui->list1->addItem(x);

    ui->list1->sortItems(order1);

    ui->list2->currentItem()->setSelected(0);
}
