#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Вывод массива
template <typename T> void showArr(T arr[], int L);
// Задача 1.
void typeOfN(int N) {
	cout << "INT\n";
}
void typeOfN(double N){
cout << "DOUBL\n";
}

// Задача 2.
int sumAB(int A, int B);

// Задача 3.
void sortRange(int arr[], int L);

// Задача 4.
void moveArray(int arr[], int L, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;

	// Задача 1.
	cout<<"Задача 1.\n";
	cout << "10 - ";
	typeOfN(10);
	cout << "5.5 - ";
	typeOfN(5.5);

	// Задача 2.
	cout <<"Задача 2.\nВведите 2 числа: ";
	cin >> n >> m;
	cout << "Сумма чисел от " << n << " до " << m << " = " << sumAB(n, m) << "\n\n";

	// Задача 3.
	cout << "Задача 3.\nИзначалный массив:\n";
	int z3[10];
	for (int i = 0; i <10; i++)
		z3[i] = rand() % (20 + 1 - (-20)) + (-20);
	showArr(z3, 10);
	cout << "Итоговый массив:\n";
	sortRange(z3, 10);
	showArr(z3, 10);

	// Задача 4
	cout << "Задача 4\nИзначальный массив: ";
	int z4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	showArr(z4, 10);
	cout << "Введите колличество сдвигов: ";
	cin >> n;
	moveArray(z4, 10, n);
	cout << "Итоговый массив: ";
	showArr(z4, 10);


	return 0;
}
// Задача 4
void moveArray(int arr[], int L, int n) {
	if (n >= L)
		n -= (n / L) * L;
	for (int j = 0; j < n; j++) {
		int tmp = arr[L - 1];
		for (int i = L - 1; i >= 1; i--)
			arr[i] = arr[i - 1];
		arr[0] = tmp;
	} 
}

// Задача 2.
int sumAB(int A, int B) {
	if (A >= B) 
		return A;
	return B + sumAB(A, B - 1);
}

// Задача 3.
void sortRange(int arr[], int L) {
	int firstIndex = -1, lastIndex = -1;
	for (int i = 0; i < L; i++)
		if (arr[i] < 0) {
			firstIndex = i;
			break;
		}
	for (int i = L - 1;i >=0; i--)
		if (arr[i] < 0) {
			lastIndex = i;
			break;
		}
	if (firstIndex != -1)
		//Пузырьковый метод
		for (int i = lastIndex; i > firstIndex; i--)
			for (int j = firstIndex; j < i; j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j],arr[j + 1]);
					// Быстрая сортировка
		sort(arr + firstIndex, arr + lastIndex);
}

// Вывод массива:
template <typename T> void showArr(T arr[], int L) {
	cout << "[";
	for (int i = 0; i < L; i++) 
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}