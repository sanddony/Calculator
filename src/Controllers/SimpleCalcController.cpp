#include "SimpleCalcController.h"

SimpleCalcController::SimpleCalcController(SimpleCalcModel model)
    : _model(model) {}

QString SimpleCalcController::getCurrentExpression() {
  qDebug() << "getCurrentExpression";
  return _currentExpression;
}

void SimpleCalcController::setCurrentExpression(QString expression) {
  _currentExpression = expression;
}

void SimpleCalcController::calculateExpression() {
  _currentExpression = _currentExpression.toLower().remove(' ');
  if (!_validator.Validate(_currentExpression)) {
    setCurrentExpression(QString("ERROR"));
    return;
  }
  _currentExpression.remove(' ');

  _model.setCurrentExpression(_currentExpression.toStdString());
  qDebug() << _currentExpression;

  _model.calculateCurrentExpression(_currentX.toDouble());
  setCurrentExpression(QString::number(_model.getCurrentResult()));
}

void SimpleCalcController::setXMin(QString currentXMin) {
  qDebug() << "setXMin" << currentXMin.toDouble();
  _model.getCurrentRange().first.first = currentXMin.toDouble();
}

QString SimpleCalcController::getXMin() {
  return QString::number(_model.getCurrentRange().first.first);
}

void SimpleCalcController::setXMax(QString currentXMax) {
  qDebug() << "setXMax" << currentXMax.toDouble();
  _model.getCurrentRange().first.second = currentXMax.toDouble();
  qDebug() << _model.getCurrentRange().first.second;
  qDebug() << currentXMax;
}

QString SimpleCalcController::getXMax() {
  return QString::number(_model.getCurrentRange().first.second);
}

void SimpleCalcController::setYMin(QString currentYMin) {
  qDebug() << "setYMin" << currentYMin.toDouble();
  _model.getCurrentRange().second.first = currentYMin.toDouble();
}

QString SimpleCalcController::getYMin() {
  return QString::number(_model.getCurrentRange().second.first);
}

void SimpleCalcController::setYMax(QString currentYMax) {
  qDebug() << "setYMax" << currentYMax.toDouble();
  _model.getCurrentRange().second.second = currentYMax.toDouble();
}

QString SimpleCalcController::getYMax() {
  return QString::number(_model.getCurrentRange().second.second);
}

void SimpleCalcController::setCoords(vector<coordinates> &xData) {
  _xData.clear();
  _yData.clear();
  for (const auto &value : xData) {
    _xData.append(value.first);
    _yData.append(value.second);
  }
}

void SimpleCalcController::setXData(QVariantList xData) { _xData = xData; }

QVariantList SimpleCalcController::getXData() { return _xData; }

void SimpleCalcController::setYData(QVariantList yData) { _yData = yData; }

QVariantList SimpleCalcController::getYData() { return _yData; }

void SimpleCalcController::drawGraph() {
  qDebug() << "drawGraph Controller";
  qDebug() << "_currentExpression " << _currentExpression;
  _currentExpression = _currentExpression.toLower().remove(' ');
  if (!_validator.Validate(_currentExpression)) {
    setCurrentExpression(QString("ERROR"));
    return;
  }
  _currentExpression.remove(' ');
  _model.setCurrentExpression(_currentExpression.toStdString());
  qDebug() << _currentExpression;
  _model.drawGraph();
  setCoords(_model.getCurrentCord());
  emit yDataChanged();
  emit xDataChanged();
}

QString SimpleCalcController::getCurrentX() { return _currentX; }

void SimpleCalcController::setCurrentX(QString x) { _currentX = x; }
