#include "Calculate.h"

#include <string>

enum class OperationType{
  Binary,
  Unary,
  OpenBracket,
  CloseBracket
};

struct Operation{
  size_t priority;
  std::string token;
  OperationType type;
};

// OperationBuilder -> OperationList
  //OperationList
    // operator[]
// Lexer(OperationList)
// Calculator(Lexer)
  // stack x 2
  // 


// binary operation
// unary operation
// brackets

// currentOperation 
// if(currentOperation == binaryOperation)
  // while(curr.prority <= top.priority)
    // caclculate previously operation -> push result to stack
  // push currentOperation to stack
// else if(currentOperation == unaryOperation)
    // push currentOperation to stack
// else if(currentOperation == openBrackets)
 // push currentOperation to stack
// else if(currentOperation == closeBrackets)
  // while(currentOperation != openBrackets)
    // caclculate previously operation -> push result to stack


double Calculate::operator()(string &expression) {
  int operation = 0;

}

double Calculate::operator()(string &expression, double x) {
  int operation = 0;
  
}
