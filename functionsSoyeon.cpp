#include "worker.h"

//company 리스트가 empty인지 체크
bool company :: emptyCheck(){
    return (head == NULL); //만약 head가 NULL이면 리스트가 empty라는 뜻, true를 리턴
}

//이름으로 검색하기, 같은 이름이 있다면 모두 출력
void company :: searchName(string s){
    int count = 0;
    cout << "이름 " << s << "를 검색한 결과" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "| 이름 | 아이디 | 부서 | 출근 시간 | 일하는 시간 | 쉬는 시간 | 퇴근 시간 |" << endl;
    cout << "------------------------------------------------------------" << endl;
    for(worker *p = head ; p != NULL ; p = p->link){
        if(p->name == s){
            count ++;
            cout << p->name << " " << p->id << " " << p->department << " " << p->timeArrived << " " << p->workingHours << " " << p->breakTime << " " << p->endTime << endl;
        }
    }
    cout << "총인원은 " << count << "명 입니다." << endl;
}

//검색하려는 부서에 포함된 회사원들의 정보 출력
void company :: searchDepart(char c){
    int count = 0;
    switch (c)
    {
    case 'M':
        cout << "관리팀 ";
        break;
    case 'D':
        cout << "디자인팀 ";
        break;
    case 'A':
        cout << "회계팀 ";
        break;
    case 'P':
        cout << "기획팀 ";
        break;
    default:
        break;
    }
    cout << "부서를 검색한 결과" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "| 이름 | 아이디 | 부서 | 출근 시간 | 일하는 시간 | 쉬는 시간 | 퇴근 시간 |" << endl;
    cout << "------------------------------------------------------------" << endl;
    for(worker *p = head ; p != NULL ; p = p->link){
        if(p->department == c){
            count ++;
            cout << p->name << " " << p->id << " " << p->department << " " << p->timeArrived << " " << p->workingHours << " " << p->breakTime << " " << p->endTime << endl;
        }
    }
    cout << "총인원은 " << count << "명 입니다." << endl;
}
void company :: searchHours(int h){
    int count = 0;
    cout << "총 일하는 시간으로 " << h << "시간을 검색한 결과" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "| 이름 | 아이디 | 부서 | 출근 시간 | 일하는 시간 | 쉬는 시간 | 퇴근 시간 |" << endl;
    cout << "------------------------------------------------------------" << endl;
    for(worker *p = head ; p != NULL ; p = p->link){
        if(p->workingHours == h){
            count ++;
            cout << p->name << " " << p->id << " " << p->department << " " << p->timeArrived << " " << p->workingHours << " " << p->breakTime << " " << p->endTime << endl;
        }
    }
    cout << "총인원은 " << count << "명 입니다." << endl;
}