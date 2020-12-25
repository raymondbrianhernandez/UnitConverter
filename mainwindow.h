#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_12_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_15_clicked();

    void on_radioButton_14_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_20_clicked();

    void on_radioButton_18_clicked();

    void on_radioButton_17_clicked();

    void on_radioButton_19_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
