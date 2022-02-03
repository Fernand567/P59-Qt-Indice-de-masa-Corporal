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


   if((ui->inDia->text().toDouble()>=1 && ui->inDia->text().toDouble()<10)&&(ui->inMes->text().toDouble()>=1 && ui->inMes->text().toDouble()<10)){
       datos= "0" +ui->inDia->text() + "/0" +ui->inMes->text()+ "/"+ui->inAnio->text()+"    "+
              ui->inPeso->text()+" kg\n";
   }else if(ui->inDia->text().toDouble()>=1 && ui->inDia->text().toDouble()<10){
       datos= "0" +ui->inDia->text() + "/" +ui->inMes->text()+ "/"+ui->inAnio->text()+"    "+
              ui->inPeso->text()+" kg\n";
   }else if(ui->inMes->text().toDouble()>=1 && ui->inMes->text().toDouble()<10){
       datos= ui->inDia->text() + "/0" +ui->inMes->text()+ "/"+ui->inAnio->text()+"    "+
              ui->inPeso->text()+" kg\n";
   }else{
   datos= ui->inDia->text() + "/" +ui->inMes->text()+ "/"+ui->inAnio->text()+"    "+
          ui->inPeso->text()+" kg\n";
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
    ui->outPactual->setText(QString::number(pesso,'t',2));


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
    painter.drawText(250-5, y-10, QString::number(IMC));

    if(IMC>15 && IMC<16){
    painter.drawRoundedRect(70,y-3,5,alto + 8,3, 1.5);
    }else if(IMC<15){
    painter.drawRoundedRect(50,y-3,5,alto + 8,3, 1.5);
    }
    else if(IMC>=16 && IMC<17){
    painter.drawRoundedRect(102,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=17 && IMC<18.5){
    painter.drawRoundedRect(127,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=18.5 && IMC<21){
    painter.drawRoundedRect(170,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=21 && IMC<25){
    painter.drawRoundedRect(195,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=25 && IMC<27.5){
    painter.drawRoundedRect(245,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=27.5 && IMC<30){
    painter.drawRoundedRect(260,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=30 && IMC<32.5){
    painter.drawRoundedRect(305,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=32.5 && IMC<35){
    painter.drawRoundedRect(330,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=35 && IMC<37.5){
    painter.drawRoundedRect(373,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=37.5 && IMC<40){
    painter.drawRoundedRect(400,y-3,5,alto + 8,3, 1.5);
    }else if(IMC>=40){
    painter.drawRoundedRect(410,y-3,5,alto + 8,3, 1.5);
    }

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

void Principal::archivoexiste()
{
    ubicacion=QDir::homePath();
    bool existe=QFile::exists(ubicacion+"/archivoAS");
    if(existe==false){
        QFile archivo(ubicacion+"/archivoAS");

       if(archivo.open(QFile::WriteOnly | QFile::Truncate)){

           QTextStream salida(&archivo);
           salida.operator<<(datos);

        }
    }else{
        double minimo=100;
        double maximo=0;

            QFile archivo(ubicacion+"/archivoAS");
        if(archivo.open(QFile::ReadOnly)){

            QTextStream entrada(&archivo);
            QString a;


            while(entrada.atEnd()==false){

                a=entrada.readLine();
                datosGuardar+=a+"\n";
                a.remove(0,14);
                a.remove(2,5);
                double min=a.toDouble();
                double max=a.toDouble();
                if(min<minimo){
                    minimo=min;
                }
                if(max>maximo){
                    maximo=max;
                }
            }

                }
        ui->outPmax->setText(QString::number(maximo)+" kg");
        ui->outPmin->setText(QString::number(minimo)+" kg");
            archivo.close();

        if(archivo.open(QFile::WriteOnly)){
            QTextStream salida(&archivo);
            salida.operator<<(datosGuardar);
            salida.operator<<(datos);
            datosGuardar="";
        }



    }
}



void Principal::on_btnCalcular_clicked()
{
    crearArchivo();
    archivoexiste();
    cargarDatos();
    verificarEstado();
    dibujar();

}


void Principal::on_pushButton_clicked()
{
    QDir directorio = QDir::home();

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




