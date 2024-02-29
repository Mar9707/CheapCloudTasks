#include <QApplication>
#include <QVector>
#include <QFile>
#include <QInputDialog>
#include <QTextEdit>

enum Sort {
    bubble,
    selection
};

void bubbleSort(QVector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(QVector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}


struct sorting {
    Sort x;
    void (*ptr)(QVector<int>&);
};

sorting sortArr[] = {
    {bubble, &bubbleSort},
    {selection, &selectionSort}
};






int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector<int> arr;
    QString name = QInputDialog::getText(nullptr, "Enter file name", "Enter file name");
    QFile file(name);
    QTextStream in (&file);

if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextEdit *textEdit = new QTextEdit();
    textEdit->setPlainText("Failed to open file for reading");
    textEdit->show();
    return 1;
} else {
    while (!in.atEnd()) {
       QString str = in.readLine();
       arr.append(str.toInt());
    }
     file.close();
}

QString choose = QInputDialog::getText(nullptr, "Enter sorting name", "Enter sorting name");

if (choose == "bubble") {
    sortArr[0].ptr(arr);
} else if (choose == "selection"){
    sortArr[1].ptr(arr);
} else {
    throw std::invalid_argument("Error");
}


QFile outFile(name);
if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qDebug() << "Failed to open file: " << name;
} else {
    QTextStream out(&outFile);
    for (int i = arr.size() - 1; i >= 0; i--) {
    out << arr[i] << "\n";
    }

    outFile.close();
}


   return a.exec();
}
