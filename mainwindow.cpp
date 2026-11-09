#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(1280,720);
    renderArea = new Renderer(this);
    setCentralWidget(renderArea);

    toolBar = new QToolBar(this);

    brushColor = new QPushButton("Color", this);
    toolBar->addWidget(brushColor);
    toolBar->setMovable(false);
    addToolBar(toolBar);

}

MainWindow::~MainWindow()
{
    delete renderArea;
    delete brushColor;
    delete toolBar;
}
