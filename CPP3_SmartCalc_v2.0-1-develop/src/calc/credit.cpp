#include "credit.h"
#include "ui_credit.h"
#include "math.h"

credit::credit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::credit)
{
    ui->setupUi(this);

}

credit::~credit()
{
    delete ui;
}




void credit::on_pushButton_2_clicked()
{
    table = new QTableWidget(100,3,this);
    table->setGeometry(QRect(5, 150, 300, 200));
    table->setColumnCount(3);
    QStringList horzHeaders;
    horzHeaders << "ежемесячный платеж" << "переплата по кредиту" << "общая выплата";//ежемесячный платеж, переплата по кредиту, общая выплата
    table->setHorizontalHeaderLabels(horzHeaders);
    annuetCredit();
    table->show();
}

void credit::annuetCredit(){
   int sum = ui->spinBox->value();
   double percent  = (double)ui->spinBox_2->value()/1200;
   int  col_month = ui->spinBox_3->value()*12;
   double result =  sum * (
               (percent)/
                   (1-pow((1+percent),(-col_month))
                   )
               );
   double perp = (result*col_month-sum)/col_month;
   table->setRowCount(col_month);
    double vaplata = result;
   for( int row = 0 ; row < col_month; row++){
       QTableWidgetItem* result_ = new QTableWidgetItem();
       QTableWidgetItem* perp_ = new QTableWidgetItem();
       QTableWidgetItem* sum_ = new QTableWidgetItem();
            result_->setText(QString::number(result));
            table->setItem(row,0,result_);
            perp_->setText(QString::number(perp));
            table->setItem(row,1,perp_);
            sum_->setText(QString::number(vaplata));
            table->setItem(row,2,sum_);
            vaplata+=result;
         }
}

void credit::on_pushButton_clicked()
{
    table = new QTableWidget(100,3,this);
    table->setGeometry(QRect(5, 150, 300, 200));
    table->setColumnCount(3);
    QStringList horzHeaders;
    horzHeaders << "ежемесячный платеж" << "переплата по кредиту" << "общая выплата";//ежемесячный платеж, переплата по кредиту, общая выплата
    table->setHorizontalHeaderLabels(horzHeaders);
diffCredit();
    table->show();
}
void credit::diffCredit(){
    int sum = ui->spinBox->value();
    double percent  = (double)ui->spinBox_2->value()/1200;
    int  col_month = ui->spinBox_3->value()*12;
    double result = 0;
    double perp = 0;
    double vaplata = 0;
    table->setRowCount(col_month);
    for( int row = 0 ; row < col_month; row++){
        perp = sum - (sum/col_month)*(row);
        result = sum/col_month + perp*(percent);
        QTableWidgetItem* result_ = new QTableWidgetItem();
        QTableWidgetItem* perp_ = new QTableWidgetItem();
        QTableWidgetItem* sum_ = new QTableWidgetItem();
             result_->setText(QString::number(result));
             table->setItem(row,0,result_);
             perp_->setText(QString::number(perp*percent));
             table->setItem(row,1,perp_);
             vaplata+=result;
             sum_->setText(QString::number(vaplata));
             table->setItem(row,2,sum_);

          }


}


