#pragma once

#include <QtWidgets/QMainWindow>
#include <QtCharts>
#include "ui_chartview.h"

class chartView : public QMainWindow
{
	Q_OBJECT

public:
	chartView(QWidget *parent = Q_NULLPTR);

private:
	Ui::chartViewClass ui;
	void chartDispaly();
	void initChartView();
private slots:
	void on_pushButton1_clicked();
	void on_pushButton2_clicked();
};
