#include <QApplication>
#include <QObject>
#include <QLabel>

class Shape {
public:
    virtual double calculate () const = 0;
};


class Rectangle : public Shape {
public:
    double x;
    double y;
    double z;
    double h;

public:
    double calculate () const override {
        return x * y;
    }
};


class Circle : public Shape {
public:
    double r;

public:
    double calculate () const override {
        return r * r * 3.14;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Rectangle ob;
    ob.x = 4;
    ob.y = 5;
    ob.z = 4;
    ob.h = 5;

    double areaRec = ob.calculate();

    Circle obj;
    obj.r = 5;
    double areaCir = obj.calculate();

    QString area = QString("Rectangle area = %1\nCircle area = %2\n")
                   .arg(areaRec)
                   .arg(areaCir);

    QLabel label(area);
    label.resize(400,500);
    label.show();


       return a.exec();
}
