/*
 * ~~~~~~~~~~~~~~~~~~~~`PROGRAM DONE BY ABHISHEK BALASUBRAMANIAM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
 * ~~~~~~~~~~~~~~~~~~~~ FOR MORE INFORMATION CONTACT (abhisheklokesh6008@gmail.com) ~~~~~~~~~~~~~~~~~
 * ~~~~~~~~~~~~~~~~~~~~ VISIT ME AT www.abhishekbalu.com ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ~~~~~~~~~~~~~~~~~~~~

*/


#include "mcalib.h"
#include "ui_mcalib.h"
#include "QDir"
#include <cstdlib>
#include <QPen>
#include<QColor>
#include<QLineEdit>
#include<QPalette>
#include"qpalette.h"
#include <QLabel>
#include <QVBoxLayout>
#include<QMessageBox>
#include<QUndoStack>
#include <QPrinter>
#include <QPrintDialog>
#include<QPainter>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QTextEdit>
#include <QPixmap>
#include <QStandardItemModel>
#include<QStackedWidget>
#include"qstackedwidget.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <iostream>


MCALIB::MCALIB(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MCALIB)
{
    ui->setupUi(this);
    this->setWindowTitle("i-cal");
      ui->stackedWidget->setCurrentIndex(0);
}

MCALIB::~MCALIB()
{
    delete ui;
}

//< +++++++++++++++++++++++++++++++++++++++++++ Menu ++++++++++++++++++++++++++++++++++++++++++>>
void MCALIB::on_action_NEW_triggered()
{
   ui->stackedWidget->setCurrentIndex(0);
   MCALIB::repaint();

}
void MCALIB::on_action_Open_triggered()
{
    filename =  QFileDialog::getOpenFileName(
                  this,
                  "Open Document",
                  QDir::currentPath(),
                  "All files (*.*) ;; Document files (*.csv *.rtf);; PNG files (*.png)");
            if( !filename.isNull() )
            {
              qDebug() << "selected file path : " <<filename.toUtf8();
            }
            QFileInfo info(filename);
              QFile file(filename.toUtf8());
              QString line;
              if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                  QTextStream stream(&file);
                  QString a[10];
                  while (!stream.atEnd()){
                    for (int i=0;i<10;i++)
                    {
                     a[i]= stream.readLine();
                    qDebug()<< a[i] << i;
                    }
                  }
                  ui->comboBox->setCurrentText(a[0]);
                  ui->lineEdit_1->setText(a[1]);
                  ui->lineEdit_2->setText(a[2]);
                  ui->lineEdit_3->setText(a[3]);
                   ui->lineEdit_4->setText(a[4]);
                   ui->comboBox_3->setCurrentText(a[5]);
                    ui->comboBox_4->setCurrentText(a[6]);
                      ui->lineEdit_5->setText(a[7]);
                        ui->lineEdit_7->setText(a[8]);
                        ui->textEdit->setPlainText(a[9]);
              }
              file.close();
}
void MCALIB::on_action_Save_As_triggered()
{
    if(ui->stackedWidget->currentIndex() == 0)
    {
        QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
        QString defaultFilter("txt files (*.txt)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
        QFile file(fileName);
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream <<  ui->comboBox->currentText()<< "\n" << ui->lineEdit_1->text()<<"\n"<<ui->lineEdit_2->text()<<"\n"<<ui->lineEdit_3->text()<<"\n"<< ui->lineEdit_4->text()<< "\n"<< ui->comboBox_3->currentText()<< "\n"<< ui->comboBox_4->currentText() << "\n"<< ui->lineEdit_5->text()<< "\n"<< ui->lineEdit_7->text()<< "\n";
    //        stream <<   ui->lineEdit_1->text() << endl;<<ui->textEdit->toPlainText()<<"\n"
        }

    }
    if(ui->comboBox->currentIndex()==1)
    {
   // exportTableWidgetToCSV();
    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.txt);;xlsx files (*.xlsx)" );
    QFile file(fileName);

    QAbstractItemModel *model =  ui->tableWidget_2->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QTextStream outStream(&file);
//          QString str = ui->comboBox->currentText();
        /* Write the line to the file */


        outStream <<  ui->comboBox->currentText() << endl;
        outStream << ui->lineEdit_1->text()<< endl ;
        outStream <<ui->lineEdit_2->text()<< endl ;
        outStream<<ui->lineEdit_3->text()<< "\n";
        outStream<< ui->comboBox_3->currentText()<< "\n";
        outStream<< ui->comboBox_4->currentText() << "\n";
        outStream<< ui->lineEdit_4->text()<< "\n";
        outStream<< ui->lineEdit_5->text()<< "\n";
        outStream<< ui->lineEdit_7->text()<< "\n";
        outStream<<ui->textEdit->toPlainText()<<endl;

        /* Close the file */

        QStringList strList;

        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }



     //  return true;




       /* Point a QTextStream object at the file */


   }
    if(ui->comboBox->currentIndex()==2)
    {
   // exportTableWidgetToCSV();
    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
   QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)" );
    QFile file(fileName);

    QAbstractItemModel *model =  ui->tableWidget_3->model();
    QAbstractItemModel *model1 =  ui->tableWidget_4->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QTextStream data1(&file);
        QTextStream outStream(&file);
