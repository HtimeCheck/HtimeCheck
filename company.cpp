#include <iostream>
#include "worker.h"

int main(void){
    company myCompany;
    int menu;
    myCompany.loadFile();
    while(1){
        menu = selectMenu();
        worker temp;
        string n, i, tA;//이름과 출근시간
        char dep; //부서
        int wH, bT; //일하는 시간과 쉬는 시간
        switch (menu){
        case 1:
            //회사원 정보 추가
            cout << "-----------------------------------" << endl;
            cout << "           회사원 정보 추가            " << endl;
            cout << "-----------------------------------" << endl;
            cout << "이름: ";
            cin >> n;
            cout << "아이디: ";
            cin >> i;
            cout << "부서 이름별 약자 -> 관리팀: M, 디자인팀: D, 회계팀: A, 기획팀: P" << endl;
            cout << "부서: ";
            cin >> dep;
            cout << "출근시간 (XXXX): ";
            cin >> tA;
            cout << "일하는 시간 (시간 단위): ";
            cin >> wH;
            cout << "쉬는 시간 (시간 단위): ";
            cin >> bT;
            temp.setData(n, i, dep, tA, wH, bT);
            cout << "회사원의 정보가 성공적으로 저장되었습니다." << endl;
            myCompany.addWorker(temp);
            break;
        case 2:
            //회사원 정보 읽기
            cout << "-----------------------------------" << endl;
            cout << "           회사원 정보 읽기            " << endl;
            cout << "-----------------------------------" << endl << endl;
            if(myCompany.numWorkers() == 0){
                cout << "입력된 정보가 없습니다\n\n";
                break;
            }
            
            myCompany.listWorker();
            break;
        case 3:
            //회사원 정보 수정
            cout << "-----------------------------------" << endl;
            cout << "           회사원 정보 수정            " << endl;
            cout << "-----------------------------------" << endl << endl;
            if(myCompany.numWorkers() == 0){
                cout << "입력된 정보가 없습니다\n\n";
                break;
            }
            cout << "수정하고 싶은 회사원의 아이디를 입력해주세요: ";
            cin >> i;
            myCompany.updateWorker(i);
            break;
        case 4:
            //회사원 정보 삭제
            cout << "-----------------------------------" << endl;
            cout << "           회사원 정보 삭제            " << endl;
            cout << "-----------------------------------" << endl << endl;
            if(myCompany.numWorkers() == 0){
                cout << "입력된 정보가 없습니다\n\n";
                break;
            }
            cout << "삭제하고 싶은 회사원의 아이디를 입력해주세요: ";
            cin >> i;
            myCompany.deleteWorker(i);
            break;
        case 5:
            //이름으로 검색
            cout << "-----------------------------------" << endl;
            cout << "             이름으로 검색             " << endl;
            cout << "-----------------------------------" << endl << endl;
            if(myCompany.numWorkers() == 0){
                cout << "입력된 정보가 없습니다\n\n";
                break;
            }
            cout << "검색하고 싶은 이름을 입력해주세요: ";
            cin >> n;
            myCompany.searchName(n);
            break;
        case 6:
            //부서 별 검색
            cout << "-----------------------------------" << endl;
            cout << "             부서 별 검색             " << endl;
            cout << "-----------------------------------" << endl << endl;
            if(myCompany.numWorkers() == 0){
                cout << "입력된 정보가 없습니다\n\n";
                break;
            }
            cout << "검색하고 싶은 부서를 입력해주세요: ";
            cin >> dep;
            myCompany.searchDepart(dep);
            break;
        case 7:
            //일 하는 총 시간으로 검색
            cout << "-----------------------------------" << endl;
            cout << "         일하는 총 시간 검색            " << endl;
            cout << "-----------------------------------" << endl << endl;
            if(myCompany.numWorkers() == 0){
                cout << "입력된 정보가 없습니다\n\n";
                break;
            }
            cout << "검색하고 싶은 총 일하는 시간을 입력해주세요: ";
            cin >> wH;
            myCompany.searchHours(wH);
            break;
        case 8:
            //총 정리 보기
            cout << "-----------------------------------" << endl;
            cout << "           총 정보 읽어오기            " << endl;
            cout << "-----------------------------------" << endl << endl;
            cout << "현재 총 출근한 인원: " << myCompany.numWorkers() << endl;
            int avg;
            if(myCompany.numWorkers() == 0){
                avg = 0;
            }else{
                avg = myCompany.sumHours() / myCompany.numWorkers();
            }
            cout << "모든 인원의 편균 일하는 시간: " <<  avg << " 시간" << endl;
        case 9:
            // 파일 읽기
            cout << "-----------------------------------" << endl;
            cout << "          파일에서 정보 읽기            " << endl;
            cout << "-----------------------------------" << endl << endl;
            myCompany.loadFile();
            break;
        case 10:
            //파일 저장
            cout << "-----------------------------------" << endl;
            cout << "           정보 파일에 저장            " << endl;
            cout << "-----------------------------------" << endl << endl;
            myCompany.saveFile();
            break;
        case 0:
            //종료
            cout << "종료됨 !!" << endl;
            return 0;
        default:
            cout << "--- 메뉴를 다시 골라주세요 ---" <<  endl;
        }
    }


    return 0;
}