#ifndef EVOLUTIONARYPROCESS_H
#define EVOLUTIONARYPROCESS_H

#include <QList>
#include "tspindividual.h"
#include "mainwindow.h"
#include "historique.h"

class EvolutionaryProcess
{
private:
    QList<TSPIndividual *> population;
    int generationNb = 0;
    double bestFitness;
    /*! \brief selection : choix d'un père avec "roue biaisée" pour la génération suivante
     */
    TSPIndividual *selection();
    /*! \brief survival : remplacement de l'ancienne génération par la nouvelle
     */
    void survival(QList<TSPIndividual *> &newGeneration);
public:
    EvolutionaryProcess();
    int getGeneration();
    QString toString();
    void run();
};

#endif // EVOLUTIONARYPROCESS_H
