//�迭(array)�� ���������� ���� ���� ���� ���� ���������� ������ �� �ִ� ������ ����
#include <iostream>
int main()
{
	using namespace std;
	int yams[3];
	yams[0] = 7;								// ù ��° ���ҿ� ���� �����Ѵ�
	yams[1] = 6;
	yams[2] = 5;

	int yamcosts[3] = { 200, 300, 50 };			// �迭�� �����ϰ� �ʱ�ȭ�Ѵ�.
	int newcosts[3] = { 5000, 7000, 50 };
	//yamcosts[3] = { 300, 300, 50 };
	//yamcosts = newcosts;

	cout << "���� �հ� = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << yams[1] << "���� ����ִ� ������ ";
	cout << "���� " << yamcosts[1] << "�� ���Դϴ�.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "�� ������ �� ������ " << total << "���Դϴ�.\n";
	cout << "\nyams �迭�� ũ��� " << sizeof yams;
	cout << "����Ʈ�Դϴ�.\n";
	cout << "���� �ϳ��� ũ��� " << sizeof yams[0];
	cout << "����Ʈ�Դϴ�.\n";
	cout << yams << "�̰� �迭�� �ּ��Դϴ�.\n\n\n";
	return 0;
}

// �迭�� �ٸ� �迭�� ��°�� ������ ���� ����.
