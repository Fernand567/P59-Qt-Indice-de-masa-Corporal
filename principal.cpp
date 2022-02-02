#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{

    ui->setupUi(this);
    lienzo=QPixmap(523,500);
    this->dibujar();

}

Principal::~Principal()
{
    delete ui;
}

void Principal::crearArchivo()
{
    if(contador==0){
    QFile archivo("C:/Users/alexi/Desktop/indice masa corporal/registroindice");
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
    QTextStream salida(&archivo);
    salida.operator<<("1 Mis apuntes");
    contador++;
        archivo.close();
    }else{
    //QString nombreArchivo = QFileDialog::getOpenFileName(C:/Users/alexi/Desktop/indice masa corporal/registroindice);
    }
}

}

void Principal::cargarDatos()
{
    QString Altura=ui->inAltura->text();
    QString peso=ui->inPeso->text();
    double altura=Altura.toDouble();
    double pesso=peso.toDouble();
    IMC= pesso /((altura/100)*(altura/100));
    ui->outAlturaActual->setText(Altura+" cm");
    ui->outIMC->setText(QString::number(IMC,'t',2));

}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 50;
    int y = 50;
    painter.setFont(QFont("Arial Bold",6));
    QColor color1(210,226,221);
    QColor color2(85,108,137);
    QColor color3(112,215,121);
    QColor color4(238,239,195);
    QColor color5(236,200,97);
    QColor color6(232,69,82);
    y = 200;
    int alto = 50;
    painter.drawText(x,y+alto + 20,"15");
    painter.drawText(x+39,y+alto + 20,"16");
    painter.drawText(x+98,y+alto + 20,"18.5");
    painter.drawText(x+177,y+alto + 20,"25");
    painter.drawText(x+236,y+alto + 20,"30");
    painter.drawText(x+305,y+alto + 20,"35");
    painter.drawText(x+365,y+alto + 20,"40");

    painter.setPen(color1);
    painter.setBrush(color1);
    painter.drawRect(x,y,30,alto);

    painter.setPen(color2);
    painter.setBrush(color2);
    painter.drawRect(x+39,y,50,alto);

    painter.setPen(color3);
    painter.setBrush(color3);
    painter.drawRect(x+98,y,70,alto);

    painter.setPen(color4);
    painter.setBrush(color4);
    painter.drawRect(x+177,y,50,alto);

    painter.setPen(color5);
    painter.setBrush(color5);
    painter.drawRect(x+236,y,60,alto);

    painter.setPen(color6);
    painter.setBrush(color6);
    painter.drawRect(x+305,y,60,alto);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawText(100-5, y-10, QString::number(IMC));

    painter.drawRoundedRect(100,y-3,5,alto + 8,3, 1.5);

    ui->outGrafico->setPixmap(lienzo);
}

void Principal::verificarEstado()
{
    if(IMC<=18.5){
        ui->outEstado->setText("\n----------El Paciente tiene bajo peso----------\n");
    }else if(IMC>= 18.5 && IMC <= 24.9){
        ui->outEstado->setText("\n----------El Paciente tiene un peso normal----------\n");
    }else if(IMC>= 25.0 && IMC <= 29.9){
         ui->outEstado->setText("\n----------El Paciente tiene Sobrepeso----------\n");
    }else if(IMC>=30){
         ui->outEstado->setText("\n----------El Paciente tiene Obesidad----------\n");
    }
}

void Principal::on_btnCalcular_clicked()
{
    crearArchivo();
    cargarDatos();
    verificarEstado();
    dibujar();
}


void Principal::on_pushButton_clicked()
{
    QDir directorio = QDir::home();

    //Agregar al path absoluto del objeto un nombre por defecto del archivo
    QString pathArchivo = directorio.absolutePath();

    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",pathArchivo,"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

