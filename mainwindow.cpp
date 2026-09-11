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

    series->setPointsVisible(true);

    QChart *chart = new QChart();

    for(double variableX = -20.0; variableX<20.0; variableX += 0.25){
        series->append(variableX, sin(variableX));
        std::cout << variableX << " " << sin(variableX) << "\n";
    }

    discoAnimTimer = new QTimer(this);

    QPen pen = series->pen();
    pen.setWidth(5);
    pen.setColor(Qt::red);
    series->setPen(pen);

    connect(discoAnimTimer, &QTimer::timeout, this, &MainWindow::drawPoints);
    connect(series, &QLineSeries::hovered, this, &MainWindow::onHoverPoint);

    chart->addSeries(series);
    series->setPointsVisible(false);
    //X
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(-10,10);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    //Y
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(-5,5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setTitle("Будущая синусоида");

    ui->widgetPlot->setChart(chart);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPoints(){
    series->clear();
    for(double variableX = -20.0; variableX<20.0; variableX += 0.25, MainWindow::incrementX +=0.001){
        series->append(variableX, sin(variableX + incrementX));
        std::cout << variableX << " " << sin(variableX) << "\n";
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
    ui->label_2->setText("x = " + QString::number(point.x()) + " y = " + QString::number(std::sin(point.x())));
}

