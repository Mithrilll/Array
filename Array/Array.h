#pragma once
#include <iostream>
#include <random>
#include <time.h>

template<class T>
class Array 
{
public:
	Array();
	Array(T* arr, size_t n);
	Array(const Array<T>& object);
	~Array();

	size_t FindElem(T value);
	
	template<typename P>
	friend std::ostream& operator<<(std::ostream& out, const Array<P>& arr);	// перегрузка оператора вывода
	template<typename P>
	friend std::istream& operator>>(std::istream& in, Array<P>& arr);	// перегрузка оператора ввода

	bool Sort();
	bool Sort(size_t left, size_t right);

	void Insert(T value, size_t index);

	void ShiftLeft(int ind, int k);
	void ShiftRight(int ind, int k);

	T Min();
	T Max();

	/*void Fill(int low, int high);
	void FillAscending(int low, int high);
	void FillDescending(int low, int high);*/

	T& operator[](size_t index);

	Array<T> operator=(const Array<T>& object);

	Array<T> operator+(T value);
	void operator+=(T value);

	void DeleteByIndex(size_t index);
	void DeleteByValue(T value);

	void operator-=(size_t index);
	void operator-(T value);
	
	bool operator==(const Array<T>& second_operand);	// перегрузка операции ==
	bool operator!=(const Array<T>& second_operand);	// перегрузка операции !=

private:
	size_t size;
	T* pArr;
};

template<typename T>
Array<T>::Array()
{
	size = 0;
	pArr = nullptr;
}

template<typename T>
Array<T>::Array(T* arr, size_t n)
{
	size = n;
	pArr = new T[size];
	for (size_t i = 0; i < size; i++)
		pArr[i] = arr[i];
}

template<typename T>
Array<T>::Array(const Array<T>& object)
{
	size = object.size;
	pArr = new T[size];
	for (size_t i = 0; i < size; i++)
		pArr[i] = object.pArr[i];
}

template<typename T>
Array<T>::~Array()
{
	if (pArr)
		delete[] pArr;
}

template<typename T>
size_t Array<T>::FindElem(T value)
{
	for (size_t i = 0; i < size; i++)
		if (pArr[i] == value)
		{
			return i;
		}

	return -1;
}

template<typename P>
std::ostream& operator<<(std::ostream& out, const Array<P>& arr)
{
	for (size_t i = 0; i < arr.size; i++)
		out << arr.pArr[i] << " ";

	return out;
}

template<typename P>
std::istream& operator>>(std::istream& in, Array<P>& arr)
{
	for (size_t i = 0; i < arr.size; i++)
		in >> arr[i];

	return in;
}

template<typename T>
bool Array<T>::Sort()
{
	return Sort(0, size - 1);
}

template<typename T>
bool Array<T>::Sort(size_t left, size_t right)
{
	if (left < 0 || right >= size)
	{
		return false;
	}

	int i = left, j = right;
	T tmp;
	T pivot = pArr[(left + right) / 2];

	while (i <= j)
	{
		while (pArr[i] < pivot)
			i++;
		while (pArr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = pArr[i];
			pArr[i] = pArr[j];
			pArr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		Sort(left, j);
	if (i < right)
		Sort(i, right);

	return true;
}

template<typename T>
void Array<T>::Insert(T value, size_t index)
{
	size++;
	T* temp = new T[size];
	for (size_t i = 0; i < index; i++)
		temp[i] = pArr[i];
	temp[index] = value;
	for (size_t i = index + 1; i < size; i++)
		temp[i] = pArr[i - 1];

	delete[] pArr;
	pArr = temp;
}

template<typename T>
void Array<T>::ShiftLeft(int ind, int k)
{
	if (ind < 0 || k < 0)
		return;

	int i = 0;
	while (i + k <= ind)
	{
		pArr[i] = pArr[i + k];
		i++;
	}
	while (i <= ind)
	{
		pArr[i] = T();
		i++;
	}
}

template<typename T>
void Array<T>::ShiftRight(int ind, int k)
{
	if (ind < 0 || k < 0)
		return;

	size_t i = size - 1;
	while (i - k >= ind)
	{
		pArr[i] = pArr[i - k];
		i--;
	}
	while (i >= ind)
	{
		pArr[i] = T();
		i--;
	}
}

template<typename T>
T Array<T>::Min()
{
	if (!pArr)
		return 0;
	T min = pArr[0];

	for (size_t i = 0; i < size; i++)
		if (pArr[i] < min)
			min = pArr[i];

	return min;
}

template<typename T>
T Array<T>::Max()
{
	if (!pArr)
		return 0;
	T max = pArr[0];

	for (size_t i = 0; i < size; i++)
		if (pArr[i] > max)
			max = pArr[i];

	return max;
}

//void Array::Fill(int low, int high)
//{
//	for (int i = 0; i < size; i++)
//		pArr[i] = rand() % (high - low + 1) + low;
//}
//
//void Array::FillAscending(int low, int high)
//{
//	for (int i = 0; i < size; i++)
//	{
//		pArr[i] = rand() % (high - low + 1) + low;
//		low = pArr[i];
//	}
//}
//
//void Array::FillDescending(int low, int high)
//{
//	for (int i = 0; i < size; i++)
//	{
//		pArr[i] = rand() % (high - low + 1) + low;
//		high = pArr[i];
//	}
//}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	return pArr[index];
}

template<typename T>
Array<T> Array<T>::operator=(const Array<T>& object)
{
	if (*this == object)
		return *this;

	if (pArr)
		delete[] pArr;

	size = object.size;
	pArr = new T[size];
	for (size_t i = 0; i < size; i++)
		pArr[i] = object.pArr[i];

	return *this;
}

template<typename T>
Array<T> Array<T>::operator+(T value)
{
	T* temp = new T[size + 1];

	for (size_t i = 0; i < size; i++)
		temp[i] = pArr[i];

	temp[size] = value;

	Array n(temp, size + 1);
	delete[] temp;

	return n;
}

template<typename T>
void Array<T>::operator+=(T value)
{
	T* temp = new T[size + 1];

	for (size_t i = 0; i < size; i++)
		temp[i] = pArr[i];

	temp[size] = value;

	size++;
	delete[] pArr;
	pArr = temp;
}

template<class T>
void Array<T>::DeleteByIndex(size_t index)
{
	if (index < 0 || index >= size)
		return;

	T* temp = new T[size - 1];

	for (size_t i = 0; i < index; i++)
		temp[i] = pArr[i];

	for (size_t i = index + 1; i < size; i++)
		temp[i - 1] = pArr[i];

	delete[] pArr;
	pArr = temp;
	size--;
}

template<class T>
void Array<T>::DeleteByValue(T value)
{
	size_t index = -1;

	for (size_t i = 0; i < size; i++)
		if (pArr[i] == value)
		{
			index = i;
			break;
		}

	DeleteByIndex(index);
}

template<typename T>
void Array<T>::operator-=(size_t index)
{
	DeleteByIndex(index);
}

template<typename T>
void Array<T>::operator-(T value)
{
	DeleteByValue(value);
}

template<typename T>
bool Array<T>::operator==(const Array<T>& second_operand)
{
	if (size != second_operand.size)
		return false;

	for (size_t i = 0; i < size; i++)
		if (pArr[i] != second_operand.pArr[i])
			return false;

	return true;
}

template<typename T>
bool Array<T>::operator!=(const Array<T>& second_operand)
{
	return !(*this == second_operand);
}