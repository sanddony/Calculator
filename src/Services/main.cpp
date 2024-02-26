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

  std::string tmp = "123123123121231231231232";
  std::string_view tmp_view(tmp.begin(),tmp.end());
  std::cout << sizeof(tmp_view )<< std::endl;
  return 0;
 }