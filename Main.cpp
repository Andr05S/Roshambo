#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;
// functions needed to run RPS
int randomizer() //to determine the computer's choice of 1,2,3 for rock paper or scissors
{
    srand((unsigned) time(NULL));
    int random = 1 + (rand() %3); //generates a 1,2, or a 3.
    return random;
}
int playerChoice() //to determine which the player picks
{
    int playerhand;
        cout <<"Rock, Paper, or scissors?" <<endl;
        cout <<"Enter the corresponding number" <<endl;
        cout <<"1. Rock" <<endl <<"2. Paper" <<endl <<"3. Scissors" <<endl;
        cin >>playerhand;
    while (playerhand >= 4 || playerhand <= 0) //validates player inputs
        {
        cout <<"error: invalid input. please enter 1, 2, or 3" <<endl;
        cin >>playerhand;
        }
    return playerhand;
}
int roundinator() //How many rounds?
{
    int rounds;
    cout <<"Please enter the desired number of rounds to play" <<endl;
    cin >>rounds;
    if (rounds <= 0)
    {
        cout <<"Please enter a valid number of rounds" <<endl;
        return 0;
    }
    else
    {
        return rounds;
    }
}
void convert(int hand) //converts numbers to rock paper or scissors
{
    if (hand == 1)
        cout <<"rock" <<endl;
    else if (hand == 2)
        cout <<"paper" <<endl;
    else if (hand == 3)
        cout<<"scissors" <<endl;
    else
        cout<<"dragon" <<endl; //for fun error code, handles exceptions if something goes wrong.
    return;
} 
int WinnerDeterminer(int playerhand, int random) //determines the winner and spits out an int value to be used for scorekeeping
{
    if (playerhand == random) //you picked the same as the computer
    {
        cout <<"it's a draw!" <<endl;
        cout <<"play the round over" <<endl;
        return 0;
    }
    else if ((playerhand == 1 && random == 2) || (playerhand == 2 && random == 3) || (playerhand == 3 && random == 1)) //all winning combos for the computer
    {
        cout <<"computer wins the round!" <<endl;
        return 1;
    }
    else
    {
        cout <<"player wins the round!" <<endl;
        return 2;
    }
    
}
//****************************************
//* main run cycle ***********************
//****************************************
int main() 
{
    int random, playerhand, rounds=0, currentround=1, roundstotal = 0, computerwins = 0, playerwins = 0;
    cout <<"Welcome to Roshambo" <<endl;
    while (rounds <=0) //asks for rounds until valid number is entered
    {
        rounds = roundinator();
    }
    cout <<"You will now play " <<rounds <<" rounds" <<endl;
    while (currentround <= rounds)
    {
        random = randomizer();
        playerhand = playerChoice();
        cout <<"Computer picked ";
        convert(random);
        cout <<"Player picked ";
        convert(playerhand);
       
        switch (WinnerDeterminer(playerhand, random)) // keeps score.
        {
            case 0: currentround--; //negates the round going up, forcing another round to be played.
            break;
            case 1: computerwins++;
            break;
            case 2: playerwins++;
            break;
        }
        sleep(1); //added for randomizer generation purposes on output window during testing, gives a new time seed for each round, 
        //otherwise because the program is technically "instant" it generates the same answer for the computer's hand each time.
        currentround++;
        roundstotal++;
        cout <<"total rounds " <<roundstotal <<" player's score " <<playerwins <<" computer's score " <<computerwins <<endl;
    }
    if (playerwins > computerwins)
    {
        cout<<"Player wins the game!" <<endl;
    }
    else if (computerwins > playerwins)
    {
        cout<<"Computer wins the game!" <<endl;
    }
    else
    {
        cout<<"It's a tie!" <<endl;
        cout<<"Try using an odd number of rounds next time" <<endl;
    }
    return 0;
};