//          QString str = ui->comboBox->currentText();
        /* Write the line to the file */
        outStream <<  ui->comboBox->currentText() << endl;
        outStream << ui->lineEdit_1->text()<< endl ;
        outStream <<ui->lineEdit_2->text()<< endl ;
        outStream<<ui->lineEdit_3->text()<< "\n";
        outStream<< ui->comboBox_3->currentText()<< "\n";
        outStream<< ui->comboBox_4->currentText() << "\n";
        outStream<< ui->lineEdit_4->text()<< "\n";
        outStream<< ui->lineEdit_5->text()<< "\n";
        outStream<< ui->lineEdit_7->text()<< "\n";
        outStream<<ui->textEdit->toPlainText()<<endl;

        /* Close the file */

        QStringList strList;
        QStringList strList1;



        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }

            for (int k = 0;k < model1->columnCount(); k++) {
                if (model1->headerData(k, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList1.append("\"" + model1->headerData(k, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList1.append("");
            }
            data1 << strList1.join(";") << "\n";
            for (int k = 0; k < model1->rowCount(); k++) {
                strList1.clear();
                for (int l = 0; l < model1->columnCount(); l++) {

                    if (model1->data(model1->index(k, l)).toString().length() > 0)
                        strList1.append("\"" + model1->data(model1->index(k, l)).toString() + "\"");
                    else
                        strList1.append("");
                }
            data1 << strList1.join(";") + "\n";
        }
        file.close();
    }



     //  return true;




       /* Point a QTextStream object at the file */


   }
    if(ui->comboBox->currentIndex()==3)
    {
        // exportTableWidgetToCSV();
         QString filters("CSV files (*.csv);;All files (*.*)");
         QString defaultFilter("CSV files (*.csv)");
         QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", "" );
         QFile file(fileName);

         QAbstractItemModel *model =  ui->tableWidget_16->model();
         if (file.open(QFile::WriteOnly | QFile::Truncate)) {
             QTextStream data(&file);
             QTextStream outStream(&file);
     //          QString str = ui->comboBox->currentText();
             /* Write the line to the file */
             outStream <<  ui->comboBox->currentText() << endl;
             outStream << ui->lineEdit_1->text()<< endl ;
             outStream <<ui->lineEdit_2->text()<< endl ;
             outStream<<ui->lineEdit_3->text()<< "\n";
             outStream<< ui->comboBox_3->currentText()<< "\n";
             outStream<< ui->comboBox_4->currentText() << "\n";
             outStream<< ui->lineEdit_4->text()<< "\n";
             outStream<< ui->lineEdit_5->text()<< "\n";
             outStream<< ui->lineEdit_7->text()<< "\n";
             outStream<<ui->textEdit->toPlainText()<<endl;

             /* Close the file */

             QStringList strList;

             for (int i = 0; i < model->columnCount(); i++) {
                 if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                     strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                 else
                     strList.append("");
             }
             data << strList.join(";") << "\n";
             for (int i = 0; i < model->rowCount(); i++) {
                 strList.clear();
                 for (int j = 0; j < model->columnCount(); j++) {

                     if (model->data(model->index(i, j)).toString().length() > 0)
                         strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                     else
                         strList.append("");
                 }
                 data << strList.join(";") + "\n";
             }
             file.close();
         }

    }
    if(ui->comboBox->currentIndex()==4)
    {
        QString filters("CSV files (*.csv);;All files (*.*)");
        QString defaultFilter("CSV files (*.csv)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)" );
        QFile file(fileName);

        QAbstractItemModel *model =  ui->tableWidget_22->model();
        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream data(&file);
            QTextStream outStream(&file);
    //          QString str = ui->comboBox->currentText();
            /* Write the line to the file */
            outStream <<  ui->comboBox->currentText() << endl;
            outStream << ui->lineEdit_1->text()<< endl ;
            outStream <<ui->lineEdit_2->text()<< endl ;
            outStream<<ui->lineEdit_3->text()<< "\n";
            outStream<< ui->comboBox_3->currentText()<< "\n";
            outStream<< ui->comboBox_4->currentText() << "\n";
            outStream<< ui->lineEdit_4->text()<< "\n";
            outStream<< ui->lineEdit_5->text()<< "\n";
            outStream<< ui->lineEdit_7->text()<< "\n";
            outStream<<ui->textEdit->toPlainText()<<endl;

            /* Close the file */

            QStringList strList;

            for (int i = 0; i < model->columnCount(); i++) {
                if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") << "\n";
            for (int i = 0; i < model->rowCount(); i++) {
                strList.clear();
                for (int j = 0; j < model->columnCount(); j++) {

                    if (model->data(model->index(i, j)).toString().length() > 0)
                        strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") + "\n";
            }
            file.close();
        }

    }
}
void MCALIB::on_action_Save_triggered()
{
    if(ui->stackedWidget->currentIndex() == 0)
    {
        QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
        QString defaultFilter("txt files (*.txt)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
        QFile file(fileName);
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream <<  ui->comboBox->currentText()<< "\n" << ui->lineEdit_1->text()<<"\n"<<ui->lineEdit_2->text()<<"\n"<<ui->lineEdit_3->text()<<"\n"<< ui->lineEdit_4->text()<< "\n"<< ui->comboBox_3->currentText()<< "\n"<< ui->comboBox_4->currentText() << "\n"<< ui->lineEdit_5->text()<< "\n"<< ui->lineEdit_7->text()<< "\n";
    //        stream <<   ui->lineEdit_1->text() << endl;<<ui->textEdit->toPlainText()<<"\n"
        }

    }
    if(ui->comboBox->currentIndex()==1)
    {
   // exportTableWidgetToCSV();
    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.txt);;xlsx files (*.xlsx)" );
    QFile file(fileName);

    QAbstractItemModel *model =  ui->tableWidget_2->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QTextStream outStream(&file);
//          QString str = ui->comboBox->currentText();
        /* Write the line to the file */


        outStream <<  ui->comboBox->currentText() << endl;
        outStream << ui->lineEdit_1->text()<< endl ;
        outStream <<ui->lineEdit_2->text()<< endl ;
        outStream<<ui->lineEdit_3->text()<< "\n";
        outStream<< ui->comboBox_3->currentText()<< "\n";
        outStream<< ui->comboBox_4->currentText() << "\n";
        outStream<< ui->lineEdit_4->text()<< "\n";
        outStream<< ui->lineEdit_5->text()<< "\n";
        outStream<< ui->lineEdit_7->text()<< "\n";
        outStream<<ui->textEdit->toPlainText()<<endl;

        /* Close the file */

        QStringList strList;

        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }



     //  return true;




       /* Point a QTextStream object at the file */


   }
    if(ui->comboBox->currentIndex()==2)
    {
   // exportTableWidgetToCSV();
    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
   QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)" );
    QFile file(fileName);

    QAbstractItemModel *model =  ui->tableWidget_3->model();
    QAbstractItemModel *model1 =  ui->tableWidget_4->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QTextStream data1(&file);
        QTextStream outStream(&file);
//          QString str = ui->comboBox->currentText();
        /* Write the line to the file */
        outStream <<  ui->comboBox->currentText() << endl;
        outStream << ui->lineEdit_1->text()<< endl ;
        outStream <<ui->lineEdit_2->text()<< endl ;
        outStream<<ui->lineEdit_3->text()<< "\n";
        outStream<< ui->comboBox_3->currentText()<< "\n";
        outStream<< ui->comboBox_4->currentText() << "\n";
        outStream<< ui->lineEdit_4->text()<< "\n";
        outStream<< ui->lineEdit_5->text()<< "\n";
        outStream<< ui->lineEdit_7->text()<< "\n";
        outStream<<ui->textEdit->toPlainText()<<endl;

        /* Close the file */

        QStringList strList;
        QStringList strList1;



        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }

            for (int k = 0;k < model1->columnCount(); k++) {
                if (model1->headerData(k, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList1.append("\"" + model1->headerData(k, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList1.append("");
            }
            data1 << strList1.join(";") << "\n";
            for (int k = 0; k < model1->rowCount(); k++) {
                strList1.clear();
                for (int l = 0; l < model1->columnCount(); l++) {

                    if (model1->data(model1->index(k, l)).toString().length() > 0)
                        strList1.append("\"" + model1->data(model1->index(k, l)).toString() + "\"");
                    else
                        strList1.append("");
                }
            data1 << strList1.join(";") + "\n";
        }
        file.close();
    }



     //  return true;




       /* Point a QTextStream object at the file */


   }
    if(ui->comboBox->currentIndex()==3)
    {
        // exportTableWidgetToCSV();
         QString filters("CSV files (*.csv);;All files (*.*)");
         QString defaultFilter("CSV files (*.csv)");
         QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", "" );
         QFile file(fileName);

         QAbstractItemModel *model =  ui->tableWidget_16->model();
         if (file.open(QFile::WriteOnly | QFile::Truncate)) {
             QTextStream data(&file);
             QTextStream outStream(&file);
     //          QString str = ui->comboBox->currentText();
             /* Write the line to the file */
             outStream <<  ui->comboBox->currentText() << endl;
             outStream << ui->lineEdit_1->text()<< endl ;
             outStream <<ui->lineEdit_2->text()<< endl ;
             outStream<<ui->lineEdit_3->text()<< "\n";
             outStream<< ui->comboBox_3->currentText()<< "\n";
             outStream<< ui->comboBox_4->currentText() << "\n";
             outStream<< ui->lineEdit_4->text()<< "\n";
             outStream<< ui->lineEdit_5->text()<< "\n";
             outStream<< ui->lineEdit_7->text()<< "\n";
             outStream<<ui->textEdit->toPlainText()<<endl;

             /* Close the file */

             QStringList strList;

             for (int i = 0; i < model->columnCount(); i++) {
                 if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                     strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                 else
                     strList.append("");
             }
             data << strList.join(";") << "\n";
             for (int i = 0; i < model->rowCount(); i++) {
                 strList.clear();
                 for (int j = 0; j < model->columnCount(); j++) {

                     if (model->data(model->index(i, j)).toString().length() > 0)
                         strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                     else
                         strList.append("");
                 }
                 data << strList.join(";") + "\n";
             }
             file.close();
         }

    }
    if(ui->comboBox->currentIndex()==4)
    {
        QString filters("CSV files (*.csv);;All files (*.*)");
        QString defaultFilter("CSV files (*.csv)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)" );
        QFile file(fileName);

        QAbstractItemModel *model =  ui->tableWidget_22->model();
        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream data(&file);
            QTextStream outStream(&file);
    //          QString str = ui->comboBox->currentText();
            /* Write the line to the file */
            outStream <<  ui->comboBox->currentText() << endl;
            outStream << ui->lineEdit_1->text()<< endl ;
            outStream <<ui->lineEdit_2->text()<< endl ;
            outStream<<ui->lineEdit_3->text()<< "\n";
            outStream<< ui->comboBox_3->currentText()<< "\n";
            outStream<< ui->comboBox_4->currentText() << "\n";
            outStream<< ui->lineEdit_4->text()<< "\n";
            outStream<< ui->lineEdit_5->text()<< "\n";
            outStream<< ui->lineEdit_7->text()<< "\n";
            outStream<<ui->textEdit->toPlainText()<<endl;

            /* Close the file */

            QStringList strList;

            for (int i = 0; i < model->columnCount(); i++) {
                if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") << "\n";
            for (int i = 0; i < model->rowCount(); i++) {
                strList.clear();
                for (int j = 0; j < model->columnCount(); j++) {

                    if (model->data(model->index(i, j)).toString().length() > 0)
                        strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") + "\n";
            }
            file.close();
        }

    }
}
void MCALIB::on_action_Print_triggered()
{
if(ui->comboBox->currentIndex() == 1)
{
    QPrinter printer;
        printer.setPrinterName("Print");
        printer.setPageSize(QPrinter::A4);
         printer.setResolution(QPrinter::HighResolution);
        QPrintDialog dialog(&printer,this);
        if(dialog.exec() == QDialog::Rejected) return;

            QPainter painter;
           painter.setFont(QFont("times",22));
            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }
if(ui->tab->height() <= 2100)
{
    QList <QWidget *> widgets;
    widgets.append({ui->scrollAreaWidgetContents_3,ui->frame,ui->frame_3});
    for(auto widget: widgets){
        if(widget){
            if(widget->width() > 0 && widget->height() >0 ){

                ui->pushButton_4->setVisible(0);
                ui->pushButton_5->setVisible(0);
                ui->pushButton_12->setVisible(0);
                ui->pushButton_13->setVisible(0);
                ui->pushButton_26->setVisible(0);
                ui->pushButton_3->setVisible(0);
                ui->pushButton_6->setVisible(0);

                qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
                qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

                qreal scale = qMin(xscale, yscale);

                painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                                  printer.paperRect().y() + printer.pageRect().height()/4.5);

                painter.scale(scale, scale);
                painter.translate(-width()/3.95, -height()/6.5);
                widget->render(&painter);
                painter.resetTransform();
                if(widget != widgets.last())
                    printer.newPage();

        }
    }
    }

    ui->pushButton_4->setVisible(1);
    ui->pushButton_5->setVisible(1);
    ui->pushButton_12->setVisible(1);
    ui->pushButton_13->setVisible(1);
    ui->pushButton_26->setVisible(1);
    ui->pushButton_3->setVisible(1);
    ui->pushButton_6->setVisible(1);

}

    if (ui->tab->height() >= 2101)
{
QList <QWidget *> widgets;
widgets.append({ui->scrollAreaWidgetContents_3,ui->frame, ui->frame_2});
for(auto widget: widgets){
    if(widget){
        if(widget->width() > 0 && widget->height() >0 ){
            ui->pushButton_4->setVisible(0);
            ui->pushButton_5->setVisible(0);
            ui->pushButton_12->setVisible(0);
            ui->pushButton_13->setVisible(0);
            ui->pushButton_26->setVisible(0);
            ui->pushButton_3->setVisible(0);
            ui->pushButton_6->setVisible(0);


            qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
            qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

            qreal scale = qMin(xscale, yscale);

            painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                              printer.paperRect().y() + printer.pageRect().height()/4.5);

            painter.scale(scale, scale);
            painter.translate(-width()/3.95, -height()/6.5);
            widget->render(&painter);
            painter.resetTransform();
            if(widget != widgets.last())
                printer.newPage();

    }
}
}
ui->pushButton_4->setVisible(1);
ui->pushButton_5->setVisible(1);
ui->pushButton_12->setVisible(1);
ui->pushButton_13->setVisible(1);
ui->pushButton_26->setVisible(1);
ui->pushButton_3->setVisible(1);
ui->pushButton_6->setVisible(1);
}
}

if(ui->comboBox->currentIndex() == 2)
{

    QPrinter printer;
        printer.setPrinterName("Print");
        printer.setPageSize(QPrinter::A4);
         printer.setResolution(QPrinter::HighResolution);
        QPrintDialog dialog(&printer,this);
        if(dialog.exec() == QDialog::Rejected) return;

            QPainter painter;
           painter.setFont(QFont("times",22));
            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }

    QList <QWidget *> widgets;
    widgets.append({ui->scrollAreaWidgetContents_5,ui->scrollAreaWidgetContents_4});
    for(auto widget: widgets){
        if(widget){
            if(widget->width() > 0 && widget->height() >0 ){

                ui->pushButton_17->setVisible(0);
                ui->pushButton_18->setVisible(0);
                ui->pushButton_24->setVisible(0);
                ui->pushButton_6->setVisible(0);
                ui->pushButton_7->setVisible(0);
                ui->pushButton_27->setVisible(0);

                qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
                qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

                qreal scale = qMin(xscale, yscale);

                painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                                  printer.paperRect().y() + printer.pageRect().height()/3.5);

                painter.scale(scale, scale);
                painter.translate(-width()/3.9, -height()/2.5);
                widget->render(&painter);
                painter.resetTransform();
                if(widget != widgets.last())
                    printer.newPage();

        }
    }
    }
    ui->pushButton_17->setVisible(1);
    ui->pushButton_18->setVisible(1);
    ui->pushButton_24->setVisible(1);
    ui->pushButton_6->setVisible(1);
    ui->pushButton_7->setVisible(1);
    ui->pushButton_27->setVisible(1);

}

