#include "ImageProvider.h"
#include <stdio.h>
#include <string.h>
#include <QDir>
#include <QRect>
#include <QDebug>


ImageProvider::ImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}


QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    fontsize = 30;
     QImage image(500,500, QImage::Format_ARGB32_Premultiplied);
    int linecount=0;

    QString fileName = "/home/sharemen-note/test.cpp";
    qDebug() << fileName;

    if(!fileName.isEmpty()){
    //QPixmap pix(800,800);
        //QImage image(this->size(), QImage::Format_ARG32_Premultiplied);
        fprintf(stderr,"checked");
    QPainter codepainter(&image);
    //codeimagePainter.drawImage(100,100,QImage("white.png"));
    //codeimagePainter.setCompositionMode(QPainter::CompositionMode_Xor);
    QRect rect(0,0,800,800);
    codepainter.fillRect(rect,Qt::white);
    codepainter.setPen(Qt::black);
    codepainter.setFont(QFont("Arial",fontsize));

    QFile filevar(fileName);
    fprintf(stderr,"test");
    if(!filevar.open(QIODevice::ReadOnly | QIODevice::Text)){}
    QTextStream in(&filevar);
    while(!in.atEnd()){
        linecount++;
        QString line = in.readLine();
        qDebug() << line;
        if(line.contains("@",Qt::CaseInsensitive)){
            hideline = linecount;
            atmark = true;
            hiderow= line.indexOf("@");
            hidenum = hiderow - line.indexOf("@",hiderow+1);
            line.remove(hiderow,1);
            line.remove(hiderow+hidenum-3,1);
            hidenum= hidenum;
            qDebug() << hiderow*fontsize << hideline;
        }
        codepainter.drawText(20,fontsize*linecount,line);
    }
    QRect recta((fontsize-15)*hiderow,fontsize*(hideline-1),fontsize*(hiderow-3),fontsize);
    codepainter.fillRect(recta,Qt::black);

    return QPixmap::fromImage(image);

}
