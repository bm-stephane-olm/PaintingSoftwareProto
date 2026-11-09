#include "mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(1280,720);
    renderArea = new Renderer(this);
    setCentralWidget(renderArea);

    createMenu();
    connectButtons();

}

void MainWindow::createMenu() {
    colorButton = new QPushButton("Color", this);

    toolBar = new QToolBar(this);
    toolBar->addWidget(colorButton);
    toolBar->setMovable(false);
    addToolBar(toolBar);
}

void MainWindow::changeColor() {
    QColor newColor = QColorDialog::getColor(renderArea->getColor());
    renderArea->setColor(newColor);
}

void MainWindow::connectButtons() {
    connect(colorButton, &QPushButton::clicked, this, &MainWindow::changeColor);
}

MainWindow::~MainWindow()
{
    delete renderArea;
    delete colorAction;
    delete toolBar;
}
