import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Layouts

import CustomComponents
import Calculator

Rectangle{
    id: root

    implicitHeight: 450
    implicitWidth: 450
    radius: 10

    property int buttonsWidth: 50
    property int buttonsHeight: 50

    property int rowSpacing: 8
    property int columnSpacing: 20

    signal calculateExpression();
    signal keyBoardButtonClicked(string btnText);
    signal deleteSymbol();
    signal clearInput();
    signal enterX();
    
    color: "transparent"
    
    ColumnLayout{
        id: keyboardLayout

        anchors.centerIn: root
        spacing: rowSpacing


        RowLayout{

            Layout.alignment: Qt.AlignCenter
            spacing: columnSpacing

            ScientificButton {  buttonText: "sin"; buttonValue: "sin()";
                                implicitWidth: root.buttonsWidth;
                                implicitHeight:  root.buttonsHeight;}

            ScientificButton {  buttonText: "cos"; buttonValue: "cos()";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }

            ScientificButton {  buttonText: "tan"; buttonValue: "tan()";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
                                                
            ScientificButton {  buttonText: "log"; buttonValue: "log()";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }

            ScientificButton {  buttonText: "ln"; buttonValue: "ln()";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
        }

        RowLayout{

            Layout.alignment: Qt.AlignCenter
            spacing: columnSpacing

            ScientificButton {  buttonText: "asin"; buttonValue: "asin()";
                                implicitWidth: root.buttonsWidth;
                                implicitHeight:  root.buttonsHeight }

            ScientificButton {  buttonText: "acos"; buttonValue: "acos()";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }

            ScientificButton {  buttonText: "atan"; buttonValue: "atan()";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
                                                
            ScientificButton {  buttonText: "√x" ; buttonValue: "sqrt()";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }

            ScientificButton {  buttonText: "xʸ" ; buttonValue: "^";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
        }

        RowLayout{

            Layout.alignment: Qt.AlignCenter
            spacing: columnSpacing

            ScientificButton {  buttonText: "⅟x"; buttonValue: "1/";
                                implicitWidth: root.buttonsWidth;
                                implicitHeight:  root.buttonsHeight }

            OperationButton {   buttonText: "C"; onClicked: clearInput();
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }

            OperationButton {   buttonText: "<-"; onClicked: deleteSymbol();
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
                                                
            OperationButton {   buttonText: "%" ; buttonValue: "%"; 
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }

            OperationButton {   buttonText: "÷" ; buttonValue: "+";   
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
        }

        RowLayout{

            Layout.alignment: Qt.AlignCenter
            spacing: columnSpacing

            ScientificButton {  buttonText: "x!"; buttonValue: "!"; 
                                implicitWidth: root.buttonsWidth;
                                implicitHeight:  root.buttonsHeight }

            DefaultButton { buttonText: "7"; buttonValue: "7"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            DefaultButton { buttonText: "8"; buttonValue: "8"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }
                                                
            DefaultButton { buttonText: "9"; buttonValue: "9"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            OperationButton {   buttonText: "×"; buttonValue: "*";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
        }

        RowLayout{

            Layout.alignment: Qt.AlignCenter
            spacing: columnSpacing

            ScientificButton {  buttonText: "π"; buttonValue: "p";
                                implicitWidth: root.buttonsWidth;
                                implicitHeight:  root.buttonsHeight }

            DefaultButton { buttonText: "4"; buttonValue: "4"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            DefaultButton { buttonText: "5"; buttonValue: "5"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }
                                                
            DefaultButton { buttonText: "6"; buttonValue: "6"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            OperationButton {   buttonText: "-" ; buttonValue: "-";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
        }

        RowLayout{

            Layout.alignment: Qt.AlignCenter
            spacing: columnSpacing

            ScientificButton {  buttonText: "e"; buttonValue: "e";
                                implicitWidth: root.buttonsWidth;
                                implicitHeight:  root.buttonsHeight }

            DefaultButton { buttonText: "1"; buttonValue: "1"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            DefaultButton { buttonText: "2"; buttonValue: "2"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }
                                                
            DefaultButton { buttonText: "3"; buttonValue: "3"; 
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            OperationButton {   buttonText: "+" ; buttonValue: "+";
                                implicitWidth: root.buttonsWidth; 
                                implicitHeight: root.buttonsHeight }
        }

        RowLayout{

            Layout.alignment: Qt.AlignCenter
            spacing: columnSpacing

            ScientificButton {  buttonText: "set X"; 
                                // icon.source: "qrc:./../../resources/Switch.svg";
                                implicitWidth: root.buttonsWidth;
                                implicitHeight:  root.buttonsHeight;
                                onClicked: enterX(); }

            DefaultButton { buttonText: "( )"; buttonValue: "()";
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            DefaultButton { buttonText: "0"; buttonValue: "0";
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }
                                                
            DefaultButton { buttonText: "." ; buttonValue: ".";
                            implicitWidth: root.buttonsWidth; 
                            implicitHeight: root.buttonsHeight }

            OperationButton { buttonText: "=" ; implicitWidth: root.buttonsWidth; 
                                                implicitHeight: root.buttonsHeight;
                                                onClicked: calculateExpression(); }
        }

    }

}