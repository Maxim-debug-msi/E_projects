#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText){
        QRegularExpression expr("^(\\+)[0-9]{11}$");
        if(expr.match(currentText).hasMatch()) setOkLabel();
        else setNoLabel();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("OK!");
    ui->label->setStyleSheet("QLabel {color: green;}");
}

void MainWindow::setNoLabel()
{
    ui->label->setText("NO!");
    ui->label->setStyleSheet("QLabel {color: red;}");
}

