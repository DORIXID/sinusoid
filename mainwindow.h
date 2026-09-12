#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineSeries>
#include <QScatterSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void on_pushButton_pressed();

    void on_pushButton_released();

    void onHoverPoint(const QPointF &point, bool state);

    void onUnhoverPoint(const QPointF &point, bool state);

private:
    Ui::MainWindow *ui;
    double incrementX = 0.0;
    void drawPoints();
    QLineSeries *series = new QLineSeries();
    QScatterSeries *pointSeries = new QScatterSeries();
    QWidget *coordinatesWidget = new QWidget();
    QTimer *discoAnimTimer;
};
#endif // MAINWINDOW_H
