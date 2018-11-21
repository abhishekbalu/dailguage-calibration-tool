#ifndef MCALIB_H
#define MCALIB_H

#include <QMainWindow>
#include<QUndoStack>


namespace Ui {
class MCALIB;
}

class MCALIB : public QMainWindow
{
    Q_OBJECT

public:
     QString filename ;
    explicit MCALIB(QWidget *parent = nullptr);
    ~MCALIB();

private slots:

    void on_action_NEW_triggered();

    void on_action_Open_triggered();

    void on_action_Save_As_triggered();

    void on_action_Save_triggered();

    void on_action_Print_triggered();

    void on_action_Exit_triggered();

    void on_action_Cut_triggered();

    void on_action_Copy_triggered();

    void on_action_Paste_triggered();

    void on_action_Add_Row_triggered();

    void on_action_Delete_Row_triggered();

    void on_action_Import_triggered();

    void on_action_To_CSV_triggered();

    void on_action_To_TXT_triggered();

    void on_action_To_XLSX_triggered();

    void on_action_Clear_Table_triggered();

    void on_action_Delete_triggered();

    void on_action_Locate_triggered();

    void on_action_Replace_triggered();

    void on_action_Add_Table_triggered();

    void on_action_Delete_Table_triggered();

    void on_action_Switch_Tab_triggered();

    void on_action_About_triggered();

    void on_action_About_Metrics_triggered();

    void on_action_Technical_Support_triggered();

    void on_action_Version_triggered();

    void on_action_System_Information_triggered();

    void on_action_Add_Page_triggered();

    void on_action_Main_Toolbar_triggered();

    void on_pushButton_clicked();
    void Calibtable();

    void Calibtable1();

    void on_pushButton_24_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_26_clicked();


    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

  //  void on_pushButton_25_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

 //   void on_pushButton_28_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_import_c_2_clicked();

    void on_pushButton_21_clicked();

private:
    Ui::MCALIB *ui;
};

#endif // MCALIB_H
