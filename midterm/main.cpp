#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using std::cin;     using std::cout;
using std::endl;    using std::setprecision;
using std::sort;    using std::vector;
using std::string;

//학생들의 데이터를 담기 위한 벡터와 일시 저장 객체임
int main() {
    vector<functions> students;
    functions record;
    string::size_type maxlen = 0;

    cout << "학생의 이름, 중간고사, 기말고사, 과제 성적을 입력해 주세요! (종료하려면 Ctrl+Z): " << endl;
    //입렵이 끝날때까지 정보를 계속 읽어옴
    while (read(cin, record)) {
        if (record.name.size() > maxlen) maxlen = record.name.size();
        students.push_back(record);
    }
    // compare를 사용, 알파벳순으로 정렬함
    sort(students.begin(), students.end(), compare);

    //반복문으로 결과를 출력시작함
    for (vector<functions>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');
        
        try {
            double final_grade = grade(students[i]);
            std::streamsize prec = cout.precision();

            // 소수점 자리를 설정하고 점수 출력함.
            cout << setprecision(3) << final_grade << setprecision(prec);
            // 90점 이상이면 추가 메시지를 표시함
            if (final_grade >= 90) {
                cout << " Excellent! 아주 훌륭합니다!";
            }
        }
        catch (std::domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
