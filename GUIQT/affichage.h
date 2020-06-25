#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QWidget>

namespace Ui {
class Affichage;
}

class Affichage : public QWidget
{
    Q_OBJECT

public:
    explicit Affichage(QWidget *parent = 0);
    ~Affichage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(int index);

private:
    float skinthickness,periduralthickness,efyellowligamentver, efinterspinalver, efyellowligamentel,efinterspinalel;
    float oldskinthickness, oldperiduralthickness, oldefyellowligamentver, oldefinterspinalver, oldefyellowligamentel, oldefinterspinalel;
    QString readcombo;
    Ui::Affichage *ui;
};

#endif // AFFICHAGE_H
