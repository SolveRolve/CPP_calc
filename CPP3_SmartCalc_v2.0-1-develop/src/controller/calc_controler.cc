#include "calc_controler.h"

double s21::calcControler::result() {
  back->stringReduction();
  back->BackPolishNotation();
  back->calculation();
  return back->getResult();
}