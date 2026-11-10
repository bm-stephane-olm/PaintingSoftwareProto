#ifndef RENDERER_H
#define RENDERER_H
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QUndoStack>

class Renderer : public QWidget {
    public:
        Renderer(QWidget* parent);
        void clearRenderer();
        void removeDraw();
        void restoreDraw();
        void setImage(const QImage& newImage);
        void setColor(QColor newColor);
        QColor getColor() const;
        QImage* getImage();

    protected:
        void paintEvent(QPaintEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;
        void mouseMoveEvent(QMouseEvent* event) override;
        void wheelEvent(QWheelEvent* event) override;

    private:
        void drawTo(QPoint endPos);
        QPoint startPos;
        QImage* image;
        QColor penColor;
        int penWidth;
        bool isDrawing;
        QUndoStack undoStack;
};

#endif // RENDERER_H
