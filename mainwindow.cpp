#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <windows.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolBar_police->addWidget(ui->fontComboBox);
    ui->toolBar_police->addWidget(ui->spinBox);
    ui->toolBar_couleurEtAlignement->addWidget(ui->lineEdit_shearch);
    ui->toolBar_couleurEtAlignement->addWidget(ui->pushButton);
    ui->toolBar_couleurEtAlignement->addWidget(ui->horizontalSlider);


    showMaximized();

    isFileOpen = false;
    endFile;

    tabActivated = false;

    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/mot.ico"));
    ui->actionAlignerADroite->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/alignRight.png"));
    ui->actionAlignerAGauche->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/AlignLeft.png"));
    ui->actionAlignerAuCentre->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/AlignCenter.png"));
    ui->actionJustifier->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/AlignJustify.png"));
    ui->actionQuitter->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/close.png"));
    ui->actionCouleur->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/color.png"));
    ui->actionGras->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/bold.png"));
    ui->actionItalique->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/italic.png"));
    ui->actionSouligner->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/underline.png"));
    ui->actionImprimer->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/print.png"));
    ui->actionEnregistrer->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/save.png"));
    ui->actionEnregistrer_sous->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/save as.png"));
    ui->actionNouveau->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/new.png"));
    ui->actionOuvrir->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/open.png"));
    ui->actionSurlignage->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/surlignage.ico"));
    ui->actionPolice->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/visible.png"));
    ui->actionCouleur_et_Alignement->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/visible.png"));
    ui->actionImage->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/image.png"));
    ui->actionA_propos->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/mot.ico"));
    ui->action_propos_de_Qt->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icons/qt.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNouveau_triggered()
{
    QProcess app;
    app.setProgram(QCoreApplication::applicationDirPath()+"/Mot.exe");
    app.startDetached();
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionItalique_triggered()
{
    if (ui->textEdit->fontItalic())
    {
        ui->textEdit->setFontItalic(false);
    }
    else
    {
       ui->textEdit->setFontItalic(true);
    }
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    if (ui->textEdit->fontItalic())
    {
        ui->actionItalique->setChecked(true);
    }
    else
    {
        ui->actionItalique->setChecked(false);
    }

    if (ui->textEdit->fontUnderline())
    {
        ui->actionSouligner->setChecked(true);
    }
    else
    {
        ui->actionSouligner->setChecked(false);
    }

    if (ui->textEdit->fontWeight() == 90)
    {
        ui->actionGras->setChecked(true);
    }
    else
    {
        ui->actionGras->setChecked(false);
    }
}

void MainWindow::on_actionSouligner_triggered()
{
    if (ui->textEdit->fontUnderline())
    {
        ui->textEdit->setFontUnderline(false);
    }
    else
    {
       ui->textEdit->setFontUnderline(true);
    }
}

void MainWindow::on_actionGras_triggered()
{
    if (ui->textEdit->fontWeight() == 90)
    {
        ui->textEdit->setFontWeight(0);
    }
    else
    {
       ui->textEdit->setFontWeight(90);
    }
}

void MainWindow::on_actionPolice_triggered()
{
    if (ui->toolBar_police->isHidden())
    {
        ui->toolBar_police->show();
        ui->actionPolice->setIcon(QIcon(QCoreApplication::applicationDirPath()+"/icons/visible.png"));
    }
    else
    {
        ui->toolBar_police->hide();
        ui->actionPolice->setIcon(QIcon(QCoreApplication::applicationDirPath()+"/icons/invisible.png"));

    }
}

void MainWindow::on_actionCouleur_et_Alignement_triggered()
{
    if (ui->toolBar_couleurEtAlignement->isHidden())
    {
        ui->toolBar_couleurEtAlignement->show();
        ui->actionCouleur_et_Alignement->setIcon(QIcon(QCoreApplication::applicationDirPath()+"/icons/visible.png"));
    }
    else
    {
        ui->toolBar_couleurEtAlignement->hide();
        ui->actionCouleur_et_Alignement->setIcon(QIcon(QCoreApplication::applicationDirPath()+"/icons/invisible.png"));
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->textEdit->setFontPointSize(arg1);
}

void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit->setCurrentFont(f);
}

void MainWindow::on_actionCouleur_triggered()
{
    QColorDialog couleur;
    ui->textEdit->setTextColor(couleur.getColor(QColor(), this, "Couleur"));
}

void MainWindow::on_actionSurlignage_triggered()
{
    QColorDialog couleur;
    ui->textEdit->setTextBackgroundColor(couleur.getColor(QColor(), this, "Surlignage"));
}

void MainWindow::on_actionEnregistrer_sous_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, "Enregistrer sous", QString::fromStdString(endFile), "Document (*.mot) ;; Document HTML (*.html) ;; Document Microsoft Word (*.doc)");

    string strFileName = fileName.toStdString();
    ofstream monFlux(strFileName.c_str());

    if (fileName != "")
    {
        if(monFlux)
        {
            monFlux << ui->textEdit->toHtml().toStdString();
        }
        else
        {
            QMessageBox::critical(this, "Erreur d'enregistrement", "L'enregistrement de votre fichier a échoué");
        }

        isFileOpen = true;
        endFile = fileName.toStdString();

        ui->statusbar->showMessage("Fichier courant : "+fileName);
    }

}

