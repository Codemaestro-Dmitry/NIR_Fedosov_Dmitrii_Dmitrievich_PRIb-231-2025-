/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label_InputeFilePath;
    QLineEdit *lineEdit;
    QPushButton *pushButton_draw_basic_graf;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_from_N;
    QLabel *label_from;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_to_N;
    QLabel *label_to;
    QPushButton *pushButton_from_plus;
    QPushButton *pushButton_from_minus;
    QPushButton *pushButton_to_plus;
    QPushButton *pushButton_to_minus;
    QPushButton *pushButton_generate_path;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_ves_N;
    QLabel *label_ves;
    QLabel *label_error;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QLatin1String("/* Main Window Styles */\n"
"MainWindow {\n"
"background-color: #f8f9fa;\n"
"font-family: 'Segoe UI', 'Helvetica Neue', sans-serif;\n"
"}\n"
"#centralwidget {\n"
"background-color: white;\n"
"border-radius: 16px;\n"
"margin: 16px;\n"
"padding: 20px;\n"
"box-shadow: 0 4px 20px rgba(0, 0, 0, 0.08);\n"
"}\n"
"/* Input Field */\n"
"#Input_file_path {\n"
"border: 2px solid #e0e0e0;\n"
"border-radius: 12px;\n"
"padding: 12px 16px;\n"
"font-size: 14px;\n"
"color: #333;\n"
"background: #fafafa;\n"
"selection-background-color: #4d7cff;\n"
"selection-color: white;\n"
"transition: all 0.3s ease;\n"
"}\n"
"#Input_file_path:focus {\n"
"border-color: #4d7cff;\n"
"background: white;\n"
"box-shadow: 0 0 0 3px rgba(77, 124, 255, 0.1);\n"
"}\n"
"/* Graphics View */\n"
"#graphicsView {\n"
"background-color: white;\n"
"border-radius: 16px;\n"
"border: 2px solid #f0f0f0;\n"
"margin: 16px 0;\n"
"transition: all 0.3s cubic-bezier(0.25, 0.8, 0.25, 1);\n"
"}\n"
"#graphicsView:hover {\n"
"border-color: #e0e0e0;\n"
"box-shadow: 0 8px 24"
                        "px rgba(0, 0, 0, 0.06);\n"
"}\n"
"/* Labels */\n"
"#label_from_N, #label_to_N, #label_ves_N, #label_InputFilePath {\n"
"font-size: 14px;\n"
"font-weight: 600;\n"
"color: #555;\n"
"letter-spacing: 0.3px;\n"
"}\n"
"#label_from, #label_to, #label_ves {\n"
"font-size: 15px;\n"
"font-weight: 700;\n"
"color: #222;\n"
"background: linear-gradient(to right, #f5f5f5, #fafafa);\n"
"border-radius: 8px;\n"
"padding: 6px 12px;\n"
"min-width: 40px;\n"
"text-align: center;\n"
"border: 1px solid #eee;\n"
"}\n"
"/* Error Label */\n"
"#label_error {\n"
"color: #ff4757;\n"
"font-size: 13px;\n"
"font-weight: 500;\n"
"background: rgba(255, 71, 87, 0.05);\n"
"border-radius: 8px;\n"
"padding: 10px 14px;\n"
"margin: 8px 0;\n"
"border-left: 3px solid #ff4757;\n"
"animation: fadeIn 0.4s ease-out;\n"
"}\n"
"/* Horizontal Line */\n"
"#line {\n"
"background: linear-gradient(to right, transparent, #e0e0e0, transparent);\n"
"height: 1px;\n"
"margin: 20px 0;\n"
"border: none;\n"
"}\n"
"/* Plus/Minus Buttons */\n"
"#pushButton_from_plus, #pus"
                        "hButton_to_plus,\n"
"#pushButton_from_minus, #pushButton_to_minus {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #f8f8f8, stop:1 #e8e8e8);\n"
"border-radius: 10px;\n"
"width: 36px;\n"
"height: 36px;\n"
"border: none;\n"
"color: #4d7cff;\n"
"font-size: 18px;\n"
"font-weight: 800;\n"
"transition: all 0.2s cubic-bezier(0.4, 0, 0.2, 1);\n"
"box-shadow: 0 2px 6px rgba(0, 0, 0, 0.05);\n"
"}\n"
"#pushButton_from_plus:hover, #pushButton_to_plus:hover,\n"
"#pushButton_from_minus:hover, #pushButton_to_minus:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #ffffff, stop:1 #f0f0f0);\n"
"color: #3a6bf0;\n"
"transform: translateY(-2px);\n"
"box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);\n"
"}\n"
"#pushButton_from_plus:pressed, #pushButton_to_plus:pressed,\n"
"#pushButton_from_minus:pressed, #pushButton_to_minus:pressed {\n"
"transform: translateY(0);\n"
"box-shadow: 0 1px 3px rgba(0, 0, 0, 0.08);\n"
"}\n"
"/* Draw Basic Graph Button */\n"
"#pushButton_draw_basic_graf {\n"
"background: qli"
                        "neargradient(x1:0, y1:0, x2:0, y2:1,\n"
"stop:0 #6e8efb, stop:1 #4d7cff);\n"
"border: none;\n"
"border-radius: 12px;\n"
"padding: 12px 24px;\n"
"font-weight: 600;\n"
"font-size: 14px;\n"
"color: white;\n"
"text-transform: uppercase;\n"
"letter-spacing: 0.5px;\n"
"box-shadow: 0 4px 16px rgba(77, 124, 255, 0.3);\n"
"transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);\n"
"}\n"
"#pushButton_draw_basic_graf:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"stop:0 #7d9bfb, stop:1 #5a8aff);\n"
"transform: translateY(-2px);\n"
"box-shadow: 0 6px 20px rgba(77, 124, 255, 0.4);\n"
"}\n"
"#pushButton_draw_basic_graf:pressed {\n"
"transform: translateY(0);\n"
"box-shadow: 0 2px 8px rgba(77, 124, 255, 0.3);\n"
"}\n"
"/* Generate Path Button */\n"
"#pushButton_generate_path {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"stop:0 #FFD700, stop:1 #FFAA00);\n"
"border: none;\n"
"border-radius: 12px;\n"
"padding: 12px 24px;\n"
"font-weight: 700;\n"
"font-size: 14px;\n"
"color: #222;\n"
"text-transfo"
                        "rm: uppercase;\n"
"letter-spacing: 0.5px;\n"
"box-shadow: 0 4px 18px rgba(255, 170, 0, 0.3);\n"
"transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);\n"
"}\n"
"#pushButton_generate_path:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"stop:0 #FFE600, stop:1 #FFC000);\n"
"transform: translateY(-2px);\n"
"box-shadow: 0 6px 22px rgba(255, 170, 0, 0.4);\n"
"}\n"
"#pushButton_generate_path:pressed {\n"
"transform: translateY(0);\n"
"box-shadow: 0 2px 10px rgba(255, 170, 0, 0.3);\n"
"}\n"
"/* Layouts */\n"
"#horizontalLayout, #horizontalLayout_2, #horizontalLayout_3 {\n"
"spacing: 12px;\n"
"margin: 12px 0;\n"
"}\n"
"/* Animations */\n"
"@keyframes fadeIn {\n"
"from {\n"
"opacity: 0;\n"
"transform: translateY(-8px);\n"
"}\n"
"to {\n"
"opacity: 1;\n"
"transform: translateY(0);\n"
"}\n"
"}\n"
"@keyframes pulse {\n"
"0% { transform: scale(1); }\n"
"50% { transform: scale(1.05); }\n"
"100% { transform: scale(1); }\n"
"}\n"
"/* Hover effect for buttons */\n"
"QPushButton:hover {\n"
"animation: pulse 1.5s "
                        "infinite;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 401, 561));
        label_InputeFilePath = new QLabel(centralwidget);
        label_InputeFilePath->setObjectName(QStringLiteral("label_InputeFilePath"));
        label_InputeFilePath->setGeometry(QRect(440, 30, 141, 18));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(440, 60, 331, 32));
        pushButton_draw_basic_graf = new QPushButton(centralwidget);
        pushButton_draw_basic_graf->setObjectName(QStringLiteral("pushButton_draw_basic_graf"));
        pushButton_draw_basic_graf->setGeometry(QRect(450, 100, 321, 51));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(460, 170, 160, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_from_N = new QLabel(horizontalLayoutWidget);
        label_from_N->setObjectName(QStringLiteral("label_from_N"));

        horizontalLayout->addWidget(label_from_N);

        label_from = new QLabel(horizontalLayoutWidget);
        label_from->setObjectName(QStringLiteral("label_from"));

        horizontalLayout->addWidget(label_from);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(460, 240, 160, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_to_N = new QLabel(horizontalLayoutWidget_2);
        label_to_N->setObjectName(QStringLiteral("label_to_N"));

        horizontalLayout_2->addWidget(label_to_N);

        label_to = new QLabel(horizontalLayoutWidget_2);
        label_to->setObjectName(QStringLiteral("label_to"));

        horizontalLayout_2->addWidget(label_to);

        pushButton_from_plus = new QPushButton(centralwidget);
        pushButton_from_plus->setObjectName(QStringLiteral("pushButton_from_plus"));
        pushButton_from_plus->setGeometry(QRect(650, 190, 31, 34));
        pushButton_from_minus = new QPushButton(centralwidget);
        pushButton_from_minus->setObjectName(QStringLiteral("pushButton_from_minus"));
        pushButton_from_minus->setGeometry(QRect(700, 190, 31, 34));
        pushButton_to_plus = new QPushButton(centralwidget);
        pushButton_to_plus->setObjectName(QStringLiteral("pushButton_to_plus"));
        pushButton_to_plus->setGeometry(QRect(650, 250, 31, 34));
        pushButton_to_minus = new QPushButton(centralwidget);
        pushButton_to_minus->setObjectName(QStringLiteral("pushButton_to_minus"));
        pushButton_to_minus->setGeometry(QRect(700, 250, 31, 34));
        pushButton_generate_path = new QPushButton(centralwidget);
        pushButton_generate_path->setObjectName(QStringLiteral("pushButton_generate_path"));
        pushButton_generate_path->setGeometry(QRect(500, 330, 221, 41));
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(510, 410, 201, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_ves_N = new QLabel(horizontalLayoutWidget_3);
        label_ves_N->setObjectName(QStringLiteral("label_ves_N"));

        horizontalLayout_3->addWidget(label_ves_N);

        label_ves = new QLabel(horizontalLayoutWidget_3);
        label_ves->setObjectName(QStringLiteral("label_ves"));
        label_ves->setLayoutDirection(Qt::LeftToRight);
        label_ves->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_ves);

        label_error = new QLabel(centralwidget);
        label_error->setObjectName(QStringLiteral("label_error"));
        label_error->setGeometry(QRect(450, 530, 311, 51));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_InputeFilePath->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203:", nullptr));
        pushButton_draw_basic_graf->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", nullptr));
        label_from_N->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\203\320\264\320\260:", nullptr));
        label_from->setText(QString());
        label_to_N->setText(QApplication::translate("MainWindow", "\320\232\321\203\320\264\320\260: ", nullptr));
        label_to->setText(QString());
        pushButton_from_plus->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_from_minus->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_to_plus->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_to_minus->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_generate_path->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        label_ves_N->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\201 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\320\260:", nullptr));
        label_ves->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