if(ui->comboBox->currentIndex() == 3)
{

}


}
void MCALIB::on_action_Exit_triggered()
{
       this->close();
}
void MCALIB::on_action_Cut_triggered()
{
    ui->lineEdit_1->cut();
    ui->lineEdit_2->cut();
    ui->lineEdit_3->cut();
    ui->lineEdit_4->cut();
    ui->lineEdit_5->cut();
    ui->lineEdit_7->cut();
    ui->textEdit->cut();

}
void MCALIB::on_action_Copy_triggered()
{
    ui->lineEdit_1->copy();
    ui->lineEdit_2->copy();
    ui->lineEdit_3->copy();
    ui->lineEdit_4->copy();
    ui->lineEdit_5->copy();
    ui->lineEdit_7->copy();
    ui->textEdit->copy();
}
void MCALIB::on_action_Paste_triggered()
{
    ui->lineEdit_1->paste();
    ui->lineEdit_2->paste();
    ui->lineEdit_3->paste();
    ui->lineEdit_4->paste();
    ui->lineEdit_5->paste();
    ui->lineEdit_7->paste();
    ui->textEdit->paste();
}
void MCALIB::on_action_Add_Row_triggered()
{
    if(ui->tabWidget->currentIndex() == 0)
    {
        int  i = ui->tableWidget->rowCount();
        //int  j = ui->tableWidget_2->rowCount();


        if (i < 52  )

        {
        int k = i+2;
        ui->tableWidget->setRowCount(k);
        QStringList v2;
        v2 <<"Forward Start"<< "Reverse Start" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
        for(int i=3; i<=k ; i++)
        {
        ui->tableWidget->setVerticalHeaderLabels(v2);
        }
         ui->frame_3->setVisible(1);

         i = ui->tableWidget->rowCount();


        }
        int i1 = ui->tableWidget->rowCount();
         int j1 = ui->tableWidget_2->rowCount();

        if(i1>51 )
        {
            ui->label_89->setNum(1);
            ui->frame_2->setVisible(1);
            ui->frame_3->setVisible(1);

            ui->scrollAreaWidgetContents_2->setGeometry(0,-658,1554,3000);

             int y2 = j1+ i1-52;
            int k1 = y2+2;
            ui->tableWidget_2->setRowCount(k1);
            QStringList v2;
            v2 <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
            for(int i=1; i<=k1 ; i++)
            {
            ui->tableWidget_2->setVerticalHeaderLabels(v2);
            }

        }

    }


}
void MCALIB::on_action_Delete_Row_triggered()
{
        if(ui->tabWidget->currentIndex() == 0)
        {
            int  i = ui->tableWidget->rowCount();
            int  j = ui->tableWidget_2->rowCount();


            if (i <= 52 && j ==0 )

            {
            int k = i-2;
            ui->tableWidget->setRowCount(k);
            QStringList v2;
            v2 <<"Forward Start"<< "Reverse Start" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
            for(int i=3; i<=k ; i++)
            {
            ui->tableWidget->setVerticalHeaderLabels(v2);
            }

             i = ui->tableWidget->rowCount();


            }
            int i1 = ui->tableWidget->rowCount();
             int j1 = ui->tableWidget_2->rowCount();

            if(i1>51 && j1>0 )
            {
                ui->label_89->setNum(1);
                ui->frame_2->setVisible(1);
                ui->scrollAreaWidgetContents_2->setGeometry(0,-658,1554,3000);

                 int y2 = j1+ i1-52;
                int k1 = y2-2;
                ui->tableWidget_2->setRowCount(k1);
                QStringList v2;
                v2 <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
                for(int i=1; i<=k1 ; i++)
                {
                ui->tableWidget_2->setVerticalHeaderLabels(v2);
                }

            }
        }
}
void MCALIB::on_action_Import_triggered()
{
   if(ui->tabWidget->currentIndex() == 0)
   {
       QString filename;
        filename =  QFileDialog::getOpenFileName(
                      this,
                      "Open Document",
                      QDir::currentPath(),
                      "All files (*.*) ;; Document files (*.csv *.rtf);; PNG files (*.png)");
                if( !filename.isNull() )
                {
                  qDebug() << "selected file path : " <<filename.toUtf8();
                }
                QFileInfo info(filename);
                QString filename1 = info.path() + "/" + info.completeBaseName() + ".csv";
                  QFile file(filename1.toUtf8());
                  QFile file1(filename1.toUtf8());
                  QTextStream in(&file);
                  int line_count=0;
                    if(!file.open(QIODevice::ReadOnly)) {
                        QMessageBox::information(this, "error", file.errorString());
                    }
                    if(!file1.open(QIODevice::ReadOnly)) {
                        QMessageBox::information(this, "error", file1.errorString());
                    }

               QString abc[110][10];
                while(!in.atEnd())
                {
                     QString line=in.readLine();
                     QStringList line_data=line.split(",",QString::SkipEmptyParts);
                     for(int j=0;j<10;j++)
                     {
                         QString m_prop=line_data.at(j);
                        abc[line_count][j] = m_prop;
                     }
                     line_count++;
                 }



       for(int i = 0 ; i <52 ;i++)
       {
           for(int j= 0 ; j<10; j++)
           {
        ui->tableWidget->setItem(i,j,new QTableWidgetItem ( abc[i][j]));
        ui->tableWidget_2->setItem(i,j,new QTableWidgetItem ( abc[i+52][j]));
           }
       }
       QPen pen;
       pen.setWidth(1);

        QVector<double> xval(101), yval(101);
        int k= ui->spinBox->value();
        int k1 = k+k;
        ui->customPlot->xAxis->setRange(0, k1);
        ui->customPlot->yAxis->setRange(-100, 100);
        ui->customPlot->yAxis->setOffset(10);
        int z;
        z=0;
         for (int j = 0; j<9; j++)
       {
             xval[j]=j;
             yval[j] = ui->tableWidget->model()->data(ui->tableWidget->model()->index(z, j)).toDouble();
             ui->customPlot->addGraph();
             ui->customPlot->graph(z)->setPen(QPen(Qt::blue));
             ui->customPlot->graph(z)->setData(xval, yval);
             ui->customPlot->replot();

         }

         z=1;
          for (int j = 0; j<9; j++)
        {
              xval[j]=j;
              yval[j] = ui->tableWidget->model()->data(ui->tableWidget->model()->index(z, j)).toDouble();

              ui->customPlot->addGraph();
              ui->customPlot->graph(z)->setPen(QPen(Qt::red));
              ui->customPlot->graph(z)->setData(xval, yval);
              ui->customPlot->replot();

          }
   }
}
void MCALIB::on_action_To_CSV_triggered()
{
  if(ui->comboBox->currentIndex() == 1)
  {
      QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
      QString defaultFilter("txt files (*.txt)");
      QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
      QFile file(fileName);
      if (file.open(QFile::WriteOnly | QFile::Truncate))
      {
          QTextStream data( &file );
          QStringList strList;
      for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
      {
          strList <<
                  "\" " +
                  ui->tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                  "\" ";
      }

      data << strList.join(";") << "\n";
      }
         file.close();
}
  if(ui->comboBox->currentIndex() == 2)
  {
      QMessageBox msgBox;
      msgBox.setWindowTitle("i-cal");
      msgBox.setText(tr("<b>SELECT TABLE</b>"));
      QAbstractButton* pButtonYes = msgBox.addButton(tr("table 1"), QMessageBox::YesRole);
       QAbstractButton* pButtonno =msgBox.addButton(tr("table 2"), QMessageBox::NoRole);



      msgBox.exec();

      if (msgBox.clickedButton()==pButtonYes) {

          QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
          QString defaultFilter("txt files (*.txt)");
          QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
          QFile file(fileName);
          if (file.open(QFile::WriteOnly | QFile::Truncate))
          {
              QTextStream data( &file );
              QStringList strList;
          for( int c = 0; c < ui->tableWidget_3->columnCount(); ++c )
          {
              strList <<
                      "\" " +
                      ui->tableWidget_3->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                      "\" ";
          }

          data << strList.join(";") << "\n";
          }
             file.close();

      }
      if (msgBox.clickedButton()==pButtonno) {

          QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
          QString defaultFilter("txt files (*.txt)");
          QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
          QFile file(fileName);
          if (file.open(QFile::WriteOnly | QFile::Truncate))
          {
              QTextStream data( &file );
              QStringList strList;
          for( int c = 0; c < ui->tableWidget_4->columnCount(); ++c )
          {
              strList <<
                      "\" " +
                      ui->tableWidget_4->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                      "\" ";
          }

          data << strList.join(";") << "\n";
          }
             file.close();


     }
  }
  if(ui->comboBox->currentIndex() == 3)
  {
      QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
      QString defaultFilter("txt files (*.txt)");
      QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
      QFile file(fileName);
      if (file.open(QFile::WriteOnly | QFile::Truncate))
      {
          QTextStream data( &file );
          QStringList strList;
      for( int c = 0; c < ui->tableWidget_16->columnCount(); ++c )
      {
          strList <<
                  "\" " +
                  ui->tableWidget_16->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                  "\" ";
      }

      data << strList.join(";") << "\n";
      }
         file.close();
  }
  if(ui->comboBox->currentIndex() == 4)
  {
      QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
      QString defaultFilter("txt files (*.txt)");
      QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
      QFile file(fileName);
      if (file.open(QFile::WriteOnly | QFile::Truncate))
      {
          QTextStream data( &file );
          QStringList strList;
      for( int c = 0; c < ui->tableWidget_22->columnCount(); ++c )
      {
          strList <<
                  "\" " +
                  ui->tableWidget_22->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                  "\" ";
      }

      data << strList.join(";") << "\n";
      }
         file.close();
  }
}
void MCALIB::on_action_To_TXT_triggered()
{
    if(ui->comboBox->currentIndex() == 1)
    {
        QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
        QString defaultFilter("txt files (*.txt)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream data( &file );
            QStringList strList;
        for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
        {
            strList <<
                    "\" " +
                    ui->tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                    "\" ";
        }

        data << strList.join(";") << "\n";
        }
           file.close();
  }
    if(ui->comboBox->currentIndex() == 2)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("i-cal");
        msgBox.setText(tr("<b>SELECT TABLE</b>"));
        QAbstractButton* pButtonYes = msgBox.addButton(tr("table 1"), QMessageBox::YesRole);
         QAbstractButton* pButtonno =msgBox.addButton(tr("table 2"), QMessageBox::NoRole);



        msgBox.exec();

        if (msgBox.clickedButton()==pButtonYes) {

            QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
            QString defaultFilter("txt files (*.txt)");
            QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
            QFile file(fileName);
            if (file.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream data( &file );
                QStringList strList;
            for( int c = 0; c < ui->tableWidget_3->columnCount(); ++c )
            {
                strList <<
                        "\" " +
                        ui->tableWidget_3->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                        "\" ";
            }

            data << strList.join(";") << "\n";
            }
               file.close();

        }
        if (msgBox.clickedButton()==pButtonno) {

            QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
            QString defaultFilter("txt files (*.txt)");
            QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
            QFile file(fileName);
            if (file.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream data( &file );
                QStringList strList;
            for( int c = 0; c < ui->tableWidget_4->columnCount(); ++c )
            {
                strList <<
                        "\" " +
                        ui->tableWidget_4->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                        "\" ";
            }

            data << strList.join(";") << "\n";
            }
               file.close();


       }
    }
    if(ui->comboBox->currentIndex() == 3)
    {
        QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
        QString defaultFilter("txt files (*.txt)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream data( &file );
            QStringList strList;
        for( int c = 0; c < ui->tableWidget_16->columnCount(); ++c )
        {
            strList <<
                    "\" " +
                    ui->tableWidget_16->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                    "\" ";
        }

        data << strList.join(";") << "\n";
        }
           file.close();
    }
    if(ui->comboBox->currentIndex() == 4)
    {
        QString filters("CSV files (*.csv);;TXT files (*txt);;All files (*.*)");
        QString defaultFilter("txt files (*.txt)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " CSV File(*.csv);;Images (*.png *.xpm *.jpg);;Text files (*.docx);;xlsx files (*.xlsx)" );
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream data( &file );
            QStringList strList;
        for( int c = 0; c < ui->tableWidget_22->columnCount(); ++c )
        {
            strList <<
                    "\" " +
                    ui->tableWidget_22->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                    "\" ";
        }

        data << strList.join(";") << "\n";
        }
           file.close();
    }
  }
