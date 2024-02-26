#pragma once
#include <iterator>
#include <string>
#include <vector>

#include <iostream>

#include <array>
#include <functional>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>

class Calculate {
public:
  double operator()(std::string &expression) {
    int operation = 0;
    return 1;
  }
  double operator()(std::string &expression, double x) {
    {
      int operation = 0;
      return 1;
    }
  }

private:
};

// double Calculate::operator()(std::string &expression) {
//   int operation = 0;
//   return 1;
// }

// double Calculate::operator()(std::string &expression, double x) {
//   int operation = 0;
//   return 1;
// }

enum class OperationType { Binary, Unary, OpenBracket, CloseBracket };

struct Lexema {
  Lexema() {}
  Lexema(std::string token) : token(token) {}
  std::string token;
  bool operator==(const Lexema &other) const { return other.token == token; }
  virtual ~Lexema() = default;
};

struct Operation : public Lexema {
  Operation() {}
  Operation(std::string token, size_t priority_, OperationType type_)
      : Lexema(token) {
    priority = priority_;
    type = type_;
  }
  size_t priority;
  OperationType type;
};

struct Literal : public Lexema {
  Literal() {}
  Literal(std::string token, double value_) : Lexema(token) { value = value_; }
  double value;
};

class OperationAction {

public:
  virtual double operator()(double lhs) const = 0;
  virtual double operator()(double lhs, double rhs) const = 0;
};

class UnaryOperationAction : public OperationAction {

public:
  UnaryOperationAction(std::function<double(double)> func) {
    func_ = std::move(func);
  }

  double operator()(double lhs) const override { return func_(lhs); }

  double operator()(double lhs, double rhs) const override {
    throw std::runtime_error("Not Binary Operation!");
  }

private:
  std::function<double(double)> func_;
};

class BinaryOperationAction : public OperationAction {

public:
  BinaryOperationAction(std::function<double(double, double)> func) {
    func_ = std::move(func);
  }
  double operator()(double lhs, double rhs) const override {
    return func_(lhs, rhs);
  }

  double operator()(double lhs) const override {
    throw std::runtime_error("Not Unary Operation!");
  }

private:
  std::function<double(double, double)> func_;
};

struct OperationHash {

  size_t operator()(const Operation &operation) const {
    return std::hash<std::string>()(operation.token);
  }
};

class OperationList {

public:
  OperationList(size_t size) { operations_.reserve(size); }

  bool Contatins(std::string_view operation_token) {
    return operations_tokens_.contains(std::string(operation_token));
  }
  Operation operator[](std::string operation_token) const {
    return operations_tokens_.at(operation_token);
  }

  std::shared_ptr<OperationAction>
  operator[](const Operation &operation) const {
    return operations_.at(operation);
  }

  [[maybe_unused]] OperationList &
  AddOperation(Operation operation,
               std::function<double(double, double)> action) {
    if (operations_.contains(operation)) {
      throw std::runtime_error("Operation - " + operation.token +
                               "already added to operation list!");
    }
    lexema_maexpression_variable_len =
        operation.token.size() > lexema_maexpression_variable_len
            ? operation.token.size()
            : lexema_maexpression_variable_len;
    operations_[operation] = std::make_shared<BinaryOperationAction>(
        BinaryOperationAction(std::move(action)));
    operations_tokens_[operation.token] = operation;
    return *this;
  }

  [[maybe_unused]] OperationList &
  AddOperation(Operation operation, std::function<double(double)> action) {
    if (operations_.contains(operation)) {
      throw std::runtime_error("Operation - " + operation.token +
                               "already added to operation list!");
    }
    lexema_maexpression_variable_len =
        operation.token.size() > lexema_maexpression_variable_len
            ? operation.token.size()
            : lexema_maexpression_variable_len;
    operations_[operation] = std::make_shared<UnaryOperationAction>(
        UnaryOperationAction(std::move(action)));
    operations_tokens_[operation.token] = operation;
    return *this;
  }

  void Build() {}

  size_t GetLexemaMaxLength() const { return lexema_maexpression_variable_len; }

private:
  std::unordered_map<Operation, std::shared_ptr<OperationAction>, OperationHash>
      operations_;
  std::unordered_map<std::string, Operation> operations_tokens_;
  size_t lexema_maexpression_variable_len = 1;
};

class Lexer {

public:
  Lexer(OperationList operation_list)
      : operation_list_(std::move(operation_list)) {}

  void SetExpressionVariable(double value) {
    is_expression_variable_setted_ = true;
    expression_variable_ = value;
  }

