#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include "tspindividual.h"


class Historique
{
private:
    int n_generation;
    int n_individu;
    TSPIndividual individu;
    //static QList<Historique *> individus;

public:
    Historique(int n,int n_i,TSPIndividual i);
    static QList <Historique *> individus;
    int getN_generation() const;
    int getN_individu() const;
    TSPIndividual get_individu() const;
    QString toString();
};

#endif // HISTORIQUE_H
