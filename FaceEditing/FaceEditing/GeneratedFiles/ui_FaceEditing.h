/********************************************************************************
** Form generated from reading UI file 'FaceEditing.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEEDITING_H
#define UI_FACEEDITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceEditingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FaceEditingClass)
    {
        if (FaceEditingClass->objectName().isEmpty())
            FaceEditingClass->setObjectName(QStringLiteral("FaceEditingClass"));
        FaceEditingClass->resize(600, 400);
        menuBar = new QMenuBar(FaceEditingClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FaceEditingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FaceEditingClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FaceEditingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FaceEditingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FaceEditingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FaceEditingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FaceEditingClass->setStatusBar(statusBar);

        retranslateUi(FaceEditingClass);

        QMetaObject::connectSlotsByName(FaceEditingClass);
    } // setupUi

    void retranslateUi(QMainWindow *FaceEditingClass)
    {
        FaceEditingClass->setWindowTitle(QApplication::translate("FaceEditingClass", "FaceEditing", 0));
    } // retranslateUi

};

namespace Ui {
    class FaceEditingClass: public Ui_FaceEditingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEEDITING_H
