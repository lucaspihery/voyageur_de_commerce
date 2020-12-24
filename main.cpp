#include "../shared/qstd.h"
using namespace qstd;
#include "parameters.h"
#include "evolutionaryprocess.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    cout<<"Projet Genetique Voyageur de Commerce :"<<endl;
    // initialisation paramètres spécifiques au voyageur de commerce
    Parameters::crossoverRate = 0.0;
    Parameters::mutationRate = 0.3;
    Parameters::mutationAddRate = 0.0;
    Parameters::mutationDeleteRate = 0.0;
    Parameters::minFitness = 2579;
    // tests sur EvolutionaryProcess
    EvolutionaryProcess evo;
    evo.run();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
