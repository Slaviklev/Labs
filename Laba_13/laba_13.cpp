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











/*
void sort(std::vector<int> &array) {
	int temp;
	for (size_t i = 0; i < array.size(); i++) {
		for (size_t j = i; j < array.size(); j++) {
			if (array[j] < array[i]) {
				temp     = array[i];
				array[i] = array[j];
				array[j] = temp;
			} 
		}
	}
}
*/


/*
#include <iostream>
#include <stdint.h>

#define GET_SIZE(X) sizeof(array)/sizeof(array[0]);
size_t size = GET_SIZE(array);
static const int array[] = { 7, 1, 8, 5, 0, 2, 6, 4, 3, 9 }; 


int main() {
	size_t size    = sizeof(array) / sizeof(array[0]);
	size_t period  = !(size % 2) ? (size / 2) : (size / 2 + 1);

	for (size_t i = 0; i < size; i++) {
		std::cout << array[i] << std::endl;

		period = size/2
		const int array[] = 
		for (size_t j = 0; j < size) {

		}

	}

	return 0;
}
*/


/*
#include <iostream>
#include <stdint.h>
#include <vector>

//static const int array[] = { 7, 1, 8, 5, 0, 2, 6, 4, 3, 9, 11 };

void sort(int *array, size_t size);
void print(const int *array, size_t size);
size_t check(size_t size, size_t period);
size_t calculate(size_t size);

void sort(std::vector<int> &array);
void print(std::vector<int> &array);

int main() {
	//int array[] = { 7, 1, 8, 5, 0, 2, 6, 4, 3, 9, 11, 10 };
	std::vector<int> array = { 7, 1, 8, 5, 0, 2, 6, 4, 3, 9, 11, 10 };
	std::vector<int> sub_array;

	//size_t size   = sizeof(array) / sizeof(array[0]);
	size_t size   = array.size(); 
	size_t period = size - 2;
	size_t newsize; 
	int sorted[size];

	for (;;) {
		period  = calculate(period);
		newsize = check(size, period);
		std::cout << "Period: " << period << std::endl;
		for (size_t k = 0; k < size; k++) {
			//int sub_array[newsize];
			sub_array.clear();
			for (size_t j = k, c = 0; (j < size) && (c < newsize); j+=period, c++) {
				//sub_array[c] = array[j];
				sub_array.push_back(array[j]);
			}
			//sort(sub_array, newsize);
			sort(sub_array);
			for (size_t j = k, c = 0; (j < size) && (c < newsize); j+=period, c++) {
				//array[j] = sub_array[c];
				array[j] = sub_array[c];
			}
			std::cout << std::endl;
			//print(array, size);
			print(array);
		}
		//break;
		if (period == 1) break;
	}
	
	for (size_t i = 0; i < size; i++) {
		period  = calculate(period);
		newsize = check(size, period);
		int sub_array[newsize];
		for (size_t j = 0, c = 0; (j < size) && (c < newsize); j+=period, c++) {
			sub_array[c] = array[j];
		}
		sort(sub_array, newsize);
		for (size_t j = 0, c = 0; (j < size) && (c < newsize); j+=period, c++) {
			array[j] = sub_array[c];
		}
		print(array, size);

		if (period == 1) break;
	}
	
	return 0;
}
void sort(int *array, size_t size) {
	int temp;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = i; j < size; j++) {
			if (array[j] < array[i]) {
				temp     = array[i];
				array[i] = array[j];
				array[j] = temp;
			} 
		}
	}
}
void print(const int *array, size_t size) {
	std::cout << "[";
	for (size_t i = 0; i < size; i++) {
		std::cout << " " << array[i];
	}
	std::cout << " ]" << std::endl;
}
size_t check(size_t size, size_t period) {
	size_t number  = 0;
	size_t counter = 0;
	for (; (counter < size) && (number < size); counter++, number += period);
	return counter;
}
size_t calculate(size_t size) {
	return !(size % 2) ? (size / 2) : (size / 2 + 1);
}


void sort(std::vector<int> &array) {
	int temp;
	for (size_t i = 0; i < array.size(); i++) {
		for (size_t j = i; j < array.size(); j++) {
			if (array[j] < array[i]) {
				temp     = array[i];
				array[i] = array[j];
				array[j] = temp;
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
*/