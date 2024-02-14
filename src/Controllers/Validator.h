#pragma once

#include <QString>
#include <algorithm>
#include <iostream>
#include <unordered_map>

class InfixNotationValidator {
private:
  enum Lexema {
    NUMBER = 0b0000000001,
    OPERATOR = 0b0000000010,
    UNARY_OPERATOR = 0b0000000100,
    FUNCTION = 0b0000001000,
    OPEN_BRACKET = 0b0000010000,
    CLOSE_BRACKET = 0b0000100000,
    VAR_X = 0b0001000000,
    DOT = 0b0010000000,
    FACTORIAL = 0b0100000000,
    EXP = 0b1000000000,
    EXP_OPERATOR = 0b100000000000,
    CONST = 0b10000000000
  };

  struct Status {
    int lexemaStatus;
    bool functionStatus;
    bool expStatus;
    int bracketCount;
    int dotCount;
    int expCount;
  };

  Status status = {};

public:
  bool isUnaryOperator(QChar &lexema) {
    bool res = false;

    if (lexema == '+') {
      lexema = ' ';
      res = true;
    } else if (lexema == '-') {
      lexema = '~';
      res = true;
    }
    return res;
  }

  bool isExponentOperator(QChar lexema) { return isUnaryOperator(lexema); }

  bool isOperator(const QChar &lexema) {
    bool res = false;
    QString operators = "+-/*^%";

    if (operators.indexOf(lexema) != -1) {
      res = true;
    } else {
      res = false;
    }
    return res;
  }

  bool isNumber(const QChar &symbol) {
    return (symbol >= '0' && symbol <= '9');
  }

  int isFunction(QString &lexema, int &startIndex) {
    bool res = false;

    std::vector<QString> functions{"sin",  "cos",  "tan", "asin", "acos",
                                   "atan", "sqrt", "ln",  "log"};
    int lexSize = lexema.size();
    for (auto &it : functions) {
      int funtionSize = it.size();
      if (lexSize >= funtionSize && lexema.mid(startIndex, funtionSize) == it) {
        res = true;
        startIndex += funtionSize - 1;
        break;
      }
    }
    qDebug() << res;
    return res;
  }

  bool Validate(QString &input) {
    status.lexemaStatus =
        NUMBER | UNARY_OPERATOR | FUNCTION | OPEN_BRACKET | VAR_X | CONST;
    status.functionStatus = true;
    status.expStatus = true;
    status.bracketCount = 0;
    status.dotCount = 0;
    status.expCount = 0;

    if (input.size() == 0) {
      status.lexemaStatus = 0;
    }

    for (int i = 0; i < input.size() && status.lexemaStatus; i++) {
      if (isNumber(input[i])) {
        SetNumber();
      } else if (isOperator(input[i])) {
        if (status.lexemaStatus & OPERATOR) {
          SetOperator();
        } else if (status.lexemaStatus & EXP_OPERATOR) {
          SetUnaryOperator();
        } else if (isUnaryOperator(input[i])) {
          SetUnaryOperator();
        } else {
          status.lexemaStatus = 0;
        }
      } else if (isFunction(input, i)) {
        SetFunction();
      } else if (input[i] == 'x') {
        SetX();
      } else if (input[i] == '(') {
        SetOpenBracket();
      } else if (input[i] == ')') {
        SetCloseBracket();
      } else if (input[i] == '.') {
        SetDot();
      } else if (input[i] == '!') {
        SetFactorial();
      } else if (input[i] == 'e' || input[i] == 'p') {
        SetConst();
      } else {
        status.lexemaStatus = 0;
      }

      if (status.expCount > 1) {
        status.lexemaStatus = 0;
      }
    }

    return FinalValidation(input);
  }

  bool FinalValidation(QString &input) {
    bool res = false;

    if (!status.lexemaStatus || !status.functionStatus || !status.expStatus ||
        status.bracketCount != 0) {
      res = false;
    } else if (input.back() == '(' || input.back() == '.' ||
               isOperator(input.back())) {
      res = false;
    } else {
      res = true;
    }
    return res;
  }

  void SetNumber() {
    if (status.lexemaStatus & NUMBER) {
      status.lexemaStatus = NUMBER | OPERATOR | DOT | EXP | CLOSE_BRACKET;
      if (status.dotCount == 0) {
        status.lexemaStatus |= FACTORIAL;
      }
      status.expStatus = true;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetOperator() {
    if (status.lexemaStatus & OPERATOR) {
      status.lexemaStatus =
          NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST | UNARY_OPERATOR;
      status.expStatus = true;
      status.expCount = 0;
    } else {
      status.lexemaStatus = 0;
    }
    status.dotCount = 0;
  }

  void SetUnaryOperator() {
    if (status.lexemaStatus & (UNARY_OPERATOR | EXP_OPERATOR)) {
      status.lexemaStatus = NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetFunction() {
    if (status.lexemaStatus & FUNCTION) {
      status.lexemaStatus = OPEN_BRACKET;
      status.functionStatus = false;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetFactorial() {
    if (status.lexemaStatus & FACTORIAL) {
      status.lexemaStatus = OPERATOR;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetX() {
    if (status.lexemaStatus & VAR_X) {
      status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetOpenBracket() {
    if (status.lexemaStatus & OPEN_BRACKET) {
      status.lexemaStatus =
          NUMBER | FUNCTION | OPEN_BRACKET | VAR_X | CONST | UNARY_OPERATOR;
      status.functionStatus = true;
      status.bracketCount++;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetCloseBracket() {
    if (status.lexemaStatus & CLOSE_BRACKET) {
      status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
      status.bracketCount--;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetDot() {
    if (status.lexemaStatus & DOT) {
      status.lexemaStatus = NUMBER;
      status.dotCount++;
    } else {
      status.lexemaStatus = 0;
    }
  }

  void SetConst() {
    if (status.lexemaStatus & EXP) {
      status.lexemaStatus = EXP_OPERATOR | NUMBER;
      status.dotCount = 0;
      status.expCount++;
      status.expStatus = false;
    } else if (status.lexemaStatus & CONST) {
      status.lexemaStatus = OPERATOR | CLOSE_BRACKET;
    } else {
      status.lexemaStatus = 0;
    }
  }
};
