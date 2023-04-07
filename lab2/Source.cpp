#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <numeric>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ukrainian");
	srand(time(NULL));

	int n = 10;
	vector<int> mas(n);

	cout << "Масив: " << endl;
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 30 - 10;
	}


	int sum = 0;
	vector<int>::iterator min, FirstNegative, it, compressed_mas;

	for (it = mas.begin(); it != mas.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//обчислити номер мінімального по модулю елемента масиву
	min = min_element(mas.begin(), mas.end(), [](int a, int b) {return abs(a) < abs(b); });
	cout << endl;
	cout << "Мiнiмальне число по модулю: " << *min << endl << endl;
	cout << "Номер мiнiмального елемента: " << min - mas.begin() << endl << endl;

	//обчислити суму модулів елементів масиву, розташованих після першого від’ємного елемента,
	FirstNegative = find_if(mas.begin(), mas.end(), [](int a) {
		return a < 0; });
	cout << "Перший вiд'ємний елемент: " << *FirstNegative << endl << endl;
	sum = accumulate(FirstNegative + 1, mas.end(), 0, [](int a, int b) {return a + abs(b); });
	cout << "номер мiнiмального по модулю елемента масиву: " << FirstNegative - mas.begin() << endl << endl;
	cout << "сума модулiв елементiв масиву, розташованих пiсля першого вiд’ємного елемента: " << sum << endl << endl;
	
	//стиснути масив, видаливши з нього всі елементи, величина яких знаходиться в інтервалі 
	//[a, b].Елементи, що звільнились в кінці масиву, заповнити нулями.
	int a, b;
	cout << "Введiть значення а:";
	cin >> a;
	cout << "Введiть значення b:";
	cin >> b;

	cout << endl;
	compressed_mas = remove_if(mas.begin(), mas.end(), [a, b](int x) {
		return (x >= a && x <= b);
		});
	mas.resize(compressed_mas - mas.begin()); //змінюємо розмір масиву після видалення елементів

   //Елементи, що звільнились в кінці масиву, заповнити нулями.
	mas.resize(n, 0);

	cout << "Стиснутий масив: ";
	for (int i = 0; i < n; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;

	return 0;
}
