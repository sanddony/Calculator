#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QtCore/QDir>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>
#include <QtWidgets/QApplication>

#include "SimpleCalcController.h"

void set_qt_environment() {
  qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");
  qputenv("QT_ENABLE_HIGHDPI_SCALING", "0");
  qputenv("QT_LOGGING_RULES", "qt.qml.connections=false");
  qputenv("QT_QUICK_CONTROLS_CONF", ":/qtquickcontrols2.conf");
  qputenv("QML_COMPAT_RESOLVE_URLS_ON_ASSIGNMENT", "1");
}

Q_DECLARE_METATYPE(SimpleCalcController)

int main(int argc, char *argv[]) {
  set_qt_environment();

  QApplication app(argc, argv);

  SimpleCalcController controller;

  qmlRegisterSingletonType(QUrl("qrc:/Style.qml"), "CalcStyle", 1, 0, "Style");

  QQmlApplicationEngine engine;

  const QUrl url(u"qrc:/main.qml"_qs);
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);

  engine.rootContext()->setContextProperty("SimpleCalcController", &controller);
  engine.rootContext()->setContextProperty("appDir",
                                           qApp->applicationDirPath());

  engine.addImportPath("qrc:/");

  engine.load(url);

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
