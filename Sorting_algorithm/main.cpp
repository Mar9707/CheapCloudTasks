#include <QApplication>
#include <QInputDialog>
#include <QLabel>

void bubble (int* arr, int size) {
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - 1; ++j){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void selection (int* arr, int size){
    for(int i = 0; i < size - 1; ++i) {
        int min = i;
        for(int j = i + 1; j < size; ++j){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        std::swap(arr[i], arr[min]);
    }
}


void chooseSort(int* arr, int size) {
    void (*ptr) (int*, int) = nullptr;
    int choose = QInputDialog::getInt(nullptr, "Choose sorting algorithm",  "1 for Bubble Sort, 2 for Selection Sort");
    if(choose == 1) {
        ptr = &bubble;
    } else if (choose == 2) {
        ptr = &selection;
    }

    ptr(arr, size);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int size = 5;
    int arr[size] = {5, 9, 1, 6, 7};
    chooseSort(arr, size);

    QString sortedArray;
    for (int i = 0; i < size; ++i) {
        sortedArray += QString::number(arr[i]) + " ";
    }

    QLabel* label = new QLabel (sortedArray);
    label->resize(500,500);
    label->show();
    return a.exec();
}
