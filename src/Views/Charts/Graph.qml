import QtQuick
import Charts
import "../JavaScriptFunctions/Chart.js" as Chart

import CustomComponents



Rectangle{
    id: root

	property color inputBgColor: Style.buttonSecondaryColor

    // implicitHeight: 350
    // implicitWidth: parent.width
    radius: 30

    border.width: 1
    border.color: inputBgColor
    color: Style.buttonSecondaryColor

	signal updateData();

	onUpdateData: chart.animateToNewData();

	property alias xData: chart.xDataInternal
	property alias yData: chart.yDataInternal


	Item {
		id: grid
		anchors.fill: parent

		Rectangle {
			color: Style.buttonSecondaryColor
			anchors.fill: parent
			radius: 30
		}
        
		Chart {
			id: chart
			anchors.fill: parent
			chartType: 'line'

			property var xDataInternal: [1,2,3,4,5,6,7]
			property var yDataInternal: [1,2,3,4,5,6,7]

			chartData: { return {
					labels: xDataInternal,
					datasets: [{
						label: 'Filled',
						fill: true,
						borderColor:  Style.textColorRGB,
						data: yDataInternal,
						pointRadius: 0
					}]
				}
			}

			chartOptions: {return {
					maintainAspectRatio: false,
					responsive: true,
					title: {
						display: true,
						text: " "
					},
					tooltips: {
						mode: 'index',
						intersect: true,
					},
					hover: {
						mode: 'nearest',
						intersect: true
					},
					scales: {
						xAxes: [{
							display: true,
							scaleLabel: {
								display: true,
								labelString: 'X'
							},
							beginAtZero: true
						}],
						yAxes: [{
							display: true,
							scaleLabel: {
								display: true,
								labelString: 'Y'
							},
							beginAtZero: true
						}]
					},
				}
			}
		}
	}
	
}