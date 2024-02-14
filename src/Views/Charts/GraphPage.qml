import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Layouts
import Charts

import CustomComponents


Page{
    id: root


    width:  1200
    height: 800

    background: Rectangle{
        anchors.fill: root
        color: Style.backgroundColor
    }

    function setGraph(){
        SimpleCalcController.drawGraph();
        graph.xData = SimpleCalcController.xData
        graph.yData = SimpleCalcController.yData
        graph.updateData();
    }

    ColumnLayout {
        
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 50

        spacing: 30

        Graph{
            id: graph
            Layout.alignment: Qt.AlignHCenter

            width: root.width - 40
            height: root.height * 0.6

            
        }

        GraphInput{
            Layout.alignment: Qt.AlignHCenter

            width: root.width
            height: root.height * 0.4

            Component.onCompleted: {
                graphExpressionInterface.forceActiveFocus(); 
                graphExpressionData = SimpleCalcController.currentExpression;
                yMinInterface = SimpleCalcController.yMin;
                yMaxInterface = SimpleCalcController.yMax;
                xMinInterface = SimpleCalcController.xMin;
                xMaxInterface = SimpleCalcController.xMax;
            }

            // Connections {
            //     target: graphExpressionInterface 
            //     onTextChanged: {
            //         SimpleCalcController.currentExpression = graphExpressionData;
            //         SimpleCalcController.yMin = yMinInterface;
            //         SimpleCalcController.yMax = yMaxInterface;
            //         SimpleCalcController.xMin = xMinInterface;
            //         SimpleCalcController.xMax = xMaxInterface;
            //     }
            // }

            onDrawGraph: setGraph();
        }
        
    }
}