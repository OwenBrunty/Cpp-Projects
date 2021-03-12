/*
Owen Brunty
Tic Tac Toe
3/7/20
*/

#include <iostream>
#include <cstring>

using namespace std;

int board[3][3];
int blank = 0;
int xmove = 1;
int omove = 2;
int xturn = 0;
int oturn = 1;
int xwins = 0;
int owins = 0;
int ties = 0;
int turn = xturn;
char position[3];

//function that prints the board
void printboard()
{
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    char ch = ('a' + row);
    cout << ch << "\t";
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == blank) {
	cout << "\t";
      }
      else if (board[row][col] == xmove) {
	cout << "X\t";
      }
      else if (board[row][col] == omove) {
	cout << "O\t";
      }
    }
    cout << "\n";
  }
}

//function that checks board for a win from either player
bool checkwin(int player)
{
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}

//function that checks board for a tie
bool checktie()
{
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] != blank) {
	  return false;
      }
    }
  }
  return true;
}

//function that resets the board to blank
void resetboard()
{ 
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = blank;
    }
  }
}

int main()
{
  bool playing = true;
  cout << "Welcome to tic tac toe. X will move first." << "\n" << "Choose a position by entering the row letter followed by the column number." << endl;
  while (playing)
    {
      printboard();
      cin >> position;
      //cout << strlen(position) << endl;
      //cout << position[0];

      //checks to see if input is valid
      if (strlen(position) != 2) {
	//cout << strlen(position) << endl;
	cout << "Please enter just a letter followed by a number, it should be only 2 characters." << endl;
	memset(position, 0, 2);
      }
      else if (position[0] != 'a' && position[0] != 'b' && position[0] != 'c') {
	cout << "Row must be either an 'a', 'b', or a 'c'." << endl;
	memset(position, 0, 2);
      }
      else if (position[1] != '1' && position[1] != '2' && position[1] != '3') {
	cout << "Column must be either a '1', '2', or a '3'." << endl;
	memset(position, 0, 2);
      }

      //if input is valid, enters position into the board
      else {
	int row = position[0] - 'a';
	int col = position[1] - '1';
	cout << row << ", " << col << endl;
	if (board[row][col] == blank) {
	  if (turn == xturn) {
	    board[row][col] = xmove;
	    turn = oturn;
	    memset(position, 0, 2);
	  }
	  else {
	    board[row][col] = omove;
	    turn = xturn;
	    memset(position, 0, 2);
	  }
	}
	
	//if position is taken then tell user
	else {
	  cout << "The position you entered is already occupied." << endl;
	  memset(position, 0, 2);
	}
	
	//check if a player has won the game or for a tie
	if (checkwin(xmove) == true) {
	  cout << "Player X wins." << endl;
	  xwins++;
	  cout << "X wins: " << xwins << endl << "O wins: " << owins << endl << "Ties: " << ties << endl;
	}
	else if (checkwin(omove) == true) {
	  cout << "Player O wins." << endl;
	  owins++;
	  cout << "X wins: " << xwins << endl << "O wins: " << owins << endl << "Ties: " << ties << endl;
	}
	else if (checktie() == true) {
	  cout << "The game ended in a tie." << endl;
	  ties++;
	  cout << "X wins: " << xwins << endl << "O wins: " << owins << endl << "Ties: " << ties << endl;
	}
	
	//if a player has won, clear board and ask to play again
	if (checkwin(xmove) == true || checkwin(omove) == true) {
	  char again[4];
	  cout << "Do you wish to play again?" << endl;
	  cin >> again;
	  if (strcmp(again, "yes") == 0) {
	    resetboard();
	    turn = xturn;
	    playing = true;
	    memset(again, 0, 3);
	  }
	  else if (strcmp(again, "no") == 0) {
	    resetboard();
	    playing = false;
	    memset(again, 0, 3);
	  }
	  else {
	    cout << "Please enter just 'yes' or 'no'." << endl;
	    memset(again, 0, 3);
	  }
	}
      }
    }
  return 0;
}
