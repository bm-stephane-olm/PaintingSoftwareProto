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
    colorButton = new QToolButton(this);
    colorButton->setText("Color");

    fileButton = new QToolButton(this);
    fileButton->setText("File");
    fileMenu= new QMenu("File", this);
    saveAction = new QAction("Save",this);
    openAction = new QAction("Open",this);
    fileMenu->addAction("Save");
    fileMenu->addAction("Open");
    fileButton->setMenu(fileMenu);
    fileButton->setPopupMode(QToolButton::InstantPopup);

    toolBar = new QToolBar(this);
    toolBar->setMovable(false);
    addToolBar(toolBar);
    toolBar->addWidget(colorButton);
    toolBar->addWidget(fileButton);
}

void MainWindow::changeColor() {
    QColor newColor = QColorDialog::getColor(renderArea->getColor(), nullptr, "Pick your color", QColorDialog::ShowAlphaChannel);
    renderArea->setColor(newColor);
}

void MainWindow::connectButtons() {
    connect(colorButton, &QToolButton::clicked, this, &MainWindow::changeColor);
}

MainWindow::~MainWindow()
{
    delete renderArea;
    delete colorAction;
    delete toolBar;
}