  std::shared_ptr<Lexema> GetLexema(const std::string &str,
                                    std::string::iterator &it) {

    if (it >= str.end()) {
      throw std::out_of_range("Expression out of range!");
      // return nullptr;
    }

    std::shared_ptr<Lexema> current_lexem;

    if (isDigit(*it) || *it == 'x') {
      current_lexem = parseNumberLiteral(str, it);
    } else {
      current_lexem = parseOperation(str, it);
    }
    if (current_lexem.get() == nullptr && *it == 'x' &&
        is_expression_variable_setted_) {
      current_lexem = std::make_shared<Literal>("x", expression_variable_);
    }
    if (current_lexem.get() == nullptr) {
      int dis = std::distance(str.begin(), str.begin() + str.find(*it));
      throw std::runtime_error("Not found a lexem at " + std::to_string(dis) +
                               " position");
    }
    return current_lexem;
  }

  const OperationList &GetOperationList() const { return operation_list_; }

private:
  std::shared_ptr<Literal> parseNumberLiteral(const std::string &str,
                                              std::string::iterator &it) {
    size_t num_size = 1;
    size_t pos = it - str.begin();
    std::shared_ptr<Literal> result;
    try {
      Literal res;
      res.value = std::stod(&str[pos], &num_size);
      res.token = "n";
      result = std::make_shared<Literal>(res);
      it += num_size;
    } catch (const std::invalid_argument &e) {
      result = nullptr;
    }
    return result;
  }

  std::shared_ptr<Operation> parseOperation(const std::string &str,
                                            std::string::iterator &it) {
    std::string::iterator current_it = it;
    std::string_view current_lexem(it, current_it);
    size_t current_lexem_len = 1;

    std::shared_ptr<Operation> result = nullptr;

    while (current_it - 1 != str.end() &&
           current_lexem_len <= operation_list_.GetLexemaMaxLength()) {
      current_lexem_len++;
      current_it++;
      current_lexem = std::string_view{it, current_it};
      std::cout << "current_lexem - " << current_lexem << std::endl;

      if (operation_list_.Contatins(current_lexem)) {
        result = std::make_shared<Operation>(
            operation_list_[std::string(current_lexem)]);
      }
    }

    if (result != nullptr) {
      it += result->token.size();
    }

    return result;
  }

  bool isDigit(char chr) { return chr >= '0' && chr <= '9'; }

private:
  OperationList operation_list_;
  double expression_variable_;
  bool is_expression_variable_setted_ = false;
};

class Calculator {

public:
  Calculator(Lexer lexer) : lexer_(lexer) {}

  double CaluclateExpression(std::string expression) {
    auto it = expression.begin();
    auto lexema = lexer_.GetLexema(expression, it);
    while (lexema != nullptr) {
      auto lexem_operation = dynamic_pointer_cast<Operation>(lexema);
      if (lexem_operation == nullptr) {
        handleLiteral(*dynamic_pointer_cast<Literal>(lexema));
      } else {
        handleOpeartion(lexem_operation);
      }
    }

    while (!operation_stack_.empty() && !literals_stack_.empty()) {
       calculateAllFromStack();
    }
  }

  double CaluclateExpression(std::string expression,
                             double expression_variable) {}

private:
  void handleLiteral(Literal literal) {
    literals_stack_.push(std::move(literal));
  }

  void handleOpeartion(std::shared_ptr<Operation> operation) {
    if (operation->type == OperationType::Binary) {
      while (operation->priority <= operation_stack_.top()->priority ||
             operation_stack_.top()->type != OperationType::OpenBracket) {
        calculateAllFromStack();
      }
      operation_stack_.push(operation);
    } else if (operation->type == OperationType::Unary) {
      operation_stack_.push(operation);
    } else if (operation->type == OperationType::OpenBracket) {
      operation_stack_.push(operation);
    } else if (operation->type == OperationType::CloseBracket) {
      while (operation_stack_.top()->type != OperationType::OpenBracket) {
        calculateAllFromStack();
      }
    }
  }

  void calculateAllFromStack() {
    auto top_operation = operation_stack_.top();
    auto action = lexer_.GetOperationList()[*top_operation];
    if (top_operation->type == OperationType::Binary) {

      double right_num = literals_stack_.top().value;
      literals_stack_.pop();

      double left_num = literals_stack_.top().value;
      literals_stack_.pop();

      auto res = (*dynamic_pointer_cast<BinaryOperationAction>(action))(
          left_num, right_num);
      literals_stack_.push({"n", res});

    } else if (top_operation->type == OperationType::Binary) {
      double num = literals_stack_.top().value;
      literals_stack_.pop();

      auto res = (*dynamic_pointer_cast<UnaryOperationAction>(action))(num);
      literals_stack_.push({"n", res});
    }
  }

private:
  Lexer lexer_;
  std::stack<std::shared_ptr<Operation>> operation_stack_;
  std::stack<Literal> literals_stack_;
};

// OperationBuilder -> OperationList
// OperationList
// operator[]
// Lexer(OperationList)
// Calculator(Lexer)
// stack x 2

// binary operation
// unary operation
// brackets

// if lexema is operation
// currentOperation = lexema
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
// else if lexema is Literal
// pushToStack