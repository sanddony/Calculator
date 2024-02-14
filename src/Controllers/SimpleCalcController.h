#pragma once
#include <iostream>

#include <QDebug>
#include <QObject>
#include <QQmlEngine>
#include <QString>

#include <QtCore/QDir>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>
#include <QtWidgets/QApplication>

#include "SimpleCalcModel.h"
#include "Validator.h"

class SimpleCalcController : public QObject {
  Q_OBJECT

  Q_PROPERTY(QString currentExpression READ getCurrentExpression WRITE
                 setCurrentExpression NOTIFY currentExpressionChanged)
  Q_PROPERTY(QString yMin READ getYMin WRITE setYMin NOTIFY yMinChanged)
  Q_PROPERTY(QString yMax READ getYMax WRITE setYMax NOTIFY yMaxChanged)
  Q_PROPERTY(QString xMin READ getXMin WRITE setXMin NOTIFY xMinChanged)
  Q_PROPERTY(QString xMax READ getXMax WRITE setXMax NOTIFY xMaxChanged)
  Q_PROPERTY(QString currentX READ getCurrentX WRITE setCurrentX NOTIFY
                 currentXChanged)

  Q_PROPERTY(
      QVariantList xData READ getXData WRITE setXData NOTIFY xDataChanged)
  Q_PROPERTY(
      QVariantList yData READ getYData WRITE setYData NOTIFY yDataChanged)

public:
  SimpleCalcController(QObject *parent = nullptr){};
  SimpleCalcController(SimpleCalcModel model);

  QString getCurrentExpression();
  void setCurrentExpression(QString expression);

  QString getYMin();
  void setYMin(QString);

  QString getYMax();
  void setYMax(QString);

  QString getXMin();
  void setXMin(QString);

  QString getXMax();
  void setXMax(QString);

  QVariantList getXData();
  void setXData(QVariantList);

  QVariantList getYData();
  void setYData(QVariantList);

  QString getCurrentX();
  void setCurrentX(QString);

  void setCoords(vector<coordinates> &xData);

  Q_INVOKABLE void calculateExpression();
  Q_INVOKABLE void drawGraph();

signals:
  void currentExpressionChanged();
  void yMinChanged();
  void yMaxChanged();
  void xMinChanged();
  void xMaxChanged();
  void currentXChanged();

  void xDataChanged();
  void yDataChanged();

private:
  SimpleCalcModel _model;
  InfixNotationValidator _validator;
  QString _currentExpression;
  QString _currentX;

  QString _yMin;
  QString _yMax;
  QString _xMin;
  QString _xMax;

  QVariantList _xData;
  QVariantList _yData;
};