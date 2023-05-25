#ifdef _MSC_VER
#pragma once
#endif

#ifndef _OPENGL_WIDGET_H_
#define _OPENGL_WIDGET_H_

#include <vector>

#include <QtWidgets/qopenglwidget.h>
#include <QtWidgets/qmenubar.h>
#include<QtWidgets/qaction.h>
#include"delaunay.hpp"

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget* parent = nullptr);
    virtual ~OpenGLWidget();

protected:
    public slots:
        void BtnRun(void);

protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void mousePressEvent(QMouseEvent* ev) override;
    virtual void mouseMoveEvent(QMouseEvent* ev) override;
    virtual void mouseReleaseEvent(QMouseEvent* ev) override;

private:
    void drawObjects() const;
    using uint = unsigned int;
    std::vector<delaunay::Point<float>> m_Points;

   
};  

#endif  // _OPENGL_WIDGET_H_