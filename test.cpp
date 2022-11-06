#include <iostream>
#include <string>

void func(int* array, int size) {
    std::cout << (&array + 1) - &array<< std::endl;
    std::cout << (array + 1) << std::endl;
}

int main() {
    int size = 10;
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    std::cout << *(&array + 1) - array << std::endl;
    std::cout << sizeof(array) << std::endl;
    func(array, size);
}