#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FaceEditing.h"

#include"Element.h"

class FaceEditing : public QMainWindow
{
    Q_OBJECT

public:
    FaceEditing(QWidget *parent = Q_NULLPTR);

private:
    Ui::FaceEditingClass ui;
};
