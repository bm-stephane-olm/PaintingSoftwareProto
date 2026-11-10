#include "mainwindow.h"
#include <QColorDialog>
#include <QImage>
#include <QDir>
#include <QFileDialog>
#include <QImageWriter>

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
    saveAction = new QAction("Save");
    openAction = new QAction("Open");
    fileMenu->addAction(saveAction);
    fileMenu->addAction(openAction);
    fileButton->setMenu(fileMenu);
    fileButton->setPopupMode(QToolButton::InstantPopup);

    undoAction = new QAction("Undo", this);
    undoAction->setShortcut(QKeySequence::Undo);

    redoAction = new QAction("Redo", this);
    redoAction->setShortcut(QKeySequence::Redo);

    toolBar = new QToolBar(this);
    toolBar->setMovable(false);
    addToolBar(toolBar);
    toolBar->addWidget(colorButton);
    toolBar->addWidget(fileButton);
    toolBar->addAction(undoAction);
    toolBar->addAction(redoAction);
}

void MainWindow::changeColor() {
    QColor newColor = QColorDialog::getColor(renderArea->getColor(), nullptr, "Pick your color", QColorDialog::ShowAlphaChannel);
    renderArea->setColor(newColor);
}

QStringList MainWindow::getSupportedFormats() const {
    QList<QByteArray> formats = QImageWriter::supportedImageFormats();
    QStringList res;
    for (const QByteArray& format : formats) {
        QString ext = QString::fromLatin1(format);
        res << QString("%1 Files (.%2)").arg(ext.toUpper(), ext);
    }
    return res;
}

void MainWindow::save() {
    QString savingPath = QDir(QDir::homePath()).filePath("untilted");
    //QStringList supportedFormats = getSupportedFormats();
    QString fileName = QFileDialog::getSaveFileName(this, "Choose a directory", savingPath, QString("PNG Files (.png)"));
    if(!fileName.isEmpty()) {
        QImage* renderImage = renderArea->getImage();
        bool saved = renderImage->save(fileName+".png");
        qDebug() << saved;
    }
}

void MainWindow::open() {

}

void MainWindow::connectButtons() {
    connect(colorButton, &QToolButton::clicked, this, &MainWindow::changeColor);
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);
    connect(undoAction, &QAction::triggered, renderArea, &Renderer::removeDraw);
    connect(redoAction, &QAction::triggered, renderArea, &Renderer::restoreDraw);
}

MainWindow::~MainWindow()
{
    delete renderArea;
    delete saveAction;
    delete openAction;
    delete undoAction;
    delete fileMenu;
    delete fileButton;
    delete colorButton;
    delete toolBar;
}
