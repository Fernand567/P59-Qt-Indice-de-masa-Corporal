#include "principal.h"
#include <QTranslator>
#include <QInputDialog>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Polaco"<< "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);

    if (idiomaSeleccionado == "Polaco"){
        traducion.load(":/indicedenasacorporal_pol.qm");
        }

    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    Principal w;
    w.show();
    return a.exec();
}
