#include <QApplication>
#include <QLabel>
#include <QString>
#include <QInputDialog>


    enum week {
        monday = 1,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday
    };

    struct date {
        int day;
        QString month;
        int year;
    };


    void printDate (week week, date date, QLabel* label) {
        QString x;
        switch (week) {
        case monday: x = "monday"; break;
        case tuesday: x = "tuesday"; break;
        case wednesday: x = "wednesday"; break;
        case thursday: x = "thursday"; break;
        case friday: x = "friday"; break;
        case saturday: x = "saturnday"; break;
        case sunday: x = "sunday"; break;
        }

        label->setText(x + ", " + QString::number(date.day) + " " + date.month + QString::number(date.year));
    }





    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
        date myDate;
        myDate.day = QInputDialog::getInt(nullptr, "Enter day", "Enter day:");
        myDate.month = QInputDialog::getText(nullptr, "Enter month", "Enter month:");
        myDate.year = QInputDialog::getInt(nullptr, "Enter year", "Enter year:");

        int dayOfWeekNum = QInputDialog::getInt(nullptr, "Enter day of the week", "Enter day of the week (1-7):");
        week dayOfWeek = static_cast<week>(dayOfWeekNum);

        QLabel label;
        printDate(dayOfWeek, myDate, &label);
        label.show();



    return a.exec();
}