void MainWindow::on_actionEnregistrer_triggered()
{
    if (isFileOpen)
    {
        string strFileName = fileName.toStdString();
        ofstream monFlux(strFileName.c_str());

        if(monFlux)
        {
            monFlux << ui->textEdit->toHtml().toStdString();
            QMessageBox::information(this, "Enregistrement réussi", "Votre fichier a bien été enregistré !\nFichier : "+fileName);
        }
        else
        {
            QMessageBox::critical(this, "Erreur d'enregistrement", "L'enregistrement de votre fichier a échoué !\nFichier : "+fileName);
        }
    }
    else
    {
        MainWindow::on_actionEnregistrer_sous_triggered();
    }
}

void MainWindow::on_actionOuvrir_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, "Ouvrir", QString::fromStdString(endFile), "Tout les documents (*.mot ; *.html ; *.doc) ;; Document (*.mot) ;; Document HTML (*.html) ;; Document Microsoft Word (*.doc)");

    string FileName = fileName.toStdString();
    ifstream strFileName(FileName.c_str());

    if (fileName != "")
    {
        if(strFileName)
        {
            string ligne;
            string texte;

            ui->textEdit->clear();

            while(std::getline(strFileName, ligne)) // Pour récupérer tout le fichier
            {
                texte += ligne;
                // ui->textEdit->append(QString::fromStdString(ligne));
            }
            ui->textEdit->setHtml(QString::fromStdString(texte));
        }
        else
        {
            QMessageBox::critical(this, "Erreur d'ouverture", "L'ouverture de votre fichier a échoué");
        }

        isFileOpen = true;
        endFile = fileName.toStdString();

        ui->statusbar->showMessage("Fichier courant : "+fileName);
    }
}

void MainWindow::on_actionAlignerAGauche_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionAlignerAuCentre_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_actionAlignerADroite_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionJustifier_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignJustify);
}

void MainWindow::on_actionImprimer_triggered()
{
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle("Imprimer/PDF");
    if (ui->textEdit->textCursor().hasSelection())
        dialog->setOption(QAbstractPrintDialog::PrintSelection);
    if (dialog->exec() == QDialog::Accepted)
        ui->textEdit->document()->print(&printer);
}

void MainWindow::on_actionImage_triggered()
{
    QTextCursor curseur;
    curseur = ui->textEdit->textCursor();

    fileName = QFileDialog::getOpenFileName(this, "Insérer une image", QString::fromStdString(endFile), "Image (*.png; *.ico; *.jpg; *.jpeg)");

    string FileName = fileName.toStdString();
    ifstream strFileName(FileName.c_str());

    if (fileName != "")
    {
        curseur.insertImage(fileName);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if(!ui->textEdit->isReadOnly())
    {
        ui->textEdit->moveCursor(QTextCursor::Start);
        QColor color = QColor(Qt::yellow).lighter(130);

        while(ui->textEdit->find(ui->lineEdit_shearch->text()))
        {
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(color);

            extra.cursor = ui->textEdit->textCursor();
            extraSelections.append(extra);
        }
    }

    ui->textEdit->setExtraSelections(extraSelections);

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->horizontalSlider->setMaximum(this->width()-100);
    ui->textEdit->setFixedWidth(value);
}

void MainWindow::on_action_propos_de_Qt_triggered()
{
    QMessageBox::aboutQt(this, "A propos de Qt");

}

void MainWindow::on_actionA_propos_triggered()
{
    QMessageBox::about(this, "A propos", "Ce logiciel a été développé par Antoine NEBOUT avec Qt 5.15.0 (open source) puis mis à jour vers Qt 6.4.2.\nBonne utilisation !");
}
