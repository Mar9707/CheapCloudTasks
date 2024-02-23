#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int age = 26;
    bool valid = true;
    float pi = 3.14;
    double num = 3.521651561;
    char x = 'A';

    QString labelText = QString("int = %1\nbool = %2\nfloat = %3\ndouble = %4\nchar = %5\n")
                            .arg(age)
                            .arg(valid)
                            .arg(pi)
                            .arg(num)
                            .arg(x);
    QLabel label(labelText);
    label.resize(400, 300);
    label.show();
    return a.exec();
}
