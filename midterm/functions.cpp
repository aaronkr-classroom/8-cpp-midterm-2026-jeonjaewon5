#include "functions.h"
#include <vector>
#include <algorithm>

using std::istream; using std::vector;

// 과자 점수를 모두 더하여 갯수로 나눔
double calculateAverage(const vector<double>& grades) { //int를 double로 고쳤음
    if (grades.empty()) return 0;

    double total = 0; // 초기화 및 세미콜론 수정함
    for (vector<double>::size_type i = 0; i < grades.size(); ++i) {
        total += grades[i]; // 누적 연산으로 수정함
    }
    return total / grades.size(); // total이 double이기 떄문에 자동 형변환됨
}

// 이름순으로 정렬하기 위한 기준 함수임
bool compare(const functions& x, const functions& y) {
    return x.name < y.name;
}

double grade(const functions& s) {

    // calculateaverage 함수를 사용하여 최종 성적을 계산
    return 0.2 * s.midterm + 0.4 * s.final_exam + 0.4 * calculateAverage(s.homework);
}

// 점수를 반복적으로 읽어오는 코드임
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x) hw.push_back(x);
        in.clear();
    }
    return in;
}

//  이름과 시험 점수를 먼저 일고 read_hw를 호출함.
istream& read(istream& in, functions& s) {
    in >> s.name >> s.midterm >> s.final_exam;
    read_hw(in, s.homework);
    return in;
}
