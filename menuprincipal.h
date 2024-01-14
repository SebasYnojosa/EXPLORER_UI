#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MenuPrincipal;
}
QT_END_NAMESPACE

class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    MenuPrincipal(QWidget *parent = nullptr);
    ~MenuPrincipal();


private slots:
    void generarBotones(QList<QPushButton *> *lista,QWidget *pagina, int posX, int posY);

    void on_botonEstaciones_clicked();

    void on_botonVolverPrincipal_clicked();

    void on_botonPlanificador_clicked();

    void on_botonVolverEstaciones_clicked();

    void on_botonVolverPrincipal_2_clicked();

    void on_botonIngresarAutos_clicked();

    void on_botonRegistrarCarro_clicked();

private:
    Ui::MenuPrincipal *ui;
    QList<QLabel *> estaciones;
    QList<QPushButton *> colaPlanificador;
    QList<QPushButton *> ingresarAutos;
};
#endif // MENUPRINCIPAL_H
