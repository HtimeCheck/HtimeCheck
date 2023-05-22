#include "worker.h"

void company::addWorker(worker t){
    worker *temp;
    temp = new worker;
    (*temp) = t;
    temp -> link = head;
    head = temp;
}

void company::listWorker(){
    cout << "********직원 출퇴근 관리 목록********" << endl;
    worker* temp = head;
    cout << "------------------------------------------------------------" << endl;
    cout << "| 이름 | 아이디 | 부서 | 출근 시간 | 일하는 시간 | 쉬는 시간 | 퇴근 시간 |" << endl;
    cout << "------------------------------------------------------------" << endl;
    while (temp != nullptr){
        cout << "| " << temp->name << " | " << temp->id << " | " << temp->department << " | " << temp->timeArrived << " | " << temp->workingHours << " | " << temp->breakTime << " | " << temp->endTime << " |" << endl;
        temp = temp->link;
    }
}

void company :: updateWorker(string s){
    worker* temp;
    temp = new worker;
    bool found = false; //존재하는 정보인지 여부에 대한 변수
    if(!idCheck(s)){
        cout << "ID가" << s << "인 회사원을 찾지 못했습니다." << endl;
        return;
    }
    while (temp != nullptr){
        if(temp ->id == s){
            found = true;
            string n, tA;//이름과 출근시간
            char dep; //부서
            int wH, bT; //일하는 시간과 쉬는 시간
            cout << "이름: ";
            cin >> n;
            cout << "부서: ";
            cin >> dep;
            cout << "출근시간: ";
            cin >> tA;
            cout << "일하는 시간: ";
            cin >> wH;
            cout << "쉬는 시간: ";
            cin >> bT;
            temp-> setData(n, dep, tA, wH, bT);
            cout << "회사원의 정보가 성공적으로 수정되었습니다." << endl;
            break;
        }
        temp = temp ->link;
    }
}

void company::deleteWorker(string s){
    worker *current = head;
    worker *previous = NULL;
    //헤드가 비었을 때
    if(current == NULL){
        cout << "파일이 비었습니다." << endl;
        return;
    }
    if(!idCheck(s)){
        

    }
    //삭제할 노드가 헤드일 때
    if(current->id == s){
        head = current->link;
        delete current;
        cout << "회사원의 정보가 삭제되었습니다." << endl;
        return;
    }
    //삭제할 노드가 헤드가 아닐 때
    while(current != NULL){
        if(current->id == s){
            previous->link = current->link;
            delete current;
            cout << "회사원의 정보가 삭제되었습니다." << endl;
            return;
        }
        previous = current;
        current = current->link;
    }
}

int company::numWorkers() {
    int count = 0;
    worker* current = head;
    while (current != NULL) {
        count++;
        current = current->link;
    }
    return count;
}

int company::sumHours() {
    int sumH = 0;
    worker* current = head;
    while (current != NULL) {
        sumH += current->workingHours;
        current = current->link;
    }
    return sumH;
}