import QtQuick 6.2
import QtQuick.Controls 6.2

import CustomComponents
import Calculator

MaterialInput{
    id: root

    textBottomMargin: 60

    implicitHeight: 350
    implicitWidth: parent.width


    Component.onCompleted: {
        inputField.forceActiveFocus(); 
        inputData = SimpleCalcController.currentExpression;
    }

    Rectangle{
        id: plugTop
        height: 30
        width: root.width
        color: inputBgColor
        anchors.top: parent.top
    }

    Connections {
        target: inputField 
        onTextChanged: {
            SimpleCalcController.currentExpression = inputData;
            root.defineInputTextSize(implicitWidth, 50, 30, 15);
        }
    }

}