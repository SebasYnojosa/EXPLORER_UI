#include "menuprincipal.h"
#include "ui_menuprincipal.h"

#include <iostream>
#include <QString>

MenuPrincipal::MenuPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuPrincipal)

{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->principal);

    // Crea la lista de estaciones para la pagina de estaciones
    for (int i = 0; i < 8; i++){
        estaciones.append(new QLabel(ui->estaciones));
        estaciones.at(i)->setStyleSheet("QLabel { background-color: rgb(143, 240, 164); }");
        estaciones.at(i)->setText("Estacion " + QString::number(i));
        estaciones.at(i)->setAlignment(Qt::AlignCenter);
        estaciones.at(i)->setGeometry(QRect(305,100+(50*i),200,30));
    }

    // Botones de las estaciones del planificador
    generarBotones(&colaPlanificador, ui->planificador, 305, 100);

    // Botones para el ingreso de autos
    generarBotones(&ingresarAutos, ui->ingresarAutos, 205, 150);

    // Hacer que en la pagina de registro de carros, el input hacepte numeros grandes
    ui->insertarKm->setRange(0, 1000000000);

}


MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}

// Genera una lista de botones para estaciones en la pagina y en las coordenadas (posX,posY) dadas
void MenuPrincipal::generarBotones(QList<QPushButton *> *lista,QWidget *pagina, int posX, int posY){
    for (int i = 0; i < 8; i++){
        lista->append(new QPushButton(pagina));
        lista->at(i)->setStyleSheet("QPushButton { background-color: rgb(154, 153, 150); }");
        lista->at(i)->setText("Estacion " + QString::number(i));
        lista->at(i)->setGeometry(QRect(posX,posY+(50*i),200,30));
    }
}

void MenuPrincipal::on_botonEstaciones_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->estaciones);
}


void MenuPrincipal::on_botonVolverPrincipal_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->principal);
}


void MenuPrincipal::on_botonPlanificador_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->planificador);
}


void MenuPrincipal::on_botonVolverEstaciones_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->estaciones);

}

void MenuPrincipal::on_botonVolverPrincipal_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->principal);
}


void MenuPrincipal::on_botonIngresarAutos_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ingresarAutos);
}

void MenuPrincipal::on_botonRegistrarCarro_clicked()
{
    /* Primero agarra el texto del input, lo pasa a mayusculas todo el texto y
    lo convierte en un std::string para que std::cout lo pueda leer */
    std::cout << "Carro:{ Placa: " << ui->insertarPlaca->text().toUpper().toStdString()
              << ", Color: " << ui->insertarColor->text().toStdString()
              << ", Dueño: " << ui->insertarPropietario->text().toStdString()
              << ", Kilometros recorridos: " << ui->insertarKm->text().toInt() << " } ";

    ui->insertarPlaca->clear();
    ui->insertarColor->clear();
    ui->insertarPropietario->clear();
    ui->insertarKm->clear();
}

