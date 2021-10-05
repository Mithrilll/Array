#include "Array.h"

int main()
{
	int a[5] = { 1, 5, 3, 6, 2 };
	Array<int> arr(a, 5);

	std::cout << "Index of element with value 3 : " << arr.FindElem(3) << std::endl;
	arr.Sort();
	std::cout << "Sorted array:\n" << arr << std::endl;
	arr.Insert(30, 2);
	std::cout << "Inserted 30 in position 2:\n" << arr << std::endl;
	arr.ShiftLeft(2, 1);
	std::cout << "Shifted left from index 2 by 1 position:\n" << arr << std::endl;
	arr.ShiftRight(3, 1);
	std::cout << "Shifted right from index 3 by 1 position:\n" << arr << std::endl;
	std::cout << "Minimum : " << arr.Min() << std::endl;
	std::cout << "Maximum : " << arr.Max() << std::endl;
	std::cout << "Array[0]: " << arr[0] << std::endl;
	arr = arr + 2;
	std::cout << "Array + 2:\n" << arr << std::endl;
	arr - 3;
	std::cout << "Array - 3:\n" << arr << std::endl;
	arr -= 2;
	std::cout << "Array -= 2:\n" << arr << std::endl;

	return 0;
}