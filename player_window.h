//
// Created by Maxim on 14.12.2021.
//

#ifndef INC_37_2_PLAYER_WINDOW_H
#define INC_37_2_PLAYER_WINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>


class PlayerMainWindow : public QMainWindow{
   Q_OBJECT

public:
    QLineEdit *lineEdit = nullptr;
    QProgressBar *progressBar = nullptr;
    PlayerMainWindow(QWidget* parent = nullptr) : QMainWindow(parent){}

    void changeProgressBar() const{
        if(is_play && progressBar->value() < 101) progressBar->setValue(progressBar->value() + adder);
    }

public slots:
    void play(){lineEdit->setText("Проигрывание"); is_play = true; adder = 1;};
    void pause(){lineEdit->setText("Пауза"); is_play = false;};
    void stop(){lineEdit->setText("Стоп"); is_play = false; progressBar->setValue(0);};
    void rewind(){lineEdit->setText("Перемотка"); is_play = true; adder = -5;};
    void forward(){lineEdit->setText("Быстрое воспроизведение"); is_play = true; adder = 5;};

private:
    int adder{};
    bool is_play{false};
};

#endif //INC_37_2_PLAYER_WINDOW_H
