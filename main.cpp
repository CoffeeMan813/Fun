#include "rope.h"
#include <fstream>
#include <iostream>

//1 for interactive, 2 for file
constexpr int inputMode{ 1 };

int main()
{
    Rope rope{};

    std::cout << "Starting board:\n";
    rope.printBoard();

    while (inputMode == 1)
    {
        std::cout << "Direction to move rope (U,D,L,R), or Q to quit: ";
        char dir{};
        std::cin >> dir;
        dir = toupper(dir);

        if (dir == 'Q') { break; }

        std::cout << "Number of spaces: ";
        int num{};
        std::cin >> num;

        //No invalid inputs or negative spaces
        if (std::cin.fail() || num <= 0) { rope_util::err(); continue; }

        rope.parseInput(dir, num);
    }

    if (inputMode == 2)
    {
        std::ifstream inp{ "moves.txt" };
        char dir{};
        int num{};

        while (inp >> dir && inp >> num)
        {
            std::cout << dir << " " << num << '\n';
            rope.parseInput(dir, num);
        }
    }

    std::cout << "The tail's path:\n";
    rope_util::printMat(rope.gettPos());

    return 0;
}