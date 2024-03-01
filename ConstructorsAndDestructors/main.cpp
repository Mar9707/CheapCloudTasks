#include <QApplication>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

class SortingStrategy {
public:
    virtual void sort(QVector<int>&) const = 0;
    virtual ~SortingStrategy () {}
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

    BubbleSort () {}
    ~BubbleSort () {}
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

    SelectionSort () {}
    ~SelectionSort () {}
};



class FileHandler {
private:
    QFile f;

public:
    FileHandler() {}
    FileHandler(const QString& str) : f(str) {
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw std::runtime_error("Failed to open file for reading.");
            return;
        }
    }

    ~FileHandler () {
        f.close();
    }


    QVector<int> readArrayFromFile () {
        QVector<int> array;
        QTextStream in(&f);
        while (!in.atEnd()) {
            QString line = in.readLine();
            array.append(line.toInt());
        }
        f.close();
        return array;
    }


    void saveArrayToFile(const QVector<int>& array) {
        if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
            throw std::runtime_error("Failed to open file for writing.");
            return;
        }

        QTextStream out(&f);
        for (int i : array) {
            out << i << "\n";
        }
        f.close();
    }
};


class SortingApplication {
private:
    SortingStrategy* strategy;
    FileHandler* fileHandler;

public:
    SortingApplication () : strategy(nullptr), fileHandler (nullptr) {}
    SortingApplication (SortingStrategy* s, FileHandler* f) : strategy(s), fileHandler(f) {}
    ~SortingApplication () {
        delete strategy;
        delete fileHandler;
    }

    void run() {
        if (!strategy || !fileHandler) {
            throw std::runtime_error("");
            return;
        }
        QString inputFileName = QInputDialog::getText(nullptr, "Enter input file name", "Enter input file name");
        QString outputFileName = QInputDialog::getText(nullptr, "Enter output file name", "Enter output file name");

        QVector<int> array = fileHandler->readArrayFromFile();
        strategy->sort(array);
        fileHandler->saveArrayToFile(array);
    }
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortingStrategy* strategy = new SelectionSort();
    FileHandler* fileHandler = new FileHandler("input.txt");
    SortingApplication sortingApp(strategy, fileHandler);

    sortingApp.run();
    return a.exec();
}
