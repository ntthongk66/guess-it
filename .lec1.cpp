#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

/*
    int generateRandomNum(int high,int low)
    int getPlayerGuess()
    void PrintAnswer()
*/

int generateRandomnNum(int high, int low)
{
    srand(time(NULL));
    return rand()%(high-low+1)+low;
}

int getPlayerGuess()
{
    int guess;
    cin>>guess;
    return guess;

}

void PrintAnswer(int guess,int secretNum)
{
    if(guess > secretNum) cout<<"your guess is too high"<<endl;
    else if(guess < secretNum) cout<<"your guess is too low"<<endl;
    else cout<<"congratulate, you win :) ";
}

int main()
{
   int guess, secretNum;
   int high,low;
   cout<<" chose the highest and the lowest you want to guess: ";
   cin>>low>>high;
   secretNum= generateRandomnNum(high,low);

   do{
        cout<<"enter your guess: ";
        guess = getPlayerGuess();
        PrintAnswer(guess,secretNum);

   }
   while(guess!=secretNum);


    return 0;
}
