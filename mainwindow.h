#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderer.h"
#include <QComboBox>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void saveImage();
    void loadImage();

private:
    QComboBox* brushType;
    QLabel* brushTypeLabel;
    Renderer* renderArea;
    void connectButtons();
};
#endif // MAINWINDOW_H
