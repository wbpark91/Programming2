#include<iostream>
using namespace std;
int d = 6;
class A {
private:
	static int a;
	int b;
public:
	A() {
		a++;
		int c = 5;
		cout << a << endl;
	}
	~A() {
		a--;
		cout << a << endl;
	}
};
int A::a = 0;
//int A::b = 0;

int main() {
	A a1;
	A a2;
	A a3;
	//cout << "c의 값은: "<< c << "\n";
	cout << "d의 값은: "<< d << "\n";
	return 0;
}