#include <iostream>
#include <set>

#include <algorithm>

// The total number of solutions is given by n!/(repetitions)!

void combinations(const std::string &s, int idx, std::set<std::string> &c, std::string st)
{
    if (idx == s.size())
    {
        c.insert(st);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        combinations(s, i + 1, c, st + s[i]);
        std::cout << "*" << st  + s[i] << std::endl;
    }
}

int main()
{
    std::set<std::string> c;
    std::string line;
    std::cin >> line;
    std::sort(line.begin(), line.end());
    combinations(line, 0, c, "");
    std::cout << c.size() << std::endl;
    for (const auto &s : c)
    {
        std::cout << s << std::endl;
    }
}
