#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Estilo del QListWidget
    ui->listWidget->setStyleSheet(
        "QListWidget::item {"
        "   font-size: 18px;"
        "   text-align: center;"
        "   border: 1px solid #808080;"    // Gris en hexadecimal
        "   padding: 5px;"
        "   margin: 5px;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: #789db4;"
        "}"
        );

    ui->infoLabel->setStyleSheet(
        "QLabel {"
        "   font-size: 16px;"
        "   border: 1px solid #808080;"   // Borde gris
        "   padding: 10px;"               // Espaciado interior
        "   margin-top: 10px;"            // Separación superior
        "   background-color: #F0F0F0;"   // Fondo gris claro
        "   border-radius: 5px;"          // Bordes redondeados
        "}"
        );

    // Crear un mapa con países, capitales e idiomas
    QMap<QString, QPair<QString, QString>> paises;
    paises.insert("Perú", {"Lima", "Español"});
    paises.insert("Francia", {"París", "Francés"});
    paises.insert("Japón", {"Tokio", "Japonés"});
    paises.insert("Alemania", {"Berlín", "Alemán"});
    paises.insert("Italia", {"Roma", "Italiano"});
    paises.insert("España", {"Madrid", "Español"});
    paises.insert("Canadá", {"Ottawa", "Inglés, Francés"});
    paises.insert("Brasil", {"Brasilia", "Portugués"});
    paises.insert("India", {"Nueva Delhi", "Hindi, Inglés"});
    paises.insert("Australia", {"Canberra", "Inglés"});
    paises.insert("México", {"Ciudad de México", "Español"});
    paises.insert("China", {"Pekín", "Chino Mandarín"});
    paises.insert("Sudáfrica", {"Pretoria", "Inglés, Afrikáans, otros"});
    paises.insert("Rusia", {"Moscú", "Ruso"});
    paises.insert("Egipto", {"El Cairo", "Árabe"});

    // Agregar países a la lista
    for (const QString &pais : paises.keys()) {
        ui->listWidget->addItem(pais);
    }

    // Conectar la señal de clic con el slot
    connect(ui->listWidget, &QListWidget::itemClicked, this, [this, paises](QListWidgetItem *item) {
        QString pais = item->text();
        if (paises.contains(pais)) {
            QPair<QString, QString> datos = paises.value(pais);
            ui->infoLabel->setText("Capital: " + datos.first + "\nIdioma: " + datos.second);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
