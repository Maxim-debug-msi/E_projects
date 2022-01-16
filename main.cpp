#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPaintEvent>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QPainter>

QImage blurImage(QImage&& source, int blurRadius){
    if(source.isNull()) {
        std::cerr << "Empty image!" << std::endl;
        return {};
    }
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    QGraphicsBlurEffect blur;
    blur.setBlurRadius(blurRadius);
    item.setGraphicsEffect(&blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return result;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //
    QWidget mainWindow(nullptr);
    mainWindow.resize(480, 440);
    //
    QVBoxLayout layout(&mainWindow);
    QPushButton button("Open", nullptr);
    QSlider slider(Qt::Horizontal);
    QLabel picture(nullptr);
    QString path;
    //
    layout.addWidget(&picture);
    layout.addWidget(&slider);
    layout.addWidget(&button);
    //
    slider.setMinimum(0);
    slider.setMaximum(10);
    //
    QObject::connect(&button, &QPushButton::clicked, [&path, &picture, &slider](){
        path = QFileDialog::getOpenFileName(nullptr, "Open jpg file", "C:", "jpg files (*.jpg)");
        picture.setPixmap(QPixmap::fromImage(blurImage(QImage(path), slider.value()).scaled(
                picture.width(),
                picture. height(),
                Qt::KeepAspectRatio)));
    });

    QObject::connect(&slider, &QSlider::valueChanged, [&path, &picture, &slider](){
        picture.setPixmap(QPixmap::fromImage(blurImage(QImage(path), slider.value()).scaled(
                picture.width(),
                picture. height(),
                Qt::KeepAspectRatio)));
    });
    mainWindow.show();
    return QApplication::exec();
