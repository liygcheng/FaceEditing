#include "FaceEditing.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaceEditing w;
    w.show();
    return a.exec();
}
