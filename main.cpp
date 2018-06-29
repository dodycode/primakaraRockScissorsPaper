#include <iostream>
#include <stdlib.h>
#include <time.h>
 
#define MAXHEALTH 100
 
using namespace std;
 
int menu, acak, pil;
 
typedef struct{
    string icon;
}icon;
 
typedef struct{
    icon item[MAXHEALTH];
    int count;
}stack;
 
stack darahPemain;
stack darahBot;
 
 
//Fungsi STACK
void initializestack(stack *s)
{
    s->count = 0;
}
 
bool empty(stack s)
{
    return (s.count == 0);
}
 
bool full(stack s)
{
    return (s.count == MAXHEALTH);
}
 
void push(string x, stack *s)
{
    if (full(*s)) {
        printf("\n");
    }
    else
    {
        s->count++;
        s->item[s->count].icon = x;
    }
}
 
icon pop(stack *s)
{
    if (empty(*s)) { //update
        printf("There's no health.\n");
    }
    else
    {
        icon temp = (s->item[s->count]);
        s->count--;
        return temp;
    }
}
 
icon peak(stack s) {
    if (empty(s)) {//update
        printf("There's no health.\n");
    }
    else
        return(s.item[s.count]);
}
 
void defaultHealth(stack *s)
{
    //default di set 5
    for(int i=0; i<5; i++)
    {
        push("*", s);
    }
}
 
void tampilStackDarah(stack p, stack b, stack tempDarahPemain, stack tempDarahBot)
{
    //munculkan
    cout<<"Your health: ";
    while(!empty(p)){
        cout<<" "<<peak(p).icon<<" ";
        push(pop(&p).icon, &tempDarahPemain);
    }
    cout<<endl;
 
    cout<<"BOT Health: ";
    while(!empty(b)){
        cout<<" "<<peak(b).icon<<" ";
        push(pop(&b).icon, &tempDarahBot);
    }
    cout<<endl;
 
    //kembalikan lagi semuanya
    while (!empty(tempDarahPemain)) {
        push(pop(&tempDarahPemain).icon, &p);
    }
 
    while (!empty(tempDarahBot)) {
        push(pop(&tempDarahBot).icon, &b);
    }
}
 
void play(stack *p, stack *b)
{
    // siapkan temp utk peak darah dari stack
    stack tempDarahPemain;
    stack tempDarahBot;
    initializestack(&tempDarahBot);
    initializestack(&tempDarahPemain);
 
    defaultHealth(p);
    defaultHealth(b);
 
    srand(time(NULL));
    int round = 0;
 
    while(!empty(*p) && !empty(*b)){
        system("cls");
        tampilStackDarah(*p,*b,tempDarahPemain,tempDarahBot);
        round++;
        acak = rand()%3 + 1;
        cout<<endl;
        cout<<"Round: "<<round<<endl;
        cout<<"1. Scissors"<<endl;
        cout<<"2. Rock"<<endl;
        cout<<"3. Paper"<<endl;
        cout<<"PLease choose: ";cin>>pil;
        switch(pil){
            case 1:
                cout<<"You choose: Scissors"<<endl;
                if (acak == 1) {
                    cout<<"Bot choose: Scissors"<<endl;
                    cout<<"-- DRAW --"<<endl;
                }else if(acak == 2) {
                    cout<<"Bot choose: Rock"<<endl;
                    cout<<"-- Oops haha, BOT win! Don't give up!' --"<<endl;
                    if(!empty(*p)){
                        //kurangi darah pemain
                        pop(p);
                    }else {
                        break;
                    }
                }else if(acak == 3) {
                    cout<<"Bot choose: Paper"<<endl;
                    cout<<"-- Wow, you defeat BOT!"<<endl;
                    if(!empty(*b)){
                        //kurangi darah bot
                        pop(b);
                    }else{
                        break;
                    }
                }else{
                    cout<<"Oops, something went wrong!"<<endl;
                }
            break;
 
            case 2:
                cout<<"You choose: Rock"<<endl;
                if (acak == 1) {
                    cout<<"Bot choose: Scissors"<<endl;
                    cout<<"-- Wow, you defeat BOT! --"<<endl;
                    if(!empty(*b)){
                        //kurangi darah bot
                        pop(b);
                    }else{
                        break;
                    }
                }else if(acak == 2) {
                    cout<<"Bot choose: Rock"<<endl;
                    cout<<"-- DRAW --"<<endl;
                }else if(acak == 3) {
                    cout<<"Bot choose: Paper"<<endl;
                    cout<<"-- Oops haha, BOT win! Don't give up!' --"<<endl;
                    if(!empty(*p)){
                        //kurangi darah pemain
                        pop(p);
                    }else {
                        break;
                    }
                }else{
                    cout<<"Oops, something went wrong!"<<endl;
                }
            break;
 
            case 3:
                cout<<"You choose: Paper"<<endl;
                if (acak == 1) {
                    cout<<"Bot choose: Scissors"<<endl;
                    cout<<"-- Oops haha, BOT win! Don't give up!' --"<<endl;
                    if(!empty(*p)){
                        //kurangi darah pemain
                        pop(p);
                    }else{
                        break;
                    }
                }else if(acak == 2) {
                    cout<<"Bot choose: Rock"<<endl;
                    cout<<"-- Wow! You defeat BOT! --"<<endl;
                    if(!empty(*b)){
                        //kurangi darah bot
                        pop(b);
                    }else {
                        break;
                    }
                }else if(acak == 3) {
                    cout<<"Bot choose: Paper"<<endl;
                    cout<<"-- DRAW --"<<endl;
                }else{
                    cout<<"Oops, something went wrong!"<<endl;
                }
            break;
 
            default: cout<<"Please choose correctly!"<<endl; break;
            system("pause");
        }
        system("pause");
    }
}
 
int main(int argc, char** argv) {
    bool ulang = true;
    initializestack(&darahPemain);
    initializestack(&darahBot);
    do{
        system("cls");
        cout<<"===============Primakara Scissors, Rock and Paper=================="<<endl;
        cout<<"1. Start Game"<<endl;
        cout<<"2. Exit Game"<<endl;
        cout<<"Please choose: ";cin>>menu;
        switch(menu){
            case 1:
                //Jalankan permainan
                play(&darahPemain, &darahBot);
               
                //Setelah game selesai, keluarkan pesan
                cout<<endl;
                if(empty(darahPemain)){
                    cout<<"Congrats! You're win!"<<endl;
                }else if(empty(darahBot)) {
                    cout<<"Game over!"<<endl;
                }else{
                    cout<<"Oops! something went wrong!"<<endl;
                }
                system("pause");
            break;
 
            case 2:
                ulang = false;
                cout<<"Game will close shortly..."<<endl;
            break;
        }
    }while(ulang);
}