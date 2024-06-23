#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <vector>
using grid = std::vector<std::vector<char>>;

std::ostream &operator<<(std::ostream &os, const grid &g)
{
    for (const auto &row : g)
    {
        for (const auto &col : row)
        {
            os << col;
        }
        os << std::endl;
    }
    return os;
}


int main()
{
    int rows, cols;
    std::string line;
    grid g;
    std::cin >> rows >> cols;

    std::cin.ignore();

    for (int i = 0; i < rows; i++)
    {
        std::getline(std::cin, line);
        std::vector<char> row;
        row.reserve(cols);
        std::stringstream ss(line);
        std::copy(std::istream_iterator<char>(ss), std::istream_iterator<char>(),
                  std::back_inserter(row));
        g.push_back(row);
    }
}