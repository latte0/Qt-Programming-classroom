#include <QtGui/QGuiApplication>
#include <QQmlEngine>
#include "qtquick2applicationviewer.h"
#include "ImageProvider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    QQmlEngine* engine = viewer.engine();
    engine->addImageProvider(QLatin1String("codeimage"), new ImageProvider);
    viewer.setMainQmlFile(QStringLiteral("qml/question/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
