import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

import CustomComponents
import Calculator

ApplicationWindow {
    id: root

    property int defaultWidth:  450
    property int defaultHeight: 800

    maximumWidth:  defaultWidth
    maximumHeight: defaultHeight

    minimumWidth:  defaultWidth
    minimumHeight: defaultHeight


    visible: true
    title: qsTr("Calculator")


    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: SimpleCalc {}
        Keys.onPressed: {

            if (event.key === Qt.Key_Tab) {
                drawer.open(); 
            }
        }
    }

    ToolButton {
        anchors.top: root.top
        anchors.left: root.left

        anchors.leftMargin: 40
        anchors.topMargin: 40

        action: navigateBackAction

    }
    
    Action {
        id: navigateBackAction
        icon.source: "qrc:./../../resources/burger-menu.svg"

        onTriggered: drawer.open();
    }

    Drawer {
        id: drawer
        width: Math.min(root.width, root.height) / 3 * 2
        height: root.height
        interactive: stackView.depth === 1

        ListView {
            id: listView

            focus: true
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: listView.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    listView.currentIndex = index;
                    var newWidth = 450;
                    if(model.title == "Graph"){
                        newWidth = 1200;
                    }
                    root.width = newWidth;
                    stackView.push(model.source);
                    drawer.close();
                }
            }

            model: ListModel {
                ListElement { title: "SmartCalc"; source: "qrc:Calculator/SimpleCalc.qml"}
                ListElement { title: "Graph"; source: "qrc:Charts/GraphPage.qml"}
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }
    



}