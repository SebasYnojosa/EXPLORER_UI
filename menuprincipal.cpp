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
    generarEstacionesLabels(&estaciones, ui->estaciones, 305, 100);

    // Botones de las estaciones del planificador
    generarEstacionesLabels(&colaPlanificador, ui->planificador, 305, 100);

    // Botones para el ingreso de autos
    generarEstacionesLabels(&ingresarAutos, ui->ingresarAutos, 205, 150);

    // Hacer que en la pagina de registro de carros, el input hacepte numeros grandes
    ui->insertarKm->setRange(0, 1000000000);

}


MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}

// Genera una lista de botones para estaciones en la pagina y en las coordenadas (posX,posY) dadas
void MenuPrincipal::generarEstacionesLabels(QList<QLabel *> *lista,QWidget *pagina, int posX, int posY){
    for (int i = 0; i < 8; i++){
        lista->append(new QLabel(pagina));
        lista->at(i)->setStyleSheet("QLabel { background-color: rgb(143, 240, 164); }");
        lista->at(i)->setText("Estacion " + QString::number(i));
        lista->at(i)->setAlignment(Qt::AlignCenter);
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
    ui->insertarKm->setValue(0);
}


void MenuPrincipal::on_botonOcuparEstacion_clicked()
{
    int seleccionado = ui->selectorEstacion->value();
    estaciones.at(seleccionado)->setStyleSheet("QLabel { background-color: rgb(246, 97, 81); }");
    colaPlanificador.at(seleccionado)->setStyleSheet("QLabel { background-color: rgb(246, 97, 81); }");
    ingresarAutos.at(seleccionado)->setStyleSheet("QLabel { background-color: rgb(246, 97, 81); }");
}


void MenuPrincipal::on_botonDesocuparEstacion_clicked()
{
    int seleccionado = ui->selectorEstacion->value();
    estaciones.at(seleccionado)->setStyleSheet("QLabel { background-color: rgb(143, 240, 164); }");
    colaPlanificador.at(seleccionado)->setStyleSheet("QLabel { background-color: rgb(143, 240, 164); }");
    ingresarAutos.at(seleccionado)->setStyleSheet("QLabel { background-color: rgb(143, 240, 164); }");
}

