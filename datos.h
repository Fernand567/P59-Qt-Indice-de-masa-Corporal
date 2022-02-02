#ifndef DATOS_H
#define DATOS_H

#include <QObject>


class Datos : public QObject
{
    Q_OBJECT
public:
    explicit Datos(QObject *parent = nullptr);


    const QString &getAltura() const;
    void setAltura(const QString &newAltura);
    double getPesoActual() const;
    void setPesoActual(double newPesoActual);
    double getPesoMax() const;
    void setPesoMax(double newPesoMax);
    double getPesoMin() const;
    void setPesoMin(double newPesoMin);
    double getIMC() const;
    void setIMC(double newIMC);

signals:

private:
    QString altura;
    double  pesoActual;
    double  pesoMax;
    double  pesoMin;
    double  IMC;

};

#endif // DATOS_H