void MCALIB::on_action_To_XLSX_triggered()
{
    if(ui->comboBox->currentIndex() == 1)
    {
        QString filters("xlsx files (*.xlsx);;All files (*.*)");
        QString defaultFilter("xlsx files (*.xlsx)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", "xlsx files (*.xlsx)" );
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream data( &file );
            QStringList strList;
        for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
        {
            strList <<
                    "\" " +
                    ui->tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                    "\" ";
        }

        data << strList.join(";") << "\n";
        }
           file.close();
  }
    if(ui->comboBox->currentIndex() == 2)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("i-cal");
        msgBox.setText(tr("<b>SELECT TABLE</b>"));
        QAbstractButton* pButtonYes = msgBox.addButton(tr("table 1"), QMessageBox::YesRole);
         QAbstractButton* pButtonno =msgBox.addButton(tr("table 2"), QMessageBox::NoRole);



        msgBox.exec();

        if (msgBox.clickedButton()==pButtonYes) {

            QString filters("xlsx files (*.xlsx);;All files (*.*)");
            QString defaultFilter("xlsx files (*.xlsx)");
            QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", " xlsx files (*.xlsx)" );
            QFile file(fileName);
            if (file.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream data( &file );
                QStringList strList;
            for( int c = 0; c < ui->tableWidget_3->columnCount(); ++c )
            {
                strList <<
                        "\" " +
                        ui->tableWidget_3->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                        "\" ";
            }

            data << strList.join(";") << "\n";
            }
               file.close();

        }
        if (msgBox.clickedButton()==pButtonno) {

            QString filters("xlsx files (*.xlsx);;All files (*.*)");
            QString defaultFilter("xlsx files (*.xlsx)");
            QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", "xlsx files (*.xlsx)" );
            QFile file(fileName);
            if (file.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream data( &file );
                QStringList strList;
            for( int c = 0; c < ui->tableWidget_4->columnCount(); ++c )
            {
                strList <<
                        "\" " +
                        ui->tableWidget_4->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                        "\" ";
            }

            data << strList.join(";") << "\n";
            }
               file.close();


       }
    }
    if(ui->comboBox->currentIndex() == 3)
    {
        QString filters("xlsx files (*.xlsx);;All files (*.*)");
        QString defaultFilter("xlsx files (*.xlsx)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", ";;xlsx files (*.xlsx)" );
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream data( &file );
            QStringList strList;
        for( int c = 0; c < ui->tableWidget_16->columnCount(); ++c )
        {
            strList <<
                    "\" " +
                    ui->tableWidget_16->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                    "\" ";
        }

        data << strList.join(";") << "\n";
        }
           file.close();
    }
    if(ui->comboBox->currentIndex() == 4)
    {
        QString filters("xlsx files (*.xlsx);;All files (*.*)");
        QString defaultFilter("xlsx files (*.xlsx)");
        QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", "xlsx files (*.xlsx)" );
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream data( &file );
            QStringList strList;
        for( int c = 0; c < ui->tableWidget_22->columnCount(); ++c )
        {
            strList <<
                    "\" " +
                    ui->tableWidget_22->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString() +
                    "\" ";
        }

        data << strList.join(";") << "\n";
        }
           file.close();
    }
}
void MCALIB::on_action_Clear_Table_triggered()
{
if(ui->comboBox->currentIndex() == 1)
{
    ui->tableWidget->clearContents();
}
if(ui->comboBox->currentIndex() == 2)
{
    ui->tableWidget_3->clearContents();
    ui->tableWidget_4->clearContents();

}
if(ui->comboBox->currentIndex() == 3)
{
    ui->tableWidget_16->clearContents();
}
if(ui->comboBox->currentIndex() == 4)
{
    ui->tableWidget_22->clearContents();
}


}
void MCALIB::on_action_Delete_triggered()
{
    if(ui->comboBox->currentIndex() == 1)
    {
        ui->tableWidget->deleteLater();
    }
    if(ui->comboBox->currentIndex() == 2)
    {
        ui->tableWidget_3->deleteLater();
        ui->tableWidget_4->deleteLater();

    }
    if(ui->comboBox->currentIndex() == 3)
    {
        ui->tableWidget_16->deleteLater();
    }
    if(ui->comboBox->currentIndex() == 4)
    {
        ui->tableWidget_22->deleteLater();
}
    }
void MCALIB::on_action_Locate_triggered()
{
        QMessageBox::warning(this, tr("i-cal"),tr("sorry Locator not avaiable for this page"));
}
void MCALIB::on_action_Replace_triggered()
{
          QMessageBox::warning(this, tr("i-cal"),tr("sorry Replace option not avaiable for this page"));
}
void MCALIB::on_action_Add_Table_triggered()
{
    QMessageBox::warning(this, tr("i-cal"),tr("Option Not Avaiable"));

}
void MCALIB::on_action_Delete_Table_triggered()
{
    QMessageBox::warning(this, tr("i-cal"),tr("Option Not Avaiable"));

}
void MCALIB::on_action_Switch_Tab_triggered()
{
  if(ui->tabWidget->currentIndex() == 0)
  {
      ui->tabWidget->setCurrentIndex(1);
  }

  else
  {
      ui->tabWidget->setCurrentIndex(0);

  }
  if(ui->tabWidget_2->currentIndex() == 0)
  {
      ui->tabWidget_2->setCurrentIndex(1);
  }

  else
  {
      ui->tabWidget_2->setCurrentIndex(0);

  }
  if(ui->tabWidget_3->currentIndex() == 0)
  {
      ui->tabWidget_3->setCurrentIndex(1);
  }

  else
  {
      ui->tabWidget_3->setCurrentIndex(0);

  }
  if(ui->tabWidget_4->currentIndex() == 0)
  {
      ui->tabWidget_4->setCurrentIndex(1);
  }

  else
  {
      ui->tabWidget_4->setCurrentIndex(0);

  }


}
void MCALIB::on_action_About_triggered()
{
    QMessageBox::information(
        this,
        tr("i-Cal"),
        tr("<i><b>i-cal</b></i> <br></br> Dail guage calibrator Tool.<br>   </br> Calculates and send value to the scource and also helps to generate certificates <br></br>"),tr("ok") );
}
void MCALIB::on_action_About_Metrics_triggered()
{
    QMessageBox::information(
        this,
        tr("i-Cal"),
        tr("<b>Metric Measurement Technologies</b> <br></br> Metric has an array of high end products and services in the field of Dimensional Metrology.<br></br> Quality Assurance is key task in every products manufactured in world.<br>   </br> We bring precise technology that your measurements are closer to the true value.<br></br> We set our standards to its class.<br></br> "),tr("ok") );
}
void MCALIB::on_action_Technical_Support_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("i-cal");
    msgBox.setText(tr("<b>CONTACT</b>"));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("phone"), QMessageBox::YesRole);
     QAbstractButton* pButtonno =msgBox.addButton(tr("email"), QMessageBox::NoRole);



    msgBox.exec();

    if (msgBox.clickedButton()==pButtonYes) {
  QDesktopServices::openUrl(QUrl("tel:+91-44-26560542"));

          QMessageBox::information(
      this,tr("phone"),tr("+91-44-26560542 "));

    }
    if (msgBox.clickedButton()==pButtonno) {

            QDesktopServices::openUrl(QUrl("mailto:?to=csd@metric.co.in"));

   }
}
void MCALIB::on_action_Version_triggered()
{
    QMessageBox::information(
        this,
        tr("i-Cal"),
        tr("<<b>Version</b> <br></br> Version 1.0 <br></br>"),tr("ok") );
}
void MCALIB::on_action_System_Information_triggered()
{
    QSysInfo systemInfo;
    const int wv = systemInfo.windowsVersion();
    const QString bc = systemInfo.buildCpuArchitecture();
    const QString cc = systemInfo.currentCpuArchitecture();
    QString status = QString("<b> System Information</b><br></br><br></br>windowsVersion : %1 <br></br> Build Cpu Architecture: %2<br></br> Current Cpu Architecture: %3").arg(wv).arg(bc).arg(cc);
    QString name = QString("i-cal");
    QMessageBox::information(this, name, status);
}
void MCALIB::on_action_Add_Page_triggered()
{
    QMessageBox::warning(this, tr("i-cal"),tr("Option Not Avaiable"));

}
void MCALIB::on_action_Main_Toolbar_triggered()
{
  ui->mainToolBar->setVisible(1);
}
//< +++++++++++++++++++++++++++++++++++++++++++ End of Menu ++++++++++++++++++++++++++++++++++++++++++>>


//< +++++++++++++++++++++++++++++++++++++++++++ Main code ++++++++++++++++++++++++++++++++++++++++++

