#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QRegExp>
#include <QString>
#include <QVector>
#include <string>

#include "../controller/calc_controler.h"
#include "credit.h"
#include "qcustomplot.h"
#include "stdio.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  credit *ced;

  QVector<double> x, y;
  double xBegin, xEnd;

 public slots:
  void digNum();
  int flag();
  double grafPainter(double x);
  void grafPlot(QString *new_label);
  void clearGraf();
  void resultPrint(QString *new_label, double result);
  void backSpace();
  void on_lineEdit_editingFinished();
  void on_lineEdit_2_editingFinished();
  void result();
  void extras();
  void xbutton();

 private slots:
  void on_pushButton_35_clicked();
};
#endif  // MAINWINDOW_H
