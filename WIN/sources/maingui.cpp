#include "maingui.h"

MainGui::MainGui(QWidget* parent)
    : QMainWindow(parent)
    , openglWidget(new OpenGLWidget) {
    this->setCentralWidget(openglWidget);
    this->resize(800, 600);
   

    CreateMenu();
}

MainGui::~MainGui() {
}
void MainGui::CreateMenu() {

    QAction* actOpen = new QAction(tr("&Delaunay"), this);
    actOpen->setIcon(QIcon(":/SurfaceMeshProcessing/Images/Open.png"));

    QAction* actClose = new QAction(tr("&BO"), this);
    actClose->setIcon(QIcon(":/SurfaceMeshProcessing/Images/Open.png"));

    QMenu* menuFile = menuBar()->addMenu(tr("&Algorithm"));
    menuFile->addAction(actOpen);
    menuFile->addAction(actClose);

    QAction* actRun = new QAction(tr("&Run"), this);
    actRun->setIcon(QIcon(":/SurfaceMeshProcessing/Images/Open.png"));
    connect(actOpen, SIGNAL(triggered()), openglWidget, SLOT(BtnRun()));
    menuBar()->addAction(actRun);

}
