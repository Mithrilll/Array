#pragma once
#include <iostream>
#include <random>
#include <time.h>

class Array 
{
public:
	Array();
	Array(int* arr, int n);
	Array(const Array& object);
	~Array();

	int FindElem(int value);
	
	friend std::ostream& operator<<(std::ostream& out, const Array& arr);	// перегрузка оператора вывода
	friend std::istream& operator>>(std::istream& in, Array& arr);	// перегрузка оператора ввода

	void Sort();
	void Sort(int left, int right);

	void Insert(int value, int index);

	void ShiftLeft(int ind, int k);
	void ShiftRight(int ind, int k);

	int Min();
	int Max();

	void Fill(int low, int high);
	void FillAscending(int low, int high);
	void FillDescending(int low, int high);

	int& operator[](int index);

	Array operator=(const Array& object);

	Array operator+(int value);
	void operator+=(int value);

	void operator-=(int index);
	Array operator-(int value);
	
	bool operator==(const Array& second_operand);	// перегрузка операции ==
	bool operator!=(const Array& second_operand);	// перегрузка операции !=

private:
	int size;
	int* pArr;
};