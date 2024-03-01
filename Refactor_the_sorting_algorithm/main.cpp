#include <QApplication>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

class SortingStrategy {
public:
    virtual void sort(QVector<int>&) const = 0;
};

class BubbleSort : public SortingStrategy{
public:
    void sort (QVector<int>& vec) const override {
        int size = vec.size();
        for (int i = 0; i < size; ++i){
            for(int j = 0; j < size - 1; ++j){
                if (vec[j] > vec[j + 1]){
                    qSwap(vec[j], vec[j + 1]);
                }
            }
        }
    }
};

class SelectionSort : public SortingStrategy {
public:
    void sort (QVector<int>& vec) const override {
        int size = vec.size();
        for(int i = 0; i < size - 1; ++i){
            int min = i;
            for (int j = i + 1; j < size; ++j){
                if (vec[j] < vec[min]){
                    min = j;
                }
            }

            qSwap(vec[i],vec[min]);
        }
    }
};

class FileHandler {
public:
    QVector<int> readArrayFromFile(const QString& filename) {
        QVector<int> array;
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                array.append(line.toInt());
            }
            file.close();
        }
        return array;
    }

    void saveArrayToFile(const QVector<int>& array, const QString& filename) {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            for (int i : array)
            {
                out << i << "\n";
            }
            file.close();
        }
    }

};


class SortingApplication {
private:
    SortingStrategy* strategy;
    FileHandler* fileHandler;

public:
    SortingApplication () : strategy(nullptr), fileHandler (nullptr) {}
    SortingApplication (SortingStrategy* s, FileHandler* f) : strategy(s), fileHandler(f) {}

    void run() {
    QString inputFileName = QInputDialog::getText(nullptr, "Enter input file name", "Enter input file name");
    QString outputFileName = QInputDialog::getText(nullptr, "Enter output file name", "Enter output file name");

    QVector<int> array = fileHandler->readArrayFromFile(inputFileName);
    strategy->sort(array);
    fileHandler->saveArrayToFile(array, outputFileName);
    }
};







int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SelectionSort select;
    FileHandler file;
    SortingApplication sortingApp(&select, &file);
    sortingApp.run();
    return a.exec();
}
