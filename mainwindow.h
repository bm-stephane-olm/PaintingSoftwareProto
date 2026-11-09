#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderer.h"
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QtoolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void saveImage();
    void loadImage();

private:
    void createMenu();
    void changeColor();
    void connectButtons();
    QToolBar* toolBar;
    QPushButton* colorButton;
    QAction* colorAction;
    Renderer* renderArea;
};
#endif // MAINWINDOW_H