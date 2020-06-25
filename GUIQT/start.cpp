#include "start.h"
#include "affichage.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_clicked()
{
   Affichage *p=new Affichage();
   p->show();
   destroy();
}
