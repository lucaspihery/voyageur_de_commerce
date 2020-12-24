#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QString>
#include "parameters.h"
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QComboBox;
class QFile;
class QGroupBox;
class QLabel;
class QListWidget;
class QTableView;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeGeneration(int row);
    void updateHeader(QModelIndex, int, int);
    QString toString(int i);

private:
    void adjustHeader();
    QGroupBox *createGenerationGroupBox();
    QGroupBox *createIndividuGroupBox();
    QGroupBox *createDetailsGroupBox();
    void showImageLabel();

    QTableView *IndividuView;
    QComboBox *GenerationView;
    QListWidget *listeVille;

    //QLabel *iconLabel;
    QLabel *imageLabel;

};
#endif // MAINWINDOW_H
