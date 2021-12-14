//
// Created by Maxim on 11.12.2021.
//

#ifndef INC_37_1_CALC_MAINWINDOW_H
#define INC_37_1_CALC_MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CalcMainWindow : public QMainWindow{
    Q_OBJECT

public:
    QLineEdit *lineEdit = nullptr;
    CalcMainWindow(QWidget* parent = nullptr): QMainWindow(parent){}
    void num_ext(){
        if(flags == 0){
            a_i = stoi(number);
        }
        else if(flags == 1){
            a_d = stod(number);
        }
        else if(flags > 1 && (flags % 2 == 1)){
            b_d = stod(number);
        }
        else{
            b_i = stoi(number);
        }
        if(flags % 2 == 1){
            flags -= 1;
        }
        number.clear();
    };

    void calculate(){
        if(flags == 2){
            if(is_double_expr){
                number = std::to_string((long double)(a_d + a_i + b_d + b_i));
            }else{
                number = std::to_string(a_i + b_i);
            }
        }
        else if(flags == 4){
            if(is_double_expr){
                number = std::to_string((long double)(a_d - a_i - b_d - b_i));
            }else{
                number = std::to_string(a_i - b_i);
            }
        }
        else if(flags == 8){
            if(a_d == a_i){
                number = "Умножать 0 на число нельзя!";
                is_over_expr = true;
                return;
            }
            else{
                if(a_d == 0){
                    a_d = 1;
                }
                else {
                    a_i = 1;
                }
            }

            if(b_d == b_i){
                b_d = 1;
            }
            else{
                if(b_d == 0){
                    b_d = 1;
                }
                else{
                    b_i = 1;
                }
            }
            if(is_double_expr){
                number = std::to_string((long double)((a_d * a_i) * (b_d * b_i)));
            }else{
                number = std::to_string(a_i * b_i);
            }
        }
        else{
            if(b_d == b_i){
                number = "Делить на 0 нельзя!";
                is_over_expr = true;
                return;
            }
            else{
                if(b_d == 0){
                    b_d = b_i * 2;
                }
                else {
                    b_i = 1;
                }
            }
            if(a_d == a_i){
                a_i = 1;
            }
            else{
                if(a_d == 0){
                    a_d = a_i * 2;
                }
                else{
                    a_i = 1;
                }
            }
            if(is_double_expr){
                number = std::to_string((long double)((a_d / a_i) / (b_d / b_i)));
            }else{
                number = std::to_string(a_i / b_i);
            }
        }
        is_over_expr = true;
    }

    void refresh(){
        if(is_over_expr){
            lineEdit->setText(lineEdit->text() = "");
            is_double_expr = false;
            a_i = 0;
            b_i = 0;
            a_d = 0;
            b_d = 0;
            flags = 0;
            is_over_expr = false;
            number.clear();
        }
    }
    
public slots:
    void add0() {refresh(); lineEdit->setText(lineEdit->text() + "0"); number += "0";};
    void add1() {refresh(); lineEdit->setText(lineEdit->text() + "1"); number += "1";};
    void add2() {refresh(); lineEdit->setText(lineEdit->text() + "2"); number += "2";};
    void add3() {refresh(); lineEdit->setText(lineEdit->text() + "3"); number += "3";};
    void add4() {refresh(); lineEdit->setText(lineEdit->text() + "4"); number += "4";};
    void add5() {refresh(); lineEdit->setText(lineEdit->text() + "5"); number += "5";};
    void add6() {refresh(); lineEdit->setText(lineEdit->text() + "6"); number += "6";};
    void add7() {refresh(); lineEdit->setText(lineEdit->text() + "7"); number += "7";};
    void add8() {refresh(); lineEdit->setText(lineEdit->text() + "8"); number += "8";};
    void add9() {refresh(); lineEdit->setText(lineEdit->text() + "9"); number += "9";};
    void add_dot() {lineEdit->setText(lineEdit->text() + "."); flags += 1; is_double_expr = true; number += ".";};
    void add_add() {if(flags < 2){num_ext(); flags += 2; lineEdit->setText(lineEdit->text() + "+");}};
    void add_sub() {if(flags < 2){num_ext(); flags += 4; lineEdit->setText(lineEdit->text() + "-");}};
    void add_mult() {if(flags < 2){num_ext(); flags += 8; lineEdit->setText(lineEdit->text() + "*");}};
    void add_div() {if(flags < 2){num_ext(); flags += 16; lineEdit->setText(lineEdit->text() + "/");}};
    void result() {num_ext(); calculate(); lineEdit->setText(number.c_str());};
private:
    long int a_i{};
    long int b_i{};

    long double a_d{};
    long double b_d{};
    
    bool is_double_expr{false};
    bool is_over_expr{false};
    int flags{0};
    //1 bit - is double num, 2 bit - add, 3 bit - sub, 4 bit - mult, 5 bit - div

    std::string number;
};
#endif //INC_37_1_CALC_MAINWINDOW_H
