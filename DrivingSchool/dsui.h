#ifndef DSUI_H
#define DSUI_H

#include <QObject>
#include <qpushbutton>
#include <QLineEdit>
#include <QComboBox>


class dsUI : public QObject
{
    Q_OBJECT
public:
    explicit dsUI(QObject *parent = nullptr);
    //设置按钮样式
    static QString setPushButtonQss(QPushButton *btn,                               //按钮对象
                                    int radius = 5,                                 //圆角半径
                                    int padding = 8,                                //间距
                                    const QString &normalColor = "#34495E",         //正常颜色
                                    const QString &normalTextColor = "#FFFFFF",     //文字颜色
                                    const QString &hoverColor = "#4E6D8C",          //悬停颜色
                                    const QString &hoverTextColor = "#F0F0F0",      //悬停文字颜色
                                    const QString &pressedColor = "#2D3E50",        //按下颜色
                                    const QString &pressedTextColor = "#B8C6D1");   //按下文字颜色

    //设置文本框样式
    static QString setLineEditQss(QLineEdit *txt,                                   //文本框对象
                                  int radius = 3,                                   //圆角半径
                                  int borderWidth = 2,                              //边框大小
                                  const QString &normalColor = "#DCE4EC",           //正常颜色
                                  const QString &focusColor = "#34495E");           //选中颜色
    static QString setComboxQss(QComboBox *combox,                                   //文本框对象
                                  int radius = 3,                                   //圆角半径
                                  int borderWidth = 2,                              //边框大小
                                  const QString &normalColor = "#DCE4EC",           //正常颜色
                                  const QString &focusColor = "#34495E");           //选中颜色
signals:

};

#endif // DSUI_H
