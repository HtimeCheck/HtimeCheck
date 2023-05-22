#include <iostream>
#include "worker.h"

int menu(){
    int menu;
    cout << "-----------------------------------"<< endl;
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
    cout << "메뉴를 골라주세요 (종료: 0) --- " << endl;
    cin >> menu;

    return menu;
}

int main(void){
    company myCompany;

    int menu;
    while(1){
        worker temp;
        switch (menu){
        case 1:
            //회사원 정보 추가


        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0:
            cout << "종료됨 !!" << endl;
            break;
        default:
            cout << "--- 메뉴를 다시 골라주세요 ---" <<  endl;
        }
    }


    return 0;
}