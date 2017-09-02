// 문제 1

/*
 기초통계량 계산: 주어진 N개의 정수의 평균, 최댓값, 최솟값을 구하는 프로그램
 먼저 정수의 개수 N을 사용자 input으로 받는다.
 그 다음 N개의 정수 각각을 input으로 받는다
 프로그램 실행 시 각각의 행에 평균, 최댓값, 최솟값을 출력한다
*/

#include <iostream>

int main() {
    int n;      // 입력받는 정수의 개수
    int max;
    int min;
    double mean = 0;
    int input;  // 입력받는 정수
    
    std::cout << "Enter the number of integer: ";
    std::cin >> n;
    
    std::cin >> input;
    mean += input;
    max = input;
    min = input;
    
    for (int i = 0; i < n - 1; i++) {
        std::cin >> input;
        // 평균 계산
        mean += input;
        
        // 최댓값 확인
        if (max < input)
            max = input;
        
        // 최솟값 확인
        if (min > input)
            min = input;
    }
    
    mean = mean / (double) n;
    
    std::cout << "Result" << std::endl;
    std::cout << "Mean: " << mean << " Max: " << max << " Min: " << min << std::endl;
    return 0;
}
