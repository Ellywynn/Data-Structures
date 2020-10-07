#include <iostream>

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void selection_sort(T arr[], size_t size) {
	int minIndex = 0;

	for (int i = 0; i < size - 1; i++) {
		minIndex = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		if (arr[minIndex] != arr[i])
			swap(arr[minIndex], arr[i]);
	}
}

int main(int argc, char* argv[]) {
	constexpr int size = 10;
	int arr[] = { 3,0,4,2,7,6,5,1,9,8 };

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cout << '\n' << '\n';

	selection_sort(arr, size);

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cin.get();
	return 0;
}