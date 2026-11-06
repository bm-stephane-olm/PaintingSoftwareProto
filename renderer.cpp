#include "renderer.h"

Renderer::Renderer(QWidget* parent) :
    QWidget(parent),
    penColor(Qt::black),
    penWidth(1)
{
    image = new QImage(500,500, QImage::Format::Format_ARGB32);
    image->fill(Qt::white);
}

void Renderer::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawImage(0, 0, *image);
}

void Renderer::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDrawing = true;
        startPos = event->pos();
    }
}

void Renderer::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        drawTo(event->pos());
        isDrawing = false;
    }
}

void Renderer::mouseMoveEvent(QMouseEvent* event) {
    if ((event->buttons() & Qt::LeftButton) && isDrawing)
        drawTo(event->pos());
}

void Renderer::wheelEvent(QWheelEvent* event) {
    int wheelDegree = event->angleDelta().y() / 8;
    if(wheelDegree != 0) {
        int stepWidth = wheelDegree / 15;
        qDebug() << "penWidth + stepWidth pre update : " << stepWidth;
        penWidth = std::clamp(penWidth + stepWidth, 0, std::numeric_limits<int>::max());
        qDebug() << "wheelDegree : " << wheelDegree;
        qDebug() << "penWidth + stepWidth post update : " << penWidth;
    }
}

void Renderer::drawTo(QPoint endPos) {
    QPainter painter(image);
    painter.setPen(QPen(penColor, penWidth));
    painter.drawLine(startPos, endPos);
    float offsetRect = penWidth / 2 + 1;
    update(QRect(startPos, endPos).normalized().adjusted(-offsetRect, -offsetRect, offsetRect, offsetRect));
    startPos = endPos;
}

