#ifndef DRAG_H
#define DRAG_H
#include <QtGui>

#include <QLabel>
#include <QTableWidget>
class Drag : public QAbstractItemView {
    Q_OBJECT
private:
    QPoint m_ptDragPos;
    void startDrag(){
        QMimeData* pMimeData=new QMimeData;
        pMimeData->setText("sdfdsf");
        QDrag* pDrag=new QDrag(this);
        pDrag->setMimeData(pMimeData);
        pDrag->exec();
    }
    virtual void mausePressEvent(QMouseEvent* pe){
        if(pe->button() == Qt::LeftButton){
            m_ptDragPos=pe->pos();
        }
        QWidget::mousePressEvent(pe);
    }

    virtual void mouseMoveEvent(QMouseEvent* pe){
        if(pe->buttons() & Qt::LeftButton) {
            int distance=(pe->pos() - m_ptDragPos).manhattanLength();
//            if(distance > QApplication::startDragDistance()){
//                startDrag();
//            }
            startDrag();
            QWidget::mouseMoveEvent(pe);
        }
    }
public:
    Drag(QWidget* pwgt =0) : QAbstractItemView(pwgt){}
};
#endif // DRAG_H
