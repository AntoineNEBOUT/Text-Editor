#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <QPrintDialog>
#include <QPrinter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void on_actionNouveau_triggered();
        void on_actionEnregistrer_sous_triggered();

    protected:
        Ui::MainWindow *ui;
        bool isFileOpen;
        std::string endFile;
        QString fileName;
        QString research;
        bool tabActivated;

    private slots:
        void on_actionQuitter_triggered();
        void on_actionItalique_triggered();
        void on_textEdit_cursorPositionChanged();
        void on_actionSouligner_triggered();
        void on_actionGras_triggered();
        void on_actionPolice_triggered();
        void on_actionCouleur_et_Alignement_triggered();
        void on_spinBox_valueChanged(int arg1);
        void on_fontComboBox_currentFontChanged(const QFont &f);
        void on_actionCouleur_triggered();
        void on_actionSurlignage_triggered();
        void on_actionEnregistrer_triggered();
        void on_actionOuvrir_triggered();
        void on_actionAlignerAGauche_triggered();
        void on_actionAlignerAuCentre_triggered();
        void on_actionAlignerADroite_triggered();
        void on_actionJustifier_triggered();
        void on_actionImprimer_triggered();
        void on_actionImage_triggered();
        void on_pushButton_clicked();
        void on_horizontalSlider_valueChanged(int value);
        void on_action_propos_de_Qt_triggered();
        void on_actionA_propos_triggered();
};
#endif // MAINWINDOW_H
