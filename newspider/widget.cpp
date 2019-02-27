#include "widget.h"
#include "mypause.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Qt::WindowFlags myflags;
    myflags = Qt::CustomizeWindowHint; //сказал что буду делать свои флаги

    this->setWindowFlags(myflags);//теперь я передал свои флаги которых нет - пустое окно

    myflags |= Qt::WindowCloseButtonHint; // добавил в свой список флагов - кнопку закрывания

    this->setWindowFlags(myflags);//снова засыпал свои флаги(появилась кнопка закрывания)

    myflags |= Qt::WindowMinMaxButtonsHint;

    this->setWindowFlags(myflags); // добавили залили свернуть\развернуть min\max

//    myflags |= Qt::WindowContextHelpButtonHint; приминимо только к диалогам
//    myflags |= Qt::WindowOkButtonHint;             //почитать про эти флаги

//    this->setWindowFlags(myflags);

//    myflags |= Qt::WindowTitleHint;

//    this->setWindowFlags(myflags);

    Qt::WindowStates mystate = this->windowState();
    //qDebug() << mystate;// выдало QFlags(), что это значит?????
    //this->setWindowState(Qt::WindowMaximized);
    this->setWindowState(Qt::WindowNoState);
    //this->setFixedSize(1000, 625); //под мою картинку в Pixmap


    QString mytitle = "asdfads";
    this->setWindowTitle(mytitle);

//    QIcon icon(QPixmap("./Images_lab1/spider1.bmp"));
//    qDebug() << icon;
//    this->setWindowIcon(icon);

//    QBrush mybrush;
//    mybrush.setStyle(Qt::BrushStyle::DiagCrossPattern);

    QString myname = QObject::tr("Choose Inactice Back Color");

    QPalette mypalette;
    QColor call = QColorDialog::getColor(Qt::white, 0, myname, 0);

    //mypalette.setColor(QPalette::Active, QPalette::Window, QColor(32,178,170));

    if(call.isValid())
    {
        mypalette.setColor(QPalette::Inactive, QPalette::Window, call/*QColor(65,105,225)*/);
    }
    else
    {
        mypalette.setColor(QPalette::Inactive, QPalette::Window, QColor(65,105,225));
    }
    //mypalette.setBrush(QPalette::Normal,QPalette::Window, QBrush(Qt::red));
    //я вообще не понял в чем разница между brush и palette
    //единственное - qpalette намного удобней

    this->setPalette(mypalette);

    QString Activve_pic = QObject::tr("Picture of Active State of Window");
    //QStyle?????????????
    QString chosen_file = QFileDialog::getOpenFileName(0, Activve_pic, "./Images_lab1", 0, 0, 0);

    if (chosen_file.isEmpty())
    {
        QPixmap myPic("./Images_lab1/13.jpg");
        QBrush myBrushWorking(myPic);//отрисовка щеткой моей картинки
        mypalette.setBrush(QPalette::Active, QPalette::Window, myBrushWorking);
    }
    else
    {
        QPixmap myPic(chosen_file);
        QBrush myBrushWorking(myPic);//отрисовка щеткой моей картинки
        mypalette.setBrush(QPalette::Active, QPalette::Window, myBrushWorking);
    }

    //qDebug() << myPic;

    this->setPalette(mypalette); //присваеваем виджиту мою отрисованную картинку

    this->setWindowOpacity(0.95); //поиграли с "прозрачностью"


    //Как бы так сделать????
//    if (QPalette::Active == false)
//    {
//        this->setWindowOpacity(0.75); //поиграли с "прозрачностью"
//    }
//    else
//    {
//        this->setWindowOpacity(0.5); //поиграли с "прозрачностью"
//    }

    //что это и зачем это надо?
//    QRect myRect = this->frameGeometry();
//    QPoint myPoint = this->pos();

    this->setGeometry(25, 45, 800, 450);
    //this->resize(800, 450); //не берет тк задан точный размер в самом начале
    this->move(50, 150);
    this->setMinimumSize(750, 400);
    this->setMaximumSize(1000, 625);

//    есть еще setMinimumSize() и setMaximumSize()
//    но у меня заданы точные размеры, под размер картинки
    QPixmap pixCursor("./Images_lab1/cursor4.bmp");
    pixCursor.setMask(QBitmap("./Images_lab1/cursor4.bmp"));
    QCursor myCursor(pixCursor);

    this->setCursor(myCursor);




}

Widget::~Widget()
{

}


