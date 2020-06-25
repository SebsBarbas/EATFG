#include "affichage.h"
#include "parameterlimits.h"
#include "start.h"
#include "ui_affichage.h"
#include "changetypes.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

Affichage::Affichage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Affichage)
{
    ui->setupUi(this);
    oldskinthickness=0;
    oldperiduralthickness=0;
    oldefyellowligamentver=0;
    oldefinterspinalver=0;
    oldefyellowligamentel=0;
    oldefinterspinalel=0;

}

Affichage::~Affichage()
{
    delete ui;
}

void Affichage::on_pushButton_clicked()
{
    Start *p=new Start();
    p->show();
    destroy();
}

void Affichage::on_pushButton_3_clicked()
{
        QString str1=ui->doubleSpinBox->text();
        QString str2=ui->doubleSpinBox_2->text();
        QString str3=ui->doubleSpinBox_3->text();
        QString str4=ui->doubleSpinBox_4->text();
        QString str5=ui->doubleSpinBox_5->text();
        QString str6=ui->doubleSpinBox_6->text();
        float val1;
        float val2=str2.toFloat();
        float val3=str3.toFloat();
        float val4=str4.toFloat();
        float val5=str5.toFloat();
        float val6=str6.toFloat();
        int send=0;
        char to_send[8];
        //QString str1=ui->doubleSpinBox->text();
        //val1=ui->doubleSpinBox->value();
        val1=str1.toFloat();
        //val7=str2.toFloat();
        //val2=ui->doubleSpinBox_2->value();
        //val3=ui->doubleSpinBox_3->value();
        //val4=ui->doubleSpinBox_4->value();
        //val5=ui->doubleSpinBox_5->value();
        //val6=ui->doubleSpinBox_6->value();*/
 ui->label_10->setText(ui->comboBox->currentText());
      if((ui->comboBox->currentText())==QString("Classique")){
             ui->label_11->setText(QString("Prueba Cla"));
            if((val1<MAX_CLAS_PROF_SKIN && val1>MIN_CLAS_PROF_SKIN) && (val2<MAX_CLAS_PROF_PERI && val2>MIN_CLAS_PROF_PERI) && (val3<MAX_CLAS_EF_JAUNE_VER && val3>MIN_CLAS_EF_JAUNE_VER) && (val4<MAX_CLAS_EF_INTER_VER && val4>MIN_CLAS_EF_INTER_VER) && (val5<MAX_CLAS_EF_JAUNE && val5>MIN_CLAS_EF_JAUNE) && (val6<MAX_CLAS_EF_INTER && val6>MIN_CLAS_EF_INTER)){
            //if(val1>1 && val1<2 && val2>6 && val2<8 && val3>12 && val3<14 && val4>8 && val4<9 && val5>12 && val5<14 && val6>10 && val6<11){
                skinthickness=val1;
                periduralthickness=val2;
                efyellowligamentver=val3;
                efinterspinalver=val4;
                efyellowligamentel=val5;
                efinterspinalel=val6;
                val6=val1*val2;
                ui->doubleSpinBox_6->setValue(val6);


                if((oldskinthickness!=skinthickness) || (oldperiduralthickness!=periduralthickness) || (oldefyellowligamentver!=efyellowligamentver) || (oldefinterspinalver!=efinterspinalver) || (oldefinterspinalel!=efinterspinalel) || (oldefyellowligamentel!=efyellowligamentel)){
                send=1;
                ui->label_14->setText(QString("Valeurs en train de s'afficher"));
                }
                else
                  ui->label_14->setText(QString("Valeurs affichés"));
            }
            else{
                ui->label_14->setText(QString("Erreur dans les valeurs donnés, verifier s'ils sont correctes"));
                if(val1<MIN_CLAS_PROF_SKIN || val1>MAX_CLAS_PROF_SKIN)
                    ui->label_3->setText(QString("Erreur"));
                if(val2<MIN_CLAS_PROF_PERI || val2>MAX_CLAS_PROF_PERI)
                    ui->label_5->setText(QString("Erreur"));
                if(val3<MIN_CLAS_EF_JAUNE_VER || val3>MAX_CLAS_EF_JAUNE_VER)
                    ui->label_7->setText(QString("Erreur "));
                if(val4<MIN_CLAS_EF_INTER_VER || val4>MAX_CLAS_EF_INTER_VER)
                    ui->label_9->setText(QString("Erreur"));
                if(val5<MIN_CLAS_EF_JAUNE || val5>MAX_CLAS_EF_JAUNE)
                    ui->label_11->setText(QString("Erreur"));
                if(val6<MIN_CLAS_EF_INTER || val6>MAX_CLAS_EF_INTER)
                    ui->label_13->setText(QString("Erreur"));
            }
      }
        if(ui->comboBox->currentText()==QString("Obese")){
               ui->label_11->setText(QString("Prueba Ob"));
            if((val1<MAX_OB_PROF_SKIN && val1>MIN_OB_PROF_SKIN) && (val2<MAX_OB_PROF_PERI && val2>MIN_CLAS_PROF_PERI) && (val3<MAX_OB_EF_JAUNE_VER && val3>MIN_OB_EF_JAUNE_VER) && (val4<MAX_OB_EF_INTER_VER && val4>MIN_OB_EF_INTER_VER) && (val5<MAX_OB_EF_JAUNE && val5>MIN_OB_EF_JAUNE) && (val6<MAX_OB_EF_INTER && val6>MIN_OB_EF_INTER)){
                skinthickness=val1;
                periduralthickness=val2;
                efyellowligamentver=val3;
                efinterspinalver=val4;
                efyellowligamentel=val5;
                efinterspinalel=val6;

               if((oldskinthickness!=skinthickness) || (oldperiduralthickness!=periduralthickness) || (oldefyellowligamentver!=efyellowligamentver) || (oldefinterspinalver!=efinterspinalver) || (oldefinterspinalel!=efinterspinalel) || (oldefyellowligamentel!=efyellowligamentel)){
                send=1;
                ui->label_14->setText(QString("Valeurs en train de s'afficher"));
                }
                else
                  ui->label_14->setText(QString("Valeurs affichés"));
            }
            else{
                ui->label_14->setText(QString("Erreur dans les valeurs donnés, verifier s'ils sont correctes"));
                if(val1<MIN_OB_PROF_SKIN || val1>MAX_OB_PROF_SKIN)
                    ui->label_3->setText(QString("Erreur"));
                if(val2<MIN_OB_PROF_PERI || val2>MAX_OB_PROF_PERI)
                     ui->label_5->setText(QString("Erreur"));
                if(val3<MIN_OB_EF_JAUNE_VER || val3>MAX_OB_EF_JAUNE_VER)
                    ui->label_7->setText(QString("Erreur "));
                if(val4<MIN_OB_EF_INTER_VER || val4>MAX_OB_EF_INTER_VER)
                    ui->label_9->setText(QString("Erreur"));
                if(val5<MIN_OB_EF_JAUNE || val5>MAX_OB_EF_JAUNE)
                    ui->label_11->setText(QString("Erreur"));
                if(val6<MIN_OB_EF_INTER || val6>MAX_OB_EF_INTER)
                    ui->label_13->setText(QString("Erreur"));
            }
        }

        if(ui->comboBox->currentText()==QString("Calcifie")){
               ui->label_11->setText(QString("Prueba Cal"));
            if((val1<MAX_CAL_PROF_SKIN && val1>MIN_CAL_PROF_SKIN) && (val2<MAX_CAL_PROF_PERI && val2>MIN_CAL_PROF_PERI) && (val3<MAX_CAL_EF_JAUNE_VER && val3>MIN_CAL_EF_JAUNE_VER) && (val4<MAX_CAL_EF_INTER_VER && val4>MIN_CAL_EF_INTER_VER) && (val5<MAX_CAL_EF_JAUNE && val5>MIN_CAL_EF_JAUNE) && (val6<MAX_CAL_EF_INTER && val6>MIN_CAL_EF_INTER)){
                skinthickness=val1;
                periduralthickness=val2;
                efyellowligamentver=val3;
                efinterspinalver=val4;
                efyellowligamentel=val5;
                efinterspinalel=val6;
                 if((oldskinthickness!=skinthickness) || (oldperiduralthickness!=periduralthickness) || (oldefyellowligamentver!=efyellowligamentver) || (oldefinterspinalver!=efinterspinalver) || (oldefinterspinalel!=efinterspinalel) || (oldefyellowligamentel!=efyellowligamentel)){
                send=1;
                ui->label_14->setText(QString("Valeurs en train de s'afficher"));
                }
                else
                  ui->label_14->setText(QString("Valeurs affichés"));

            }
            else{
                ui->label_14->setText(QString("Erreur dans les valeurs donnés, verifier s'ils sont correctes"));
                if(val1<MIN_CAL_PROF_SKIN || val1>MAX_CAL_PROF_SKIN)
                    ui->label_3->setText(QString("Erreur"));
                if(val2<MIN_CAL_PROF_PERI || val2>MAX_CAL_PROF_PERI)
                     ui->label_5->setText(QString("Erreur"));
                if(val3<MIN_CAL_EF_JAUNE_VER || val3>MAX_CAL_EF_JAUNE_VER)
                    ui->label_7->setText(QString("Erreur "));
                if(val4<MIN_CAL_EF_INTER_VER || val4>MAX_CAL_EF_INTER_VER)
                    ui->label_9->setText(QString("Erreur"));
                if(val5<MIN_CAL_EF_JAUNE || val5>MAX_CAL_EF_JAUNE)
                   ui->label_11->setText(QString("Erreur"));
                if(val6<MIN_CAL_EF_INTER || val6>MAX_CAL_EF_INTER)
                    ui->label_13->setText(QString("Erreur"));
            }
        }

        if(ui->comboBox->currentText()==QString("Custom")){
               ui->label_11->setText(QString("Prueba Cus"));
            if((val1<MAX_CUST_PROF_SKIN && val1>MIN_CUST_PROF_SKIN) && (val2<MAX_CUST_PROF_PERI && val2>MIN_CUST_PROF_PERI) && (val3<MAX_CUST_EF_JAUNE_VER && val3>MIN_CUST_EF_JAUNE_VER) && (val4<MAX_CUST_EF_INTER_VER && val4>MIN_CUST_EF_INTER_VER) && (val5<MAX_CUST_EF_JAUNE && val5>MIN_CUST_EF_JAUNE) && (val6<MAX_CUST_EF_INTER && val6>MIN_CUST_EF_INTER)){
                skinthickness=val1;
                periduralthickness=val2;
                efyellowligamentver=val3;
                efinterspinalver=val4;
                efyellowligamentel=val5;
                efinterspinalel=val6;

                if((oldskinthickness!=skinthickness) || (oldperiduralthickness!=periduralthickness) || (oldefyellowligamentver!=efyellowligamentver) || (oldefinterspinalver!=efinterspinalver) || (oldefinterspinalel!=efinterspinalel) || (oldefyellowligamentel!=efyellowligamentel)){
                send=1;
                ui->label_14->setText(QString("Valeurs en train de s'afficher"));
                }
                else
                  ui->label_14->setText(QString("Valeurs affichés"));

            }
            else{
               ui->label_14->setText(QString("Erreur dans les valeurs donnés, verifier s'ils sont correctes"));
               if(val1<MIN_CUST_PROF_SKIN || val1>MAX_CUST_PROF_SKIN)
                    ui->label_3->setText(QString("Erreur"));
                if(val2<MIN_CUST_PROF_PERI || val2>MAX_CUST_PROF_PERI)
                     ui->label_5->setText(QString("Erreur"));
                if(val3<MIN_CUST_EF_JAUNE_VER || val3>MAX_CUST_EF_JAUNE_VER)
                    ui->label_7->setText(QString("Erreur "));
                if(val4<MIN_CUST_EF_INTER_VER || val4>MAX_CUST_EF_INTER_VER)
                    ui->label_9->setText(QString("Erreur"));
                if(val5<MIN_CUST_EF_JAUNE || val5>MAX_CUST_EF_JAUNE)
                    ui->label_11->setText(QString("Erreur"));
                if(val6<MIN_CUST_EF_INTER || val6>MAX_CUST_EF_INTER)
                    ui->label_13->setText(QString("Erreur"));
            }
        }
        //Now we are going to send the values with our pipe to the main program

    /*if(send==1 && tuberia>=0){
        passtochar(skinthickness, to_send);
        write(tuberia,to_send,7);
        read(tuberia,to_send,2);
        passtochar(periduralthickness, to_send);
        write(tuberia,to_send,7);
        read(tuberia,to_send,2);
        passtochar(efyellowligamentver,to_send);
        write(tuberia,to_send,7);
        read(tuberia,to_send,2);
        passtochar(efinterspinalver,to_send);
        write(tuberia,to_send,7);
        read(tuberia,to_send,2);
        passtochar(efyellowligamentel,to_send);
        write(tuberia,to_send,7);
        read(tuberia,to_send,2);
        passtochar(efinterspinalel,to_send);
        write(tuberia,to_send,7);
        read(tuberia,to_send,2);
         StaticText3->SetLabel(wxString::Format("Valeurs affichés"));
        send=0;
    }
        //str1=TextCtrl1->GetValue();
       // str2=TextCtrl2->GetValue();
        str1.ToDouble(&val1);
        str2.ToDouble(&val2);
        if(val1<=0 || val2<=0){
            wxMessageBox("Erreur, les valuers doivent être mailleur qu'un");
        StaticText3->SetLabel(wxString::Format(" "));
        }*/

       // else{
           // StaticText3->SetLabel(wxString::Format("Valeurs affichés"));
       // }
        printf("%lf \n", skinthickness);
        printf("%lf \n", periduralthickness);
        printf("%lf \n", efyellowligamentver);
        printf("%lf \n", efinterspinalver);
        printf("%lf \n", efyellowligamentel);
        printf("%lf \n", efinterspinalel);
}
           // }
