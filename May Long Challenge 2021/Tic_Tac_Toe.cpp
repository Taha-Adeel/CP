#include <bits/stdc++.h>

using namespace std;

bool X_win(array<char,9> board){
    bool win=false;
    for(int i=0; i<3; i++){
        if(board[3*i]=='X' && board[3*i+1]=='X' && board[3*i+2]=='X')   win=true;
        else if(board[i]=='X' && board[i+3]=='X' && board[i+6]=='X')   win=true;
    }
    if(board[0]=='X' && board[4]=='X' && board[8]=='X')   win=true;
    else if(board[2]=='X' && board[4]=='X' && board[6]=='X')   win=true;

    return win;
}

bool O_win(array<char,9> board){
    bool win=false;
    for(int i=0; i<3; i++){
        if(board[3*i]=='O' && board[3*i+1]=='O' && board[3*i+2]=='O')   win=true;
        else if(board[i]=='O' && board[i+3]=='O' && board[i+6]=='O')   win=true;
    }
    if(board[0]=='O' && board[4]=='O' && board[8]=='O')   win=true;
    else if(board[2]=='O' && board[4]=='O' && board[6]=='O')   win=true;

    return win;
}

int main(){
    int T;
    cin >> T;
    for (int t=0; t<T; ++t){
        array<char,9> board{};
        for(int i=0; i<9; ++i){
            cin >> board[i];
        }
        long int no_X{std::count(board.begin(), board.end(), 'X')};
        long int no_O{std::count(board.begin(), board.end(), 'O')};
        long int no_{std::count(board.begin(), board.end(), '_')};

        if(no_X==no_O || no_X==no_O+1){
            if((O_win(board) && X_win(board)) || (O_win(board) && no_X-no_O==1) || (X_win(board) && no_X==no_O))
                cout << 3 << '\n';
            else if(O_win(board) || X_win(board) || no_==0)
                cout << 1 << '\n';
            
            else if(no_>0)
                cout << 2 << '\n';
        }
        else
            cout << 3 << '\n';
    }

    return 0;
}