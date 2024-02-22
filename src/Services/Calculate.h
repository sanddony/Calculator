#pragma once
#include <string>
#include <vector>
#include <vector>

using namespace std;

// // x,y
// typedef pair<double, double> coordinates;

class Calculate {
public:
  double operator()(string &expression);
  double operator()(string &expression, double x);

private: 

};