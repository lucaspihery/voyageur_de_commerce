#include "historique.h"
#include <QTextStream>

int Historique::getN_generation() const
{
    return n_generation;
}

int Historique::getN_individu() const
{
    return n_individu;
}

TSPIndividual Historique::get_individu() const
{
    return individu;
}

QString Historique::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"Generation no "<<n_generation<<" Individu : "<<n_individu<<individu.toString();
    return res;
}

Historique::Historique(int n,int n_i, TSPIndividual i):
    n_generation(n),n_individu(n_i),individu(i)
{

}
