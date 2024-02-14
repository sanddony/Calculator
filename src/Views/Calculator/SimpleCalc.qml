import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Layouts

import CustomComponents
import Calculator

Page{

    id: root

    anchors.fill: parent

    width:  400
    height: 800

    background: Rectangle{
        anchors.fill: root
        color: Style.backgroundColor
    }

    function addInputData(lexem){
        calcInput.inputData += lexem;
    }   

    function clearInputData(){
        calcInput.inputData = "";
    }

    function removeSymbol(){
        calcInput.inputData = calcInput.inputData.slice(0, -1);
    }  

    function calculate(){
        SimpleCalcController.calculateExpression();        
        calcInput.inputData = SimpleCalcController.currentExpression;
    }

    ColumnLayout{

        CalcInput{
            id: calcInput
            width: root.width
            height: root.height * 0.30
        }

        ScientificKeyboard{
            height: root.height - calcInput.height
            onCalculateExpression: {
                calculate();
            }
            onKeyBoardButtonClicked: {
                addInputData(btnText);
            }
            onDeleteSymbol: {
                removeSymbol();
            }
            onClearInput: {
                clearInputData();
            }
            onEnterX: {
                popup.open();
            }
        }
    }

    Popup {
        id: popup
        width: 200
        height: 150
        modal: true // Захватывает фокус и блокирует остальные элементы окна
        anchors.centerIn: parent

        
        contentItem: TextField {
            id: textField
            anchors.centerIn: parent
            width: parent.width - 40 // Ширина текстового поля
            placeholderText: "Enter a string"

            validator: DoubleValidator {}

            onAccepted: {
                    var number = parseInt(textField.text)
                    console.log("Entered number:", number)
                    SimpleCalcController.currentX = textField.text;
                    popup.close();
            }
        }
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
           calculate(); 
        }
    }

    Connections {
        target: parent // Родительский StackView
        onCurrentItemChanged: {
            if (currentItem != null && currentItem === root) {
                calcInput.defineInputTextSize();
            } 
        }
    }
}