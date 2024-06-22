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

void DFS(const grid &g, int m, int n, int node, std::vector<bool> &visited)
{
    std::stack<int> stk;
    stk.push(node);
    while (!stk.empty())
    {
        int t = stk.top();
        stk.pop();
        // Process the node
        visited[t] = true;

        // Push all adjacent floors
        int row = t / n;
        int col = t % n;
        for (int i = -1; i <= 1; i += 2)
        {
            int nr = row + i;
            int nc = col + i;
            if (nr >= 0 && nr < m && g[nr][col] == '.')
            {
                int idx = nr * n + col;
                if (!visited[idx])
                {
                    stk.push(idx);
                }
            }
            if (nc >= 0 && nc < n && g[row][nc] == '.')
            {
                int idx = row * n + nc;
                if (!visited[idx])
                {
                    stk.push(idx);
                }
            }
        }
    }
}

int number_of_rooms(const grid &g, int m, int n)
{
    // Here is my approach:
    // rooms = 0
    // For each square in the grid
    //     If the square is not visited and it is a floor (.)
    //         rooms += 1
    //         Perform DFS(square) and mark all adjacent floors as visited
    int rooms = 0;
    // 0 means unvisited, 1 means visited
    std::vector<bool> visited(m * n, 0);
    for (int i = 0; i < (m * n); i++)
    {
        int row = i / n;
        int col = i % n;
        if (g[row][col] == '.' && !visited[i])
        {
            rooms++;
            DFS(g, m, n, i, visited);
        }
    }

    return rooms;
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

    std::cout << number_of_rooms(g, rows, cols) << std::endl;
}