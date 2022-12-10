#include "Rope.h"
#include <array>
#include <iostream>

//Type alias for 2D char array
using Mat = std::array<std::array<char, rope_util::size>, rope_util::size>;

namespace rope_util
{
    void inline err()
    {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void printMat(const Mat& arr)
    {
        for (const std::array<char, rope_util::size>& row : arr)
        {
            for (char el : row) { std::cout << el << ' '; }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}

Rope::Rope()
{
    hX = 1;
    hY = rope_util::size;
    tX = 1;
    tY = rope_util::size;

    std::array<char, rope_util::size> row{};
    row.fill('X');
    tPos.fill(row);
}

void Rope::parseInput(char dir, int num)
{
    switch (dir)
    {
    case 'U':
        if (hY - num >= 1) { moveRope(0, -num); }
        else { rope_util::err(); }
        break;
    case 'D':
        if (hY + num <= rope_util::size) { moveRope(0, num); }
        else { rope_util::err(); }
        break;
    case 'L':
        if (hX - num >= 1) { moveRope(-num, 0); }
        else { rope_util::err(); }
        break;
    case 'R':
        if (hX + num <= rope_util::size) { moveRope(num, 0); }
        else { rope_util::err(); }
        break;
    default:
        rope_util::err();
    }
}

void Rope::printBoard()
{
    std::array<char, rope_util::size> rows{};
    rows.fill('.');
    Mat board{};
    board.fill(rows);

    //Replaces '.' with specific letters at the starting, head, and tail positions
    board[rope_util::size - 1][0] = 's';
    board[tY - 1][tX - 1] = 'T';
    board[hY - 1][hX - 1] = 'H';

    rope_util::printMat(board);
}

void Rope::moveRope(int dX, int dY)
{
    //How many moves left in each direction
    int moveX{ dX };
    int moveY{ dY };

    //-1, 1, or 0 
    int stepX{ dX != 0 ? dX / abs(dX) : 0 };
    int stepY{ dY != 0 ? dY / abs(dY) : 0 };

    //While the head still has to move
    while (moveX != 0 || moveY != 0)
    {
        hX += stepX;
        hY += stepY;
        moveX -= stepX;
        moveY -= stepY;

        //If the head and tail are more than 1 space apart horizontally
        if (abs(hX - tX) > 1)
        {
            //Moves the tail diagonally if it's in an adjacent column 
            if (abs(hY - tY) == 1) { tY = hY; }

            tX += stepX;
            tPos[tY - 1][tX - 1] = 'O';
        }

        //If the head and tail are more than 1 space apart vertically
        if (abs(hY - tY) > 1)
        {
            //Moves the tail diagonally if it's in an adjacent row 
            if (abs(hX - tX) > 0) { tX = hX; }

            tY += stepY;
            tPos[tY - 1][tX - 1] = 'O';
        }

        printBoard();
    }
}