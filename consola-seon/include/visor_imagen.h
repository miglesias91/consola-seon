#pragma once

// qt
#include <QtWidgets>

// idea e implementacion sacada de este posteo:
// https://stackoverflow.com/questions/21246766/how-to-efficiently-display-opencv-video-in-qt/21253353#21253353

namespace gui {

class visor_imagen : public QWidget {
    Q_OBJECT

public:
    visor_imagen(QWidget * parent = nullptr);

    Q_SLOT void setear_imagen(const QImage & img);

private:

    QImage imagen_qt;
    void paintEvent(QPaintEvent *);
};

}