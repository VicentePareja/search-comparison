#include <iostream>
#include <ctime>

int search(int divisor, int low, int high, int number)
{
    int tries = 0;
    int guess;
    int diff;

    // std::cout << "current number = " << number << '\n';

    do
    {
        diff = high - low;
        guess = diff / divisor + low + (diff % divisor > 0 ? 1 : 0);
        // std::cout << "current guess = " << guess << '\n';
        // std::cout << "low = " << low << '\n';
        // std::cout << "high = " << high << '\n';
        // std::cout << "-----------------------\n";
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
    } while (guess != number);

    return tries + 1;
}

int main()
{
    double total = 0;
    int high = 10000;
    for (int divisor = 2; divisor <= 100; divisor++)
    {

        for (int number = 1; number <= high; number++)
        {
            total += search(divisor, 0, high, number);
        }

        std::cout
            << "The average was: " << total / high << "\n";
    }

    return 0;
}