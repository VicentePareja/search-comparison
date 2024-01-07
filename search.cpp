#include <iostream>
#include <ctime>

int binary_search()
{
    int tries = 0;
    int guess;
    int number = rand() % 100 + 1;
    int diference = 50;
    guess = 50;
    std::cout << "current number = " << number << '\n';

    do
    {
        std::cout << "current guess = " << guess << '\n';
        if (guess > number)
        {
            guess = guess - diference / 2;
            diference = diference / 2;
            tries += 1;
        }
        else if (guess < number)
        {
            guess = guess + diference / 2;
            diference = diference / 2;
            tries += 1;
        }
        else
        {
            return tries + 1;
        }
    } while (guess != number);

    return tries + 1;
}

int ternary_search()
{
    int tries = 0;
    int guess;
    int number = rand() % 100 + 1;
    int low = 0;
    int diff;
    int high = 100;

    std::cout << "current number = " << number << '\n';

    do
    {
        diff = high - low;
        guess = diff / 3 + low + (diff % 3 > 0 ? 1 : 0);
        std::cout << "current guess = " << guess << '\n';
        std::cout << "low = " << low << '\n';
        std::cout << "high = " << high << '\n';
        std::cout << "-----------------------\n";
        if (guess > number)
        {
            high = guess;
            tries += 1;
        }
        else if (guess < number)
        {
            low = guess;
            tries += 1;
        }
        else
        {
            return tries + 1;
        }
    } while (guess != number && tries < 10);

    return tries + 1;
}

int main()
{
    srand(time(NULL));
    std::cout << ternary_search() << '\n';
    return 0;
}