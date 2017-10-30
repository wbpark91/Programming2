#include <iostream>     // 전처리기(컴파일하기 전 처리해야 하는 부분을 처리하는 것)
// using namespace std; (가급적이면 쓰지 않는 것이 좋다. 이름공간이라는 것 자체가 충돌을 방지하기 위해 만들었기 때문에)

/*
 주 석
 주 석
 JOOSUC
 */

int main() {
    // 문자와 문자열은 다름 (문자: ' ', 문자열: " ")
    std::cout << "Hello World!!!\n";
    int a;  // 선언 (한 블럭에서 같은 변수명에 대한 선언은 반드시 한 번만 이루어져야 함)
    a = 10; // 대입
    
    int b = 20; // 선언과 동시에 대입
    double c = 3.5;
    
    std::cout << a << " " << b << " " << c << std::endl;
    
    int s = a + b;
    double d = a / (double) b;      // 정수 / 정수는 정수기 때문에 Type Casting하였음
    double e = 1.0 / 3;             // 정수 / 정수는 정수기 때문에 Type을 바꿔줌
    // 메모리가 큰 쪽의 타입을 따라감
    std::cout << s << " " << d << " " << e << std::endl;
    
    char n = 'a';
    char m = 'b';
    std::cout << n << m << std::endl;
    
    int w, t, y;     // 여러 개의 변수를 동시에 선언할 수도 있음
    unsigned int q = 0;
    
    std::cout << q - 1 << std::endl;    // unsigned int 값은 음수가 될 수 없음
    
    // 증가와 감소 연산자
    // a++;    // 같은 줄에 있는 연산을 마치고 a가 1 증가
    std::cout << a++ << std::endl;      // a를 출력하고 a가 1 증가
    b--;
    std::cout << b << std::endl;
    // ++a;    // 같은 줄에 있는 연산이 실행되기 전에 a가 1 증가
    std::cout << ++a << std::endl;      // a를 출력하기 전에 a가 1 증가
    --b;
    std::cout << b << std::endl;
    
    // 파이썬에서는 and or not을 바로 사용할 수 있었지만, c++는 (&&, ||, !) 을 사용해야 한다
    return 0;
}
