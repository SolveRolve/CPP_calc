#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  {
    ced = new credit;
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(xbutton()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_22, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_23, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(result()));
    connect(ui->pushButton_25, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_26, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_27, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(digNum()));
    connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(backSpace()));
    connect(ui->pushButton_30, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_31, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_32, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_33, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_34, SIGNAL(clicked()), this, SLOT(extras()));
    connect(ui->pushButton_37, SIGNAL(clicked()), this, SLOT(digNum()));
  }
}

MainWindow::~MainWindow() { delete ui; }

int MainWindow::flag() {
  int len = ui->label->text().size();
  int last_operator =
      ui->label->text().lastIndexOf(QRegularExpression("[*(%^/.+-]"));
  return len == (last_operator + 1);
}

void MainWindow::digNum() {
  QPushButton* button = (QPushButton*)sender();
  QString new_label, signs_ = "/*^%e", errors = "error",
                     after_point = "-+/*^%e", nums = "1234567890";
  QString label = ui->label->text();
  int operator_index = label.lastIndexOf(QRegularExpression("[(%^.+*-//]"));
  int point_index = label.indexOf('.', operator_index);
  int flag_num = flag();
  if (errors.indexOf(label) != -1) ui->label->setText(new_label);
  if (label.length() && label.back() == 'x' && nums.contains(button->text()))
    new_label = (label + '*' + button->text());
  else if (signs_.indexOf(button->text()) != -1) {
    if (!flag())
      new_label = (label + button->text());
    else
      new_label = (label);
  } else if (button->text() == "√")
    new_label = (label + "sqrt(");

  else if (button->text() == "AC")
    clearGraf();
  else if (button->text() == "OFF")
    MainWindow::close();
  else if (button->text() == ".") {
    if (!flag_num && point_index == -1)
      new_label = (label + ".");
    else
      new_label = (label);
  } else {
    new_label = (label + button->text());
  }
  ui->label->setText(new_label);
}
void MainWindow::xbutton() {
  QPushButton* button = (QPushButton*)sender();
  QString new_label;
  int len = ui->label->text().size();
  int last_operator =
      ui->label->text().lastIndexOf(QRegularExpression("[0-9x]"));
  if (len == (last_operator + 1) && len != 0) {
    new_label = (ui->label->text() + '*' + button->text());
  } else
    new_label = (ui->label->text() + button->text());
  ui->label->setText(new_label);
}
void MainWindow::extras() {
  xbutton();
  QString new_label = (ui->label->text() + '(');
  ui->label->setText(new_label);
}
void MainWindow::result() {
  s21::BackEnd str;
  s21::calcControler call(&str);
  std::string utf8_text = ui->label->text().toUtf8().constData();
  call.setStr(&utf8_text);
  QString new_label = ui->label->text();
  clearGraf();
  if (!call.valid())
    new_label = "error";
  else if (ui->label->text().indexOf('x') != -1) {
    grafPlot(&new_label);
  } else {
    try {
      resultPrint(&new_label, call.result());
    } catch (std::invalid_argument& s) {
      new_label = "error";
    } catch (std::out_of_range& d) {
      new_label = "error";
    }
  }
  ui->label->setText(new_label);
};
double MainWindow::grafPainter(double x) {
  s21::BackEnd str_;
  double result_ = 0;
  s21::calcControler call(&str_);
  std::string new_str = '(' + std::to_string(x) + ')';
  std::string utf8_text = ui->label->text().toUtf8().constData();
  size_t start{utf8_text.find('x')};
  while (start != end_str) {
    utf8_text.replace(start, 1, new_str);
    start = utf8_text.find('x', start + new_str.length());
  }
  call.setStr(&utf8_text);
  if (call.valid()) result_ = call.result();
  return result_;
}
void MainWindow::on_lineEdit_editingFinished() {
  float x = ui->lineEdit->text().toFloat();
  ui->widget->xAxis->setRange(-x, x);
};
void MainWindow::on_lineEdit_2_editingFinished() {
  float x = ui->lineEdit_2->text().toFloat();
  ui->widget->yAxis->setRange(-x, x);
};
void MainWindow::grafPlot(QString* new_label) {
  float xs = ui->lineEdit->text().toFloat();
  double h = xs / 100;
  double f = ui->lineEdit->text().toFloat() * (-1.0);
  double ff = -f;
  float s = ui->lineEdit_3->text().toFloat();
  if (ui->lineEdit_3->text() == 'x') {
    while (f < ff) {
      f = f + h + 0.00001;
      try {
        y.push_back(grafPainter((double)f));
      } catch (std::out_of_range& d) {
        *new_label = "error";
        break;
      }
      x.push_back(f);
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    ui->widget->replot();
    if (*new_label != "error") *new_label = ui->label->text();
  } else {
    try {
      *new_label = QString::number(grafPainter(s), 'f', 6);
    } catch (std::out_of_range& d) {
      *new_label = "error";
    }
  }
}

void MainWindow::clearGraf() {
  x.clear();
  y.clear();
  ui->widget->clearGraphs();
  ui->widget->replot();
};
void MainWindow::resultPrint(QString* new_label, double result) {
  if (result > 100000000)
    *new_label = QString::number(result, 'f', 0);
  else if (result > 1000000)
    *new_label = QString::number(result, 'f', 2);
  else if (result <= 0.000001)
    *new_label = QString::number(result, 'f', 9);
  else
    *new_label = QString::number(result, 'f', 6);
};
void MainWindow::backSpace() {
  QString new_label = (ui->label->text());
  int len = new_label.size();
  int len_chop = new_label.lastIndexOf(QRegularExpression("[-+*)%^/]"));
  new_label.chop(len - len_chop - 1);
  if ((len - len_chop - 1) == 0) new_label.chop(1);
  ui->label->setText(new_label);
};
void MainWindow::on_pushButton_35_clicked() { ced->show(); };
