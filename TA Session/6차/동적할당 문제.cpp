
# include <iostream>

using namespace std;

int main()
{
	cout << "ȫ���ʵ��б��� �� ���� ����: ";
	int num_class;
	cin >> num_class;
	int *top = new int[num_class];
	for (int k = 0; k < num_class; k++) {
		cout << k + 1 << "���� �л� ���� �� ��?: ";
		int num_stu;
		cin >> num_stu;
		int *student = new int[num_stu];
		for (int i = 0; i < num_stu; i++) {
			cout << k+1 << "���� " << i + 1 << "��° �л��� ������ �Է��ϼ���.: ";
			cin >> student[i];
			cout << "\n";
		}
		int sum = 0;
		for (int j = 0; j < num_stu; j++) {
			sum += student[j];
		}
		top[k] = sum / num_stu;
		delete[] student;
	}

	int max, min, max_class, min_class;
	max = top[0];
	min = top[0];
	max_class = 0;
	min_class = 0;
	for (int a = 0; a < num_class; a++) {
		if (max == top[a]) {
			max = top[a];
			max_class = a + 1;
		}
		else if (max < top[a]) {
			max = top[a];
			max_class = a + 1;
		}
		if (min == top[a]) {
			min = top[a];
			min_class = a + 1;
		}
		else if (min > top[a]) {
			min = top[a];
			min_class = a + 1;
		}
	}
	cout << "���� �� �� ���� " << max_class << "�� �Դϴ�." << endl;
	cout << "�� ��� ������ " << max << "�� �Դϴ�." << endl;
	cout << "���� �� �� ���� " << min_class << "�� �Դϴ�." << endl;
	cout << "�� ��� ������ " << min << "�� �Դϴ�." << endl;
	delete[] top;
}


