#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame() 
{
    int num,guess,tries=0,maxTries=0;
    
    srand(time(0)); // Seed random number generator
    num=rand() % 100 + 1; // Random number between 1 and 100
    
    cout<<"--## Enter the difficulty level ##--\n";
    cout<<" 1. for Easy (maxTries=15)\n";
    cout<<" 2. for Medium (maxTries=10)\n";
    cout<<" 3. for Difficult (maxTries=5)\n";
    cout<<" 0. to End the Game\n\n";
    
    int difficultyChoice;
    cout<<"Enter your choice from (1/2/3/0)::";
    cin>>difficultyChoice;
    
    switch (difficultyChoice) 
	{
        case 1:
            cout<<"\nYou have chosen Easy level you have 15 tries!\n\n";
            maxTries=15;
            break;
        case 2:
            cout<<"\nYou have chosen Medium level you have 10 tries!\n\n";
            maxTries=10;
            break;
        case 3:
            cout<<"\nYou have chosen Difficult level you have 5 tries!\n\n";
            maxTries=5;
            break;
        case 0:
            cout<<"Thank you for playing. Goodbye!\n";
            return;
        default:
            cout<<"Invalid choice! Please restart the game and enter a valid choice (0, 1, 2, or 3).\n";
            return;
    }
    
    do 
	{
        cout<<"Enter a guess between 1 and 100: ";
        cin>>guess;
        tries++;
        
        if(guess>num) 
		{
            cout<<"TOO HIGH!The number is smaller than the number you have chosen.\n\n";
        } else if (guess<num) 
		{
            cout<<"TOO LOW! The number is greater than the number you have chosen.\n\n";
        } else 
		{
            cout<<"\n   Correct!\n--**You won**--! \nThanks for playing!\n";
            cout<<"You took "<<tries<<" guesses.\n";
            break;
        }

        if (tries>=maxTries)
		{
            cout<<"**-You've reached the maximum number of tries-** \n----Game over!----\n";
            cout<<"The correct number was "<<num<<"\nBetter luck next time!\n";
            break;
        }
    } 
	while (guess!=num);
}

int main() 
{
    char playAgain;
    
    do 
	{
        cout<<"Welcome to the Guess The Number Game!!\n\n";
        playGame();
        
        cout<<"\nDo you want to play again? (y/n): ";
        cin>>playAgain;
    } 
	while (playAgain=='y' || playAgain=='Y');
    
    cout<<"Thank you for playing. Goodbye!\n";
    return 0;
}

