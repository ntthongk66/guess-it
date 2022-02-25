#include<iostream>

int computer_guess(int low, int high)
{
    return low + (high - low)/2;
}


int main()
{
    int h,l;
    std::cout<<"choose the range to guess: ";
    std::cin>>l>>h;
    int guess;
    bool gameLoop = true;
    while ( !gameLoop )
    {
        std::cout<<computer_guess(l,h);

    }
    
    return 0;
}