#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);

    // Conectar el botón "Quitar" para remover
    connect(ui->pushButton_2, &QPushButton::clicked, [this]{
        emit removed(this);
    });

    // Conectar el botón "Editar" al slot editTask
    connect(ui->pushButton, &QPushButton::clicked, this, &Task::editTask);
}

Task::~Task()
{
    delete ui;
}

void Task::editTask()
{
    // Abrir un cuadro para editar la tarea
    bool ok;
    QString newText = QInputDialog::getText(this, tr("Editar Tarea"),
                                            tr("Nuevo título:"), QLineEdit::Normal,
                                            ui->checkbox->text(), &ok);
    if (ok && !newText.isEmpty()) {
        ui->checkbox->setText(newText);
    }
}
