#include <QApplication>
#include <QString>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int num = 15;
    int* ptr = &num;
    int& rf = num;

    int tempnum = *ptr - 8;
    int tmp = rf - 12;

    QString number = QString("variable = %1\npointer variable = %2\nreference variable = %3\n")
                         .arg(num)
                         .arg(tempnum)
                         .arg(tmp);

    QLabel label(number);
    label.resize(200, 200);
    label.show();




    return a.exec();
}
