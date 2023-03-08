#include <iostream>

using namespace std;

void CreateMassive(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 10 + 1;
	}
}

void PrintMassive(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << ' ';
	}
	cout << endl;
}

int NotABMassive(int* arr, int size, int* arr1, int* arr2)
{
	int size1 = 0;

	for (int i = 0; i < size; i++)
	{
		bool key = false;
		for (int j = 0; j < size; j++)
		{
			if (*(arr + i) != *(arr1 + j))
				continue;

				key = true;
					break;
			
			
		}
		if (!key)
		{
			size1++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		bool key = false;
		for (int j = 0; j < size1; j++)
		{
			if (*(arr + i) != *(arr1 + j))
				continue;

			key = true;
			break;


		}
		if (!key)
		{
			*(arr2 + size1)=*(arr+i);
			size1++;
		}
	}

	return size1;
}

int GetValue()
{
	int value;
	cin >> value;
	return value;
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	cout << "Введите длину массивов №1 и №2: " << endl;
	int size = GetValue();

	int* arr = new int[size];
	int* arr1 = new int[size];
	int* arr2 = new int[size];
	

	cout << "Массив №1: " << endl;
	CreateMassive(arr, size);
	PrintMassive(arr, size);

	cout << "Массив №2: " << endl;
	CreateMassive(arr1, size);
	PrintMassive(arr1, size);

	

	cout << "Массив №3: " << endl;
	int size1 = NotABMassive(arr, size, arr1, arr2);
	//cout << size1 << endl; (для проверки работы первого цикла функции NotABMassive)
	PrintMassive(arr2, size1);

	delete[] arr;
	delete[] arr1;
	delete[] arr2;

	return 0;
}