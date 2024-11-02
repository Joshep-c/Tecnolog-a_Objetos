#ifndef TASK_H
#define TASK_H

#include <QDialog>
#include <QInputDialog>

namespace Ui {
class Task;
}

class Task : public QDialog
{
    Q_OBJECT

public:
    explicit Task(const QString &country, const QString &capital, QWidget *parent = nullptr);
    ~Task();

signals:
    void removed(Task* task); // Signal to remove a task

private slots:
    void editTask(); // Slot to edit country and capital names

private:
    Ui::Task *ui;
    QString mCountry;
    QString mCapital;
};

#endif // TASK_H
