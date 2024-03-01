#include <QLabel>
#include <QApplication>
#include <stdexcept>
#include <QInputDialog>
#include <QString>


class Shape {
public:
    virtual double area () const  = 0;
    void throwException () const {
        throw std::invalid_argument ("Error");
    }
};


class Circle : public Shape {
public:
    Circle (double r) : r{r} {
        if (r <= 0){
            throwException();
        }
    }

    double area () const override {
               return r * r * 3.14;
    }

private:
    double r;

};


class Rectangle : public Shape {
public:
    Rectangle (double k, double k1) : x{k}, y{k1} {
        if (x <= 0 || y <= 0){
            throwException();
        }
    }
    double area () const override {
        return x * y;
    }

private:
    double x;
    double y;

};




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    double x = QInputDialog::getInt(nullptr, "Enter radius", "Enter radius");
    Circle ob(x);

    double y = QInputDialog::getInt(nullptr, "Enter side 1", "Enter side 1");
    double r = QInputDialog::getInt(nullptr, "Enter side 2", "Enter side 2");
    Rectangle obj(y, r);

    double ar1 = ob.area();
    double ar2 = obj.area();

    QString str = QString("Circle area = %1\nRectangle area = %2\n")
                       .arg(ar1)
                       .arg(ar2);
    QLabel label(str);
    label.show();
    return a.exec();
}
