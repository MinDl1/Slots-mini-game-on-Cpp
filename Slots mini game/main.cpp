//
//  main.cpp
//  Slots mini game
//
//  Created by MinDl on 17.11.2021.
//
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

void count_money(int *a,double &money,double &bet,int &slot); //Prototype of function to count money

int main(int argc, const char * argv[]) {
    srand(time(0));
//  Casino lettering with ASCII
    cout<<"                             o8o\n                             `''\n.ooooo.   .oooo.    .oooo.o oooo  ooo. .oo.    .ooooo.\nd88' `'Y8 `P  )88b  d88(  '8 `888  `888P'Y88b  d88' `88b\n888        .oP'888  `'Y88b.   888   888   888  888   888\n888   .o8 d8(  888  o.  )88b  888   888   888  888   888\n`Y8bod8P' `Y888'8o 8''888P' o888o o888o o888o `Y8bod8P'\n"<<endl;
//  Slot visualization
    string slot_top3 = "_-_-_-_-_-_-_\n|/ \\|/ \\|/ \\|\n";
    string slot_down3 = "\n|\\ /|\\ /|\\ /|\n‾-‾-‾-‾-‾-‾-‾\n";
    string slot_top4 = "_-_-_-_-_-_-_-_-_\n|/ \\|/ \\|/ \\|/ \\|\n";
    string slot_down4 = "\n|\\ /|\\ /|\\ /|\\ /|\n‾-‾-‾-‾-‾-‾-‾-‾-‾\n";
    string slot_top5 = "_-_-_-_-_-_-_-_-_-_-_\n|/ \\|/ \\|/ \\|/ \\|/ \\|\n";
    string slot_down5 = "\n|\\ /|\\ /|\\ /|\\ /|\\ /|\n‾-‾-‾-‾-‾-‾-‾-‾-‾-‾-‾\n";
    int slot=3,spins=0,a[5]={0,0,0,0,0}; //Variables: number of slots, number of spins, the numbers that are displayed by the casino
    double bet=50,money=0; //Variables: amount of money and bet
    string exit;
    while(true){
        cout<<"Top up money: ";
        if(cin>>money){
            break;
        }
        else{
            cout<<"Wrong input"<<endl;
            cin.clear();
            cin.ignore(money<=0,'\n');
        }
    }
    while(exit!="exit"){
        cout<<"Money:"<<money<<"$"<<"    Bet:"<<bet<<"$"<<"     Spins:"<<spins<<endl<<"Write some letters or numbers to play | Write 'bet' to change bet | Write 'slot' to change number of slots"<<endl<<"::";
        cin>>exit;
        if(exit!="exit"){
            if(exit=="slot"||exit=="Slot"){
                while(true){
                    cout<<"Write number of slots(3-5):";
                    if(cin>>slot){
                        break;
                    }
                    else{
                        cout<<"Wrong input"<<endl;
                        cin.clear();
                        cin.ignore(slot<0,'\n');
                    }
                }
                if(slot<3)slot=3;
                else if(slot>5)slot=5;
            }
            else if(exit=="bet"||exit=="Bet"){
                while(true){
                    cout<<"Write your new bet:";
                    if(cin>>bet){
                        break;
                    }
                    else{
                        cout<<"Wrong input"<<endl;
                        cin.clear();
                        cin.ignore(bet<=0,'\n');
                    }
                }
            }
            else if(money<=0){
                while(true){
                    cout<<"Top up money: ";
                    if(cin>>money){
                        break;
                    }
                    else{
                        cout<<"Wrong input"<<endl;
                        cin.clear();
                        cin.ignore(money<=0,'\n');
                    }
                    if(money==0){
                        money=bet;
                    }
                }
            }
            count_money(a,money,bet,slot); //function to count money
            //numbers of slots
            if(slot==3){
                cout<<slot_top3<<"| "<<a[0]<<" | "<<a[1]<<" | "<<a[2]<<" |"<<slot_down3;
            }
            else if(slot==4){
                cout<<slot_top4<<"| "<<a[0]<<" | "<<a[1]<<" | "<<a[2]<<" | "<<a[3]<<" |"<<slot_down4;
            }
            else if(slot==5){
                cout<<slot_top5<<"| "<<a[0]<<" | "<<a[1]<<" | "<<a[2]<<" | "<<a[3]<<" | "<<a[4]<<" |"<<slot_down5;
            }
        }
        spins++;
    }
    if(money<=0){
        cout<<"Money:"<<money<<endl<<"Very bad!"<<endl;
    }
    else{
        cout<<"Money:"<<money<<endl<<"Well played"<<endl;
    }
    system("pause>nul");
}
//Function to count money
void count_money(int *a,double &money,double &bet,int &slot){
    a[0]=rand()%9;
    a[1]=rand()%9;
    a[2]=rand()%9;
    a[3]=rand()%9;
    a[4]=rand()%9;
    if(slot<3)slot=3;
    else if(slot>5)slot=5;
//    3 slots
    else if(slot==3){
        if(a[0]==a[1]||a[1]==a[2]||a[0]==a[2]){
            money+=bet;
        }
        if(a[0]==a[1]+1&&a[1]+1==a[2]+2){
            money+=bet*5;
        }
        if(a[0]==a[1]-1&&a[1]-1==a[2]-2){
            money+=bet*5;
        }
        if(a[0]==a[1]&&a[1]==a[2]){
            money+=bet*38;
        }
    }
//    4 slots
    else if(slot==4){
        if(a[0]==a[1]||a[0]==a[2]||a[0]==a[3]||a[1]==a[2]||a[1]==a[3]||a[2]==a[3]){
            money+=bet;
        }
        if((a[0]==a[1]&&a[1]==a[2])||(a[0]==a[1]&&a[1]==a[3])||(a[1]==a[2]&&a[2]==a[3])){
            money+=bet*2;
        }
        if((a[0]==a[1]+1&&a[1]+1==a[2]+2)||(a[1]==a[2]+1&&a[2]+1==a[3]+2)){
            money+=bet*3;
        }
        if((a[0]==a[1]-1&&a[1]-1==a[2]-2)||(a[1]==a[2]-1&&a[2]-1==a[3]-2)){
            money+=bet*3;
        }
        if(a[0]==a[1]+1&&a[1]+1==a[2]+2&&a[2]+2==a[3]+3){
            money+=bet*44;
        }
        if(a[0]==a[1]-1&&a[1]-1==a[2]-2&&a[2]-2==a[3]-3){
            money+=bet*44;
        }
        if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]){
            money+=bet*144;
        }
    }
