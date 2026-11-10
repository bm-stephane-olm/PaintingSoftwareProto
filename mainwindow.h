#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderer.h"
#include <QComboBox>
#include <QMenu>
#include <QToolButton>
#include <QtoolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void save();
    void open();

private:
    void createMenu();
    void changeColor();
    void connectButtons();
    QStringList getSupportedFormats() const;
    QToolBar* toolBar;
    QToolButton* colorButton;
    QToolButton* fileButton;
    QAction* saveAction;
    QAction* openAction;
    QMenu* fileMenu;
    Renderer* renderArea;
};
#endif // MAINWINDOW_H