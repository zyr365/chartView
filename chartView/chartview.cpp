#include "chartview.h"

chartView::chartView(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
}
void chartView::on_pushButton1_clicked()
{
	chartDispaly();
}
void chartView::on_pushButton2_clicked()
{
	initChartView();
}
void chartView::chartDispaly()
{
	QSplineSeries *series = new QSplineSeries();
	for (float i = 0; i < 100; i++)
	{
		series->append(i, sin(0.5*i));
	}
	QChart *chart = new QChart();
	chart->addSeries(series);
	chart->legend()->hide();
	chart->createDefaultAxes();
	chart->setTheme(QChart::ChartThemeDark);
	//方法1
	ui.widget->setChart(chart);
	//方法2
	//QChartView *chartView = new QChartView(chart);
	//chartView->setRenderHint(QPainter::Antialiasing);
	//this->setCentralWidget(chartView);
}

void chartView::initChartView()
{
	QChart *chart2 = new QChart();
	QLineSeries *series = new QLineSeries();
	*series << QPointF(1.0, 1.0) << QPointF(2.0, 73.0) << QPointF(3.0, 268.0) << QPointF(4.0, 17.0)
		<< QPointF(5.0, 4325.0) << QPointF(6.0, 723.0);
	chart2->addSeries(series);
	chart2->legend()->hide();//隐藏图例
	chart2->setTitle("Logarithmic axis example");//设置图标标题
	QValueAxis *axisX = new QValueAxis();
	axisX->setTitleText("Data point");
	axisX->setLabelFormat("%im");
	axisX->setTickCount(series->count());
	chart2->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);
	QLogValueAxis *axisY = new QLogValueAxis();
	axisY->setTitleText("Values");
	axisY->setLabelFormat("%gkg");
	axisY->setBase(8);
	//axisY->setMinorTickCount(-1);
	chart2->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);
	QChartView *chartView = new QChartView(chart2);
	chartView->setRenderHint(QPainter::Antialiasing);
	//connect(series, &QLineSeries::hovered, this, &QtGuiApplication1::showValue);
	this->setCentralWidget(chartView);
}

