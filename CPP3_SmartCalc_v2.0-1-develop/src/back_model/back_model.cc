#include "back_model.h"
int s21::BackEnd::signsValid() {
  std::string signs = "+-/*%^e.";
  std::string nums = "0123456789x";
  std::string signs_after = "/*%^.";
  std::string signs_1 = "(";
  std::string signs_2 = "/*%^";
  int valid = 1;
  for (long unsigned int i = 0; i != this->str->length() && valid; i++) {
    if (i && (signs_after.find(curr_chr) != end_str) &&
        (signs.find(prev_chr) != end_str))
      valid = 0;
    else if (i && (signs_2.find(curr_chr) != end_str) &&
             (signs_1.find(prev_chr) != end_str)) {
      valid = 0;
    } else if (i && prev_chr == '.' && curr_chr == '(')
      valid = 0;
    else if (i && prev_chr == ')' && curr_chr == '.')
      valid = 0;
    else if (i && curr_chr == '.' && nums.find(prev_chr) == std::string::npos)
      valid = 0;
    else if (i && prev_chr == '.' && nums.find(curr_chr) == std::string::npos)
      valid = 0;
  }
  if (signs.find(this->str->back()) != end_str) valid = 0;
  if (this->str->find("inf") != std::string::npos) valid = 0;
  if (this->str->find("error") != std::string::npos) valid = 0;

  return valid;  // s21Matrix s(1,1),x(std::move(s))
}
int s21::BackEnd::bracket() {
  std::stack<char> Stack;
  int err = 0;
  for (long unsigned int i = 0; i != this->str->length() && !err; i++) {
    if ((curr_chr == ')' && Stack.empty()) == 1)
      err = 1;
    else if (curr_chr == '(')
      Stack.push('(');
    else if (curr_chr == ')' && !Stack.empty()) {
      int back_bracket = 0;
      back_bracket = new_char;
      if (back_bracket != '(') err = 1;
    }
  }

  if (!Stack.empty()) err = 1;
  return err;
}
int s21::BackEnd::validation() {
  std::size_t found = this->str->find("()");
  return (found != end_str) || !signsValid() || bracket() || !str->length() ? 0
                                                                            : 1;
};
void s21::BackEnd::stringReduction() {
  std::string substrings[10] = {"acos", "asin", "atan", "cos", "sin",
                                "tan",  "sqrt", "ln",   "log"};
  std::string new_str[10] = {"A", "n", "y", "c", "s", "t", "q", "l", "g"};
  if (this->str[0] == "-" || this->str[0] == "+")
    this->str->insert(this->str->begin(), '0');
  for (int i = 0; i < 9; i++) {
    size_t start = {this->str->find(substrings[i])};
    while (start != end_str) {
      this->str->replace(start, substrings[i].length(), new_str[i]);
      start = this->str->find(substrings[i], start + new_str[i].length());
    }
  }
  this->unarns();
};
void s21::BackEnd::unarns() {
  std::string tmp;
  std::string nums = "1234567890.)";
  for (long unsigned int i = 0; i != this->str->length(); i++) {
    if ((curr_chr == '-' || curr_chr == '+') &&
        nums.find(tmp.back()) == end_str && tmp.back() != 'e') {
      tmp += '0';
      tmp += curr_chr;
    } else
      tmp += curr_chr;
  }
  *this->str = tmp;
}
int priority(char sign) {
  int priority = -1;
  if (sign == '(')
    priority = 0;
  else if (sign == ')')
    priority = 1;
  else if (sign == '+' || sign == '-')
    priority = 2;
  else if (sign == '*' || sign == '/' || sign == '%')
    priority = 3;
  else if ((sign >= 97 && sign <= 122) || (sign >= 65 && sign <= 90))
    priority = 5;
  else if (sign == '^')
    priority = 4;
  return priority;
}
void s21::BackEnd::BackPolishNotation() {
  std::stack<char> Stack;
  std::string red_std;
  std::string nums = "1234567890.xe";

  for (long unsigned int i = 0; i != this->str->length(); i++) {
    if (nums.find(curr_chr) == end_str && red_std.back() != ' ' &&
        red_std.length())
      red_std += ' ';
    if (nums.find(curr_chr) != end_str) {
      red_std += curr_chr;
      if (curr_chr == 'e') {
        red_std += str->at(++i);
      }
    } else if (curr_chr == '(')
      Stack.push('(');
    else if (curr_chr == ')') {
      while (Stack.top() != '(') {
        space_();
        red_std += new_char;
      }
      Stack.pop();
    } else if (Stack.empty() || priority(Stack.top()) < priority(curr_chr))
      Stack.push(curr_chr);
    else {
      while (priority(Stack.top()) >= priority(curr_chr)) {
        space_();
        red_std += new_char;
        if (Stack.empty()) break;
      }
      Stack.push(curr_chr);
      space_();
    }
  }
  while (!Stack.empty()) {
    space_();
    red_std += new_char;
  }
  *this->str = red_std;
};
double functionCalculate(char func, double num_1, double num_2) {
  double result = 0;
  if (func == '/' && num_2 == 0.0)
    throw std::invalid_argument("n/0");
  else if (func == '+')
    result = num_1 + num_2;
  else if (func == '^')
    result = pow(num_1, num_2);
  else if (func == '-')
    result = num_1 - num_2;
  else if (func == '*')
    result = num_1 * num_2;
  else if (func == '/' && num_2 != 0.0)
    result = num_1 / num_2;
  else if (func == '%') {
    int mul = (int)num_1 / (int)num_2;
    result = num_1 - num_2 * mul;
  }
  return result;
}
double triganometricFuntion(char func, double num_1) {
  double result = 0;
  if (func == 'c')
    result = cos(num_1);
  else if (func == 't')
    result = tan(num_1);
  else if (func == 'n')
    result = asin(num_1);
  else if (func == 'q')
    result = sqrt(num_1);
  else if (func == 'g')
    result = log10(num_1);
  else if (func == 's')
    result = sin(num_1);
  else if (func == 'A')
    result = acos(num_1);
  else if (func == 'y')
    result = atan(num_1);
  else if (func == 'l')
    result = log(num_1);
  return result;
}
std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}
void s21::BackEnd::calculation() {
  std::vector<std::string> v = split(*str, ' ');
  std::string nums = "1234567890.x";
  std::string signs = "+-/*%^";
  std::string extras = "csyAntqlg";
  std::stack<double> Stack;
  for (auto i : v) {
    if (std::strpbrk(i.data(), nums.data()) != NULL) {
      Stack.push(std::stod(i));
    } else if (std::strpbrk(i.data(), signs.data()) != NULL &&
               Stack.size() > 1) {
      double first = Stack.top();
      Stack.pop();
      double second = Stack.top();
      Stack.pop();
      Stack.push(functionCalculate(i.at(0), second, first));
    } else if (std::strpbrk(i.data(), extras.data()) != NULL) {
      double second = Stack.top();
      Stack.pop();
      Stack.push(triganometricFuntion(i.at(0), second));
    }
    this->result = Stack.top();
  }
}
