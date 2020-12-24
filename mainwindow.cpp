#include "mainwindow.h"
#include "evolutionaryprocess.h"
#include <QtWidgets>
#include <string>
#include <iostream>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGroupBox *generations= createGenerationGroupBox();
    QGroupBox *individus = createIndividuGroupBox();
    QGroupBox *details = createDetailsGroupBox();


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(generations, 0, 0);
    layout->addWidget(individus, 1, 0);
    layout->addWidget(details, 0, 1, 2, 1);
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(0, 500);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    showImageLabel();
    resize(850, 400);
    setWindowTitle(tr("Voyageur de commerce"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::changeGeneration(int row)
{
    if (row > 0) {
        //showArtistProfile(index);
    } else if (row == 0) {
        showImageLabel();
    } else {
        return;
    }
}
QGroupBox* MainWindow::createGenerationGroupBox()
{
    GenerationView = new QComboBox;
    //GenerationView->setModelColumn(1);
    GenerationView->addItem("Génération 20");
    QGroupBox *box = new QGroupBox(tr("Génération"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(GenerationView, 0, 0);
    box->setLayout(layout);

    return box;
}

QGroupBox* MainWindow::createIndividuGroupBox()
{
    QGroupBox *box = new QGroupBox(tr("Individu"));

    IndividuView = new QTableView;
    IndividuView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    IndividuView->setSortingEnabled(true);
    IndividuView->setSelectionBehavior(QAbstractItemView::SelectRows);
    IndividuView->setSelectionMode(QAbstractItemView::SingleSelection);
    IndividuView->setShowGrid(false);
    IndividuView->verticalHeader()->hide();
    IndividuView->setAlternatingRowColors(true);
    //IndividuView->setItem(0, 1, new QTableWidgetItem("Hello"));

    //adjustHeader();

    QLocale locale = IndividuView->locale();
    locale.setNumberOptions(QLocale::OmitGroupSeparator);
    IndividuView->setLocale(locale);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(IndividuView, 0, 0);
    box->setLayout(layout);

    return box;
}

QGroupBox* MainWindow::createDetailsGroupBox()
{
    QGroupBox *box = new QGroupBox(tr("Carte"));

    imageLabel = new QLabel;
    imageLabel->setWordWrap(true);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setPixmap(QPixmap("/home/lucas/Documents/qt/voyageur_de_commerce/image/image.png"));

    listeVille = new QListWidget;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(imageLabel, 0, 0, 3, 2);
    layout->addWidget(listeVille, 2, 0, 1, 2);
    layout->setRowStretch(2, 1);
    box->setLayout(layout);

    return box;
}

void MainWindow::showImageLabel()
{
    listeVille->hide();
    imageLabel->show();
}

void MainWindow::updateHeader(QModelIndex, int, int)
{
    adjustHeader();
}

QString MainWindow::toString(int i)
{
    QString res;
    QTextStream buf(&res);
    buf<<i<<endl;
    return res;
}

void MainWindow::adjustHeader()
{
    IndividuView->hideColumn(0);
    IndividuView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    IndividuView->resizeColumnToContents(2);
    IndividuView->resizeColumnToContents(3);
}
