#include "openglitem.h"

#include <QtQuick/QQuickWindow>


OpenGLItem::OpenGLItem()
{
    connect(this, SIGNAL(windowChanged(QQuickWindow*)), this, SLOT(handleWindowChanged(QQuickWindow*)));
}

void OpenGLItem::handleWindowChanged(QQuickWindow *win)
{
    if (!win) return;
    win->setClearBeforeRendering(false);

    connect(win, SIGNAL(beforeRendering()), this, SLOT(paint()), Qt::DirectConnection);
    connect(win, SIGNAL(beforeSynchronizing()), this, SLOT(sync()), Qt::DirectConnection);
}

void OpenGLItem::paint()
{
   glClearColor(0, 0, 0.5, 0.5);
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_TRIANGLES);
   {
     glColor3f(1,0,0);
     glVertex2f(0,0);

     glColor3f(0,1,0);
     glVertex2f(1,0);

     glColor3f(0,0,1);
     glVertex2f(1,1);
   }
   glEnd();
}

void OpenGLItem::sync()
{
}
