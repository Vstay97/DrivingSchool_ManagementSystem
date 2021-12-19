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
    void Q_1();
    void Q_2();
    void Q_3();
    void Q_4();
    void Q_5();
    void Q_6();
    void Q_7();
    void Q_8();
    void Q_9();
    void Q_10();
    void Q_11();
    void Q_12();
    void Q_13();
    void Q_14();
    void Q_15();
private slots:

    void on_selectButton_clicked();

    void on_qesComboBox_activated(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
