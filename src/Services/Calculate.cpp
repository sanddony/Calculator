#include "Calculate.h"

#include <string>
#include <array>
#include <unordered_map>
#include <functional>

enum class OperationType{
  Binary,
  Unary,
  OpenBracket,
  CloseBracket
};

struct Lexema{
  std::string token;
};

struct Operation: public Lexema{
  size_t priority;
  OperationType type;
};

struct Literal: public Lexema{
  int value;
};

class OperationAction{};

class UnaryOperationAction: public OperationAction{

public: 
  UnaryOperationAction(std::function<size_t(size_t)> func){
    func_ = std::move(func);
  }

  size_t operator()(size_t lhs){
    return func_(lhs);
  }

private:
  std::function<size_t(size_t)> func_;
};

class BinaryOperationAction: public OperationAction{

public: 
  BinaryOperationAction(std::function<size_t(size_t, size_t)> func){
    func_ = std::move(func);
  }
  size_t operator()(size_t lhs, size_t rhs){
    return func_(lhs, rhs);
  }

private: 
  std::function<size_t(size_t, size_t)> func_;
};

class OperationList{

public:

  std::function<size_t(size_t)> operator[](const Operation& operation) const{
    
  }

  OperationList(size_t size){

  }
  class Builder{
    public:

      Builder& StartBuild(){
        return *this;
      }
      Builder& AddOperation(Operation operation){
        // operations_.
        return *this;
      }


    private:
        Builder(){}

      
        
      Operation current_operation_;
  };

private:
  std::unordered_map<Operation, OperationAction> binary_operations_;

};

class Lexer{

public:


private:


};

// OperationBuilder -> OperationList
  //OperationList
    // operator[]
// Lexer(OperationList)
// Calculator(Lexer)
  // stack x 2

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
