#include "../back_model/back_model.h"

namespace s21 {
class calcControler {
 private:
  s21::BackEnd *back;

 public:
  calcControler(s21::BackEnd *b) : back(b){};
  bool valid() { return back->validation(); };
  void setStr(std::string *input) { back->setStr(input); }
  double result();
};
}; 