//}

void Affichage::on_comboBox_activated(int index)
{
        char sk_th_ch[10];
        char per_th_ch[10];
        char yel_ef_ver[10];
        char int_ef_ver[10];
        char yel_ef_el[10];
        char int_ef_el[10];
        char sliderchar[5];

        readcombo=ui->comboBox->currentText();
        srand(time(NULL));

        if(readcombo==QString("Classique")){


            skinthickness=rand()%101*0.01+1;
            periduralthickness=6+rand()%201*0.01;
            efyellowligamentver=12+rand()%201*0.01;
            efinterspinalver=8+rand()%101*0.01;
            efyellowligamentel=12+rand()%201*0.01;
            efinterspinalel=10+rand()%101*0.01;


           /* passtochar(skinthickness, sk_th_ch);
            passtochar(periduralthickness, per_th_ch);
            passtochar(efyellowligamentver, yel_ef_ver);
            passtochar(efinterspinalver, int_ef_ver);
            passtochar(efyellowligamentel, yel_ef_el);
            passtochar(efinterspinalel, int_ef_el);*/

            ui->doubleSpinBox->setValue(skinthickness);
            ui->doubleSpinBox_2->setValue(periduralthickness);
            ui->doubleSpinBox_3->setValue(efyellowligamentver);
            ui->doubleSpinBox_4->setValue(efinterspinalver);
            ui->doubleSpinBox_5->setValue(efyellowligamentel);
            ui->doubleSpinBox_6->setValue(efinterspinalel);

           // Slider1->SetRange(0,50);

            ui->label_3->setText(QString("Valeurs d'epaisseur du peau doit être entre 1 et 2 cm"));
            ui->label_5->setText(QString("Valeurs d'epaisseur du espace épidural doivent  être entre 6 et 8 mm"));
            ui->label_7->setText(QString("Valeurs d'effort du ligament jaune pour le vérin doit être entre 12N et 14 N "));
            ui->label_9->setText(QString("Valeurs d'effort interépinal pour le vérin doit être entre 8N et 9N"));
            ui->label_11->setText(QString("Valeurs d'effort du ligament jaune de l'interface électrique doit être entre 12N et 14N"));
            ui->label_13->setText(QString("Valeurs d'effort interépinal pour l'interface électrique doit être entre 10N et 11N"));
           //Add here the slider
        }
        else if(readcombo==QString("Obese")){


            skinthickness=rand()%131*0.01+3;
            periduralthickness=5+rand()%201*0.01;
            efyellowligamentver=13+rand()%201*0.01;
            efinterspinalver=8+rand()%101*0.01;
            efyellowligamentel=13+rand()%201*0.01;
            efinterspinalel=8+rand()%101*0.01;


           /* passtochar(skinthickness, sk_th_ch);
            passtochar(periduralthickness, per_th_ch);
            passtochar(efyellowligamentver, yel_ef_ver);
            passtochar(efinterspinalver, int_ef_ver);
            passtochar(efyellowligamentel, yel_ef_el);
            passtochar(efinterspinalel, int_ef_el);*/

            ui->doubleSpinBox->setValue(skinthickness);
            ui->doubleSpinBox_2->setValue(periduralthickness);
            ui->doubleSpinBox_3->setValue(efyellowligamentver);
            ui->doubleSpinBox_4->setValue(efinterspinalver);
            ui->doubleSpinBox_5->setValue(efyellowligamentel);
            ui->doubleSpinBox_6->setValue(efinterspinalel);

            //Slider1->SetRange(10,60);

            ui->label_3->setText(QString("Valeurs d'epaisseur du peau doit être entre 3 et 4.3 cm"));
            ui->label_5->setText(QString("Valeurs d'epaisseur du espace épidural doivent  être entre 5 et 7 mm"));
            ui->label_7->setText(QString("Valeurs d'effort du ligament jaune pour le vérin doit être entre 13N et 15 N "));
            ui->label_9->setText(QString("Valeurs d'effort interépinal pour le vérin doit être entre 8N et 9N"));
            ui->label_11->setText(QString("Valeurs d'effort du ligament jaune de l'interface électrique doit être entre 13N et 15N"));
            ui->label_13->setText(QString("Valeurs d'effort interépinal pour l'interface électrique doit être entre 10N et 11N"));

        }
        else if(readcombo==QString("Calcifie")){

            skinthickness=rand()%201*0.01+1;
            periduralthickness=4+rand()%301*0.01;
            efyellowligamentver=16+rand()%201*0.01;
            efinterspinalver=9+rand()%101*0.01;
            efyellowligamentel=16+rand()%201*0.01;
            efinterspinalel=11+rand()%101*0.01;


          /*  passtochar(skinthickness, sk_th_ch);
            passtochar(periduralthickness, per_th_ch);
            passtochar(efyellowligamentver, yel_ef_ver);
            passtochar(efinterspinalver, int_ef_ver);
            passtochar(efyellowligamentel, yel_ef_el);
            passtochar(efinterspinalel, int_ef_el);*/

            ui->doubleSpinBox->setValue(skinthickness);
            ui->doubleSpinBox_2->setValue(periduralthickness);
            ui->doubleSpinBox_3->setValue(efyellowligamentver);
            ui->doubleSpinBox_4->setValue(efinterspinalver);
            ui->doubleSpinBox_5->setValue(efyellowligamentel);
            ui->doubleSpinBox_6->setValue(efinterspinalel);


            ui->label_3->setText(QString("Valeurs d'epaisseur du peau doit être entre 1 et 3 cm"));
            ui->label_5->setText(QString("Valeurs d'epaisseur du espace épidural doivent  être entre 4 et 7 mm"));
            ui->label_7->setText(QString("Valeurs d'effort du ligament jaune pour le vérin doit être entre 16N et 18 N "));
            ui->label_9->setText(QString("Valeurs d'effort interépinal pour le vérin doit être entre 9N et 10N"));
            ui->label_11->setText(QString("Valeurs d'effort du ligament jaune de l'interface électrique doit être entre 16N et 18N"));
            ui->label_13->setText(QString("Valeurs d'effort interépinal pour l'interface électrique doit être entre 11N et 12N"));

        }
        else if(readcombo==QString("Custom")){

            skinthickness=rand()%331*0.01+1;
            periduralthickness=5+rand()%301*0.01;
            efyellowligamentver=12+rand()%601*0.01;
            efinterspinalver=8+rand()%201*0.01;
            efyellowligamentel=12+rand()%601*0.01;
            efinterspinalel=10+rand()%201*0.01;

            /*passtochar(skinthickness, sk_th_ch);
            passtochar(periduralthickness, per_th_ch);
            passtochar(efyellowligamentver, yel_ef_ver);
            passtochar(efinterspinalver, int_ef_ver);
            passtochar(efyellowligamentel, yel_ef_el);
            passtochar(efinterspinalel, int_ef_el);*/

            ui->doubleSpinBox->setValue(skinthickness);
            ui->doubleSpinBox_2->setValue(periduralthickness);
            ui->doubleSpinBox_3->setValue(efyellowligamentver);
            ui->doubleSpinBox_4->setValue(efinterspinalver);
            ui->doubleSpinBox_5->setValue(efyellowligamentel);
            ui->doubleSpinBox_6->setValue(efinterspinalel);


            ui->label_3->setText(QString("Valeurs d'epaisseur du peau doit être entre 1 et 4.3 cm"));
            ui->label_5->setText(QString("Valeurs d'epaisseur du espace épidural doivent  être entre 5 et 8 mm"));
            ui->label_7->setText(QString("Valeurs d'effort du ligament jaune pour le vérin doit être entre 12N et 18 N "));
            ui->label_9->setText(QString("Valeurs d'effort interépinal pour le vérin doit être entre 8N et 10N"));
            ui->label_11->setText(QString("Valeurs d'effort du ligament jaune de l'interface électrique doit être entre 12N et 18N"));
            ui->label_13->setText(QString("Valeurs d'effort interépinal pour l'interface électrique doit être entre 10N et 12N"));

        }
        //Now I have to find a way of making the wxString into a char string.
        //ALSO, the doubles I have created have to be part of the private class of Afficheur.cpp, as they need to be available for all the other methods.


}
