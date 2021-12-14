#include <QApplication>
#include <QTimer>
#include "player_window.h"
#include "ui_player_ui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    PlayerMainWindow window(nullptr);
    Ui::MainWindow player;
    QTimer timer;

    player.setupUi(&window);

    QObject::connect(&timer, &QTimer::timeout, &window, &PlayerMainWindow::changeProgressBar);
    timer.start(1000);

    window.lineEdit = player.lineEdit;
    window.progressBar = player.progressBar;

    window.resize(480, 64);
    window.show();
    return QApplication::exec();
}
