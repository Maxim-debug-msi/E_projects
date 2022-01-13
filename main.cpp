#include <QApplication>
#include <QHBoxLayout>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QPlainTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //
    QWidget main;
    QHBoxLayout layout(&main);
    QWebEngineView htmlView;
    QPlainTextEdit textEdit;
    //
    main.resize(1280, 768);
    layout.addWidget(&textEdit);
    layout.addWidget(&htmlView);
    //
    QSizePolicy sp1(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp1.setHorizontalStretch(1);
    sp1.setVerticalStretch(0);
    //
    textEdit.setSizePolicy(sp1);
    htmlView.setSizePolicy(sp1);
    //
    QObject::connect(&textEdit, &QPlainTextEdit::textChanged, [&htmlView, &textEdit](){
        htmlView.setHtml(textEdit.toPlainText());
    });
    main.show();
    return a.exec();
}
