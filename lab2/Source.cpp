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

	cout << "�����: " << endl;
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 30 - 10;
	}


	int sum = 0;
	vector<int>::iterator min, FirstNegative, it, compressed_mas;

	for (it = mas.begin(); it != mas.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//��������� ����� ���������� �� ������ �������� ������
	min = min_element(mas.begin(), mas.end(), [](int a, int b) {return abs(a) < abs(b); });
	cout << endl;
	cout << "�i�i������ ����� �� ������: " << *min << endl << endl;
	cout << "����� �i�i�������� ��������: " << min - mas.begin() << endl << endl;

	//��������� ���� ������ �������� ������, ������������ ���� ������� �䒺����� ��������,
	FirstNegative = find_if(mas.begin(), mas.end(), [](int a) {
		return a < 0; });
	cout << "������ �i�'����� �������: " << *FirstNegative << endl << endl;
	sum = accumulate(FirstNegative + 1, mas.end(), 0, [](int a, int b) {return a + abs(b); });
	cout << "����� �i�i�������� �� ������ �������� ������: " << FirstNegative - mas.begin() << endl << endl;
	cout << "���� �����i� �������i� ������, ������������ �i��� ������� �i䒺����� ��������: " << sum << endl << endl;
	
	//�������� �����, ��������� � ����� �� ��������, �������� ���� ����������� � �������� 
	//[a, b].��������, �� ���������� � ���� ������, ��������� ������.
	int a, b;
	cout << "����i�� �������� �:";
	cin >> a;
	cout << "����i�� �������� b:";
	cin >> b;

	cout << endl;
	compressed_mas = remove_if(mas.begin(), mas.end(), [a, b](int x) {
		return (x >= a && x <= b);
		});
	mas.resize(compressed_mas - mas.begin()); //������� ����� ������ ���� ��������� ��������

   //��������, �� ���������� � ���� ������, ��������� ������.
	mas.resize(n, 0);

	cout << "��������� �����: ";
	for (int i = 0; i < n; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;

	return 0;
}