void MCALIB::Calibtable()
{

  int x = ui->spinBox->value();

  if(x <= 25 )
  {
      int y=x+x+2;
  ui->tableWidget->setRowCount(y);
  QStringList v2;
  v2 <<"Forward Start"<< "Reverse Start" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
  for(int i=3; i<=y ; i++)
  {
  ui->tableWidget->setVerticalHeaderLabels(v2);
  }
   ui->frame_2->setVisible(0);
   ui->frame_3->setVisible(1);
   ui->scrollAreaWidgetContents_2->setGeometry(30,0,1554,2100);
   ui->frame_3->setGeometry(30,1500,1554,2000);

  }
  if(x>=26)
  {

ui->frame_2->setVisible(1);

ui->scrollAreaWidgetContents_2->setGeometry(30,0,1554,3600);

      int y = 25+25+2;
      ui->tableWidget->setRowCount(y);
      QStringList v2;
      v2 <<"Forward Start"<< "Reverse Start" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
      for(int i=3; i<=y ; i++)
      {
      ui->tableWidget->setVerticalHeaderLabels(v2);
      }
      int y2 = (x+x)-(25+25);
        ui->frame_3->setVisible(1);

      ui->tableWidget_2->setRowCount(y2);
      QStringList v3;
      v3  <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
      for(int i=3; i<=y2 ; i++)
      {
      ui->tableWidget_2->setVerticalHeaderLabels(v3);
      }
  }

}
void MCALIB::Calibtable1()
{
     int x = ui->spinBox->value();


     if(x==0)
     {
         int y1=x+x+4;
          ui->tableWidget_3->setRowCount(y1);
           ui->tableWidget_4->setRowCount(y1);
     QStringList v3;
     v3 <<"Forward Start"<< "Reverse End" <<"Forward End" <<"Reverse Start";
     for(int i=3; i<=y1 ; i++)
     {
     ui->tableWidget_3->setVerticalHeaderLabels(v3);
     ui->tableWidget_4->setVerticalHeaderLabels(v3);

     }
      }
     else {
         int y2=x+x+2;
          ui->tableWidget_3->setRowCount(y2);
          ui->tableWidget_4->setRowCount(y2);
         QStringList v4;
         v4 <<"Forward Start"<< "Reverse End" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
         for(int i=3; i<=y2 ; i++)
         {
             ui->tableWidget_3->setVerticalHeaderLabels(v4);
             ui->tableWidget_4->setVerticalHeaderLabels(v4);

         }
     }
}
void MCALIB::on_pushButton_clicked()
{

    //<----------------------------------------------------------------- START OF PLUNGER DAIL ------------------------------------>//

    ui->label_22->setText(ui->lineEdit_1->text());
    ui->label_23->setText(ui->lineEdit_2->text());
    ui->label_24->setText(ui->lineEdit_3->text());
    ui->label_38->setText(ui->comboBox_3->currentText());
    ui->label_39->setText(ui->comboBox_4->currentText());
    ui->label_40->setText(ui->lineEdit_4->text());
    ui->label_41->setText(ui->lineEdit_5->text());
    ui->label_42->setText(ui->lineEdit_7->text());
    ui->textEdit_2->setText(ui->textEdit->toPlainText());


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==1)
    {
          ui->stackedWidget->setCurrentIndex(1);
        ui->tabWidget->setCurrentIndex(0);
          Calibtable();
         ui->tableWidget->setColumnCount(10);
         ui->tableWidget_2->setColumnCount(10);
         ui->tableWidget_2->horizontalHeader()->setVisible(0);

         int s =60;
         for(int j=0; j<=10 ;j++)
         {
         ui->tableWidget->setColumnWidth(j,s);
         ui->tableWidget_2->setColumnWidth(j,s);
         }
         int c1 =25;
         int t = ui->spinBox->value();
         int t2=t+t;
         for(int c=0; c<=t2 ;c++)
         {
         ui->tableWidget->setRowHeight(c,c1);
          ui->tableWidget_2->setRowHeight(c,c1);
         }

          QStringList h1;
            h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
         for(int h=3; h<=10 ; h++)
         {
         ui->tableWidget->setHorizontalHeaderLabels(h1);
         }

         ui->label_12->setPixmap(QPixmap("/mcalib/Logo/resource/page 1.jpg"));
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

          QStringList h1;
            h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
         for(int h=3; h<=10 ; h++)
         {
         ui->tableWidget->setHorizontalHeaderLabels(h1);
         }

    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }


    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }

        int width = (s*14)+120;
        int height = (25*t2)+231;
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_2->setGeometry(0,0,1571,wh);
        ui->scrollAreaWidgetContents_2->setMinimumHeight(1500);
    }

    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==5)
    {

        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }

    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==6)
    {

        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==7)
    {

        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==1 &&  ui->comboBox_4->currentIndex()==8)
    {

        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }

                        //   -----------------end of set one ------------------------------ //

    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }

    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==2 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }


        //------------------------end of set two-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }

    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==3 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }


              //--------------end of set three-----------------//

    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }

    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==4 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }




    //------------------------end of set four-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==5 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set five-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==6 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set six-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==7 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set seven-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==8 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set eight-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==9 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set nine-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==10 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set ten-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==11 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set eleven-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==12 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }

    //------------------------end of set twelven-------------------------------//


    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(1);
        Calibtable();
        ui->tableWidget_2->setColumnCount(10);

        int s =80;
        for(int j=0; j<=10 ;j++)
        {
        ui->tableWidget_2->setColumnWidth(j,s);
        }
        int c1 =25;
        int t = ui->spinBox->value();
        for(int c=0; c<=t ;c++)
        {
        ui->tableWidget_2->setRowHeight(c,c1);
        }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget_2->setHorizontalHeaderLabels(h1);
        }
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==13 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(1);
      ui->tabWidget->setCurrentIndex(0);
        Calibtable();
       ui->tableWidget->setColumnCount(10);
       ui->tableWidget_2->setColumnCount(10);
       ui->tableWidget_2->horizontalHeader()->setVisible(0);

       int s =60;
       for(int j=0; j<=10 ;j++)
       {
       ui->tableWidget->setColumnWidth(j,s);
       ui->tableWidget_2->setColumnWidth(j,s);
       }
       int c1 =25;
       int t = ui->spinBox->value();
       int t2=t+t;
       for(int c=0; c<=t2 ;c++)
       {
       ui->tableWidget->setRowHeight(c,c1);
        ui->tableWidget_2->setRowHeight(c,c1);
       }

         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90";
        for(int h=3; h<=10 ; h++)
        {
        ui->tableWidget->setHorizontalHeaderLabels(h1);
        }
    }

  //  <---------------------------------------------------------------- END OF PLUNGER---------------------------------------------------->//


 //<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ LEVER DAIL GUAGE +++++++++++++++++++++++++++++++++++++++++++++++++>//

    ui->label_76->setText(ui->lineEdit_1->text());
    ui->label_77->setText(ui->lineEdit_2->text());
    ui->label_78->setText(ui->lineEdit_3->text());
    ui->label_150->setText(ui->comboBox_3->currentText());
    ui->label_148->setText(ui->comboBox_4->currentText());
    ui->label_66->setText(ui->lineEdit_4->text());
    ui->label_115->setText(ui->lineEdit_5->text());
    ui->label_117->setText(ui->lineEdit_7->text());
    ui->textEdit_3->setText(ui->textEdit->toPlainText());


    //<-------------------------------------- end of page 4 --------------------------------------->//

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);

    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);

    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==15 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }

                        //   -----------------end of set one ------------------------------ //

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==16 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }

                //------------------------end of set two-------------------------------//


    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==17 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }


              //--------------end of set three-----------------//

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==18 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }


    //------------------------end of set four-------------------------------//


    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==1 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }

    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==19 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }

    //------------------------end of set five-------------------------------//


    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==20 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }

    //------------------------end of set six-------------------------------//


    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==21 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }

    //------------------------end of set seven-------------------------------//


    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==1)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(8);
        ui->tableWidget_4->setColumnCount(8);

        int s =90;
        for(int j=0; j<=8 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "1"<<"2"<<"3"<<"4"<<"3"<<"2"<<"1";
        for(int h=3; h<=8 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==2)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(14);
        ui->tableWidget_4->setColumnCount(14);

        int s =60;
        for(int j=0; j<=14 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(290,labely,551,61);
         QStringList h1;
           h1 <<"0" << "10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"60"<<"50"<<"40"<<"30"<< "20"<<"10";
        for(int h=3; h<=14 ; h++)
        {
        ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==3)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==8)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }
    if(ui->comboBox->currentIndex()==2 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==22 &&  ui->comboBox_4->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(3);
        Calibtable1();
        ui->tableWidget_3->setColumnCount(10);
        ui->tableWidget_4->setColumnCount(10);

        int s =70;
        for(int j=0; j<=10 ;j++)
        {
         ui->tableWidget_3->setColumnWidth(j,s);
         ui->tableWidget_4->setColumnWidth(j,s);
        }
        int l1 =30;
        int tl = ui->spinBox->value();
        int t2 =tl*2;
        for(int l=0; l<=t2 ;l++)
        {
        ui->tableWidget_3->setRowHeight(l,l1);
        ui->tableWidget_4->setRowHeight(l,l1);
        }
        int width = (s*14)+120;
        int height = (20*t2)+231;
        ui->tableWidget_3->setGeometry(30,90,width,height);
        int labely = 90+height+5;
        ui->textBrowser->setGeometry(200,labely,551,61);
         QStringList h1;
           h1 <<"0" << "20"<<"40"<<"60"<<"80"<<"100"<<"80"<<"60"<<"40"<<"20";
        for(int h=3; h<=10 ; h++)
        {
         ui->tableWidget_3->setHorizontalHeaderLabels(h1);
         ui->tableWidget_4->setHorizontalHeaderLabels(h1);
        }
        int textb = ui->textBrowser->y();
        int tabel4y = textb+75;
        ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
        int wh = tabel4y+height+100;
        ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);    }






//<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ END OF LEVER DAIL +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>//

//<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  BORE DAIL +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>//

    ui->label_183->setText(ui->lineEdit_1->text());
    ui->label_184->setText(ui->lineEdit_2->text());
    ui->label_185->setText(ui->lineEdit_3->text());
    ui->label_190->setText(ui->comboBox_3->currentText());
    ui->label_203->setText(ui->comboBox_4->currentText());
    ui->label_193->setText(ui->lineEdit_4->text());
    ui->label_192->setText(ui->lineEdit_5->text());
    ui->label_196->setText(ui->lineEdit_7->text());
    ui->textEdit_5->setText(ui->textEdit->toPlainText());


        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==24 &&  ui->comboBox_4->currentIndex()==10)
        {
            ui->tabWidget_3->setCurrentIndex(0);

            ui->tabWidget_3->setCurrentIndex(0);
            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }
           ui->tableWidget_17->setRowCount(2);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));

        }
        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==24 &&  ui->comboBox_4->currentIndex()==11)
        {
            ui->tabWidget_3->setCurrentIndex(0);

               ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }

           ui->tableWidget_17->setRowCount(2);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));
        }
        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==24 &&  ui->comboBox_4->currentIndex()==12)
        {
            ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }
           ui->tableWidget_17->setRowCount(2);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));

        }


                            //   -----------------end of set one ------------------------------ //

        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==25 &&  ui->comboBox_4->currentIndex()==10)
        {
            ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }
           ui->tableWidget_17->setRowCount(2);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));
        }
        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==25 &&  ui->comboBox_4->currentIndex()==11)
        {
            ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }
           ui->tableWidget_17->setRowCount(2);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));
        }
        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==25 &&  ui->comboBox_4->currentIndex()==12)
        {
            ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }
           ui->tableWidget_17->setRowCount(2);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));
        }

                    //------------------------end of set two-------------------------------//


        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==26 &&  ui->comboBox_4->currentIndex()==10)
        {
               ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }

           ui->tableWidget_17->setRowCount(3);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));

                ui->tableWidget_17->setItem(2,0,new QTableWidgetItem("Wide Range Accuracy"));

        }
        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==26 &&  ui->comboBox_4->currentIndex()==11)
        {
               ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }

           ui->tableWidget_17->setRowCount(3);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));

                ui->tableWidget_17->setItem(2,0,new QTableWidgetItem("Wide Range Accuracy"));

        }
        if(ui->comboBox->currentIndex()==3 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==26 &&  ui->comboBox_4->currentIndex()==12)
        {
               ui->tabWidget_3->setCurrentIndex(0);

            ui->tableWidget_16->setColumnCount(3);
            int k = ui->spinBox->value();
            ui->tableWidget_16->setRowCount(k);
            QStringList h1;
              h1 <<"Reference value on Bore Gauge" << "Observed value on Master (DCT)"<<"Error";
           for(int h=3; h<=3 ; h++)
           {
            ui->tableWidget_16->setHorizontalHeaderLabels(h1);

           }

           ui->tableWidget_17->setRowCount(3);
            ui->tableWidget_17->setColumnCount(2);
            QStringList c1;

            c1<<"Repeatability"<<"Adjacent Error"<<"Wide Range Accuracy";


                ui->tableWidget_17->setItem(0,0,new QTableWidgetItem("Repeatability"));

                ui->tableWidget_17->setItem(1,0,new QTableWidgetItem("Adjacent Error"));

                ui->tableWidget_17->setItem(2,0,new QTableWidgetItem("Wide Range Accuracy"));

        }
//<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  END OF BORE GUAGE ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>//

