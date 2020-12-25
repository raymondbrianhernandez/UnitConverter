#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;


const string imperials[] = {"inches", "feet", "yards", "miles"};
const string metrics[] = {"mm", "cm", "m", "km"};

QString q_amount, q_initialUnit, q_resultingUnit;
string amount = "0";
string initialUnit = "inches";
string resultingUnit = "cm";

string convert(double amount, string initialUnit, string resultingUnit);
double metricCalc(double amount, string initialUnit, string resultingUnit);
double englishCalc(double amount, string initialUnit, string resultingUnit);
string same(double num) {return to_string(num + 1);}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    q_amount = ui->lineEdit->text();
    double amount = q_amount.toDouble();

    string output = convert(amount, initialUnit, resultingUnit);
    QString q_output = QString::fromStdString(output);


    ui->label_2->setText(q_output);
}

string convert (double amount, string initialUnit, string resultingUnit)
{
    string output;
    for(int i=0; i<4; i++){
        if (initialUnit == imperials[i]) {
            // cout << metricCalc(amount, initialUnit, resultingUnit) << " " << resultingUnit << endl;
            output = to_string(metricCalc(amount, initialUnit, resultingUnit)) + " " + resultingUnit;
            }
        }

    for(int i=0; i<4; i++){
        if (initialUnit == metrics[i]) {
            // cout << englishCalc(amount, initialUnit, resultingUnit) << " " << resultingUnit << endl;
            output = to_string(englishCalc(amount, initialUnit, resultingUnit)) + " " + resultingUnit;
            }
        }
    return output;
}

double englishCalc(double amount, string initialUnit, string resultingUnit)
{
    double num = 0;

    // CONVERT TO CM FIRST
    if (initialUnit == "mm") { num = amount / 10; }
    if (initialUnit == "cm") { num = amount; }
    if (initialUnit == "m") { num = amount / 0.01; }   
    if (initialUnit == "km") { num = amount / 0.00001; }

    // FROM CM TO ENGLISH
    if (resultingUnit == "inches") { num = num * 0.3937007874; }
    if (resultingUnit == "feet") { num = num * 0.032808399; }
    if (resultingUnit == "yards") { num = num * 0.010936133; }
    if(resultingUnit == "miles") { num = num * 0.0000062137; }

    // FROM CM TO ANY METRIC
    if (resultingUnit == "mm") { num = num * 10; }
    if (resultingUnit == "m") { num = num * 0.01; }
    if(resultingUnit == "km") { num = num * 0.00001; }

    return num;
}

double metricCalc(double amount, string initialUnit, string resultingUnit)
{
    double num = 0;

    // CONVERT TO INCHES
    if (initialUnit == "inches") { num = amount; }
    if (initialUnit == "feet") { num = amount * 12; }
    if (initialUnit == "yards") { num = amount * 36; }
    if (initialUnit == "miles") { num = amount * 63360; }

    // INCHES TO METRIC
    if (resultingUnit == "cm" ) { num = num * 2.54; }
    if (resultingUnit == "mm") { num = num * 25.4; }
    if (resultingUnit == "m") { num = num * .0254; }
    if(resultingUnit == "km") { num = num * .0000254; }

    // INCHES TO ENGLISH
    if (resultingUnit == "feet") { num = num * 0.0833333333; }
    if (resultingUnit == "yards") { num = num * 0.0277777778; }
    if(resultingUnit == "miles") { num = num * 0.0000157828; }

    return num;
}

void MainWindow::on_radioButton_12_clicked()
{
    initialUnit = "inches";
}

void MainWindow::on_radioButton_11_clicked()
{
    initialUnit = "feet";
}

void MainWindow::on_radioButton_10_clicked()
{
    initialUnit = "yards";
}

void MainWindow::on_radioButton_9_clicked()
{
    initialUnit = "miles";
}

void MainWindow::on_radioButton_16_clicked()
{
    initialUnit = "mm";
}

void MainWindow::on_radioButton_15_clicked()
{
    initialUnit = "cm";
}

void MainWindow::on_radioButton_14_clicked()
{
    initialUnit = "m";
}

void MainWindow::on_radioButton_13_clicked()
{
    initialUnit = "km";
}

void MainWindow::on_radioButton_7_clicked()
{
    resultingUnit = "mm";
}

void MainWindow::on_radioButton_8_clicked()
{
    resultingUnit = "cm";
}

void MainWindow::on_radioButton_6_clicked()
{
    resultingUnit = "m";
}

void MainWindow::on_radioButton_5_clicked()
{
    resultingUnit = "km";
}

void MainWindow::on_radioButton_20_clicked()
{
    resultingUnit = "inches";
}

void MainWindow::on_radioButton_18_clicked()
{
    resultingUnit = "feet";
}

void MainWindow::on_radioButton_17_clicked()
{
    resultingUnit = "yards";
}

void MainWindow::on_radioButton_19_clicked()
{
    resultingUnit = "miles";
}
