#include <QObject>
#include <QDebug>
#include "Comunicacion.cpp"
#include "qcoreapplication.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *person = new QObject;
    Comunicacion *pepe = new Comunicacion(person);
    Comunicacion *jose = new Comunicacion(person);

    QObject::connect(pepe,SIGNAL(enviarmensaje(QString)),jose,SLOT(escuchar(QString)));
    QObject::connect(jose,SIGNAL(enviarmensaje(QString)),pepe,SLOT(escuchar(QString)));
    pepe->conversar("buenos dias");
    jose->conversar("como vas");

    delete person;
}

