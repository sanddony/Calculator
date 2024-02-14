#include "SimpleCalcModel.h"
#include <iostream>

string SimpleCalcModel::getCurrentExpression() { return currentExpression; }

void SimpleCalcModel::setCurrentExpression(string expression) {
  cout << expression << endl;
  currentExpression = expression;
}

void SimpleCalcModel::calculateCurrentExpression() {
  setCurrentResult(_calculate(currentExpression));
}

void SimpleCalcModel::calculateCurrentExpression(double x) {
  setCurrentResult(_calculate(currentExpression, x));
}

double SimpleCalcModel::getCurrentResult() { return currentResult; }

void SimpleCalcModel::setCurrentResult(double result) {
  currentResult = result;
}

vector<coordinates> &SimpleCalcModel::getCurrentCord() { return currentCord; }

void SimpleCalcModel::setCurrentCord(vector<coordinates> cord) {
  currentCord = cord;
}

pair<coordinates, coordinates> &SimpleCalcModel::getCurrentRange() {
  return currentRange;
}

void SimpleCalcModel::setCurrentRange(pair<coordinates, coordinates> range) {
  currentRange = range;
}

void SimpleCalcModel::drawGraph() {
  currentCord.clear();
  cout << "drawGraph Model" << endl;
  cout << currentRange.first.second << endl;

  double range = currentRange.first.second - currentRange.first.first > 10000
                     ? 10000
                     : currentRange.first.second - currentRange.first.first;
  double step = range / 1000;
  // step = step < 0.1 ? 0.1 : step;

  for (double x = currentRange.first.first; x < currentRange.first.second;
       x += step) {
    coordinates tmp = make_pair(x, _calculate(currentExpression, x));
    currentCord.push_back(tmp);
    // cout << tmp.first << " " << tmp.second << endl;
  }
}