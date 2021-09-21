#include "functions.h"


//class database {
//private:
//    struct Record_card {
//        int place_number;
//        string full_name;
//        string car_model;
//        bool car_avaliability;
//        bool payment_avaliability;
//    };
//
//public: 
//
//};

int menuState = 0;


//menu 
void menu() {
    system("cls");
    cout << "(1) Создание файла информационной базы" << endl;
    cout << "(2) Распечатка информационной базы" << endl;
    cout << "(3) Обработка информационной базы" << endl;
    cout << "(4) Добавление записей в базу данных" << endl;
    cout << "(5) Удаление ненужных записей из базы" << endl;
    cout << "(6) Изменение записи с заданным ключевым полем" << endl;
    cout << "(7) Окончание работы" << endl;
    cout << "\nВаш выбор: ";
    cin >> menuState;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //console menu
    menu();

    int actions;
    int dataAmount = 0;
    string fileName;

    Data* d = new Data[dataAmount];
    

    while (menuState != 7) {
        switch (menuState)
        {
        case 1:
            system("cls");
            DataEntry(d, dataAmount);
            menu();
            break;

        case 2:
            system("cls");
            ReadingData(d, dataAmount);
            system("pause");
            menu();
            break;

        case 3:
            system("cls");
            cout << "Какие свеения вы хотите получить?" << endl;
            cout << "(1) Выдача сведений о свободных автостоянках в данный момент" << endl;
            cout << "(2) Выдача сведений о владельцах автомобилей, не оплативших за пользование автостоянкой" << endl;
            cout << "\nВаш выбор: ";
            cin >> actions;

            switch (actions) 
            {
            case 1: 
                system("cls");
                AvaliablePlaces(d, dataAmount);
                system("pause");
                menu();
                break;

            case 2:
                system("cls");
                NonPaidUsers(d, dataAmount);
                system("pause");
                menu();
                break;
            }

            break;

        case 4:
            system("cls");
            addInfo(d, dataAmount);
            system("pause");
            menu();
            break;

        case 5:
            system("cls");
            deleteByNumber(d, dataAmount);
            menu();
            break;

        case 6:
            system("cls");
            editByNumber(d, dataAmount);
            menu();
            break;

        default:
            break;
        }
    }

}
