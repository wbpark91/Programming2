#include <iostream>
#include <string>
#include <random>

#define PI 3.141592
#define SQ(x)   ((x)*(x))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int main() {
    
    double sq = SQ(3+2);      // 빌드 전에 ((3+2)*(3+2))으로 코드가 바뀜
    double m = MAX(3, 5);
    
    std::cout << m << std::endl;
    /*
    char a[10] = "abcd";
    char* b = "1234";
    strcpy(a, b);
    std::cout << a << "\t" << b << std::endl;
    
    std::string s = "string";
    std::cout << s << std::endl;
 
    
    std::mt19937 gen;
    std::normal_distribution<double> dist(0, 1);
    for (int i = 0; i < 100; ++i) {
        double r = dist(gen);
        printf("random number = %.6f\n", r);
    }
    
    for (int i = 0; i < 10; ++i) {
        std::cout << rand() << std::endl;
    }
    */
    return 0;
     
}

