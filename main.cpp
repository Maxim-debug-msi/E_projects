#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <QSlider>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <iostream>

class ImageButton : public QWidget{
public:
    ImageButton() = default;
    explicit ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
public slots:
    void setGreen();
    void setYellow();
    void setRed();
private:
    QPixmap greenPixmap;
    QPixmap yellowPixmap;
    QPixmap redPixmap;
    QPixmap currentPixmap;
};

ImageButton::ImageButton(QWidget *parent){
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    redPixmap = QPixmap(R"(C:\Users\Maxim\CLionProjects\36.1qt\pic\red.png)");
    greenPixmap = QPixmap(R"(C:\Users\Maxim\CLionProjects\36.1qt\pic\green.png)");
    yellowPixmap = QPixmap(R"(C:\Users\Maxim\CLionProjects\36.1qt\pic\yellow.png)");
    currentPixmap = greenPixmap;
    setGeometry(currentPixmap.rect());
}

void ImageButton::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(), currentPixmap);
}

QSize ImageButton::sizeHint() const{
    return {100, 100};
}

QSize ImageButton::minimumSizeHint() const{
    return {100, 100};
}

void ImageButton::setGreen(){
    currentPixmap = greenPixmap;
    update();
}

void ImageButton::setYellow(){
    currentPixmap = yellowPixmap;
    update();
}

void ImageButton::setRed(){
    currentPixmap = redPixmap;
    update();
}

int main(int argc, char **argv){
    QApplication app(argc, argv);

    ImageButton circle(nullptr);
    auto *slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    QWidget *window = new QWidget;
    auto *layout = new QVBoxLayout(window);

    layout->addWidget(&circle);
    layout->addWidget(slider);

    window->resize(100, 100);
    window->move(1000, 500);

    QObject::connect(slider, &QSlider::valueChanged,[&circle](int value){
        if(value > 66){
            circle.setRed();
        }
        else if(value > 32){
            circle.setYellow();
        }
        else{
            circle.setGreen();
        }
    });
    window->show();
    QApplication::exec();
}
