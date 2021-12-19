#include "question.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <iostream>
#include <QDebug>
Question::Question()
{

}
void MainWindow::Q_1()      //根据姓名，筛选出该学员的训练总时长
{
    // 获得输入的参数
    QString inputEdit = ui->inputLineEdit->text();
    QString nameToTime = QString("call select_studytime('%1')").arg(inputEdit);
    // 显示到view里面
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(nameToTime);
        model->setHeaderData(0, Qt::Horizontal, tr("编号"));      //第一列的标题
        model->setHeaderData(1, Qt::Horizontal, tr("姓名"));    //没用的列数
        model->setHeaderData(2,Qt::Horizontal,tr("总时长"));

        ui->tableView->setModel(model);

}
void MainWindow::Q_2()      //查询完成所有训练科目、训练时长最短的前20名学员相关信息
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call toptwenty()");

    ui->tableView->setModel(model);
}
void MainWindow::Q_3()      //根据教练姓名，查询指导各科目学员人数和训练总时长
{
    // get input
    QString inputEdit = ui->inputLineEdit->text();
    QString nameToStuCount = QString("CALL select_coachToTime('%1')").arg(inputEdit);
    // 显示到view里面
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(nameToStuCount);
    ui->tableView->setModel(model);
}
void MainWindow::Q_4()      //根据驾校名称和日期，查询某驾校在某时间范围内的教练信息
{
    QDate inputBeginDate = ui->dateBeginEdit->date();
    QDate inputEndDate = ui->dateEndEdit->date();
    QString BeginDate = inputBeginDate.toString("yyyy-MM-dd");
    QString EndDate = inputEndDate.toString("yyyy-MM-dd");

    QString dsName = ui->inputLineEdit->text();

    QString dsNameToCoach = QString("call queryCoachMessageByDS('%1', '%2', '%3')").arg(dsName,BeginDate,EndDate);

    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(dsNameToCoach);
    ui->tableView->setModel(model);

//    qDebug()<<dsName;
//    qDebug() <<BeginDate.toStdString().data();
//    qDebug()<<EndDate.toStdString().data();

}
void MainWindow::Q_5()      //统计各年龄段报名学习的人数
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call statisticalAge();");

    ui->tableView->setModel(model);
}
void MainWindow::Q_6()      //统计驾校用车类型 时长 人数
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call statisticalCarType()");

    ui->tableView->setModel(model);
}
void MainWindow::Q_7()      //查询人气最旺的驾校的车辆情况
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call queryMostPopular() ;");

    ui->tableView->setModel(model);
}
void MainWindow::Q_8()      //查询金牌教练（学员人数居前5名）的工作单位和学员人数
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call goldCoach() ;");

    ui->tableView->setModel(model);
}
void MainWindow::Q_9()      // 查询已报名但没有学习记录的学员信息
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call noLearningRecord()");

    ui->tableView->setModel(model);
}
void MainWindow::Q_10()      // 根据学员姓名查信息
{
    // 获得输入的参数
    QString inputEdit = ui->inputLineEdit->text();
    QString nameToTime = QString("call stuNameNum('%1')").arg(inputEdit);
    // 显示到view里面
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(nameToTime);
        model->setHeaderData(0, Qt::Horizontal, tr("姓名"));      //第一列的标题
        model->setHeaderData(1, Qt::Horizontal, tr("电话"));    //没用的列数
        model->setHeaderData(2,Qt::Horizontal,tr("地址"));

        ui->tableView->setModel(model);
}
void MainWindow::Q_11()     //查询所有设备的信息
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call allDevice()");

    ui->tableView->setModel(model);
}
void MainWindow::Q_12()     //查询所有学生的信息
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call allStudent()");

    ui->tableView->setModel(model);
}
void MainWindow::Q_13()     //查询所有教练的信息
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call allCoach()");

    ui->tableView->setModel(model);
}
void MainWindow::Q_14()     //查询所有车辆的信息
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call allVehicle()");

    ui->tableView->setModel(model);
}
void MainWindow::Q_15()     //查询所有学时的信息
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("call allStudyRecord()");

    ui->tableView->setModel(model);
}

