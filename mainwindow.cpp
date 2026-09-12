#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>


#include <QTimer>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QValueAxis>

#include <cmath>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QChart *chart = new QChart();

    //Pens config
    QPen pen = series->pen();
    pen.setWidth(5);
    pen.setColor(Qt::red);
    series->setPen(pen);
    QPen pointPen = pointSeries->pen();
    pointSeries->setMarkerSize(12);
    pointPen.setWidth(1);
    pointSeries->setPen(pointPen);


    //Points config
    chart->addSeries(series);
    chart->addSeries(pointSeries);

    series->setPointsVisible(false);
    //X
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(-10,10);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    pointSeries->attachAxis(axisX);
    //Y
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(-5,5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    pointSeries->attachAxis(axisY);

    for(double variableX = -10.0; variableX<11.0; variableX += 0.3){
        series->append(variableX, sin(variableX));
        std::cout << variableX << " " << sin(variableX) << "\n";
    }

    chart->setTitle("Синусоида");

    //signal-slot binding
    discoAnimTimer = new QTimer(this);
    connect(discoAnimTimer, &QTimer::timeout, this, &MainWindow::drawPoints);
    connect(series, &QLineSeries::hovered, this, &MainWindow::onHoverPoint);
    connect(pointSeries, &QScatterSeries::hovered, this, &MainWindow::onUnhoverPoint);

    ui->widgetPlot->setChart(chart);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPoints(){
    incrementX +=0.101;

    series->clear();
    for(double variableX = -10.0; variableX<11.0; variableX += 0.3){
        series->append(variableX, sin(variableX + incrementX));
        std::cout << variableX << " " << sin(variableX + incrementX) << "\n";
        pointSeries->clear();
    }
}


void MainWindow::on_pushButton_pressed()
{
    discoAnimTimer->start(10);
}


void MainWindow::on_pushButton_released()
{
    discoAnimTimer->stop();
}

void MainWindow::onHoverPoint(const QPointF &point, bool state)
{
    if (state){
        ui->label_2->setText("x = " + QString::number(point.x()) + "\ny = " + QString::number(std::sin(point.x() + incrementX)));
        pointSeries->clear();
        pointSeries->append(point.x(), std::sin(point.x() + incrementX));
    }
}

void MainWindow::onUnhoverPoint(const QPointF &point, bool state)
{
    if (!state){
        ui->label_2->setText("Неопределены");
        pointSeries->clear();
    }
}

