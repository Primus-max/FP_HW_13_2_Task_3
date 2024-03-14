// Используя два указателя на массивы целых
// чисел, скопировать один массив в другой так, чтобы во
// втором массиве элементы находились в обратном порядке.
// Использовать в программе арифметику указателей
// для продвижения по массиву, а также оператор разыменования.

#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

template<typename T>
void FillArray(T* arr, int size);

template<typename T>
void PrintArray(T* arr, int size);

template<typename T>
void CopyReversedArray(T* oldArr, T* newArr, int size);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;
	cout << "Указать размер массива для заполнения : ";
	cin >> size;
	int* Array = new int[size];
	int* ReversedArr = new int[size];
	FillArray(Array, size);

	cout << "Заполненный массив ------------------- >>" << endl;
	PrintArray(Array, size);

	cout << "Скопировано-ревёрснутый массив ------------------- >>" << endl;
	CopyReversedArray(Array, ReversedArr, size);
	PrintArray(ReversedArr, size);
}

template<typename T>
void FillArray(T* arr, int size) {
	random_device random;
	for (T* i = arr; i < arr + size; ++i) {
		*i = random() % (100 + 50) - 50;
	}
}

template<typename T>
void PrintArray(T* arr, int size) {	
		for (T* i = arr; i < arr + size; ++i) 
			cout << "[ " << *i << " ]";
	cout << endl;
}

template<typename T>
void CopyReversedArray(T* oldArr, T* newArr, int size){
	for (T* i = oldArr + size - 1, *j = newArr; i >= oldArr; --i, ++j)				
		*j = *i;		
}
