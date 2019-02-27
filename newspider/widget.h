#ifndef WIDGET_H
#define WIDGET_H
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QWidget>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QStyle>
#include <QRect>
#include <QPoint>
#include <QCursor>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>


class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
