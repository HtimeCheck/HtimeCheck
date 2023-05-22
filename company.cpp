#include <iostream>
#include "worker.h"

int main(void){
    company myCompany;
    int menu;
    while(1){
        menu = selectMenu();
        worker temp;
        string n, tA;//이름과 출근시간
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
            cout << "부서 이름별 약자 -> 관리팀: M, 디자인팀: D, 회계팀: A, 기획팀: P" << endl;
            cout << "부서: ";
            cin >> dep;
            cout << "출근시간 (XXXX): ";
            cin >> tA;
            cout << "일하는 시간 (시간 단위): ";
            cin >> wH;
            cout << "쉬는 시간 (시간 단위): ";
            cin >> bT;
            temp.setData(n, dep, tA, wH, bT);
            cout << "회사원의 정보가 성공적으로 저장되었습니다." << endl;
            myCompany.addWorker(temp);
        // case 2:
        //     //회사원 정보 읽기
        // case 3:
        //     //
        // case 4:
        //     //
        // case 5:
        //     //
        // case 6:
        //     //
        // case 7:
        //     //
        // case 8:
        //     //
        // case 9:
        //     //
        // case 10:
        //     //
        case 0:
            //
            cout << "종료됨 !!" << endl;
            return 0;
        default:
            cout << "--- 메뉴를 다시 골라주세요 ---" <<  endl;
        }
    }


    return 0;
}