#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dsui.h"
#include "question.h"
#include <QtSql>
#include <iostream>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QMovie>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("dringschool");
        db.setUserName("root");
        db.setPassword("root");
        if(!db.open())
        {
            std::cout<<"Cannot open database!!"<< std::endl;

        }
        else
        {
            std::cout<<"open database success!!"<<std::endl;
        }
    //button UI设置
    dsUI::setPushButtonQss(ui->selectButton, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    //inputEdit UI设置
    dsUI::setLineEditQss(ui->inputLineEdit, 5, 2, "#DCE4EC", "#1ABC9C");
    //combobox UI设置
    dsUI::setComboxQss(ui->qesComboBox, 5, 2, "#DCE4EC", "#1ABC9C");
    //设置行和列的大小设为与内容相匹配
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);        //表格禁止编辑
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);       //设置表格为整行选中
    //开始时  把日历信息隐藏,显示题目一的信息
    ui->dateBeginEdit->hide();
    ui->dateEndEdit->hide();
    ui->inputLineEdit->setPlaceholderText("请输入学员姓名");
    // 动态图
    QMovie * move = new QMovie(":/new/image/img/Xmai.gif");
    ui->xMai->setMovie(move);
    move->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectButton_clicked()
{
    int flag = -1;
    flag = ui->qesComboBox->currentIndex();
    switch(flag)
    {
    case 0:
        Q_1();break;    // ui->qesComboBox->currentText() == "总时长"    select_studytime
    case 1:
        Q_2();break;    // ui->qesComboBox->currentText() == "训练时长最短"     topTwenty
    case 2:
        Q_3();break;    // ui->qesComboBox->currentText() == "查询教练指导各科目学员人数和训练总时长"        select_coachTotime
    case 3:
        Q_4();break;    //根据驾校名称和日期，查询某驾校在某时间范围内的教练信息
    case 4:
        Q_5();break;    //统计各年龄段报名学习的人数
    case 5:
        Q_6();break;    //统计驾校用车类型 时长 人数
    case 6:
        Q_7();break;    //查询人气最旺的驾校的车辆情况
    case 7:
        Q_8();break;    //查询金牌教练（学员人数居前5名）的工作单位和学员人数
    case 8:
        Q_9();break;    //查询已报名但没有学习记录的学员信息
    case 9:
        Q_10();break;   // 单表查询
    case 10:
        Q_11();break;
    case 11:
        Q_12();break;
    case 12:
        Q_13();break;
    case 13:
        Q_14();break;
    case 14:
        Q_15();break;

    default:
        std::cout<<"Please select a legal option!"<< std::endl;
    }
}


void MainWindow::on_qesComboBox_activated(int index)        //不用输入的时候  就把输入框隐藏
{
    std::cout<<index<<std::endl;
    switch(index)
    {
    // 切换回开始
    case 0:
        ui->dateBeginEdit->hide();
        ui->dateEndEdit->hide();
        ui->inputLineEdit->show();
        break;
    // 市场最短的前20名学员
    // 什么都不要
    case 1:
        ui->inputLineEdit->hide();
        ui->dateBeginEdit->hide();
        ui->dateEndEdit->hide();
        break;
    // 根据教练姓名查询
    // 只要输入框
    case 2:
        ui->inputLineEdit->setPlaceholderText("请输入教练姓名");
        ui->inputLineEdit->show();
        ui->dateBeginEdit->hide();
        ui->dateEndEdit->hide();
        break;
    case 9:
        ui->inputLineEdit->setPlaceholderText("请输入学员姓名");
        ui->inputLineEdit->show();
        ui->dateBeginEdit->hide();
        ui->dateEndEdit->hide();
        break;
    // 根据名称和日期查教练信息
    // 输入框 日历
    case 3:
        ui->dateBeginEdit->show();
        ui->dateEndEdit->show();
        ui->inputLineEdit->show();
        // 设置日期最大、最小值
        ui->dateBeginEdit->setMinimumDate(QDate::currentDate().addYears(-6));
        ui->dateBeginEdit->setMaximumDate((QDate::currentDate().addYears(+0)));
        ui->dateEndEdit->setMinimumDate(QDate::currentDate().addYears(-6));
        ui->dateEndEdit->setMaximumDate((QDate::currentDate().addYears(+0)));
        // 日历下拉框
        ui->dateBeginEdit->setCalendarPopup(true);
        ui->dateEndEdit->setCalendarPopup(true);
        break;
    default:
        ui->inputLineEdit->hide();
        ui->dateBeginEdit->hide();
        ui->dateEndEdit->hide();
        break;
    }

}
