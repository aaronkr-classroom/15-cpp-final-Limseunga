// final_main.cpp
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h"
#include "Grad.h"
#include "Intl.h"           // Intl 헤더 포함
#include "Vec.h"
#include "Student_info.h"
#include "median.h"

using namespace std;

int main() {
	vector<Core*> students;
	Core* record;
	char ch;
	string::size_type maxlen = 0;

	// 데이터 읽기
	while (cin >> ch) {
		if (cin.eof()) break;

		// 유효한 타입 확인
		if (ch != 'U' && ch != 'G' && ch != 'I') {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (ch == 'U')
			record = new Core;
		else if (ch == 'G')
			record = new Grad;
		else // ch == 'I'
			record = new Intl;

		record->read(cin);

		maxlen = max(maxlen, record->getName().size());
		students.push_back(record);
	}

	// 이름순 정렬
	sort(students.begin(), students.end(), compare_Core_ptrs);

	// 출력
	for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
		if (dynamic_cast<Grad*>(students[i])) {
			cout << "(G) ";
		}
		else if (dynamic_cast<Intl*>(students[i])) {
			cout << "(I) ";
		}
		else {
			cout << "(U) ";
		}

		cout << students[i]->getName()
			<< string(maxlen + 1 - students[i]->getName().size(), ' ');

		try {
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error& e) {
			cout << e.what() << endl;
		}

		delete students[i];
	}

	return 0;
}