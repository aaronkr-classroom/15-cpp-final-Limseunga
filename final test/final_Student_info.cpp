// final_Student_info.cpp
#include <iostream>

#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "Intl.h"      // Intl 추가
#include "grade.h"

using namespace std;

// 복사 생성자
Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}

// 할당 연산자
Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;
		cp = s.cp ? s.cp->clone() : 0;
	}
	return *this;
}

// 학생 정보 읽기
istream& Student_info::read(istream& is) {
	delete cp;

	char ch;
	is >> ch;

	if (ch == 'U') {
		cp = new Core(is);
	}
	else if (ch == 'G') {
		cp = new Grad(is);
	}
	else if (ch == 'I') {
		cp = new Intl(is);
	}
	else {
		// 기본값 처리 (Core로 읽기)
		cp = new Core(is);
	}

	return is;
}

// 숙제 점수 읽기 함수 (외부 구현)
istream& read_hw(istream& in, Vec<double>& hw) {
	if (in) {
		hw.clear();
		double x;
		while (in >> x) {
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}