//    5 slots
    else if(slot==5){
        if(a[0]==a[1]||a[0]==a[2]||a[0]==a[3]||a[0]==a[4]||a[1]==a[2]||a[1]==a[3]||a[1]==a[4]||a[2]==a[3]||a[2]==a[4]||a[3]==a[4]){
            money+=bet;
        }
        if((a[0]==a[1]&&a[1]==a[2])||(a[0]==a[1]&&a[1]==a[3])||(a[1]==a[2]&&a[2]==a[3])){
            money+=bet*2;
        }
        if((a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])||(a[0]==a[1]&&a[1]==a[3]&&a[3]==a[4])||(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[4])||(a[0]==a[2]&&a[2]==a[3]&&a[3]==a[4])||(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])){
            money+=bet*3;
        }
        if((a[0]==a[1]+1&&a[1]+1==a[2]+2)||(a[1]==a[2]+1&&a[2]+1==a[3]+2)||(a[2]==a[3]+1&&a[3]+1==a[4]+2)){
            money+=bet*3;
        }
        if((a[0]==a[1]-1&&a[1]-1==a[2]-2)||(a[1]==a[2]-1&&a[2]-1==a[3]-2)||(a[2]==a[3]-1&&a[3]-1==a[4]-2)){
            money+=bet*3;
        }
        if(a[0]==a[1]+1&&a[1]+1==a[2]+2&&a[2]+2==a[3]+3){
            money+=bet*22;
        }
        if(a[0]==a[1]-1&&a[1]-1==a[2]-2&&a[2]-2==a[3]-3){
            money+=bet*22;
        }
        if(a[0]==a[1]+1&&a[1]+1==a[2]+2&&a[2]+2==a[3]+3&&a[3]+3==a[4]+4){
            money+=bet*294;
        }
        if(a[0]==a[1]-1&&a[1]-1==a[2]-2&&a[2]-2==a[3]-3&&a[3]-3==a[4]-4){
            money+=bet*294;
        }
        if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]){
            money+=bet*294;
        }
    }
    money-=bet;
}
