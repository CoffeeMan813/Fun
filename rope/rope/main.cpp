#include "Rope.h"
#include <iostream>

int main()
{
    Rope rope{};

    std::cout << "Starting board:\n";
    rope.printBoard();

    while (true)
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

    std::cout << "The tail's path:\n";
    rope_util::printMat(rope.gettPos());

    return 0;
}