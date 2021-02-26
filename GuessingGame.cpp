/*
Guessing Game
Owen Brunty
2/20/21
*/

#include <iostream>


using namespace std;

void guessinggame()
{
  //variable to keep track of the number of guesses
  int guesses = 0;

  //variable that is a random number between 1 and 100
  srand (time(NULL));
  int number = rand() % 101;
  //cout << number;

  //variable that is users input of their guess
  int guess;

  //variable that determines if user is currently playing the game
  bool playing = true;

  //variable that determines if user wishes to play again
  char again;

  cout << "Try to guess a number between 1 and 100, after each guess I will tell you if the answer is higher or lower. \nGood luck!\n";

  while (playing)
    {
      //gets users guess and adds 1 to number of guesses
      cout << "Guess a number\n";
      cin >> guess;
      guesses++;

      //if user guesses correctly
      if (guess == number)
	{
	  cout << "Congratulations you guessed the correct number! And it only took you " << guesses << " tries. \nIf you would like to play again enter 'y' if not enter 'n'.\n";
	  cin >> again;
	  //if user chooses to play again
	  if (again == 'y')
	    {
	      cout << "Ok! A new number between 1 and 100 has been generated, good luck!\n";
	      number = rand() % 101;
	      guesses = 0;
	    }
	  //if user chooses not to play again
	  else if (again == 'n')
	    {
	      cout << "Ok! Thanks for playing, come again.\n";
	      playing = false;
	    }
	  //if user enters neither "y" or "n"
	  else
	    {
	      cout << "Please enter either just 'y' or 'n'.\n";
	      cin >> again;
	    }
	}
      //if user's guess is higher than answer
      else if (guess > number)
	{
	  cout << "Incorrect. Your guess was higher than the answer.\n";
	}
      //if user's guess is lower than answer
      else if (guess < number)
	{
	  cout << "Incorrect. Your guess was lower than the answer.\n";
	}
    }
}
int main()
{
  guessinggame();
}
