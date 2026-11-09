#include "mainwindow.h"
#include <QColorDialog>
#include <QImage>
#include <QDir>
#include <QFileDialog>

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

void MainWindow::save() {
    QString currentPath = QDir(QDir::currentPath()).filePath("untilted.png");
    QString fileName = QFileDialog::getSaveFileName(this, "Choose a directory", currentPath);
    QImage* renderImage = renderArea->getImage();
    renderImage->save(fileName);
}

void MainWindow::open() {

}

void MainWindow::connectButtons() {
    connect(colorButton, &QToolButton::clicked, this, &MainWindow::changeColor);
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);
}

MainWindow::~MainWindow()
{
    delete renderArea;
    delete colorAction;
    delete toolBar;
}
