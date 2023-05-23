#include <iostream>
#include <string.h>
using namespace std;
struct guest_list{
    char Name [100];
    char Phonenum[100];
    guest_list* next;
};

class guestDB { 
    guest_list *e;
    guest_list *look(char*);
public:
    guestDB() { e=0;}
    ~guestDB() {};
    void insert(char*, char*);
    void remove(char*);
    void search(char*);
    void show_all();
};

void guestDB::show_all()
{
    if(e==0){
        cout<<"저장된 전화번호가 없습니다.\n";
        return;
    }
    cout<<"모든 전화 번호 보기\n";
    for(guest_list* gl=e; gl!=0; gl=gl->next){
        cout<<gl->Name<<":"<<gl-> char Phonenum <<endl;
    }
}

guest_list*guestDB::look(char* n)
{
    for(guest_list* gl=e; gl!=0; gl=gl->next){
        if(strcmp(n,gl->Name)==0) return gl;
    }
    return(guest_list*)0;
}

void guest_list::insert(char*Name, char*Phone)
{
    if(look(Name)){
        cout<<"이미 존재하는 전화번호 입니다.\n";
    }else{
        guest_list *gl = new guest_list;
        strcpy(gl->Name,Name);
        strcpy(gl->Phonenum, Phonenum);
        gl->next=e;
        e = gl;
    }
}

void guest_list::remove(char*Name)
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

class menu{
    guest_DB Phone;
public:
    void print_guest();
    void show_Phone();
    void insert_Phone();
    void remove_Phone();
    void search_Phone();
};

void menu :: print_menu()
{
    cout<<"========== 전화번호 찾기 ==========\n";
    cout<<"1.모든 전화번호 출력\n";
    cout<<"2.전화번호 입력\n";
    cout<<"3.전화번호 삭제\n";
    cout<<"4.전화번호 찾기\n";
    cout<<"5.프로그램 종료\n";
    cout<<"================================\n";    
}

void menu::print_menu()
{
    Phone.show_all();
}

void menu::insert_Phone()
{
    char Name[100], Phonenum[100];
    cout<<"이름을 입력하세요 ?";
    cin>>Name;
    cout<<"전화번호를 입력하세요 ?";
    cin>>Phonenum;
    Phone.insert(Name, Phonenum);
}

void menu::remove_Phone()
{
    char Name[100];
    cout<<"이름을 입력하세요 ?";
    cin>>Phonenum;
    Phone.insert(Name, Phonenum);
}

void menu:: search_Phone()
{
    char Name[100];
    cout<<"이름을 입력하세요 ?";
    cin>>Phonenum;
    Phone.search(Name);
}

int main()
{
    menu menu1;
    int number;
    while(1){
        menu1.show_menu();
        cout<<"원하는 번호를 입력하세요?";
        cin>>number;
        switch(number){
            case 1: menu1.show_Phone();
                break;
            case 2: menu1.insert_Phone();
                break;
            case 3: menu1.remove_Phone();
                break;
            case 4: menu1.search_Phone();
                break;
            case 5:return 0;
        }
    }
}