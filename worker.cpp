#include <iostream>
using namespace std;
#include <string>

class worker{
    public:
    string name; //회사원 이름 (공백없음) [입럭 받는 정보]]
    char department; //부서 (한글자로 입력) 관리팀: M, 디자인팀: D, 회계팀: A, 기획팀: P [입력받는 정보]
    string timeArrived; //출근 시간 (공백없음) [입력 받는 정보]
    int workingHours; //총 일하는 시간(hour단위로 받음) [입력 받는 정보]
    int breakTime; //쉬는시간(hour 단위로 받음) [입력 받는 정보]
    string endTime; //퇴근시간 (공백없음) [산출 되는 정보]
    void setData(string n, char dep, string tA, int wH, int bT);
};
void worker :: setData(string n, char dep, string tA, int wH, int bT){
    name = n; //이름
    department = dep; //부서
    timeArrived = tA; //출근 시간
    workingHours = wH; //일하는 시간
    breakTime = bT; //쉬는 시간
    
    int end = stoi(tA) + wH*100 + bT*100; //퇴근 시간 구하기
    endTime = to_string(end); //퇴근 시간
}
