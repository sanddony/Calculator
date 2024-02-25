#include "Calculate.h"
#include <functional>
#include <unordered_map>
#include <iostream>

// 

int main () {
  //  std::string text ("1e3    a");
  //  std::string::size_type sz;     // alias of size_t
  //  double result = std::stod(text, &sz);
  //  std::cout << "The result is " << result << std::endl; // outputs 1000
  //  std::cout << "Size -  " << sz << std::endl; // outputs 1000

  std::unordered_map<int, std::string> tmp;
  tmp[1] = "123";

  std::cout << tmp[2].size(
    
  ) << std::endl;
  return 0;
 }