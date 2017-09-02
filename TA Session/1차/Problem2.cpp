// 문제 2
/*
 자연수 N을 input으로 받는다
 처음 N개의 소수(prime number)를 출력한다
 */

#include <iostream>

int main() {
    int n;      // 출력할 소수의 개수
    std::cout << "Enter the integer: ";
    std::cin >> n;
    
    int i = 0;
    int k = 2;
    
    while (i < n) {
        bool cond = true;
        
        // 소수가 아니면 cond가 false가 되게 만듬
        for (int j = 2; j < k; j++) {
            if (k % j == 0) {
                cond = false;
                break;
            }
        }
        
        if (cond == true) {
            std::cout << k << " ";
            i++;
        }
        k++;
    }
    std::cout << std::endl;
    
    return 0;
}
