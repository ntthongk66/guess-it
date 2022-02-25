#include<iostream>
#include<cstdlib>
#include<time.h>

/*
    new feature:
        - two player, computer vs human
        - play again
        - ranking

*/
// ============
int generateRandomnNum(int high, int low)
{
    srand(time(NULL));
    return rand()%(high-low+1)+low;
}

int getPlayerGuess()
{
    int guess;
    std::cin>>guess;
    return guess;

}

void PrintAnswer(int guess,int secretNum)
{
    if(guess > secretNum) std::cout<<"your guess is too high"<<std::endl;
    else if(guess < secretNum) std::cout<<"your guess is too low"<<std::endl;
    else std::cout<<"congratulate, you win :) ";
}

void replay()
{
   int guess, secretNum;
   int high,low;
   std::cout<<" chose the highest and the lowest you want to guess: ";
   std::cin>>low>>high;
   secretNum= generateRandomnNum(high,low);

   do{
        std::cout<<"enter your guess: ";
        guess = getPlayerGuess();
        PrintAnswer(guess,secretNum);

   }
   while(guess!=secretNum);

}
//=========================================

int computer_guess(int low, int high)
{
    return low + (high - low)/2;
}

void check_the_computer_guess(char check,bool& gameloop,int & l,int &h, int guess)
{
    if(check=='<')
    {
        l=guess;
    }
    else if(check=='>')
    {
        h= guess;
    }
    else {
        gameloop= true;
        std::cout<<"the little shit! AI win!!!!";
    }


}

void replay_2()
{

    int h,l;
    char check;
    std::cout<<"choose the range to guess: ";
    std::cin>>l>>h;
    int guess;
    bool gameLoop = false;



    while ( !gameLoop )
    {
        std::cout<<computer_guess(l,h)<<" : it > ; < or = your secret_nunmber"<<std::endl;
        std::cin>>check;

        check_the_computer_guess(check,gameLoop,l,h,computer_guess(l,h));


    }
}
//===========================================

int main()
{
    char choice;
    std::cout<<" type 1 if you want to play with computer \n";
    std::cout<<" type 2 if you want computer play with you "<<std::endl;
    std::cin>> choice;
    if( choice =='2')

    {

        bool gameloop = false;
        while(!gameloop)
        {
            replay();
            std::cout<<" do you want to play again ( y/n): ";
            char y_n;
            std::cin>>y_n;
            if(y_n=='n') gameloop=true;
        }

    }
    else{
        bool gameloop = false;
        while(!gameloop)
        {
            replay_2();
            std::cout<<" do you want to play again the f*cking shit :) ( y/n): ";
            char y_n;
            std::cin>>y_n;
            if(y_n=='n') gameloop=true;
        }

    }

    return 0;
}
