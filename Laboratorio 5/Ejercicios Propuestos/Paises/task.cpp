#include "task.h"
#include "ui_task.h"

Task::Task(const QString &country, const QString &capital, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Task)
    , mCountry(country)
    , mCapital(capital)
{
    ui->setupUi(this);

    // Set initial text for country and capital
    ui->checkBox->setText(mCountry);
    ui->capitalLabel->setText(mCapital);

    // Connect "Quitar" button to the remove signal
    connect(ui->pushButton_2, &QPushButton::clicked, [this]{
        emit removed(this);
    });

    // Connect "Editar" button to editTask slot
    connect(ui->pushButton, &QPushButton::clicked, this, &Task::editTask);
}

Task::~Task()
{
    delete ui;
}

void Task::editTask()
{
    // Edit country name
    bool ok;
    QString newCountry = QInputDialog::getText(this, tr("Editar País"),
                                               tr("Nuevo nombre del país:"), QLineEdit::Normal,
                                               mCountry, &ok);
    if (ok && !newCountry.isEmpty()) {
        mCountry = newCountry;
        ui->checkBox->setText(mCountry);
    }

    // Edit capital name
    QString newCapital = QInputDialog::getText(this, tr("Editar Capital"),
                                               tr("Nuevo nombre de la capital:"), QLineEdit::Normal,
                                               mCapital, &ok);
    if (ok && !newCapital.isEmpty()) {
        mCapital = newCapital;
        ui->capitalLabel->setText(mCapital);
    }
}
