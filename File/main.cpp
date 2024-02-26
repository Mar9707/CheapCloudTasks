#include <QApplication>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QFile file("text.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextEdit *textEdit = new QTextEdit(&w);
        textEdit->setPlainText("Failed to open file for writing");
        QVBoxLayout *layout = new QVBoxLayout(&w);
        layout->addWidget(textEdit);
        w.setLayout(layout);
        w.show();
        return -1;
    }

    QTextStream out(&file);

    out << "Anna\n";
    out << "Alisa\n";
    out << "Mariam\n";
    out << "Astgik\n";

    file.close();

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextEdit *textEdit = new QTextEdit(&w);
        textEdit->setPlainText("Failed to open file for reading");
        QVBoxLayout *layout = new QVBoxLayout(&w);
        layout->addWidget(textEdit);
        w.setLayout(layout);
        w.show();
        return -1;
    }

    QTextStream in(&file);

    QTextEdit *textEdit = new QTextEdit(&w);

    while (!in.atEnd()) {
        QString line = in.readLine();
        textEdit->append(line);
    }

    file.close();

    QVBoxLayout *layout = new QVBoxLayout(&w);
    layout->addWidget(textEdit);
    w.setLayout(layout);
    w.show();

    return a.exec();
}
