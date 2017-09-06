// 두 정수를 arguments로 받아서, 최대공약수와 최소공배수를 반환하는 함수를 작성하세요

#include <iostream>
using namespace std;

int gcd(int x, int y) {
    /*
     if (x > y) {
        int temp = y;
        y = x;
        x = temp;
    }
    */
    
    int r = y % x;
    while (r != 0) {
        y = x;
        x = r;
        r = y % x;
    }
    return x;
}

int lcm(int x, int y) {
    int k = gcd(x, y);
    return k * (x / k) * (y / k);
}

int main() {
    cout << gcd(1679, 874) << endl;
    cout << gcd(3762, 4047) << endl;
    cout << gcd(6080, 3876) << endl;
    cout << lcm(8, 12) << endl;
    return 0;
}
