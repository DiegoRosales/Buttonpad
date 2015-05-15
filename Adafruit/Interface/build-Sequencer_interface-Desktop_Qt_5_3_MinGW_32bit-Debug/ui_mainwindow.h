/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *serialComboBox;
    QPushButton *refreshButton;
    QPushButton *openButton;
    QPushButton *closeButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCommandLinkButton *commandLinkButton;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *t1;
    QRadioButton *t2;
    QRadioButton *t3;
    QRadioButton *t4;
    QRadioButton *t5;
    QRadioButton *t6;
    QRadioButton *t7;
    QRadioButton *t8;
    QGridLayout *gridLayout;
    QPushButton *pb16;
    QPushButton *pb15;
    QPushButton *pb11;
    QPushButton *pb10;
    QPushButton *pb1;
    QPushButton *pb7;
    QPushButton *pb5;
    QPushButton *pb9;
    QPushButton *pb2;
    QPushButton *pb8;
    QPushButton *pb3;
    QPushButton *pb14;
    QPushButton *pb6;
    QPushButton *pb4;
    QPushButton *pb13;
    QPushButton *pb12;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(440, 383);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        serialComboBox = new QComboBox(groupBox);
        serialComboBox->setObjectName(QStringLiteral("serialComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(serialComboBox->sizePolicy().hasHeightForWidth());
        serialComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(serialComboBox);

        refreshButton = new QPushButton(groupBox);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        openButton = new QPushButton(groupBox);
        openButton->setObjectName(QStringLiteral("openButton"));

        horizontalLayout->addWidget(openButton);

        closeButton = new QPushButton(groupBox);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addWidget(groupBox);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        commandLinkButton = new QCommandLinkButton(tab);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(140, 140, 172, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        t1 = new QRadioButton(tab_2);
        t1->setObjectName(QStringLiteral("t1"));

        verticalLayout_2->addWidget(t1);

        t2 = new QRadioButton(tab_2);
        t2->setObjectName(QStringLiteral("t2"));

        verticalLayout_2->addWidget(t2);

        t3 = new QRadioButton(tab_2);
        t3->setObjectName(QStringLiteral("t3"));

        verticalLayout_2->addWidget(t3);

        t4 = new QRadioButton(tab_2);
        t4->setObjectName(QStringLiteral("t4"));

        verticalLayout_2->addWidget(t4);

        t5 = new QRadioButton(tab_2);
        t5->setObjectName(QStringLiteral("t5"));

        verticalLayout_2->addWidget(t5);

        t6 = new QRadioButton(tab_2);
        t6->setObjectName(QStringLiteral("t6"));

        verticalLayout_2->addWidget(t6);

        t7 = new QRadioButton(tab_2);
        t7->setObjectName(QStringLiteral("t7"));

        verticalLayout_2->addWidget(t7);

        t8 = new QRadioButton(tab_2);
        t8->setObjectName(QStringLiteral("t8"));

        verticalLayout_2->addWidget(t8);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pb16 = new QPushButton(tab_2);
        pb16->setObjectName(QStringLiteral("pb16"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb16->sizePolicy().hasHeightForWidth());
        pb16->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb16, 3, 3, 1, 1);

        pb15 = new QPushButton(tab_2);
        pb15->setObjectName(QStringLiteral("pb15"));
        sizePolicy2.setHeightForWidth(pb15->sizePolicy().hasHeightForWidth());
        pb15->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb15, 3, 2, 1, 1);

        pb11 = new QPushButton(tab_2);
        pb11->setObjectName(QStringLiteral("pb11"));
        sizePolicy2.setHeightForWidth(pb11->sizePolicy().hasHeightForWidth());
        pb11->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb11, 2, 2, 1, 1);

        pb10 = new QPushButton(tab_2);
        pb10->setObjectName(QStringLiteral("pb10"));
        sizePolicy2.setHeightForWidth(pb10->sizePolicy().hasHeightForWidth());
        pb10->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb10, 2, 1, 1, 1);

        pb1 = new QPushButton(tab_2);
        pb1->setObjectName(QStringLiteral("pb1"));
        sizePolicy2.setHeightForWidth(pb1->sizePolicy().hasHeightForWidth());
        pb1->setSizePolicy(sizePolicy2);
        pb1->setAutoDefault(false);
        pb1->setFlat(false);

        gridLayout->addWidget(pb1, 0, 0, 1, 1);

        pb7 = new QPushButton(tab_2);
        pb7->setObjectName(QStringLiteral("pb7"));
        sizePolicy2.setHeightForWidth(pb7->sizePolicy().hasHeightForWidth());
        pb7->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb7, 1, 2, 1, 1);

        pb5 = new QPushButton(tab_2);
        pb5->setObjectName(QStringLiteral("pb5"));
        sizePolicy2.setHeightForWidth(pb5->sizePolicy().hasHeightForWidth());
        pb5->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb5, 1, 0, 1, 1);

        pb9 = new QPushButton(tab_2);
        pb9->setObjectName(QStringLiteral("pb9"));
        sizePolicy2.setHeightForWidth(pb9->sizePolicy().hasHeightForWidth());
        pb9->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb9, 2, 0, 1, 1);

        pb2 = new QPushButton(tab_2);
        pb2->setObjectName(QStringLiteral("pb2"));
        sizePolicy2.setHeightForWidth(pb2->sizePolicy().hasHeightForWidth());
        pb2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb2, 0, 1, 1, 1);

        pb8 = new QPushButton(tab_2);
        pb8->setObjectName(QStringLiteral("pb8"));
        sizePolicy2.setHeightForWidth(pb8->sizePolicy().hasHeightForWidth());
        pb8->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb8, 1, 3, 1, 1);

        pb3 = new QPushButton(tab_2);
        pb3->setObjectName(QStringLiteral("pb3"));
        sizePolicy2.setHeightForWidth(pb3->sizePolicy().hasHeightForWidth());
        pb3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb3, 0, 2, 1, 1);

        pb14 = new QPushButton(tab_2);
        pb14->setObjectName(QStringLiteral("pb14"));
        sizePolicy2.setHeightForWidth(pb14->sizePolicy().hasHeightForWidth());
        pb14->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb14, 3, 1, 1, 1);

        pb6 = new QPushButton(tab_2);
        pb6->setObjectName(QStringLiteral("pb6"));
        sizePolicy2.setHeightForWidth(pb6->sizePolicy().hasHeightForWidth());
        pb6->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb6, 1, 1, 1, 1);

        pb4 = new QPushButton(tab_2);
        pb4->setObjectName(QStringLiteral("pb4"));
        sizePolicy2.setHeightForWidth(pb4->sizePolicy().hasHeightForWidth());
        pb4->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb4, 0, 3, 1, 1);

        pb13 = new QPushButton(tab_2);
        pb13->setObjectName(QStringLiteral("pb13"));
        sizePolicy2.setHeightForWidth(pb13->sizePolicy().hasHeightForWidth());
        pb13->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb13, 3, 0, 1, 1);

        pb12 = new QPushButton(tab_2);
        pb12->setObjectName(QStringLiteral("pb12"));
        sizePolicy2.setHeightForWidth(pb12->sizePolicy().hasHeightForWidth());
        pb12->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pb12, 2, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 440, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Serial port", 0));
        refreshButton->setText(QApplication::translate("MainWindow", "Refresh", 0));
        openButton->setText(QApplication::translate("MainWindow", "Open", 0));
        closeButton->setText(QApplication::translate("MainWindow", "Close", 0));
        commandLinkButton->setText(QApplication::translate("MainWindow", "CommandLinkButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Settings", 0));
        label->setText(QApplication::translate("MainWindow", "Track selection", 0));
        t1->setText(QApplication::translate("MainWindow", "Track 1", 0));
        t2->setText(QApplication::translate("MainWindow", "Track 2", 0));
        t3->setText(QApplication::translate("MainWindow", "Track 3", 0));
        t4->setText(QApplication::translate("MainWindow", "Track 4", 0));
        t5->setText(QApplication::translate("MainWindow", "Track 5", 0));
        t6->setText(QApplication::translate("MainWindow", "Track 6", 0));
        t7->setText(QApplication::translate("MainWindow", "Track 7", 0));
        t8->setText(QApplication::translate("MainWindow", "Track 8", 0));
        pb16->setText(QApplication::translate("MainWindow", "16", 0));
        pb15->setText(QApplication::translate("MainWindow", "15", 0));
        pb11->setText(QApplication::translate("MainWindow", "11", 0));
        pb10->setText(QApplication::translate("MainWindow", "10", 0));
        pb1->setText(QApplication::translate("MainWindow", "1", 0));
        pb7->setText(QApplication::translate("MainWindow", "7", 0));
        pb5->setText(QApplication::translate("MainWindow", "5", 0));
        pb9->setText(QApplication::translate("MainWindow", "9", 0));
        pb2->setText(QApplication::translate("MainWindow", "2", 0));
        pb8->setText(QApplication::translate("MainWindow", "8", 0));
        pb3->setText(QApplication::translate("MainWindow", "3", 0));
        pb14->setText(QApplication::translate("MainWindow", "14", 0));
        pb6->setText(QApplication::translate("MainWindow", "6", 0));
        pb4->setText(QApplication::translate("MainWindow", "4", 0));
        pb13->setText(QApplication::translate("MainWindow", "13", 0));
        pb12->setText(QApplication::translate("MainWindow", "12", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Sequencer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
