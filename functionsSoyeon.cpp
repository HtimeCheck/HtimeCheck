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
            cout << p->name << " " << p->id << " " << p->department << " " << p->timeArrived << " " << p->workingHours << " " << p->breakTime << " " << p->endTime << endl;
        }
    }
    cout << "총인원은 " << count << "명 입니다." << endl;
}

//파일에 있는 정보 로드해오기, 파일이 없다면 파일이 존재하지 않는다고 출력
int company :: loadFile(){ 
    worker *t = head;
    int i = 0;
    FILE *fp = fopen("worker.txt", "r");
    if(fp == NULL){
        cout << "\n파일이 존재 하지 않음 !!\n";
        return 0;
    }
    for(;i<100;i++){
        fscanf(fp,"%s",t->name);
        if(feof(fp)) break;
        fscanf(fp,"%s",t->id);
        fscanf(fp,"%c",t->department);
        fscanf(fp,"%s",t->timeArrived);
        fscanf(fp,"%d",t->workingHours);
        fscanf(fp,"%d",t->breakTime);
        fscanf(fp,"%s",t->endTime);
        t->link = NULL;
    }
    fclose(fp);
    cout << "파일 로드 성공!!" << endl;
    return i;
}

//파일에 저장, 이미 파일이 존재 한다면 파일 정보 지우고 리스트에 있는 정보로 저장
void company :: saveFile(){ 
    FILE *fp = fopen("worker.txt","w");
    for(worker *t = head; t != NULL; t= t->link){
        fprintf(fp,"%s %s %c %s %d %d %s\n",t->name, t->id, t->department, t->timeArrived, t->workingHours, t->breakTime, t->endTime);
    }
    fclose(fp);
    cout << "파일에 저장됨!!" << endl;
}
