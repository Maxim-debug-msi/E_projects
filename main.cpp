#include <QApplication>
#include "calc_mainwindow.h"
#include "./ui_calc_interface.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalcMainWindow window(nullptr);
    Ui::MainWindow calc;
    calc.setupUi(&window);
    window.lineEdit = calc.lineEdit;
    window.resize(480, 640);
    window.show();
    return QApplication::exec();
}
