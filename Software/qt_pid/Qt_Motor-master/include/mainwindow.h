#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "crc16.h"
#include "serial_proto.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void customize_ui();

    void on_sendPID_clicked();

    void updateCOM();

    void readDataFromSTM();

    void on_Select_COM_clicked();

    //   void on_pushButton_clicked();

    void on_pushButton_readData_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_position_clicked();

    void on_pushButton_velocity_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_run_clicked();

    void on_pushButton_plot_clicked();

    void updateGraph();

    void updateGraph_realTime();

    void on_pushButton_clearGraph_clicked();

    void on_pushButton_reload_clicked();

    //   QByteArray floatToByteArray(float num);
    void on_pushButton_clear_2_clicked();

    void on_pushButton_plot_2_clicked();

    void on_actionSave_txt_triggered();


    void on_PID1_clicked();

    void on_PID2_clicked();

private:
    Ui::MainWindow *ui;

private:
    QList<double> dataPoints;
    QString m_data;
    int count;
    QTime time;
    QTimer *timer;
    QTimer *timer_realTime;
    QVector<double> dataPointsVector;
    QStringList values;
    double value;
};
#endif // MAINWINDOW_H
