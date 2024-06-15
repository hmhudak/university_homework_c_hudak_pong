/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *scoreLabel;
    QPushButton *pauseButton;
    QFrame *gameFrame;
    QWidget *playerPaddle;
    QWidget *aiPaddle;
    QWidget *ball;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(360, 10, 80, 30));
        scoreLabel->setAlignment(Qt::AlignCenter);
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(700, 10, 75, 30));
        gameFrame = new QFrame(centralwidget);
        gameFrame->setObjectName("gameFrame");
        gameFrame->setGeometry(QRect(50, 50, 700, 500));
        gameFrame->setFrameShape(QFrame::Box);
        gameFrame->setLineWidth(2);
        playerPaddle = new QWidget(gameFrame);
        playerPaddle->setObjectName("playerPaddle");
        playerPaddle->setGeometry(QRect(30, 200, 20, 100));
        playerPaddle->setStyleSheet(QString::fromUtf8("background-color: #000000;"));
        aiPaddle = new QWidget(gameFrame);
        aiPaddle->setObjectName("aiPaddle");
        aiPaddle->setGeometry(QRect(650, 200, 20, 100));
        aiPaddle->setStyleSheet(QString::fromUtf8("background-color: #000000;"));
        ball = new QWidget(gameFrame);
        ball->setObjectName("ball");
        ball->setGeometry(QRect(340, 240, 20, 20));
        ball->setStyleSheet(QString::fromUtf8("background-color: #FF0000; border-radius: 10px;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        scoreLabel->setText(QCoreApplication::translate("MainWindow", "0:0", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
