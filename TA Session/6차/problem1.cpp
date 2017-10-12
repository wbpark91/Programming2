#include <iostream>

int main() {
    try {
        // 평균점수 입력
        int numClass;
        std::cout << "홍릉초등학교의 총 반의 개수: ";
        std::cin >> numClass;
        
        if (numClass <= 0) {
            std::cout << "반 개수 입력 오류" << std::endl;
            throw(numClass);
        }
        
        double* avgScore = new double[numClass];      // 각 반의 평균점수를 입력할 배열
        
        for (int i = 0; i < numClass; ++i) {
            int numStudent;
            int score = 0;
            std::cout << std::endl;
            std::cout << i+1 << "반의 학생 수는 몇 명? ";
            std::cin >> numStudent;
            
            if (numStudent <= 0) {
                std::cout << "학생 숫자 입력 오류" << std::endl;
                throw(numStudent);
            }
            
            int* studentScore = new int[numStudent];
            for (int j = 0; j < numStudent; ++j) {
                std::cout << i+1 << "반의 " << j+1 << "번째 학생의 점수를 입력하세요: ";
                std::cin >> studentScore[j];        // 학생 숫자 배열
                score += studentScore[j];
            }
            avgScore[i] = score / (double)numStudent;
            delete[] studentScore;
        }
        
        // 대소비교
        int minidx = 0;
        double min = avgScore[0];
        int maxidx = 0;
        double max = avgScore[0];
        for (int i = 0; i < numClass; ++i) {
            if (max < avgScore[i]) {
                max = avgScore[i];
                maxidx = i;
            }
            if (min > avgScore[i]) {
                min = avgScore[i];
                minidx = i;
            }
        }
        
        // 출력
        std::cout << std::endl;
        std::cout << "제일 잘 본 반은 " << maxidx + 1 << "반 입니다." << std::endl;
        std::cout << "그 평균 점수는 " << max << "점 입니다." << std::endl;
        std::cout << "제일 못 본 반은 " << minidx + 1 << "반 입니다." << std::endl;
        std::cout << "그 평균 점수는 " << min << "점 입니다." << std::endl;
        
        delete[] avgScore;
    }
    
    catch(int num) {
        std::cout << "잘못된 숫자 입력: " << num << std::endl;
        exit(1);
    }
    return 0;
}
