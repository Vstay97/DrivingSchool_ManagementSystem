#include "dsui.h"
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStandardItemModel>
dsUI::dsUI(QObject *parent) : QObject(parent)
{

}
QString dsUI::setPushButtonQss(QPushButton *btn, int radius, int padding,
                                    const QString &normalColor,
                                    const QString &normalTextColor,
                                    const QString &hoverColor,
                                    const QString &hoverTextColor,
                                    const QString &pressedColor,
                                    const QString &pressedTextColor)
{
    QStringList list;
    list.append(QString("QPushButton{border-style:none;padding:%1px;border-radius:%2px;color:%3;background:%4;}")
                .arg(padding).arg(radius).arg(normalTextColor).arg(normalColor));
    list.append(QString("QPushButton:hover{color:%1;background:%2;}")
                .arg(hoverTextColor).arg(hoverColor));
    list.append(QString("QPushButton:pressed{color:%1;background:%2;}")
                .arg(pressedTextColor).arg(pressedColor));

    QString qss = list.join("");
    btn->setStyleSheet(qss);
    return qss;
}

QString dsUI::setLineEditQss(QLineEdit *txt, int radius, int borderWidth,
                                  const QString &normalColor,
                                  const QString &focusColor)
{
    QStringList list;
    list.append(QString("QLineEdit{border-style:none;padding:3px;border-radius:%1px;border:%2px solid %3;}")
                .arg(radius).arg(borderWidth).arg(normalColor));
    list.append(QString("QLineEdit:focus{border:%1px solid %2;}")
                .arg(borderWidth).arg(focusColor));

    QString qss = list.join("");
    txt->setStyleSheet(qss);
    return qss;
}
QString dsUI::setComboxQss(QComboBox *combox, int radius, int borderWidth,
                           const QString &normalColor,
                           const QString &focusColor)
{
QStringList list;
list.append(QString("ComboBox{border-style:none;padding:3px;border-radius:%1px;border:%2px solid %3;}")
         .arg(radius).arg(borderWidth).arg(normalColor));
list.append(QString("QComboBox:focus{border:%1px solid %2;}")
         .arg(borderWidth).arg(focusColor));
//QComboBox下拉按钮
list.append("QComboBox:drop-down{"
            "margin-right: 10px;"
            "border: none; "
            "}"
            );
//QComboBox下拉框样式
list.append("QComboBox:QAbstractItemView{"
            "font-family: 微软雅黑;"
            "font-size: 12px;"
            "border:1px solid rgba(0,0,0,10%);"
            "border-radius: 14px;"
            "padding:5px;"
            "background-color: #FFFFFF;");
list.append("QComboBox:QAbstractItemView::item{"
            "height: 36px;"
            "}"
            );
//QComboBox下拉框选中样式
list.append("QComboBox:QAbstractItemView::item:selected{"
            "background:rgba(0,0,0,3%);"
            "color:#000000;"
            "}");

QString qss = list.join("");
combox->setStyleSheet(qss);

/*
txt->setStyleSheet("QComboBox::drop-down{"
                   "margin-right: 10px;"
                   "border: none; "
                   "}"
                   );
                   */
return qss;
}
