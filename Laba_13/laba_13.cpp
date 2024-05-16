#include <iostream>
#include <stdint.h>
#include <vector>

size_t check(size_t size, size_t period);
size_t calculate(size_t size);
void sort(std::vector<int> &array);
void print(std::vector<int> &array);

int main() {
	std::vector<int> array = { 7, 1, 8, 5, 0, 2, 6, 4, 3, 9, 11, 10 };
	std::vector<int> sub_array;

	size_t size   = array.size(); 
	size_t period = size - 2;

	std::cout << "Array: ";
	print(array);

	while (1) {
		period  = calculate(period);
		std::cout << "Period: " << period << std::endl;

		for (size_t k = 0; k < size; k++) {
			for (size_t j = k; (j < size); j+=period) {
				sub_array.push_back(array[j]);
			}
			sort(sub_array);
			for (size_t j = k, c = 0; (j < size); j+=period, c++) {
				array[j] = sub_array[c];
			}
			print(array);
			sub_array.clear();
			if (period == 1) return 0;
		}
	}
	return 0;
}
size_t check(size_t size, size_t period) {
	size_t number  = 0;
	size_t counter = 0;
	for (; (counter < size) && (number < size); counter++, number += period);
	return counter;
}
size_t calculate(size_t size) {
	return !(size % 2) || (size / 2 != 2) ? (size / 2) : (size / 2 + 1);
}
void sort(std::vector<int> &array) {
	int temp;
	for (size_t i = 0; i < array.size()-1; i++) {
		for (size_t j = 0; j < array.size()-1; j++) {
			if (array[j] > array[j+1]) {
				temp     = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
void print(std::vector<int> &array) {
	std::cout << "[";
	for (size_t i = 0; i < array.size(); i++) {
		std::cout << " " << array[i];
	}
	std::cout << " ]" << std::endl;
}
