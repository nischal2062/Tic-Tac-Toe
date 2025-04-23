#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove (char *spaces, char player);
void compMove (char *spaces, char computer);
bool checkWinner (char *spaces, char player, char computer);
bool checkTie (char *spaces);
using namespace std;
int main(){
    srand(time(0));
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'O';
    char computer = 'X';
    bool running = true;
    drawBoard(spaces);
    while (running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if (checkTie(spaces)){
            running = false;
            break;
        }

        compMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if (checkTie(spaces)){
            running = false;
            break;
        }
}
    cout << "Thank you for playing the game! " << endl;
    return 0;
}

void drawBoard(char *spaces){
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << endl;
    cout << "_____|_____|____" << endl; 
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << endl;
    cout << "_____|_____|____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << endl;
    cout << "     |     |     " << endl;
  cout << endl;
}
void playerMove(char *spaces, char player){
    int num;
    do{
        cout << "Choose a place where you want to mark(1-9): ";
        cin >> num;
        if (spaces[num - 1] == ' '){
            spaces[num - 1] = player;
            break;
        }
    }while (num > 1 && num < 9);
}
void compMove(char *spaces, char computer){
    int num;
    while (true)
    {
        num = rand() % 9;
        if (spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        cout << ((spaces[0] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        cout << ((spaces[3] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        cout << ((spaces[6] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        cout << ((spaces[0] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        cout << ((spaces[1] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        cout << ((spaces[2] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        cout << ((spaces[0] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        cout << ((spaces[2] == player) ? "You win! Congratulations big boy." : "You lost!") << endl;
        return true;
    }
    return false;
}

bool checkTie (char *spaces){
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' '){
            return false;
            break;
        }
    }
    cout << "It's a TIE!" << endl;
    return true;
}