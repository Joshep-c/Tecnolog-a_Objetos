#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDebug>

void MainWindow::onAddTaskButtonClicked() {
    // Agregar la lógica cuando se haga clic en el botón
    ui->statusLabel->setText("Tarea agregada");
}

void MainWindow::addTask() {
    // Este slot se activará al hacer clic en el botón
    qDebug() << "Slot corresponde al clic en el botón ...";
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::onAddTaskButtonClicked);
    connect(ui->addTaskButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}
