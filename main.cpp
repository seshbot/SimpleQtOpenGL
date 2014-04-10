#include <QGuiApplication>

#include <QtQuick/QQuickView>

#include "openglitem.h"


int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<OpenGLItem>("OpenGLTest", 1, 0, "OpenGLItem");

    QQuickView view;
    view.setSource(QUrl("qrc:///scenegraph/opengltest/main.qml"));
    view.show();

    return app.exec();
}

