#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , caesarWindow(new Task1_Caesar())  // Убрали parent
{
    ui->setupUi(this);

    connect(ui->pushButton_task1, &QPushButton::clicked, this, &MainWindow::onTask1Clicked);
    connect(ui->pushButton_exit, &QPushButton::clicked, this, &MainWindow::on_pushButton_exit_clicked);
    connect(ui->pushButton_result, &QPushButton::clicked, this, [this]() {
        QMessageBox::information(this, "Stats", "Статистика будет здесь");
    });
    connect(caesarWindow, &Task1_Caesar::backToMainWindow, this, [this]() {
        caesarWindow->hide();
        this->show();
    });
}

void MainWindow::onTask1Clicked()
{
    if (!caesarWindow) {
        caesarWindow = new Task1_Caesar();
    }
    this->hide();
    caesarWindow->show();
    caesarWindow->activateWindow();  // Делаем окно активным
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_task1_clicked()
{
    this->hide();
    caesarWindow->show();
    caesarWindow->activateWindow();
}

void MainWindow::on_pushButton_exit_clicked()
{
    QApplication::quit();
}
