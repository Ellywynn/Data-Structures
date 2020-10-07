#include <iostream>

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void bubble_sort(T arr[], size_t size) {
	bool sorted = true;

	do {
		sorted = true;

		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				sorted = false;
			}
		}
	} while (!sorted);
}

int main(int argc, char* argv[]) {
	constexpr int size = 10;
	int arr[] = { 3,0,4,2,7,6,5,1,9,8 };

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cout << '\n' << '\n';

	bubble_sort(arr, size);

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cin.get();
	return 0;
}