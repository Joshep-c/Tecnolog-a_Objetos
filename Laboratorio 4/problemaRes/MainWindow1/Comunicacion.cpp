#include "Comunicacion.h"
#include <QDebug>

Comunicacion::Comunicacion(QObject *parent) : QObject{parent}
{

}

void Comunicacion::escuchar(const QString &str){
    qDebug() << "estoy escuchandoo..."<<str;
}

void Comunicacion::conversar(const QString &conversa){
    //emitir la señal
    emit enviarmensaje(conversa);
}
