#include <QApplication>
#include <QTimer>
#include "TV_Remote_Window.h"
#include "ui_TV_Remote_UI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TVRemoteMainWindow window;
    Ui::MainWindow tv_remote;
    QTimer timer;

    tv_remote.setupUi(&window);

    window.lineEdit = tv_remote.lineEdit;
    window.lineEdit_2 = tv_remote.lineEdit_2;

    window.resize(320, 360);
    window.show();
    return QApplication::exec();
}
