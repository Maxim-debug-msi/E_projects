//
// Created by Maxim on 14.12.2021.
//

#ifndef INC_37_3_TV_REMOTE_WINDOW_H
#define INC_37_3_TV_REMOTE_WINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class TVRemoteMainWindow : public QMainWindow{
    Q_OBJECT

public:
    QLineEdit *lineEdit = nullptr;
    QLineEdit *lineEdit_2 = nullptr;
    TVRemoteMainWindow(QWidget *parent = nullptr) : QMainWindow(parent){}

    void print_channel() const{
        std::string line(channel + lineEdit->text().toStdString());
        lineEdit->setText(line.c_str());
    }

    void print_volume() const{
        std::string line(vol_level + std::to_string(volume));
        lineEdit_2->setText(line.c_str());
    }

public slots:
    void add0(){lineEdit->setText("0"); print_channel();};
    void add1(){lineEdit->setText("1"); print_channel();};
    void add2(){lineEdit->setText("2"); print_channel();};
    void add3(){lineEdit->setText("3"); print_channel();};
    void add4(){lineEdit->setText("4"); print_channel();};
    void add5(){lineEdit->setText("5"); print_channel();};
    void add6(){lineEdit->setText("6"); print_channel();};
    void add7(){lineEdit->setText("7"); print_channel();};
    void add8(){lineEdit->setText("8"); print_channel();};
    void add9(){lineEdit->setText("9"); print_channel();};
    void de_volume(){ if(volume > 0) volume -= 10; print_volume();};
    void in_volume(){if(volume < 100) volume += 10; print_volume();};

private:
    std::string channel{"Канал: "};
    std::string vol_level{"Уровень громкости: "};
    int volume{};
};

#endif //INC_37_3_TV_REMOTE_WINDOW_H
