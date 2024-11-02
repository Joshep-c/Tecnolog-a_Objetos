#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar el botón para agregar países
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    // Define default values for country and capital
    QString country = "Perú";
    QString capital = "Lima";

    // Create a new Task with default country and capital
    Task* task = new Task(country, capital, this);

    // Connect the task's removed signal to the removeTask slot
    connect(task, &Task::removed, this, &MainWindow::removeTask);

    // Add the task to the layout
    ui->tasksLayout->addWidget(task);

    // Store the task in the QVector
    mTasks.append(task);

    // Log the addition
    qDebug() << "País agregado - Total de tareas:" << mTasks.size();
}


void MainWindow::removeTask(Task* task)
{
    // Eliminar la tarea del layout
    ui->tasksLayout->removeWidget(task);

    // Eliminar la tarea del QVector
    mTasks.removeOne(task);

    // Liberar la memoria de la tarea
    task->deleteLater();

    // Escribir en la consola para verificar la funcionalidad
    qDebug() << "País eliminado - Total países:" << mTasks.size();
}
