#ifndef OPENGL_ITEM_H
#define OPENGL_ITEM_H

#include <QtQuick/QQuickItem>

class OpenGLItem : public QQuickItem
{
    Q_OBJECT

public:
    OpenGLItem();

public slots:
    void paint();
    void sync();

private slots:
    void handleWindowChanged(QQuickWindow *win);
};


#endif // OPENGL_ITEM_H
