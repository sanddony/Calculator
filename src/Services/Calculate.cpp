#include "Calculate.h"

#include <string>
#include <array>
#include <stack>
#include <memory>
#include <unordered_map>
#include <functional>

double Calculate::operator()(string &expression) {
  int operation = 0;
  return 1;
}

double Calculate::operator()(string &expression, double x) {
  int operation = 0;
  return 1;
}

enum class OperationType{
  Binary,
  Unary,
  OpenBracket,
  CloseBracket
};

struct Lexema{
  Lexema(){}
  Lexema(std::string token):token(token){}
  std::string token;
  bool operator==(const Lexema& other) const{
    return other.token == token;
  }
};

struct Operation: public Lexema{
  Operation(){}
  Operation(std::string token, size_t priority_, OperationType type_): Lexema(token){
    priority = priority_;
    type = type_;
  }
  size_t priority;
  OperationType type;
};

struct Literal: public Lexema{
  Literal(){}
  Literal(std::string token, double value_): Lexema(token){
    value = value_;
  }
  double value;
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

struct OperationHash{

  size_t operator()(const Operation& operation) const{
    return std::hash<std::string>()(operation.token);
  }

};

class OperationList{

public:

  OperationList(size_t size){
    operations_.reserve(size);
  }

  bool Contatins(std::string_view operation_token){
    return operations_tokens_.contains(std::string(operation_token));
  }
  Operation operator[](std::string operation_token){
    return operations_tokens_[operation_token];
  }

  std::shared_ptr<OperationAction> operator[](const Operation& operation){
    return operations_[operation];
  }

  std::shared_ptr<OperationAction> operator[](const Operation& operation) const {
    return operations_.at(operation);
  }

  OperationList& AddOperation(Operation operation, std::function<size_t(size_t, size_t)> action){
    lexema_maexpression_variable_len = operation.token.size() > lexema_maexpression_variable_len ? operation.token.size() : lexema_maexpression_variable_len;
    operations_[operation] = std::make_shared<OperationAction>(BinaryOperationAction(std::move(action)));
    operations_tokens_[operation.token] = operation;
    return *this;
  }

  OperationList& AddOperation(Operation operation, std::function<size_t(size_t)> action){
    lexema_maexpression_variable_len = operation.token.size() > lexema_maexpression_variable_len ? operation.token.size() : lexema_maexpression_variable_len;
    operations_[operation] = std::make_shared<OperationAction>(UnaryOperationAction(std::move(action)));
    operations_tokens_[operation.token] = operation;
    return *this;
  }

  size_t GetLexemaMaxLength() const {
    return lexema_maexpression_variable_len;
  }

private:
  std::unordered_map<Operation, std::shared_ptr<OperationAction>, OperationHash> operations_;
  std::unordered_map<std::string, Operation> operations_tokens_;
  size_t lexema_maexpression_variable_len = 1;
};

class Lexer{

public:

  Lexer(OperationList operation_list): operation_list_(std::move(operation_list)){}

  void SetExpressionVariable(double value){
    is_expression_variable_setted_ = true;
    expression_variable_ = value;
  }

  std::shared_ptr<Lexema> GetLexema(const std::string& str, std::string::iterator& it) {
    std::string::iterator current_it = it;
    std::shared_ptr<Lexema> current_lexem;
    if(isDigit(*it) || *it == 'x'){
      current_lexem = parseNumberLiteral(str, it);
    } else {
      current_lexem = parseOperation(str, it);
    }
    if(current_lexem.get() == nullptr && *it == 'x' && is_expression_variable_setted_){
      current_lexem = std::make_shared<Literal>("x", expression_variable_);
    }
    if(current_lexem.get() == nullptr){
      throw std::runtime_error("Not found a lexem at " + std::string(static_cast<char>(it - str.begin() + '0'), 1) + " position");
    }
    return current_lexem;
  }

  const OperationList& GetOperationList() const {
    return operation_list_;
  }

private:

  std::shared_ptr<Literal> parseNumberLiteral(const std::string& str, std::string::iterator& it){
    size_t num_size = 1;
    size_t pos = it - str.begin();
    std::shared_ptr<Literal> result;
    try {
      Literal res;
      res.value = std::stod(&str[pos], &num_size);
      res.token = std::string(str[pos], str[pos + num_size]);
      it += num_size;
      result = std::make_shared<Literal>(res);
    } catch(const std::invalid_argument& e) {
      result = nullptr;
    }
    return result;
  }

  std::shared_ptr<Operation> parseOperation(const std::string& str, std::string::iterator& it) {
    std::string::iterator current_it = it+1;
    std::string_view current_lexem(it, current_it);
    size_t current_lexem_len = 1;
    std::shared_ptr<Operation> result = nullptr;

    while(current_it-1 != str.end() && current_lexem_len < operation_list_.GetLexemaMaxLength()){
      if(operation_list_.Contatins(current_lexem)){
        result = std::make_shared<Operation>(operation_list_[std::string(current_lexem)]);
      }
      current_lexem = std::string_view{it, current_it};
      current_lexem_len++;
      current_it++;
    }

    if(result != nullptr){
      it += result->token.size();
    }
    
    return result;
  }

  bool isDigit(char chr){
    return chr >= '0' && chr <= '9';
  }

private:

  OperationList operation_list_;
  double expression_variable_;
  bool is_expression_variable_setted_ = false;

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

class Calculator{

public:

  Calculator(Lexer lexer): lexer_(lexer){}



private:
  Lexer lexer_;
  std::stack<std::shared_ptr<Operation>> operation_stack_;
  std::stack<Literal> literals_stack_;

};