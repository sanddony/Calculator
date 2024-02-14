/*!
 * Elypson's Chart.qml adaptor to Chart.js
 * (c) 2020 ChartJs2QML contributors (starting with Elypson, Michael A. Voelkel, https://github.com/Elypson)
 * Released under the MIT License
 */

import QtQuick
import "../JavaScriptFunctions/Chart.js" as Chart

Canvas {
    id: root

    property var jsChart: undefined
    property string chartType
    property var chartData
    property var chartOptions
    property double chartAnimationProgress: 0.1
    property var animationEasingType: Easing.InOutExpo
    property double animationDuration: 500
    property var memorizedContext
    property var memorizedData
    property var memorizedOptions
    property alias animationRunning: chartAnimator.running
    
    signal animationFinished()

    function animateToNewData()
    {
        chartAnimationProgress = 0.1;
        jsChart.update();
        chartAnimator.restart();
    }

    MouseArea {
        id: event
        anchors.fill: root
        hoverEnabled: true
        enabled: true
        property var handler: undefined

        property QtObject mouseEvent: QtObject {
            property int left: 0
            property int top: 0
            property int x: 0
            property int y: 0
            property int clientX: 0
            property int clientY: 0
            property string type: ""
            property var target
        }

        function submitEvent(type, mouseX, mouseY) {
        var mouseEvent = {
            type: type,
            clientX: mouseX,
            clientY: mouseY,
            x: mouseX,
            y: mouseY,
            left: 0,
            top: 0,
            target: root
        };

        if (event.handler) {
            event.handler(mouseEvent);
        }

        root.requestPaint();
        }

        onClicked: {
            submitEvent("click", mouseX, mouseY);
        }
        onPositionChanged: {
            submitEvent("mousemove", mouseX, mouseY);
        }
        onExited: {
            submitEvent("mouseout", mouseX, mouseY);
        }
        onEntered: {
            submitEvent("mouseenter", mouseX, mouseY);
        }
        onPressed: {
            submitEvent("mousedown", mouseX, mouseY);
        }
        onReleased: {
            submitEvent("mouseup", mouseX, mouseY);
        }
    }

    PropertyAnimation {
        id: chartAnimator
        target: root
        property: "chartAnimationProgress"
        alwaysRunToEnd: true
        to: 1
        duration: root.animationDuration
        easing.type: root.animationEasingType
        onFinished: {
            root.animationFinished();
        }
    }

    onChartAnimationProgressChanged: {
        root.requestPaint();
    }

    onPaint: {
        if(root.getContext('2d') != null && memorizedContext != root.getContext('2d') || memorizedData != root.chartData || memorizedOptions != root.chartOptions) {
            var ctx = root.getContext('2d');

            jsChart = new Chart.build(ctx, {
                type: root.chartType,
                data: root.chartData,
                options: root.chartOptions
                });

            memorizedData = root.chartData ;
            memorizedContext = root.getContext('2d');
            memorizedOptions = root.chartOptions;

            root.jsChart.bindEvents(function(newHandler) {event.handler = newHandler;});

            chartAnimator.start();
        }

        jsChart.draw(chartAnimationProgress);
    }

    onWidthChanged: {
        if(jsChart) {
            jsChart.resize();
        }
    }

    onHeightChanged: {
        if(jsChart) {
            jsChart.resize();
        }
    }
}
