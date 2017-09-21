#include <iostream>
// 배열의 초기화는 배열을 정의하는 곳에서만 사용할 수 있다
// 배열을 부분적으로 초기화를 하면 컴파일러가 나머지 원소들을 모두 0으로 설정함

void selectionSort(int arr[], int size) {
    int key;
    int idx;
    for (int i = 0; i < size - 1; ++i) {
        key = arr[i];
        idx = i;
        for (int j = i+1; j < size; ++j) {
            if (arr[j] < key) {
                key = arr[j];
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = key;
        arr[idx] = temp;
    }
}

int main() {
    int score[5] = {100, 30, 76, 53, 80};
    for (int i = 0; i < 5; ++i) {
        std::cout << score[i] << " ";
    }
    std::cout << std::endl;
    
    // 숫자 5개를 사용자에게 입력받아 두 번째로 낮은 숫자를 출력해주는 프로그램
    int arr[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter an integer: ";
        std::cin >> arr[i];
    }
    selectionSort(arr, 5);
    
    for (int i = 0; i < 5; ++i) {
        if (arr[i] < arr[i+1]) {
            std::cout << "2nd Min: " << arr[i+1] << std::endl;
            break;
        }
    }


    
    return 0;
}
