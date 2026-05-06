#include <iostream>
using namespace std;

enum enGame{paper=1,scissor=2,stone=3};

struct stResult{
    int GameRound;
    int PlayerWinner=0;
    int ComputerWinner=0;
    int Draw=0;
    int FinalWineer;
};

int Random(int From,int To){
    
    int Rand=rand()%(To-From+1)+From;
    
    return Rand;
    
}

int Read(string Mass){
    int num;cout<<Mass;cin>>num;
    return num;
}


int Read_Round(){
    
    return Read("How many Rounds 1 to 10 ? : ");
    
}

int Read_USer(){
    
    return Read("Your choise : [1] paper , [2] scissor , [3] stone : ");
    
}

int Read_comp(){
    
    return (Random(1, 3));
    
}

void Print_Stone(enGame user,enGame comp,stResult &Temp){
    cout<<"the choise of user is : Stone"<<endl;
    if (user==enGame::stone){
        if (comp==enGame::scissor) {
    cout<<"the choise of comp is : scissor"<<endl;
            cout<<"  Round winner : you won !"<<endl;
            Temp.PlayerWinner++;
        }
        else if (comp==enGame::paper){
    cout<<"the choise of comp is : paper"<<endl;
            cout<<"  Round winner : you lose !"<<endl;
            Temp.ComputerWinner++;
        }
        else {
    cout<<"the choise of comp is : stone"<<endl;
            cout<<"  Round winner : [No Winner]"<<endl;
            Temp.Draw++;
        }
    }
}

void Print_Scissor(enGame user,enGame comp,stResult &Temp){
    cout<<"the choise of user is : Scissor"<<endl;
    if (user==enGame::scissor){
        if (comp==enGame::paper) {
    cout<<"the choise of comp is : paper"<<endl;
            cout<<" Round winner : you won !"<<endl;
            Temp.PlayerWinner++;
        }
        else if (comp==enGame::stone){
    cout<<"the choise of comp is : stone"<<endl;
            cout<<" Round winner : you lose !"<<endl;
            Temp.ComputerWinner++;
        }
        else {
    cout<<"the choise of comp is : Scissor"<<endl;
            cout<<" Round winner : [No Winner]"<<endl;
            Temp.Draw++;
        }
    }
}

void Print_Paper(enGame user,enGame comp,stResult &Temp){
    cout<<"the choise of user is : paper"<<endl;
    if (user==enGame::paper){
        if (comp==enGame::stone) {
    cout<<"the choise of comp is : stone"<<endl;
            cout<<" Round winner : you won !"<<endl;
            Temp.PlayerWinner++;
        }
        else if (comp==enGame::scissor){
    cout<<"the choise of comp is : scisoor"<<endl;
    cout<<" Round winner : you lose !"<<endl;
            Temp.ComputerWinner++;
        }
        else {
    cout<<"the choise of comp is : paper"<<endl;
    cout<<" Round winner : [No Winner]"<<endl;
            Temp.Draw++;
        }
    }
}

void Print_Round(stResult &Temp){
    int NumofRound;NumofRound=Read_Round();cout<<endl<<endl;
    Temp.GameRound=NumofRound;
    for (int i=1;i<=NumofRound;i++) {
        cout<<"Round ["<<i<<"] beigns : \n\n";
        enGame user=(enGame)Read_USer();
        enGame comp=enGame(Read_comp());
        cout<<"-------Round ["<<i<<"]-------"<<endl<<endl;
        if (user==enGame::stone) {
            Print_Stone(user,comp,Temp);
        } else if(user==enGame::scissor){
            Print_Scissor(user,comp,Temp);
        }
        else {
            Print_Paper(user,comp,Temp);
        }
        cout<<"-----------------------"<<endl<<endl;
    }
    cout<<"             --------------------------------"<<endl;
    cout<<"                     +++ GAME OVER +++"<<endl;
    cout<<"             --------------------------------"<<endl;
}

void print_Result(){
    stResult Res;
    Print_Round(Res);
    cout<<endl<<"        ---------------[Game Result]------------\n\n";
    cout<<"                 Game Round           : "<<Res.GameRound<<endl;
    cout<<"                 Player won time      : "<<Res.PlayerWinner<<endl;
    cout<<"                 computer won time    : "<<Res.ComputerWinner<<endl;
    cout<<"                 Draw time            : "<<Res.Draw<<endl;
    Res.FinalWineer=Res.PlayerWinner-Res.ComputerWinner;
    if (Res.FinalWineer > 0) {
    cout<<"                 Final winner         : "<<"you Won"<<endl;
    } else if (Res.FinalWineer<0){
    cout<<"                 Final winner         : "<<"you Lose"<<endl;
    }
    else {
    cout<<"                 Final Winner         : "<<"[No Winner]"<<endl;
    }
    cout<<"              ----------------------------------------\n\n";
}

void StartGame(){
    
    string Contin="Y";
    
    while (Contin=="Y"||Contin=="y") {
        
        print_Result();
        
        cout<<"Do you want to play again? Y/N? : ";
        
        cin>>Contin;cout<<endl<<endl;
        
    }
    
}

int main() {
    
    srand((unsigned)time(NULL));
    
    StartGame();
    
    return 0;
}
