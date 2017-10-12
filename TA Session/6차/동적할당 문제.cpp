
# include <iostream>

using namespace std;

int main()
{
	cout << "홍릉초등학교의 총 반의 개수: ";
	int num_class;
	cin >> num_class;
	int *top = new int[num_class];
	for (int k = 0; k < num_class; k++) {
		cout << k + 1 << "반의 학생 수는 몇 명?: ";
		int num_stu;
		cin >> num_stu;
		int *student = new int[num_stu];
		for (int i = 0; i < num_stu; i++) {
			cout << k+1 << "반의 " << i + 1 << "번째 학생의 점수를 입력하세요.: ";
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
	cout << "제일 잘 본 반은 " << max_class << "반 입니다." << endl;
	cout << "그 평균 점수는 " << max << "점 입니다." << endl;
	cout << "제일 못 본 반은 " << min_class << "반 입니다." << endl;
	cout << "그 평균 점수는 " << min << "점 입니다." << endl;
	delete[] top;
}


