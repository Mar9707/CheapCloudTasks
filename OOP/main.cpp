#include <QObject>
#include <QApplication>
#include <QString>
#include <QLabel>


class Book {
private:
    QString name;
    QString author;
    int ISBN;


public:
    QString getName () const {
        return name;
    }

    QString getAuthor () const {
        return author;
    }

    int getISBN () const {
        return ISBN;
    }

    void setName (QString a){
        name = a;
    }

    void setAuthor (QString a) {
        author = a;
    }

    void setISBN (int num) {
        ISBN = num;
    }


};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Book book;
    book.setName("The picture of Dorian Grey");
    book.setAuthor("Oscar Wilde");
    book.setISBN(15464131);

    QString name = book.getName();
    QString author = book.getAuthor();
    int ISBN = book.getISBN();

    QString view =  QString("Book of name: %1\nBook of author: %2\nBook of ISBN: %3\n")
                       .arg(name)
                       .arg(author)
                       .arg(ISBN);

    QLabel label(view);
    label.resize(400,500);
    label.show();

    return a.exec();
}
