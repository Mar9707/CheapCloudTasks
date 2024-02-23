#include <QApplication>
#include <QInputDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>

int max (int* arr, const int size){
    int maximum = arr[0];
    for(int i = 1; i < size; ++i){
        if (arr[i] > maximum){
            maximum = arr[i];
        }
    }

    return maximum;
}

int min (int* arr, const int size){
    int minimum = arr[0];
    for (int i = 1; i < size; ++i){
        if (arr[i] <  minimum){
            minimum = arr[i];
        }
    }

    return minimum;
}


double average (int* arr, const int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum / size;
}

int length(const char* arr) {
    if (arr == nullptr) {
        return 0;
    }

    int size = 0;
    while (arr[size]) {
        ++size;
    }

    return size;
}

const char* concat(const char* a, const char* b) {
    size_t i = length(a);
    size_t j = length(b);
    size_t size = i + j + 1;
    char* result = new char[size];
    i = 0;
    j = 0;
    while (a[i]) {
        result[i] = a[i];
        ++i;
    }

    while (b[j]) {
        result[i++] = b[j];
        ++j;
    }

    result[size - 1] = '\0';
    return result;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const int size = 5;
    int arr[size] = {0};
    for (int i = 0; i < 5; ++i) {
        arr[i] = QInputDialog::getInt(nullptr, "Enter value", "Enter value #" + QString::number(i + 1) + ":");
    }

    int maxVal = max(arr, size);
    int minVal = min(arr, size);
    double avgVal = average(arr, size);

    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    const char* strstr = concat(str1, str2);


    QString result = QString("Maximum value: %1\nMinimum value: %2\nAverage value: %3\nConcat string: %4\n")
                         .arg(maxVal)
                         .arg(minVal)
                         .arg(avgVal)
                         .arg(strstr);

    QLabel* label = new QLabel(result);
    label->show();
    return a.exec();
}
