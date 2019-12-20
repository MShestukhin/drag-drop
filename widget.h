#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QMap>
#include <QVector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_tableWidget_itemPressed(QTableWidgetItem *item);

    void on_tableWidget_itemActivated(QTableWidgetItem *item);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_tableWidget_itemSelectionChanged();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_tableWidget_itemEntered(QTableWidgetItem *item);

private:
    QMap<QTableWidgetItem *, QVector<QString>> tt;
    Ui::Widget *ui;
};

#endif // WIDGET_H
