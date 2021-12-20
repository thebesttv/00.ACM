#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

char board[10];
int player = 1;

int status(); // 0: in progress, 1: 1 wins, 2: 2 wins, 3: tie
void drawBoard();

int main(void){
  for(int i=1;i<=9;++i) board[i] = '0' + i;

  int st;
  do{
    drawBoard();
    std::cout << "Player " << player << ", enter a number [1-9]: " << std::flush;
    std::string s; std::cin >> s;
    if(s.size()!=1 || s[0]<'1' || s[0]>'9') continue;

    int pos = s[0] - '0';
    if(board[pos] != pos + '0'){
      std::cout << "Invalid input, choose another cell." << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      continue;
    }
    board[pos] = player==1 ? 'X' : 'O';

    player = player==1 ? 2 : 1;
    st = status();
  }while(!st);

  if(st==3)
    std::cout << "Game ends in a tie." << std::endl;
  else
    std::cout << "Player " << st << " wins." << std::endl;

  return 0;
}

const char v[8][3] = {{1,2,3}, {4,5,6}, {7,8,9},
                      {1,4,7}, {2,5,8}, {3,6,9},
                      {1,5,9}, {3,5,7}          };

int status(){ // 0: in progress, 1: 1 wins, 2: 2 wins, 3: tie
  for(int i=0;i<8;++i){
    if(board[v[i][0]] == board[v[i][1]] &&
       board[v[i][1]] == board[v[i][2]])
      return board[v[i][0]]=='X' ? 1 : 2;
  }
  int remain = 9;
  for(int i=1;i<=9;++i)
    if(board[i] != '0' + i)
      remain--;
  return remain ? 0 : 3;
}

void drawBoard(){
  system("clear");

  printf("         Tic Tac Toe\n\n\n");
  printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
  printf("     |     |     \n");
  std::cout << "\n\n" << std::flush;
}
