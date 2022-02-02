#include "datos.h"

Datos::Datos(QObject *parent) : QObject(parent)
{

}

const QString &Datos::getAltura() const
{
    return altura;
}

void Datos::setAltura(const QString &newAltura)
{
    altura = newAltura;
}

double Datos::getPesoActual() const
{
    return pesoActual;
}

void Datos::setPesoActual(double newPesoActual)
{
    pesoActual = newPesoActual;
}

double Datos::getPesoMax() const
{
    return pesoMax;
}

void Datos::setPesoMax(double newPesoMax)
{
    pesoMax = newPesoMax;
}

double Datos::getPesoMin() const
{
    return pesoMin;
}

void Datos::setPesoMin(double newPesoMin)
{
    pesoMin = newPesoMin;
}

double Datos::getIMC() const
{
    return IMC;
}

void Datos::setIMC(double newIMC)
{
    IMC = newIMC;
}
