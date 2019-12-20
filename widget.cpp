#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(3);
    QIcon icon(":/images/apple.jpg");
    QTableWidgetItem *icon_item = new QTableWidgetItem;
    icon_item->setIcon(icon);
    QStringList itemList;
    itemList << "gray";
    ui->tableWidget_2->setRowCount(1);
    ui->tableWidget_2->setColumnCount(1);
    ui->listWidget->addItems(itemList);
    ui->listWidget->setDragEnabled(true);
    ui->tableWidget_2->setDragEnabled(true);
    ui->tableWidget_2->setItem(0,0,icon_item);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableWidget->setDragDropMode(QAbstractItemView::DragDrop);
    ui->tableWidget->setDefaultDropAction(Qt::MoveAction);
    ui->tableWidget->setDragEnabled(true);
    ui->tableWidget->setDropIndicatorShown(true);
    ui->tableWidget->setAcceptDrops(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_tableWidget_itemPressed(QTableWidgetItem *item)
{
    qDebug()<<"pressed";
//    item->setText("aaa");
}

void Widget::on_tableWidget_itemActivated(QTableWidgetItem *item)
{
    qDebug()<<"activate";
//    item->setText("fff");
}

void Widget::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    qDebug()<<"clicked";
//    item->setText("sss");
}

void Widget::on_tableWidget_itemSelectionChanged()
{
    qDebug()<<"changed";
//    qDebug()<<"lll\n";
}

void Widget::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    tt[item].append(item->text());
    qDebug()<<tt[item].size();
//    item->setText("ttt");
}

void Widget::on_tableWidget_itemEntered(QTableWidgetItem *item)
{
    qDebug()<<"entered";
//    item->setText("ttt");
}