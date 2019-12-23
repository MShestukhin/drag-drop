#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QDebug>
#include <QHBoxLayout>
#include "drag.h"

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

//    icon_item->setIconSize(icon_item->columnWidth(), icon_item->rowHeight() );
    ui->tableWidget_2->setIconSize(QSize(100,100));
    ui->tableWidget->setIconSize(QSize(100,100));
    ui->tableWidget_2->setMaximumSize(QSize(100,100));
    QStringList itemList;
    itemList << "gray";
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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

//    tt[item]=tt[item]+1;
//    qDebug()<<tt[item];
//    item->setText("ttt");
    qDebug()<<item;
}

void Widget::on_tableWidget_itemEntered(QTableWidgetItem *item)
{
    qDebug()<<"entered";
//    item->setText("ttt");
}
