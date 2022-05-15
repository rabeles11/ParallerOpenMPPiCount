#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <omp.h>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int n = 0;
    int num_of_threads = 0;

private slots:
    void on_pushButtonStartPi_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
