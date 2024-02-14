#pragma once
#include "Calculate.h"

class SimpleCalcModel {

public:
  void calculateCurrentExpression();
  void calculateCurrentExpression(double x);

  string getCurrentExpression();
  void setCurrentExpression(string expression);

  double getCurrentResult();
  void setCurrentResult(double result);

  vector<coordinates> &getCurrentCord();
  void setCurrentCord(vector<coordinates> cord);

  pair<coordinates, coordinates> &getCurrentRange();
  void setCurrentRange(pair<coordinates, coordinates> range);

  string getCurrentX();
  void setcurrentX(string x);

  void drawGraph();

private:
  string currentExpression;

  //(x_min, x_max), (y_min, y_max)
  pair<coordinates, coordinates> currentRange;

  double currentResult;
  vector<coordinates> currentCord;

  Calculate _calculate;
  // vector<string> archiveExpressions;
};