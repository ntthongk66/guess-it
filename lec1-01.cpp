#include<iostream>

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
int main()
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

    return 0;
}
