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
    explicit Task(QWidget *parent = nullptr);
    ~Task();

signals:
    void removed(Task* task); // Signal to remove a task

private slots:
    void editTask(); // Slot to edit task title

private:
    Ui::Task *ui;
};

#endif // TASK_H
