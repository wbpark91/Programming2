//배열(array)는 데이터형이 같은 여러 개의 값을 연속적으로 저장할 수 있는 데이터 구조
#include <iostream>
int main()
{
	using namespace std;
	int yams[3];
	yams[0] = 7;								// 첫 번째 원소에 값을 대입한다
	yams[1] = 6;
	yams[2] = 5;

	int yamcosts[3] = { 200, 300, 50 };			// 배열을 생성하고 초기화한다.
	int newcosts[3] = { 5000, 7000, 50 };
	//yamcosts[3] = { 300, 300, 50 };
	//yamcosts = newcosts;

	cout << "고구마 합계 = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << yams[1] << "개가 들어있는 포장은 ";
	cout << "개당 " << yamcosts[1] << "원 씩입니다.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "세 포장의 총 가격은 " << total << "원입니다.\n";
	cout << "\nyams 배열의 크기는 " << sizeof yams;
	cout << "바이트입니다.\n";
	cout << "원소 하나의 크기는 " << sizeof yams[0];
	cout << "바이트입니다.\n";
	cout << yams << "이건 배열의 주소입니다.\n\n\n";
	return 0;
}

// 배열은 다른 배열에 통째로 대입할 수도 없다.