//<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  COMPARATOR ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>//

        ui->label_252->setText(ui->lineEdit_1->text());
        ui->label_253->setText(ui->lineEdit_2->text());
        ui->label_254->setText(ui->lineEdit_3->text());
        ui->label_237->setText(ui->comboBox_3->currentText());
        ui->label_256->setText(ui->comboBox_4->currentText());
        ui->label_240->setText(ui->lineEdit_4->text());
        ui->label_241->setText(ui->lineEdit_5->text());
        ui->label_260->setText(ui->lineEdit_7->text());
        ui->textEdit_6->setText(ui->textEdit->toPlainText());




            if(ui->comboBox->currentIndex()==4 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==28 &&  ui->comboBox_4->currentIndex()==2)
            {
                ui->stackedWidget->setCurrentIndex(6);
                ui->tableWidget_22->setSpan(0,1,1,2);
                ui->tableWidget_22->setSpan(0,0,2,1);
                int co = ui->spinBox->value();
                int c1= co+2;
                ui->tableWidget_22->setRowCount(c1);

                ui->tableWidget_22->setItem(0,0,new QTableWidgetItem (QString("Reference value (mm)")));
                ui->tableWidget_22->setItem(0,1,new QTableWidgetItem (QString("Observed Error (µm) ")));
                ui->tableWidget_22->setItem(1,1,new QTableWidgetItem (QString(" (-Ve Side)")));
                ui->tableWidget_22->setItem(1,2,new QTableWidgetItem (QString(" (+Ve Side)")));
                ui->tableWidget_22->setItem(2,0,new QTableWidgetItem (QString("0")));
                ui->tableWidget_22->setItem(2,1,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->setItem(2,2,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->horizontalHeader()->setVisible(false);
                ui->tableWidget_22->verticalHeader()->setVisible(false);

                int hc = (37*co)+80;
                ui->tableWidget_22->setGeometry(200,1100,800,hc);
                int hw = 1100+hc+100;
                ui->scrollAreaWidgetContents_7->setGeometry(0,0,1571,hw);

                 ui->scrollAreaWidgetContents_7->setMinimumHeight(2000);
            }
            if(ui->comboBox->currentIndex()==4 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==28 &&  ui->comboBox_4->currentIndex()==13)
            {
                ui->stackedWidget->setCurrentIndex(6);
                ui->tableWidget_22->setSpan(0,1,1,2);
                ui->tableWidget_22->setSpan(0,0,2,1);
                int co = ui->spinBox->value();
                int c1= co+2;
                ui->tableWidget_22->setRowCount(c1);

                ui->tableWidget_22->setItem(0,0,new QTableWidgetItem (QString("Reference value (mm)")));
                ui->tableWidget_22->setItem(0,1,new QTableWidgetItem (QString("Observed Error (µm) ")));
                ui->tableWidget_22->setItem(1,1,new QTableWidgetItem (QString("L.H.S")));
                ui->tableWidget_22->setItem(1,2,new QTableWidgetItem (QString("R.H.S")));
                ui->tableWidget_22->setItem(2,0,new QTableWidgetItem (QString("0")));

                ui->tableWidget_22->setItem(2,1,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->setItem(2,2,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->horizontalHeader()->setVisible(false);
                ui->tableWidget_22->verticalHeader()->setVisible(false);
                int hc = (37*co)+80;
                ui->tableWidget_22->setGeometry(200,1100,800,hc);
                int hw = 1100+hc+100;
                ui->scrollAreaWidgetContents_7->setGeometry(0,0,1571,hw);

                 ui->scrollAreaWidgetContents_7->setMinimumHeight(2000);
            }


                                //   -----------------end of set one ------------------------------ //

            if(ui->comboBox->currentIndex()==4 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==29 &&  ui->comboBox_4->currentIndex()==2)
            {
                ui->stackedWidget->setCurrentIndex(6);
                ui->tableWidget_22->setSpan(0,1,1,2);
                ui->tableWidget_22->setSpan(0,0,2,1);
                int co = ui->spinBox->value();
                int c1= co+2;
                ui->tableWidget_22->setRowCount(c1);

                ui->tableWidget_22->setItem(0,0,new QTableWidgetItem (QString("Reference value (mm)")));
                ui->tableWidget_22->setItem(0,1,new QTableWidgetItem (QString("Observed Error (µm) ")));
                ui->tableWidget_22->setItem(1,1,new QTableWidgetItem (QString(" (-Ve Side)")));
                ui->tableWidget_22->setItem(1,2,new QTableWidgetItem (QString(" (+Ve Side)")));
                ui->tableWidget_22->setItem(2,0,new QTableWidgetItem (QString("0")));

                ui->tableWidget_22->setItem(2,1,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->setItem(2,2,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->horizontalHeader()->setVisible(false);
                ui->tableWidget_22->verticalHeader()->setVisible(false);
                int hc = (37*co)+80;
                ui->tableWidget_22->setGeometry(200,1100,800,hc);
                int hw = 1100+hc+100;
                ui->scrollAreaWidgetContents_7->setGeometry(0,0,1571,hw);

                 ui->scrollAreaWidgetContents_7->setMinimumHeight(2000);

            }
            if(ui->comboBox->currentIndex()==4 && ui->comboBox_2->currentIndex()==1 && ui->comboBox_3->currentIndex()==29 &&  ui->comboBox_4->currentIndex()==13)
            {
                ui->stackedWidget->setCurrentIndex(6);
                ui->tableWidget_22->setSpan(0,1,1,2);
                ui->tableWidget_22->setSpan(0,0,2,1);
               int co = ui->spinBox->value();
               int c1= co+2;
                ui->tableWidget_22->setRowCount(c1);


                ui->tableWidget_22->setItem(0,0,new QTableWidgetItem (QString("Reference value (mm)")));
                ui->tableWidget_22->setItem(0,1,new QTableWidgetItem (QString("Observed Error (µm) ")));
                ui->tableWidget_22->setItem(1,1,new QTableWidgetItem (QString("L.H.S")));
                ui->tableWidget_22->setItem(1,2,new QTableWidgetItem (QString("R.H.S")));
                ui->tableWidget_22->setItem(2,0,new QTableWidgetItem (QString("0")));

                ui->tableWidget_22->setItem(2,1,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->setItem(2,2,new QTableWidgetItem (QString("SET")));
                ui->tableWidget_22->horizontalHeader()->setVisible(false);
                ui->tableWidget_22->verticalHeader()->setVisible(false);
                int hc = (37*co)+80;
                ui->tableWidget_22->setGeometry(200,1100,1200,hc);
                int hw = 1100+hc+100;
                ui->scrollAreaWidgetContents_7->setGeometry(0,0,1571,hw);
                ui->scrollAreaWidgetContents_7->setMinimumHeight(2000);


            }

                        //------------------------end of set two-------------------------------//


  //<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ END OF COMPARATOR +++++++++++++++++++++++++++++++++++++++++++++++++>//

}
//< +++++++++++++++++++++++++++++++++++++++++++ End Main code ++++++++++++++++++++++++++++++++++++++++++

//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   PLUNGER DAIL BUTTONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//

void MCALIB::on_pushButton_5_clicked()
{
    QPrinter printer;
        printer.setPrinterName("Print");
        printer.setPageSize(QPrinter::A4);
         printer.setResolution(QPrinter::HighResolution);
        QPrintDialog dialog(&printer,this);
        if(dialog.exec() == QDialog::Rejected) return;

            QPainter painter;
           painter.setFont(QFont("times",22));
            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }
if(ui->tab->height() <= 2100)
{
    QList <QWidget *> widgets;
    widgets.append({ui->scrollAreaWidgetContents_3,ui->frame,ui->frame_3});
    for(auto widget: widgets){
        if(widget){
            if(widget->width() > 0 && widget->height() >0 ){

                ui->pushButton_4->setVisible(0);
                ui->pushButton_5->setVisible(0);
                ui->pushButton_12->setVisible(0);
                ui->pushButton_13->setVisible(0);
                ui->pushButton_26->setVisible(0);
                ui->pushButton_3->setVisible(0);
                ui->pushButton_6->setVisible(0);

                qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
                qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

                qreal scale = qMin(xscale, yscale);

                painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                                  printer.paperRect().y() + printer.pageRect().height()/4.5);

                painter.scale(scale, scale);
                painter.translate(-width()/3.95, -height()/6.5);
                widget->render(&painter);
                painter.resetTransform();
                if(widget != widgets.last())
                    printer.newPage();

        }
    }
    }

    ui->pushButton_4->setVisible(1);
    ui->pushButton_5->setVisible(1);
    ui->pushButton_12->setVisible(1);
    ui->pushButton_13->setVisible(1);
    ui->pushButton_26->setVisible(1);
    ui->pushButton_3->setVisible(1);
    ui->pushButton_6->setVisible(1);

}

    if (ui->tab->height() >= 2101)
{
QList <QWidget *> widgets;
widgets.append({ui->scrollAreaWidgetContents_3,ui->frame, ui->frame_2});
for(auto widget: widgets){
    if(widget){
        if(widget->width() > 0 && widget->height() >0 ){
            ui->pushButton_4->setVisible(0);
            ui->pushButton_5->setVisible(0);
            ui->pushButton_12->setVisible(0);
            ui->pushButton_13->setVisible(0);
            ui->pushButton_26->setVisible(0);
            ui->pushButton_3->setVisible(0);
            ui->pushButton_6->setVisible(0);


            qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
            qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

            qreal scale = qMin(xscale, yscale);

            painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                              printer.paperRect().y() + printer.pageRect().height()/4.5);

            painter.scale(scale, scale);
            painter.translate(-width()/3.95, -height()/6.5);
            widget->render(&painter);
            painter.resetTransform();
            if(widget != widgets.last())
                printer.newPage();

    }
}
}
ui->pushButton_4->setVisible(1);
ui->pushButton_5->setVisible(1);
ui->pushButton_12->setVisible(1);
ui->pushButton_13->setVisible(1);
ui->pushButton_26->setVisible(1);
ui->pushButton_3->setVisible(1);
ui->pushButton_6->setVisible(1);
}
}

void MCALIB::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
     ui->tableWidget->clearContents();
     ui->tableWidget_2->clearContents();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);
    ui->spinBox->setValue(0);


}

void MCALIB::on_pushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MCALIB::on_pushButton_12_clicked()
{

       int  i = ui->tableWidget->rowCount();



       if (i < 52  )

       {
       int k = i+2;                // ADD ROWS PAGE 2
       ui->tableWidget->setRowCount(k);
       QStringList v2;
       v2 <<"Forward Start"<< "Reverse Start" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
       for(int i=3; i<=k ; i++)
       {
       ui->tableWidget->setVerticalHeaderLabels(v2);
       }

        i = ui->tableWidget->rowCount();


       }
       int i1 = ui->tableWidget->rowCount();
        int j1 = ui->tableWidget_2->rowCount();

       if(i1>51 )
       {
           ui->frame_2->setVisible(1);
           ui->scrollAreaWidgetContents_2->setGeometry(0,-658,1554,3000);

            int y2 = j1+ i1-52;
           int k1 = y2+2;
           ui->tableWidget_2->setRowCount(k1);
           QStringList v2;
           v2 <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
           for(int i=1; i<=k1 ; i++)
           {
           ui->tableWidget_2->setVerticalHeaderLabels(v2);
           }

       }
}

void MCALIB::on_pushButton_13_clicked()
{
    int  i = ui->tableWidget->rowCount();
    int  j = ui->tableWidget_2->rowCount();


    if (i <= 52 && j ==0 )

    {
    int k = i-2;            // DELETE ROWS PAGE 2
    ui->tableWidget->setRowCount(k);
    QStringList v2;
    v2 <<"Forward Start"<< "Reverse Start" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
    for(int i=3; i<=k ; i++)
    {
    ui->tableWidget->setVerticalHeaderLabels(v2);
    }

     i = ui->tableWidget->rowCount();


    }
    int i1 = ui->tableWidget->rowCount();
     int j1 = ui->tableWidget_2->rowCount();

    if(i1>51 && j1>0 )
    {
        ui->label_89->setNum(1);
        ui->frame_2->setVisible(1);
        ui->scrollAreaWidgetContents_2->setGeometry(0,-658,1554,3000);

         int y2 = j1+ i1-52;
        int k1 = y2-2;
        ui->tableWidget_2->setRowCount(k1);
        QStringList v2;
        v2 <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
        for(int i=1; i<=k1 ; i++)
        {
        ui->tableWidget_2->setVerticalHeaderLabels(v2);
        }

    }
}

void MCALIB::on_pushButton_26_clicked()
{
    QString filename;
     filename =  QFileDialog::getOpenFileName(
                   this,
                   "Open Document",
                   QDir::currentPath(),
                   "All files (*.*) ;; Document files (*.csv *.rtf);; PNG files (*.png)");
             if( !filename.isNull() )
             {
               qDebug() << "selected file path : " <<filename.toUtf8();
             }
             QFileInfo info(filename);
             QString filename1 = info.path() + "/" + info.completeBaseName() + ".csv";
               QFile file(filename1.toUtf8());
               QFile file1(filename1.toUtf8());
               QTextStream in(&file);
               int line_count=0;
                 if(!file.open(QIODevice::ReadOnly)) {
                     QMessageBox::information(this, "error", file.errorString());
                 }
                 if(!file1.open(QIODevice::ReadOnly)) {
                     QMessageBox::information(this, "error", file1.errorString());
                 }

            QString abc[110][10];
             while(!in.atEnd())
             {
                  QString line=in.readLine();
                  QStringList line_data=line.split(",",QString::SkipEmptyParts);
                  for(int j=0;j<10;j++)
                  {
                      QString m_prop=line_data.at(j);
                     abc[line_count][j] = m_prop;
                  }
                  line_count++;
              }


//int t = ui->spinBox->value();

    for(int i = 0 ; i <52 ;i++)
    {
        for(int j= 0 ; j<10; j++)
        {
     ui->tableWidget->setItem(i,j,new QTableWidgetItem ( abc[i][j]));
     ui->tableWidget_2->setItem(i,j,new QTableWidgetItem ( abc[i+52][j]));
        }
    }
file.close();
QPen pen;
pen.setWidth(1);

 QVector<double> xval(101), yval(101);
 int k= ui->spinBox->value();
 int k1 = k+k;
 ui->customPlot->xAxis->setRange(0, k1);
 ui->customPlot->yAxis->setRange(-100, 100);
 ui->customPlot->yAxis->setOffset(10);
 int z;
 z=0;
  for (int j = 0; j<9; j++)
{
      xval[j]=j;
      yval[j] = ui->tableWidget->model()->data(ui->tableWidget->model()->index(z, j)).toDouble();
      ui->customPlot->addGraph();
      ui->customPlot->graph(z)->setPen(QPen(Qt::blue));
      ui->customPlot->graph(z)->setData(xval, yval);
      ui->customPlot->replot();

  }

  z=1;
   for (int j = 0; j<9; j++)
 {
       xval[j]=j;
       yval[j] = ui->tableWidget->model()->data(ui->tableWidget->model()->index(z, j)).toDouble();

       ui->customPlot->addGraph();
       ui->customPlot->graph(z)->setPen(QPen(Qt::red));
       ui->customPlot->graph(z)->setData(xval, yval);
       ui->customPlot->replot();

   }


}
//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  END PLUNGER DAIL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//

//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  lEVER DAIL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//

void MCALIB::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidget_3->clearContents();
    ui->tableWidget_4->clearContents();
   ui->comboBox->setCurrentIndex(0);
   ui->comboBox_2->setCurrentIndex(0);
   ui->comboBox_3->setCurrentIndex(0);
   ui->comboBox_4->setCurrentIndex(0);
   ui->spinBox->setValue(0);

}

