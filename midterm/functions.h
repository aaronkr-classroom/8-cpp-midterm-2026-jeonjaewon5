#ifndef GUARD_functions
#define GUARD_functions

//필요한 라이브러리 iostream, vector,string
#include <iostream>
#include <vector>
#include <string>


//학생의 정보를 담는 구조체임
struct functions {
    std::string name;
    double midterm, final_exam;
    std::vector<double> homework;
};
// 외부에서 호출할 함수임
bool compare(const functions&, const functions&);
std::istream& read(std::istream&, functions&);
std::istream& read_hw(std::istream&, std::vector<double>&);
double calculateAverage(const std::vector<double>&);
double grade(const functions&);

#endif
