#include <iostream>
#include <cmath>
using namespace std;

bool rectangleCalculations(double length, double width, double* perimeter, double* area, double* diagonal) {
    if (length <= 0 || width <= 0) //проверка на положительность сторон
        return false;
    *perimeter = 2 * (length + width); // периметр
    *area = length * width;             // площадь
    *diagonal = sqrt(length * length + width * width); // длина диагонали
    return true;
}

int main() {
    double length, width;
    cout << "Введите длину прямоугольника: ";
    cin >> length;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;

    double perimeter, area, diagonal;
    bool result = rectangleCalculations(length, width, &perimeter, &area, &diagonal);

    if (result) {
        cout << "Периметр прямоугольника: " << perimeter << endl;
        cout << "Площадь прямоугольника: " << area << endl;
        cout << "Длина диагонали прямоугольника: " << diagonal << endl;
    }
    else {
        cout << "Длина и ширина должны быть положительными числами" << endl;
    }

    return 0;
}