void MCALIB::on_pushButton_7_clicked()
{
      ui->stackedWidget->setCurrentIndex(6);
}

void MCALIB::on_pushButton_17_clicked()
{
    int   i = ui->tableWidget_3->rowCount();
       int j = i+1;
       ui->tableWidget_3->setRowCount(j);
       ui->tableWidget_4->setRowCount(j);
       if(j >= 4)
       {
       QStringList v4;
       v4 <<"Forward Start"<< "Reverse End" << "1 Revolution (Forward)"<<"1 Revolution (Reverse)"<<"2 Revolution (Forward)"<<"2 Revolution (Reverse)"<<"3 Revolution (Forward)"<<"3 Revolution (Reverse)"<<"4 Revolution (Forward)"<<"4 Revolution (Reverse)"<<"5 Revolution (Forward)"<<"5 Revolution (Reverse)"<<"6 Revolution (Forward)"<<"6 Revolution (Reverse)"<<"7 Revolution (Forward)"<<"7 Revolution (Reverse)"<<"8 Revolution (Forward)"<<"8 Revolution (Reverse)"<<"9 Revolution (Forward)"<<"9 Revolution (Reverse)"<<"10 Revolution (Forward)"<<"10 Revolution (Reverse)"<<"11 Revolution (Forward)"<<"11 Revolution (Reverse)" << "12 Revolution (Forward)"<<"12 Revolution (Reverse)"<<"13 Revolution (Forward)"<<"13 Revolution (Reverse)" <<"14 Revolution (Forward)"<<"14 Revolution (Reverse)"<<"15 Revolution (Forward)"<<"15 Revolution (Reverse)" <<"16 Revolution (Forward)"<<"16 Revolution (Reverse)"<<"17 Revolution (Forward)"<<"11 Revolution (Reverse)" <<"18 Revolution (Forward)"<<"18 Revolution (Reverse)"<<"19 Revolution (Forward)"<<"19 Revolution (Reverse)" <<"20 Revolution (Forward)"<<"20 Revolution (Reverse)"<<"21 Revolution (Forward)"<<"21 Revolution (Reverse)" <<"22 Revolution (Forward)"<<"22 Revolution (Reverse)"<<"23 Revolution (Forward)"<<"23 Revolution (Reverse)" <<"24 Revolution (Forward)"<<"24 Revolution (Reverse)"<<"25 Revolution (Forward)"<<"25 Revolution (Reverse)" <<"26 Revolution (Forward)"<<"26 Revolution (Reverse)"<<"27 Revolution (Forward)"<<"27 Revolution (Reverse)" <<"28 Revolution (Forward)"<<"28 Revolution (Reverse)"<<"29 Revolution (Forward)"<<"29 Revolution (Reverse)" <<"30 Revolution (Forward)"<<"30 Revolution (Reverse)"<<"31 Revolution (Forward)"<<"31 Revolution (Reverse)" <<"32 Revolution (Forward)"<<"32 Revolution (Reverse)"<<"33 Revolution (Forward)"<<"33 Revolution (Reverse)" <<"34 Revolution (Forward)"<<"34 Revolution (Reverse)"<<"35 Revolution (Forward)"<<"35 Revolution (Reverse)" <<"36 Revolution (Forward)"<<"36 Revolution (Reverse)"<<"37 Revolution (Forward)"<<"37 Revolution (Reverse)" <<"38 Revolution (Forward)"<<"38 Revolution (Reverse)"<<"39 Revolution (Forward)"<<"39 Revolution (Reverse)" <<"40 Revolution (Forward)"<<"40 Revolution (Reverse)"<<"41 Revolution (Forward)"<<"41 Revolution (Reverse)" <<"42 Revolution (Forward)"<<"42 Revolution (Reverse)"<<"43 Revolution (Forward)"<<"43 Revolution (Reverse)" <<"44 Revolution (Forward)"<<"44 Revolution (Reverse)"<<"45 Revolution (Forward)"<<"45 Revolution (Reverse)" <<"46 Revolution (Forward)"<<"46 Revolution (Reverse)"<<"47 Revolution (Forward)"<<"47 Revolution (Reverse)" <<"48 Revolution (Forward)"<<"48 Revolution (Reverse)"<<"49 Revolution (Forward)"<<"49 Revolution (Reverse)" <<"50 Revolution (Forward)"<<"50 Revolution (Reverse)";
       for(int i=3; i<=j ; i++)
       {
           ui->tableWidget_3->setVerticalHeaderLabels(v4);
           ui->tableWidget_4->setVerticalHeaderLabels(v4);

       }
       }
       if(j <=4)
       {
       QStringList v3;
       v3 <<"Forward Start"<< "Reverse End" <<"Forward End" <<"Reverse Start";
       for(int i=3; i<=j ; i++)
       {
       ui->tableWidget_3->setVerticalHeaderLabels(v3);
       ui->tableWidget_4->setVerticalHeaderLabels(v3);

       }
       }
       int l1=30;
       int t2 =j*2;
       for(int l=0; l<=t2 ;l++)
       {
       ui->tableWidget_3->setRowHeight(l,l1);
       ui->tableWidget_4->setRowHeight(l,l1);
       }
       int s=90;
       int width = (s*14)+120;
       int height = (20*t2)+100;
       ui->tableWidget_3->setGeometry(30,90,width,height);
       int labely = 90+height+5;
       ui->textBrowser->setGeometry(200,labely,551,61);

       int textb = ui->textBrowser->y();
       int tabel4y = textb+75;
       ui->tableWidget_4->setGeometry(30,tabel4y,width,height);
       int wh = tabel4y+height+100;
       ui->scrollAreaWidgetContents_4->setGeometry(0,0,1571,wh);
}

void MCALIB::on_pushButton_18_clicked()
{
    int   i = ui->tableWidget_3->rowCount();
       int j = i-1;
       ui->tableWidget_3->setRowCount(j);
       ui->tableWidget_4->setRowCount(j);
}

void MCALIB::on_pushButton_10_clicked()
{
    QPrinter printer;
        printer.setPrinterName("Print");
        printer.setPageSize(QPrinter::A4);
         printer.setResolution(QPrinter::HighResolution);
        QPrintDialog dialog(&printer,this);
        if(dialog.exec() == QDialog::Rejected) return;

            QPainter painter;
           painter.setFont(QFont("times",22));
            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }

    QList <QWidget *> widgets;
    widgets.append({ui->scrollAreaWidgetContents_5,ui->scrollAreaWidgetContents_4});
    for(auto widget: widgets){
        if(widget){
            if(widget->width() > 0 && widget->height() >0 ){

                ui->pushButton_17->setVisible(0);
                ui->pushButton_18->setVisible(0);
                ui->pushButton_24->setVisible(0);
                ui->pushButton_6->setVisible(0);
                ui->pushButton_7->setVisible(0);
                ui->pushButton_27->setVisible(0);

                qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
                qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

                qreal scale = qMin(xscale, yscale);

                painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                                  printer.paperRect().y() + printer.pageRect().height()/3.5);

                painter.scale(scale, scale);
                painter.translate(-width()/3.9, -height()/2.5);
                widget->render(&painter);
                painter.resetTransform();
                if(widget != widgets.last())
                    printer.newPage();

        }
    }
    }
    ui->pushButton_17->setVisible(1);
    ui->pushButton_18->setVisible(1);
    ui->pushButton_24->setVisible(1);
    ui->pushButton_6->setVisible(1);
    ui->pushButton_7->setVisible(1);
    ui->pushButton_27->setVisible(1);
}

