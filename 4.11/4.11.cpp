#include <iostream>
#include <stdexcept>

using namespace std;


class INPUT {
protected:
	int n = 0;
public:
	virtual int input() = 0;
};

class Division {
public:
	static double div(const int a, const int b) {
		if (b == 0) throw invalid_argument("0으로 나눌 수 없습니다");
		return (double)a / b;
	}
};

class INT : public INPUT {		// 분모가 0일때 제외
public:
	bool isNumber(const char* buffer) const {
		for (int i = 0; i < strlen(buffer); i++) {
			if ('0' > buffer[i] || buffer[i] > '9') {
				return false;
			}
		}
		return true;
	}

	virtual int input() override {
		char buffer1[256];
		char buffer2[256];

		n++;
		while(true) {
			cout << " 입력 : ";
			cin.getline(buffer1, sizeof(buffer1));
			cout << " 입력 : ";
			cin.getline(buffer2, sizeof(buffer2));

			//종료 처리 
			if (buffer1[0] == '\0') {
				break;
			}

			if (isNumber(buffer1) && isNumber(buffer2)) {
				cout << buffer1 << " / " << buffer2 << " = " 
					<< Division::div(atoi(buffer1), atoi(buffer2)) << endl;
			}
			else {
				cout << "수치를 입력해주세요" << endl;
			}

		} 

		return 0;
	}
};


int main()
{
	INPUT* pInput = new INT;

	pInput->input();

	delete pInput;

}
