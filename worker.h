#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
using namespace std;
#include <string> 

/*
출퇴근 관리 시스템
회사원의 출근시간, 일하는 시간, 쉬는 시간 을 입력 받아 퇴근시간을 구하는 프로그램
회사원끼리 같은 이름이 있을 수 있기에 고유 정보 인 아이디를 입력 받아 누구인지 확인 가능
쉬는 시간과 일하는 시간은 hour단위로 입력받아 계산을 조금 더 쉽게 만듬
Linked list로 구현하기
*/
int selectMenu();

class worker{
    public:
    worker *link;
    string name; //회사원 이름 (공백없음) [입럭 받는 정보]]
    string id; //회사원의 고유 아이디 (공백 없음) [22200XXX]
    char department; //부서 (한글자로 입력) 관리팀: M, 디자인팀: D, 회계팀: A, 기획팀: P [입력받는 정보]
    string timeArrived; //출근 시간 (공백없음) [입력 받는 정보]
    int workingHours; //총 일하는 시간(hour단위로 받음) [입력 받는 정보]
    int breakTime; //쉬는시간(hour 단위로 받음) [입력 받는 정보]
    string endTime; //퇴근시간 (공백없음) [산출 되는 정보]
    void setData(string n, char dep, string tA, int wH, int bT);
};

class company{
    worker *head; //company의 head(시작점) [여기서 addWorker가 이루어짐]
    public:
    company();
    void addWorker(worker t); //addToHead() 와 같은 기능, 회사원 정보 추가
    void listWorker(); //모든 회사원의 정보를 출력
    void updateWorker(string s); //회사원의 정보를 업데이트, 업데이트 할 정보를 위해 고유 아이디를 입력받음
    void deleteWorker(string s); //회사원의 정보를 삭제, 삭제 할 정보를 위해 고유 아이디를 입력받음
    int numWorkers(); //입력된 총 회사원의 수
    int sumHours(); //모든 회사원의 총 일하는 시간
    void searchName(string s); //이름으로 검색하기, 같은 이름이 있다면 모두 출력
    void searchDepart(char c); //검색하려는 부서에 포함된 회사원들의 정보 출력
    void searchHours(int h); //일하는 총시간이 입력된 값과 같은 회사원의 정보를 출력
    int loadFile(); //파일에 있는 정보 로드해오기, 파일이 없다면 파일이 존재하지 않는다고 출력
    void saveFile(); //파일에 저장, 이미 파일이 존재 한다면 파일 정보 지우고 리스트에 있는 정보로 저장
    bool emptyCheck(); //company 리스트가 empty인지 체크
    bool idCheck(string s); //같은 아이디인 사람이 있는지 확인
};

#endif