void MCALIB::on_pushButton_9_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}
//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END LEVER DAIL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//

//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  BORE DAIL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//


void MCALIB::on_pushButton_16_clicked()
{

    QPrinter printer;
        printer.setPrinterName("Print");
        printer.setPageSize(QPrinter::A4);
         printer.setResolution(QPrinter::HighResolution);
        QPrintDialog dialog(&printer,this);
        if(dialog.exec() == QDialog::Rejected) return;

            QPainter painter;
           painter.setFont(QFont("times",22));
            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }

    QList <QWidget *> widgets;
    widgets.append({ui->scrollAreaWidgetContents_6});
    for(auto widget: widgets){
        if(widget){
            if(widget->width() > 0 && widget->height() >0 ){

                ui->pushButton_17->setVisible(0);
                ui->pushButton_18->setVisible(0);
                ui->pushButton_24->setVisible(0);
                ui->pushButton_6->setVisible(0);
                ui->pushButton_7->setVisible(0);
                ui->pushButton_27->setVisible(0);

                qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
                qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

                qreal scale = qMin(xscale, yscale);

                painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                                  printer.paperRect().y() + printer.pageRect().height()/3.5);

                painter.scale(scale, scale);
                painter.translate(-width()/3.9, -height()/2.5);
                widget->render(&painter);
                painter.resetTransform();
                if(widget != widgets.last())
                    printer.newPage();

        }
    }
    }
    ui->pushButton_17->setVisible(1);
    ui->pushButton_18->setVisible(1);
    ui->pushButton_24->setVisible(1);
    ui->pushButton_6->setVisible(1);
    ui->pushButton_7->setVisible(1);
    ui->pushButton_27->setVisible(1);
}

void MCALIB::on_pushButton_15_clicked()
{
    filename =  QFileDialog::getOpenFileName(
                  this,
                  "Open Document",
                  QDir::currentPath(),
                  "All files (*.*) ;; Document files (*.csv *.rtf);; PNG files (*.png)");
            if( !filename.isNull() )
            {
              qDebug() << "selected file path : " <<filename.toUtf8();
            }
            QFileInfo info(filename);
            QString filename1 = info.path() + "/" + info.completeBaseName() + ".csv";
              QFile file(filename1.toUtf8());
              QTextStream in(&file);
              int line_count=0;
                if(!file.open(QIODevice::ReadOnly)) {
                    QMessageBox::information(0, "error", file.errorString());
                }




                while(!in.atEnd())
                             {
                                QString line=in.readLine();
                                QStringList line_data=line.split(",",QString::SkipEmptyParts);
                              for(int j=0;j<line_data.size();j++)
                              {
                                  QString m_prop=line_data.at(j);
                                  //QStandardItem *item=new QStandardItem(m_prop);  this is for tableview
                                  QTableWidgetItem *it=new QTableWidgetItem(m_prop,1002);
                                  //model->setItem(line_count,j,item);

                                  ui->tableWidget_16->setItem(line_count,j,it);

                                  // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
                             // ui->tableWidget->setItem();
                              }



                              line_count++;
                             }


                file.close();

                QPen pen;
                pen.setWidth(1);

                 QVector<double> xval(101), yval(101);
                 int k= ui->spinBox->value();
                 int k1 = k+k;
                 ui->customPlot_4->xAxis->setRange(0, k1);
                 ui->customPlot_4->yAxis->setRange(-100, 100);
                 ui->customPlot_4->yAxis->setOffset(10);
                 int z;
                 z=0;
                  for (int j = 0; j<9; j++)
                {
                      xval[j]=j;
                      yval[j] = ui->tableWidget_16->model()->data(ui->tableWidget_16->model()->index(z, j)).toDouble();
                      ui->customPlot_4->addGraph();
                      ui->customPlot_4->graph(z)->setPen(QPen(Qt::blue));
                      ui->customPlot_4->graph(z)->setData(xval, yval);
                      ui->customPlot_4->replot();

                  }

                  z=1;
                   for (int j = 0; j<9; j++)
                 {
                       xval[j]=j;
                       yval[j] = ui->tableWidget_16->model()->data(ui->tableWidget_16->model()->index(z, j)).toDouble();

                       ui->customPlot_4->addGraph();
                       ui->customPlot_4->graph(z)->setPen(QPen(Qt::red));
                       ui->customPlot_4->graph(z)->setData(xval, yval);
                       ui->customPlot_4->replot();

                   }

}

void MCALIB::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidget_3->clearContents();
    ui->tableWidget_4->clearContents();
   ui->comboBox->setCurrentIndex(0);
   ui->comboBox_2->setCurrentIndex(0);
   ui->comboBox_3->setCurrentIndex(0);
   ui->comboBox_4->setCurrentIndex(0);
   ui->spinBox->setValue(0);
}

void MCALIB::on_pushButton_19_clicked()
{

    int    i = ui->tableWidget_16->rowCount();
       int j = i+1;
       ui->tableWidget_16->setRowCount(j);
}

void MCALIB::on_pushButton_20_clicked()
{
    int i = ui->tableWidget_16->rowCount();
     int j = i-1;
     ui->tableWidget_16->setRowCount(j);
}
//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END BORE DAIL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//

//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  COMPARATOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//


void MCALIB::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidget_3->clearContents();
    ui->tableWidget_4->clearContents();
   ui->comboBox->setCurrentIndex(0);
   ui->comboBox_2->setCurrentIndex(0);
   ui->comboBox_3->setCurrentIndex(0);
   ui->comboBox_4->setCurrentIndex(0);
   ui->spinBox->setValue(0);
}

void MCALIB::on_pushButton_23_clicked()
{

    int    i = ui->tableWidget_22->rowCount();
       int j = i+1;
       ui->tableWidget_22->setRowCount(j);
}

void MCALIB::on_pushButton_24_clicked()
{

    int    i = ui->tableWidget_22->rowCount();
       int j = i-1;
       ui->tableWidget_22->setRowCount(j);
}

void MCALIB::on_import_c_2_clicked()
{
    filename =  QFileDialog::getOpenFileName(
                  this,
                  "Open Document",
                  QDir::currentPath(),
                  "All files (*.*) ;; Document files (*.csv *.rtf);; PNG files (*.png)");
            if( !filename.isNull() )
            {
              qDebug() << "selected file path : " <<filename.toUtf8();
            }
            QFileInfo info(filename);
            QString filename1 = info.path() + "/" + info.completeBaseName() + ".csv";
              QFile file(filename1.toUtf8());
              QTextStream in(&file);
              int line_count=0;
                if(!file.open(QIODevice::ReadOnly)) {
                    QMessageBox::information(0, "error", file.errorString());
                }




                while(!in.atEnd())
                             {
                                QString line=in.readLine();
                                QStringList line_data=line.split(",",QString::SkipEmptyParts);
                              for(int j=0;j<line_data.size();j++)
                              {
                                  QString m_prop=line_data.at(j);
                                  //QStandardItem *item=new QStandardItem(m_prop);  this is for tableview
                                  QTableWidgetItem *it=new QTableWidgetItem(m_prop,1002);
                                  //model->setItem(line_count,j,item);

                                  ui->tableWidget_22->setItem(line_count,j,it);

                                  // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
                             // ui->tableWidget->setItem();
                              }



                              line_count++;
                             }


                file.close();

                QPen pen;
                pen.setWidth(1);

                 QVector<double> xval(101), yval(101);
                 int k= ui->spinBox->value();
                 int k1 = k+k;
                 ui->customPlot_5->xAxis->setRange(0, k1);
                 ui->customPlot_5->yAxis->setRange(-100, 100);
                 ui->customPlot_5->yAxis->setOffset(10);
                 int z;
                 z=0;
                  for (int j = 0; j<9; j++)
                {
                      xval[j]=j;
                      yval[j] = ui->tableWidget_22->model()->data(ui->tableWidget_22->model()->index(z, j)).toDouble();
                      ui->customPlot_5->addGraph();
                      ui->customPlot_5->graph(z)->setPen(QPen(Qt::blue));
                      ui->customPlot_5->graph(z)->setData(xval, yval);
                      ui->customPlot_5->replot();

                  }

                  z=1;
                   for (int j = 0; j<9; j++)
                 {
                       xval[j]=j;
                       yval[j] = ui->tableWidget_22->model()->data(ui->tableWidget_22->model()->index(z, j)).toDouble();

                       ui->customPlot_5->addGraph();
                       ui->customPlot_5->graph(z)->setPen(QPen(Qt::red));
                       ui->customPlot_5->graph(z)->setData(xval, yval);
                       ui->customPlot_5->replot();

                   }
}

void MCALIB::on_pushButton_21_clicked()
{
    QPrinter printer;
        printer.setPrinterName("Print");
        printer.setPageSize(QPrinter::A4);
         printer.setResolution(QPrinter::HighResolution);
        QPrintDialog dialog(&printer,this);
        if(dialog.exec() == QDialog::Rejected) return;

            QPainter painter;
           painter.setFont(QFont("times",22));
            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }

    QList <QWidget *> widgets;
    widgets.append({ui->tab_7});
    for(auto widget: widgets){
        if(widget){
            if(widget->width() > 0 && widget->height() >0 ){

                ui->pushButton_12->setVisible(0);
                ui->pushButton_13->setVisible(0);
                ui->pushButton_14->setVisible(0);
                ui->pushButton_19->setVisible(0);
                ui->pushButton_20->setVisible(0);
                ui->import_c_2->setVisible(0);



                qreal xscale = 0.99*printer.pageRect().width()/qreal(widget->width());
                qreal yscale = 1.7*printer.pageRect().height()/qreal(widget->height());

                qreal scale = qMin(xscale, yscale);

                painter.translate(printer.paperRect().x() + printer.pageRect().width()/3.5,
                                  printer.paperRect().y() + printer.pageRect().height()/3.5);

                painter.scale(scale, scale);
                painter.translate(-width()/3.9, -height()/2.5);
                widget->render(&painter);
                painter.resetTransform();
                if(widget != widgets.last())
                    printer.newPage();

        }
    }
    }
    ui->pushButton_12->setVisible(1);
    ui->pushButton_13->setVisible(1);
    ui->pushButton_14->setVisible(1);
    ui->pushButton_19->setVisible(1);
    ui->pushButton_20->setVisible(1);
    ui->import_c_2->setVisible(1);
}

//<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END COMPARATOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>//


//<-------------------------------------------------------- Calculations ---------------------------------------> //

/* calculation
 *
 * part
 *
 * will
 *
 * be
 *
 * done
 *
 * here
 *
 * for
 *
 * each
 *
 * table
 *
 * and
 *
 * certificate




//<-------------------------------------------------------- End of Calculations ---------------------------------------> //
