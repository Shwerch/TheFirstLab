#include <iostream>

using namespace std;

// Структура для хранения параметров окружности
struct CircleParameters {
    int radius;
    float angle; // Угол будет использоваться только в случае сектора
};

// Функция для получения параметров окружности
CircleParameters enterCircleParameters(int option) {
    CircleParameters params;

    // Запрашиваем радиус
    do {
        cout << "Введите радиус (в сантиметрах): ";
        cin >> params.radius;
        if (params.radius < 0) {
            cout << "Введите положительное число.\n";
        }
    } while (params.radius < 0);

    // Если выбран сектор, нужно также запросить угол
    if (option == 3) {
        do {
            cout << "Введите угол в градусах (0-360): ";
            cin >> params.angle;
            if (params.angle < 0 || params.angle > 360) {
                cout << "Ошибка: угол должен быть в пределах 0-360 градусов.\n";
            }
        } while (params.angle < 0 || params.angle > 360);
    } else {
        params.angle = 0; // Угол не понадобится для первой и второй опции
    }

    return params;
}

float circle_length(int R) { // функция для расчета длины окружности
    return 2 * 3.14 * R;
}

float circle_area(int R) { // функция для расчета площади круга
    return 3.14 * R * R;
}

float circle_sector_area(int R, float angle) { // функция для расчета площади сектора окружности
    return (angle / 360) * circle_area(R);
}

int main() {
    short int choice = 0; // переменная для выбора действия
    while (true) { // бесконечный цикл меню
        cout << "\nВыберите действие с окружностью:\n";
        cout << "1: Вычислить длину окружности\n";
        cout << "2: Вычислить площадь круга\n";
        cout << "3: Вычислить площадь кругового сектора\n";
        cout << "4: Выход из программы\n";

        cin >> choice;

        CircleParameters params;
        if (choice == 1 || choice == 2 || choice == 3) {

            // Получаем параметры с помощью новой функции
            params = enterCircleParameters(choice);
        }

            return 0;
        } else {
            // Если пользователь ввел не существующий номер
            cout << "Несуществующий выбор. Пожалуйста, повторите попытку\n";
        }
    }

    return 0;
}
