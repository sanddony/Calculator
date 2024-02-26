#include "Calculate.h"
#include <functional>
#include <unordered_map>
#include <iostream>
#include <memory>

// 
#include <cmath> 

int Lexer_Test_1(){
  OperationList operation_list(3);

  operation_list.AddOperation({"+", 1, OperationType::Binary}, 
                    [](double lhs, double rhs){
                      return lhs + rhs;
                    }).
                  AddOperation({"-", 1, OperationType::Binary}, 
                    [](double lhs, double rhs){
                      return lhs + rhs;
                    }).
                  AddOperation({"~", 1, OperationType::Binary}, 
                    [](double lhs, double rhs){
                      return lhs + rhs;
                    }).
                  AddOperation({"log", 1, OperationType::Unary}, 
                    [](double lhs){
                      return std::log10(lhs);
                    }).
                  AddOperation({"loga", 1, OperationType::Unary}, 
                    [](double lhs){
                      return std::log10(lhs);
                    });
  Lexer lexer(std::move(operation_list));
  std::string expression = "loga3";
  auto it = expression.begin();
  auto token = lexer.GetLexema(expression, it);
  auto tmp = dynamic_pointer_cast<Operation>(token);
  if(tmp == nullptr){
    std::cout << "nullptr" << std::endl;
  }
  std::cout << token->token << std::endl;

  token = lexer.GetLexema(expression, it);
  std::cout << token->token << std::endl;

  // token = lexer.GetLexema(expression, it);
  // std::cout << token->token << std::endl;
  
  // token = lexer.GetLexema(expression, it);
  // std::cout << token->token << std::endl;

  // token = lexer.GetLexema(expression, it);
  // std::cout << token->token << std::endl;
  return 1;
}

int Lexer_Tests(){
  Lexer_Test_1();
}

int main () {
  Lexer_Tests();
}