// Intl.cpp
#include <algorithm>
#include <vector>

#include "Intl.h"

using std::istream;
using std::vector;

istream& read_hw(istream& in, vector<double>& hw);

istream& Intl::read(istream& in) {
    Core::read_common(in);      // Core의 이름, 중간/기말 점수 등 읽기
    in >> country >> visaType;  // Intl 전용 필드 읽기
    read_hw(in, homework);      // 숙제 점수 읽기
    return in;
}

double Intl::grade() const {
    return Core::grade();       // 특별한 로직 없음 (논문 없음)
}