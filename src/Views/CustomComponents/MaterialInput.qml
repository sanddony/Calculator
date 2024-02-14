import QtQuick 6.2
import QtQuick.Controls 6.2

import CustomComponents

Rectangle{
    id: root

    property color inputBgColor: Style.buttonSecondaryColor
    property int textBottomMargin: 0
    property int filedMargin: 40

    property alias inputField: inputText
    property alias inputData: inputText.text


    radius: 30
    border.width: 1
    border.color: inputBgColor
    color: Style.buttonSecondaryColor

    signal textChanged();



    function defineInputTextSize(inputTextWidth, maxPixelSize, minPixelSize, maxTextLenght) {
        var newSize = inputTextWidth / inputData.length * 1.5;

        if(inputData.length < maxTextLenght){
            inputField.font.pixelSize = maxPixelSize;
        }
        else if((inputField.font.pixelSize > minPixelSize && inputData.length > maxTextLenght) || (inputField.font.pixelSize < newSize)) {
            inputField.font.pixelSize = newSize;
        }
    }

    Rectangle{
        id: inputTextWrapper
        width: root.width - filedMargin
        anchors.bottom: root.bottom
        anchors.bottomMargin: root.textBottomMargin
        anchors.horizontalCenter: root.horizontalCenter

        height: inputText.implicitHeight
        color: inputBgColor 

        clip: true

        TextInput{
            id: inputText

            anchors.fill: parent

            text: "0"
            color: Style.textColor
            selectionColor: "transparent"

            font.pixelSize: inputField.font.pixelSize
            
            Behavior on font.pixelSize {
                NumberAnimation {
                    duration: 300 // Длительность анимации (в миллисекундах)
                    easing.type: Easing.InOutQuad // Тип плавности анимации
                }
            }
            horizontalAlignment: TextInput.AlignRight

            onTextChanged: textChanged();


        }
    }
}