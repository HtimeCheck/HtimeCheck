#include "worker.h"

//company 리스트가 empty인지 체크
bool company :: emptyCheck(){
    return (head == NULL); //만약 head가 NULL이면 리스트가 empty라는 뜻, true를 리턴
}

//이름으로 검색하기, 같은 이름이 있다면 모두 출력
void company :: searchName(string s){
    cout << "| 이름 | 아이디 | 부서 | 출근 시간 | 일하는 시간 | 쉬는 시간 | 퇴근 시간 |" << endl;
    for(worker *p = head ; p != NULL ; p = p->link){
        if(p->name == s){
            cout << p->name << " " << p->id << " " << p->department << " " << p->timeArrived << " " << p->workingHours << " " << p->breakTime << " " << p->endTime << endl;
        }
    }
}

