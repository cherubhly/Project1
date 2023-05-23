#include <iostream>
#include <string.h>
using namespace std;
struct guest_list{
    char Name [500];
    char Phonenum[500];
    char birthday[500];
    char remainP[500];
    char lastvisit[500];
    guest_list* next;
};

class guestDB { 
    guest_list *e;
    guest_list *look(char*);
public:
    guestDB() { e=0;}
    ~guestDB() {};
    void insert(char*, char*, char*);
    void remove(char*);
    void search(char*);
    void show_all();
};

void guestDB::show_all()
{
    if(e==0){
        cout<<"저장된 고객정보가 없습니다.\n";
        return;
    }
    cout<<"모든 고객 정보 보기\n";
    for(guest_list* gl=e; gl!=0; gl=gl->next){
        cout<<gl->Name<<":"<<gl-> Phonenum <<endl;
    }
}

guest_list*guestDB::look(char* n)
{
    for(guest_list* gl=e; gl!=0; gl=gl->next){
        if(strcmp(n,gl->Name)==0) return gl;
    }
    return(guest_list*)0;
}

void guestDB::insert(char* Name, char* number, char* birth)
{
    if(look(Name)){
        cout<<"이미 존재하는 고객정보 입니다.\n";
    }else{
        guest_list *gl = new guest_list;
        strcpy(gl->Name,Name);
        strcpy(gl->Phonenum,number);
        gl->next=e;
        e = gl;
    }
}

void guestDB::remove(char*Name)
{
    guest_list *gl;
    if(!(gl=look(Name))){
        cout<<"이름에 해당하는 전화번호가 없습니다.\n";}
    else{
        if(gl== e){
            e = gl ->next;
        }else{
            guest_list *prev = e;
            while(prev -> next!= gl){
                prev = prev->next;
            }
            prev -> next = gl ->next;
        }
        delete gl;
    }
}

void guestDB::search(char *Name)
{
    guest_list* gl;
    if(gl = look(Name)){
        cout <<Name<<" 고객의 전화번호는" << gl->Phonenum << "입니다.\n";
    }else{
        cout<<"이름에 해당하는 전화번호가 없습니다.\n";
    }
}

class menu{
    guestDB Guest;
public:
    void print_menu();
    void show_Guest();
    void insert_Guest();
    void remove_Guest();
    void search_Guest();
};

void menu::print_menu()
{
    cout<<"========== 미용실 회원 관리 프로그램 ==========\n";

    cout<<"1.모든 고객정보 출력\n";
    cout<<"2.고객정보 추가 입력\n";
    cout<<"3.고객정보 삭제\n";
    cout<<"4.고객정보 찾기\n";
    cout<<"5.헤어서비스 정보 저장\n";
    cout<<"6.프로그램 종료\n";

    cout<<"================================\n";    
}

void menu::show_Guest()
{
    Guest.show_all();
}

void menu::insert_Guest()
{
    char Name[500], Phonenum[500], birthday[500];
    cout<<"이름을 입력하세요 ?";
    cin>>Name;
    cout<<"전화번호를 입력하세요 ?";
    cin>>Phonenum;
    cout<<"생일을 입력하세요 ?";
    cin>>birthday;
    Guest.insert(Name, Phonenum, birthday);
}

void menu::remove_Guest()
{
    char Name[500];
    cout<<"이름을 입력하세요 ?";
    cin>>Name;
    Guest.remove(Name);
}

void menu:: search_Guest()
{
    char Name[500];
    cout<<"이름을 입력하세요 ?";
    cin>>Name;
    Guest.search(Name);
}

int main()
{
    menu menu1;
    int number;
    while(1){
        menu1.print_menu();
        cout<<"원하는 메뉴 번호를 선택하세요 ?";
        cin>>number;
        switch(number){
            case 1: menu1.show_Guest();
                break;
            case 2: menu1.insert_Guest();
                break;
            case 3: menu1.remove_Guest();
                break;
            case 4: menu1.search_Guest();
                break;
            case 5:return 0;
        }
    }
}