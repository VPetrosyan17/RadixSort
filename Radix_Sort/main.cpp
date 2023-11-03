#include <iostream>

//function to get the biggest element from an array
int getMax(int* arr, int size){
	int max = arr[0];
	for(int i = 1; i < size; ++i){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

void countingSort(int* arr, int size, int place){
	//assuming a decimal number system;
	const int max = 10;
	int output[size];
	int count[max];

	for(int i = 0; i < max; ++i){
		count[i] = 0;
	}
	//calculate count of elements
	for(int i = 0; i < size; ++i){
		count[(arr[i] / place) % 10]++;
	}
	//caculate cumulative count
	for(int i = 1; i < max; ++i){
		count[i] += count[i - 1];
	}
	//place the elements in sorted order
	for(int i = size - 1; i >= 0; i--){
		output[count[(arr[i] / place) % 10] - 1] = arr[i];
		count[(arr[i] / place) % 10]--;
	}
	for(int i = 0; i < size; ++i){
		arr[i] = output[i];
	}
}
//main funcion to implement radix sort
void radixSort(int* arr, int size){
	int max = getMax(arr, size);
	//sort elements based on place value
	for(int place = 1; max / place > 0; place *= 10){
		countingSort(arr, size, place);
	}
}

void printArray(int* arr, int size){
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " " ;
	}
}

int main(){
	int arr[] = {18, 4, 6, 0, 8, 2};
	int size = sizeof(arr)/sizeof(arr[0]);

	std::cout<< "Unsorted array: ";
	printArray(arr, size);
	std::cout << std::endl;

	std::cout << "Sorted array: ";
	radixSort(arr, size);
	printArray(arr, size);
	std::cout << std::endl;
}
