// Intl.cpp
#include <algorithm>
#include <vector>

#include "Intl.h"

using std::istream;
using std::vector;

istream& read_hw(istream& in, vector<double>& hw);

istream& Intl::read(istream& in) {
    Core::read_common(in);      // Core�� �̸�, �߰�/�⸻ ���� �� �б�
    in >> country >> visaType;  // Intl ���� �ʵ� �б�
    read_hw(in, homework);      // ���� ���� �б�
    return in;
}

double Intl::grade() const {
    return Core::grade();       // Ư���� ���� ���� (�� ����)
}