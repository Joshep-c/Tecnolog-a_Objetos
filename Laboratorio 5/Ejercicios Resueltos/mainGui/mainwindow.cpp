#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar el botón para agregar tareas
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    // Crear una nueva tarea
    Task* task = new Task(this);

    // Conectar la señal de "removed" de la tarea al slot "removeTask"
    connect(task, &Task::removed, this, &MainWindow::removeTask);

    // Agregar la tarea al layout
    ui->tasksLayout->addWidget(task);

    // Guardar la tarea en el QVector
    mTasks.append(task);

    // Escribir en la consola para verificar la funcionalidad
    qDebug() << "Tarea agregada - Tareas totales:" << mTasks.size();
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
    qDebug() << "Tarea eliminada - Tareas Totales:" << mTasks.size();
}
