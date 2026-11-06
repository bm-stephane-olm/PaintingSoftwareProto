#ifndef RENDERER_H
#define RENDERER_H
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class Renderer : public QWidget {
    public:
        Renderer(QWidget* parent);
        void clearRenderer();

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
};

#endif // RENDERER_H
