#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "datos.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QPainter>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_btnCalcular_clicked();

    void on_pushButton_clicked();

private:
    Ui::Principal *ui;
    QPixmap lienzo;
    QImage imagen;
    double IMC;
    int contador=0;
    void crearArchivo();
    void obtenerDatos();
    void cargarDatos();
    void dibujar();
    void verificarEstado();

};
#endif // PRINCIPAL_H
