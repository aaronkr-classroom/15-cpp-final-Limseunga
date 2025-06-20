// final_Student_info.cpp
#include <iostream>

#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "Intl.h"      // Intl �߰�
#include "grade.h"

using namespace std;

// ���� ������
Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}

// �Ҵ� ������
Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;
		cp = s.cp ? s.cp->clone() : 0;
	}
	return *this;
}

// �л� ���� �б�
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
		// �⺻�� ó�� (Core�� �б�)
		cp = new Core(is);
	}

	return is;
}

// ���� ���� �б� �Լ� (�ܺ� ����)
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