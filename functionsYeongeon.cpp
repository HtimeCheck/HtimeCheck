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