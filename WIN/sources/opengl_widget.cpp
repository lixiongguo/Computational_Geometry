#include "opengl_widget.h"

#include <gl/GLU.h>

#include <QtGui/qevent.h>

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent) {
}

OpenGLWidget::~OpenGLWidget() {
}

void OpenGLWidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void OpenGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void OpenGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, 800, 600);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);

    drawObjects();
}

void OpenGLWidget::mousePressEvent(QMouseEvent* ev) {

    m_Points.emplace_back(ev->pos().x(), ev->pos().y());
    // Draw
    paintGL();

}

void OpenGLWidget::mouseMoveEvent(QMouseEvent* ev) {
}

void OpenGLWidget::mouseReleaseEvent(QMouseEvent* ev) {
}

void OpenGLWidget::drawObjects() const {
  
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    for (auto const& p : m_Points) {
        glVertex3f(p.x, p.y,0);
    }
    glEnd();

    const auto triangulation = delaunay::triangulate(m_Points);

    /* Draw lines. */
    glBegin(GL_LINES);
    for (auto const& e : triangulation.edges) {
        glVertex3f(e.p0.x, e.p0.y,0);
        glVertex3f(e.p1.x, e.p1.y,0);
    }
    glEnd();

}

void OpenGLWidget::BtnRun(void) {
    printf("Run Algorithm\n");
}