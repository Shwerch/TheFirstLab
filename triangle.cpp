#include <cmath>
#include <iostream>
using namespace std;

bool triangleCalculations(double sides[], double *perimeter, double *square, bool *isosceles) {
	// Проверка, может ли существовать треугольник с такими сторонами
	for (int i = 0; i < 3; i++)
		if (((sides[i] + sides[(i + 1) % 3]) <= sides[(i + 2) % 3]) || (sides[i] <= 0))
			return false;
	// Вычисление периметра
	for (int i = 0; i < 3; i++)
		*perimeter += sides[i];
	// Вычисление площади
	double halfPerimeter = *perimeter / 2;
	*square = pow(halfPerimeter * (halfPerimeter - sides[0]) * (halfPerimeter - sides[1]) * (halfPerimeter - sides[2]), 0.5);
	// Определение, равнобедренный ли треугольник
	*isosceles = false;
	for (int i = 0; i < 3; i++)
		if (sides[i] == sides[(i + 1) % 3])
			*isosceles = true;
	return true;
}
// Комментарий)

int main() {
	while (true) {
		// Ввод параметров треугольника
		double sides[3];
		for (int i = 0; i < 3; i++) {
			cout << "Введите " << i + 1 << "-ю сторону треугольника: ";
			while (!(cin >> sides[i])) {
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		cout << endl;
		// Рассчет и вывод параметров треугольника
		double perimeter, square;
		bool isosceles, result = triangleCalculations(sides, &perimeter, &square, &isosceles);
		if (result) {
			cout << "Стороны:  " << sides[0] << " " << sides[1] << " " << sides[2] << endl;
			cout << "Периметр: " << perimeter << endl;
			cout << "Площадь:  " << square << endl;
			cout << ((isosceles) ? "Равнобедренный" : "Не равнобедренный") << " треугольник" << endl;
		} else
			cout << "Треугольник с такими сторонами не может существовать!" << endl;
		cout << endl;
	}
	return 0;
}
