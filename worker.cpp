#include "worker.h"
#include <cstring>
#include <fstream>
#include <string>

int selectMenu(){
    int menu;
    cout << "\n-----------------------------------"<< endl;
    cout << "1. 회사원 정보 저장" << endl;
    cout << "2. 회사원 정보 읽기" << endl;
    cout << "3. 회사원 정보 수정" << endl;
    cout << "4. 회사원 정보 삭제" << endl;
    cout << "5. 이름으로 검색" << endl;
    cout << "6. 부서별 검색" << endl;
    cout << "7. 일하는 총 시간으로 검색" << endl;
    cout << "8. 총 정리" << endl;
    cout << "9. 파일 읽기" << endl;
    cout << "10. 파일 저장" << endl;
    cout << "-----------------------------------"<< endl;
    cout << "메뉴를 골라주세요 (종료: 0) --- " ;
    cin >> menu;
    return menu;
}
void worker :: setData(string n, string i, char dep, string tA, int wH, int bT){
    name = n; //이름
    id = i;
    department = dep; //부서
    timeArrived = tA; //출근 시간
    workingHours = wH; //일하는 시간
    breakTime = bT; //쉬는 시간
    
    int end = stoi(tA) + wH*100 + bT*100; //퇴근 시간 구하기
    endTime = to_string(end); //퇴근 시간
}
company :: company(){
    head = NULL;
}
void company::addWorker(worker t){
    worker *temp;
    temp = new worker;
    (*temp) = t;
    temp -> link = head;
    head = temp;
}

void company::listWorker(){
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
    temp = head;
    bool found = false; //존재하는 정보인지 여부에 대한 변수
    if(!idCheck(s)){
        cout << "ID가" << s << "인 회사원을 찾지 못했습니다." << endl;
        return;
    }
    string n,i, tA;//이름과 출근시간
    char dep; //부서
    int wH, bT; //일하는 시간과 쉬는 시간
    cout << "이름: ";
    cin >> n;
    cout << "아이디: ";
    cin >> i;
    cout << "부서: ";
    cin >> dep;
    cout << "출근시간: ";
    cin >> tA;
    cout << "일하는 시간: ";
    cin >> wH;
    cout << "쉬는 시간: ";
    cin >> bT;
    while (temp != nullptr){
        if(temp ->id == s){
            found = true;
            temp-> setData(n, i, dep, tA, wH, bT);
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
        cout << "해당 아이디를 가진 회사원이 존재하지 않습니다!\n";
        return;
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
            cout << p->name << " | " << p->id << " | " << p->department << " | " << p->timeArrived << " | " << p->workingHours << " | " << p->breakTime << " | " << p->endTime << endl;
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
            cout << p->name << " | " << p->id << " | " << p->department << " | " << p->timeArrived << " | " << p->workingHours << " | " << p->breakTime << " | " << p->endTime << endl;
        }
    }
    cout << "총인원은 " << count << "명 입니다." << endl;
}

//일하는 총시간이 입력된 값과 같은 회사원의 정보를 출력
void company :: searchHours(int h){
    int count = 0;
    cout << "총 일하는 시간으로 " << h << "시간을 검색한 결과" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "| 이름 | 아이디 | 부서 | 출근 시간 | 일하는 시간 | 쉬는 시간 | 퇴근 시간 |" << endl;
    cout << "------------------------------------------------------------" << endl;
    for(worker *p = head ; p != NULL ; p = p->link){
        if(p->workingHours == h){
            count ++;
            cout << p->name << " | " << p->id << " | " << p->department << " | " << p->timeArrived << " | " << p->workingHours << " | " << p->breakTime << " | " << p->endTime << endl;
        }
    }
    cout << "총인원은 " << count << "명 입니다." << endl;
}

//파일에 있는 정보 로드해오기, 파일이 없다면 파일이 존재하지 않는다고 출력
void company::loadFile() {
    worker* temp ;
    head = NULL;
    ifstream file("worker.txt");
    if (!file.is_open()) {
        std::cout << "\n파일이 존재하지 않음!!\n";
        return;
    }
    string n, id, tA, eT;
    char dep;
    int wH, bT;
    while (file >> n >> id >> dep >> tA >> wH >> bT >> eT) {
        temp = new worker;
        temp->setData(n, id, dep, tA, wH, bT);
        temp->link = head;
        head = temp;
    }
    file.close();
    cout << "파일 로드 성공!!" << endl;
}



//파일에 저장, 이미 파일이 존재 한다면 파일 정보 지우고 리스트에 있는 정보로 저장
void company :: saveFile(){ 
    FILE *fp = fopen("worker.txt","w");
    for(worker *t = head; t != NULL; t= t->link){
        fprintf(fp,"%s %s %c %s %d %d %s\n",t->name.c_str(), t->id.c_str(), t->department, t->timeArrived.c_str(), t->workingHours, t->breakTime, t->endTime.c_str());
    }
    fclose(fp);
    cout << "파일에 저장됨!!" << endl;
}
//같은 아이디인 사람이 있는지 확인
bool company :: idCheck(string s){
    for(worker *p = head ; p != NULL ; p = p->link){
        if(p->id == s){ 
            //id가 존재 한다면 false를 return
            return true;
        }
    }
    return false;
}