#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Objeto para manejar las traducciones
    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "English" << "Spanish";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Languaje",
                               "Select a Languaje",
                               idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    if (idiomaSeleccionado == "English"){
        traducion.load(":/en_us.qm");
    }

    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Spanish"){
        a.installTranslator(&traducion);
    }
    Principal w;
    w.show();
    return a.exec();
}
