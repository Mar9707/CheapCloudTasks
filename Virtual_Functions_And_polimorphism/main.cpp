#include <QLabel>
#include <QApplication>
#include <QInputDialog>
#include <QString>


class Shape {
public:
    virtual double area () const  = 0;
};


class Circle : public Shape {
private:
    double r;

public:
    Circle (double r) : r{r} {}

    double area () const override {
        return r * r * 3.14;
    }

    double getCircle () const {
        return r;
    }

    void setCircle (double x) {
        r = x;
    }
};


class Rectangle : public Shape {
private:
    double x;
    double y;

public:
    Rectangle (double k, double k1) : x{k}, y{k1} {}

    double area () const override {
        return x * y;
    }

    double getX () const {
        return x;
    }

    double getY () const {
        return y;
    }

    void setX (double r){
        x = r;
    }

    void setY (double r) {
        y = r;
    }
};

void print (const Shape* ptr){
    QString str = QString::number(ptr->area());
    QLabel* label = new QLabel (str);
    label->resize(300,400);
    label->show();

    QObject::connect(label, &QObject::destroyed, [label]() {
        delete label;
    });
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Circle ob(5);
    Rectangle obj(3,4);
    print(&ob);
    print(&obj);
    return a.exec();
}
