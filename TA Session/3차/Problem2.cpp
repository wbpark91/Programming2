#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    int* pnum = &num;
    
    std::cout << "Number: " << num << std::endl;
    std::cout << "Pointer Number: " << *pnum << std::endl;
    std::cout << "Number address: " << &num << std::endl;
    std::cout << "Pointer: " << pnum << std::endl;
    
    return 0;
}
