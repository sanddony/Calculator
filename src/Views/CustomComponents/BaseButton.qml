import QtQuick 6.2
import QtQuick.Controls 6.2

import CustomComponents

Button {
    id: root
    
    enum ButtonType{
        SIMPLE,
        SCIENTIFIC
    }

    property int buttonSizeState: BaseButton.ButtonType.SIMPLE

    property string buttonValue;

    property alias buttonText: btnText.text
    property alias textSize: btnText.font.pointSize
    
    property color textColor
    property color buttonColor
    property color buttonPressedColor



    background: Rectangle{
        anchors.fill: parent
        color: parent.down ? buttonPressedColor : buttonColor  
        radius: 100
    }



    Text {
        id: btnText
        color: textColor
        text: buttonText
        anchors.centerIn: parent

        font.pointSize: textSize
    }

    onClicked: keyBoardButtonClicked(buttonValue)

}
