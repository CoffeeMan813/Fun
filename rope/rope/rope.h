#ifndef ROPE_H
#define ROPE_H

#include <array>

namespace rope_util
{
    inline constexpr int size{ 5 };
    void inline err();
    void printMat(const std::array<std::array<char, rope_util::size>, rope_util::size>& arr);
}

class Rope
{
private:
    //Coordinates are 1-indexed
    int m_hX{};
    int m_hY{};
    int m_tX{};
    int m_tY{};

    //A 2D array showing the tail's path
    std::array<std::array<char, rope_util::size>, rope_util::size> tPos{};

public:
    Rope();

    void parseInput(char dir, int num);
    void printBoard();
    void moveRope(int dX, int dY);

    const std::array<std::array<char, rope_util::size>, rope_util::size>& gettPos() { return tPos; }
};

#endif