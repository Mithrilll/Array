#include "Array.h"

Array::Array()
{
	size = 0;
	pArr = nullptr;
}

Array::Array(int* arr, int n)
{
	size = n;
	pArr = new int[size];
	for (int i = 0; i < size; i++)
		pArr[i] = arr[i];
}

Array::Array(const Array& object)
{
	size = object.size;
	pArr = new int[size];
	for (int i = 0; i < size; i++)
		pArr[i] = object.pArr[i];
}

Array::~Array()
{
	if (pArr)
		delete[] pArr;
}

int Array::FindElem(int value)
{
	for(int i =0; i < size; i++)
		if (pArr[i] == value)
		{
			return i;
		}

	return -1;
}

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
	for (int i = 0; i < arr.size; i++)
		out << arr.pArr[i] << " ";

	return out;
}

std::istream& operator>>(std::istream& in, Array& arr)
{
	for (int i = 0; i < arr.size; i++)
		in >> arr[i];

	return in;
}

void Array::Sort()
{
	Sort(0, size - 1);
}

void Array::Sort(int left, int right)
{
	if (left < 0 || right >= size) 
	{
		std::cout << "Wrong borders!" << std::endl; 
		return;
	}

	int i = left, j = right; 
	int tmp; 
	int pivot = pArr[(left + right) / 2]; 

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
}

void Array::Insert(int value, int index)
{
	size++;
	int* temp = new int[size];
	for (int i = 0; i < index; i++)
		temp[i] = pArr[i];
	temp[index] = value;
	for (int i = index + 1; i < size; i++)
		temp[i] = pArr[i - 1];

	delete[] pArr;
	pArr = temp;
}

void Array::ShiftLeft(int ind, int k)
{
	int i = 0;
	while (i + k <= ind)
	{
		pArr[i] = pArr[i + k];
		i++;
	}
	while (i <= ind)
	{
		pArr[i] = 0;
		i++;
	}
}

void Array::ShiftRight(int ind, int k)
{
	int i = size - 1;
	while (i - k >= ind)
	{
		pArr[i] = pArr[i - k];
		i--;
	}
	while (i >= ind)
	{
		pArr[i] = 0;
		i--;
	}
}

int Array::Min()
{
	if (!pArr)
		return 0;
	int min = pArr[0];

	for (int i = 0; i < size; i++)
		if (pArr[i] < min)
			min = pArr[i];

	return min;
}

int Array::Max()
{
	if (!pArr)
		return 0;
	int max = pArr[0];

	for (int i = 0; i < size; i++)
		if (pArr[i] > max)
			max = pArr[i];

	return max;
}

void Array::Fill(int low, int high)
{
	for (int i = 0; i < size; i++)
		pArr[i] = rand() % (high - low + 1) + low;
}

void Array::FillAscending(int low, int high)
{
	for (int i = 0; i < size; i++)
	{
		pArr[i] = rand() % (high - low + 1) + low;
		low = pArr[i];
	}
}

void Array::FillDescending(int low, int high)
{
	for (int i = 0; i < size; i++)
	{
		pArr[i] = rand() % (high - low + 1) + low;
		high = pArr[i];
	}
}

int& Array::operator[](int index)
{
	return pArr[index];
}

Array Array::operator=(const Array& object)
{
	if (*this == object)
		return *this;

	if (pArr)
		delete[] pArr;

	size = object.size;
	pArr = new int[size];
	for (int i = 0; i < size; i++)
		pArr[i] = object.pArr[i];

	return *this;
}

Array Array::operator+(int value)
{
	int* temp = new int[size + 1];

	for (int i = 0; i < size; i++)
		temp[i] = pArr[i];

	temp[size] = value;

	Array n(temp, size + 1);
	delete[] temp;

	return n;
}

void Array::operator+=(int value)
{
	int* temp = new int[size + 1];

	for (int i = 0; i < size; i++)
		temp[i] = pArr[i];

	temp[size] = value;

	size++;
	delete[] pArr;
	pArr = temp;
}

void Array::operator-=(int index)
{
	if (index < 0 || index >= size)
		return;

	int* temp = new int[size - 1];

	for (int i = 0; i < index; i++)
		temp[i] = pArr[i];

	for (int i = index+1; i < size; i++)
		temp[i-1] = pArr[i];

	delete[] pArr;
	pArr = temp;
	size--;
}

Array Array::operator-(int value)
{
	int index = -1;

	for(int i =0; i < size; i++)
		if (pArr[i] == value)
		{
			index = i;
			break;
		}

	*this -= index;

	return *this;
}

bool Array::operator==(const Array& second_operand)
{
	if (size != second_operand.size)
		return false;

	for(int i =0; i < size; i++)
		if (pArr[i] != second_operand.pArr[i])
			return false;

	return true;
}

bool Array::operator!=(const Array& second_operand)
{
	return !(*this == second_operand);
}
