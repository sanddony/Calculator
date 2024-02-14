import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Layouts

import CustomComponents


Rectangle{
    id: root

    
    property int rowSpacing: 20
    property int columnSpacing: 120
    property int fontSize: 30

    property int fieldsWidth: 350
    property int fieldsHeight: 50

    property alias graphExpressionInterface: graphExpression.inputField
    property alias graphExpressionData: graphExpression.inputData
    property alias yMinInterface: yMin.inputData
    property alias yMaxInterface: yMax.inputData
    property alias xMinInterface: xMin.inputData
    property alias xMaxInterface: xMax.inputData

    signal drawGraph();

    color: "transparent"

    ColumnLayout{
        id: keyboardLayout
    
        anchors.top: root.top
        anchors.horizontalCenter: root.horizontalCenter
        spacing: rowSpacing


        MaterialInput{
            id: graphExpression

            Text{
                anchors.right: parent.left
                anchors.bottom: parent.bottom
                width: 40
                height: parent.height
                text: "y="
                color: Style.textColor
                font.pixelSize: fontSize
            }

            implicitWidth: (fieldsWidth * 2) + columnSpacing
            implicitHeight: fieldsHeight
            textBottomMargin: 5
            inputField.font.pixelSize: fontSize

        }

        RowLayout{
            id: yRange
            spacing: columnSpacing

            MaterialInput{
                id: yMin

                Text{
                    anchors.right: parent.left
                    anchors.rightMargin: 10
                    anchors.bottom: parent.bottom
                    height: parent.height
                    text: "yₘᵢₙ"
                    color: Style.textColor
                    font.pixelSize: fontSize
                }

                textBottomMargin: 5

                inputField.font.pixelSize: fontSize
                implicitWidth: fieldsWidth
                implicitHeight: fieldsHeight
            }

            MaterialInput{
                id: yMax

                Text{
                    anchors.right: parent.left
                    anchors.rightMargin: 10
                    anchors.bottom: parent.bottom
                    height: parent.height
                    text: "yₘₐₓ"
                    color: Style.textColor
                    font.pixelSize: fontSize
                }
                textBottomMargin: 5

                inputField.font.pixelSize: fontSize
                implicitWidth: fieldsWidth
                implicitHeight: fieldsHeight
            }

        }

        RowLayout{
            id: xRange
            spacing: columnSpacing

            MaterialInput{
                id: xMin

                Text{
                    anchors.right: parent.left
                    anchors.rightMargin: 10
                    anchors.bottom: parent.bottom
                    height: parent.height
                    text: "xₘᵢₙ"
                    color: Style.textColor
                    font.pixelSize: fontSize
                }
                textBottomMargin: 5

                inputField.font.pixelSize: fontSize
                implicitWidth: fieldsWidth
                implicitHeight: fieldsHeight
            }

            MaterialInput{
                id: xMax
                
                Text{
                    anchors.right: parent.left
                    anchors.rightMargin: 10
                    anchors.bottom: parent.bottom
                    height: parent.height
                    text: "xₘₐₓ"
                    color: Style.textColor
                    font.pixelSize: fontSize
                }
                textBottomMargin: 5

                inputField.font.pixelSize: fontSize
                implicitWidth: fieldsWidth
                implicitHeight: fieldsHeight
            }

        }
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
            SimpleCalcController.currentExpression = graphExpressionData;
            SimpleCalcController.yMin = yMinInterface;
            SimpleCalcController.yMax = yMaxInterface;
            SimpleCalcController.xMin = xMinInterface;
            SimpleCalcController.xMax = xMaxInterface;
            drawGraph();
        }
    }
}
