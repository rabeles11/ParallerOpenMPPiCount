#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<stdio.h>
#include<math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    omp_set_num_threads(8);
    ui->label_info_threads_max->setText(QString::number(omp_get_max_threads()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStartPi_clicked()
{
    num_of_threads = ui->Number_of_threads_input->toPlainText().toInt();
    n = ui->N_input->toPlainText().toInt();
    omp_set_num_threads(num_of_threads);
    double tdata = omp_get_wtime();
    double sum = 0.0;
    #pragma omp parallel for reduction(+: sum)
       for (int i = 0; i < n-1; i++){
            double temp = 4/(1+(pow(((double)i+0.5)/(double)n, 2))) * (1/(double)n);
            sum = sum + temp;
       }
    tdata = omp_get_wtime() - tdata;
    ui->label_estimated_time_Pi->setText(QString::number(tdata)+"s");
    ui->label_result_Pi->setText(QString::number(sum));
}

