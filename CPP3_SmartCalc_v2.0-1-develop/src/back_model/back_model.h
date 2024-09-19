#include <math.h>

#include <array>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define curr_chr str->at(i)
#define prev_chr str->at(i - 1)
#define space_() \
  if (red_std.back() != ' ') red_std += ' '
#define new_char Stack.top(), Stack.pop()
#define end_str std::string::npos

namespace s21 {
class BackEnd {
  std::string* str;
  double result;

 public:
  BackEnd() : str(new std::string){};
  BackEnd(std::string s) {
    str = new std::string;
    *str = s;
  };
  int validation();
  void stringReduction();
  void BackPolishNotation();
  void calculation();
  void unarns();
  int bracket();
  int signsValid();
  double getResult() { return result; };
  std::string* getString() { return str; }
  void setStr(std::string* in) { str = in; };
};
}; 