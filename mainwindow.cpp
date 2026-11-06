#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    resize(1280,720);
    renderArea = new Renderer(this);
    setCentralWidget(renderArea);
}

MainWindow::~MainWindow()
{
    delete brushType;

}
