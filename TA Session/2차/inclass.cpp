#include <iostream>
using namespace std;

// Copy & Paste 방식: 개발이 오래 걸림
/*
int main() {
    int a = 1;
    for (int i = 0; i < 4; i = i+1) {
        a = a * 3;
    }
    cout << "3^4 is " << a << endl;
    
    int b = 1;
    for (int i = 0; i < 5; i = i+1) {
        b = b * 6;
    }
    cout << "6^5 is " << b << endl;
    
    int c = 1;
    for (int i = 0; i < 10; i = i+1) {
        c = c * 12;
    }
    cout << "12^10 is " << c << endl;
    
    return 0;
}
*/


// 함수를 이용하면 재생산, 수정이 쉬워진다
int raiseToPower(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/*
int main() {
    int a = raiseToPower(3, 4);
    cout << "3^4 is " << a << endl;
    
    int b = raiseToPower(6, 5);
    cout << "6^5 is " << b << endl;
    
    int c = raiseToPower(12, 10);
    cout << "12^10 is " << c << endl;
    
    return 0;
}
*/


void printNumberIfEven(int num) {
    if (num % 2 == 1) {
        cout << "odd number" << endl;
        return;     // return이 실행되면 함수를 빠져나오게 됨
    }
    cout << "even number: number is " << num << endl;
}

// Function Overloading: 이름은 같지만 argument가 다르게 함수를 정의할 수 있다.
void printOnNewLine(int x) {
    cout << "Integer: " << x << endl;
}

void printOnNewLine(char* x) {
    cout << "String: " << x << endl;
}

void printOnNewLine(int x, int y) {
    cout << "Two integers: " << x << " and " << y << endl;
}

int main() {
    printOnNewLine(3);
    printOnNewLine("Hello");
    printOnNewLine(2, 3);
    
    return 0;
}
