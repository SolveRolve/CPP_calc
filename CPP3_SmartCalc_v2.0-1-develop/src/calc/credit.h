#ifndef CREDIT_H
#define CREDIT_H

#include <QTableWidget>
#include <QWidget>

namespace Ui {
class credit;
}

class credit : public QWidget {
  Q_OBJECT

 public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

 private slots:
  void on_pushButton_2_clicked();
  void annuetCredit();
  void diffCredit();
  void on_pushButton_clicked();

 private:
  Ui::credit *ui;
  QTableWidget *table;
};

#endif  // CREDIT_H
