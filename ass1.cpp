#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

string goal = "123456780";

void printPuzzle(string s)
{
    for (int i = 0; i < 9; i++)
    {
        if (s[i] == '0')
            cout << "  ";
        else
            cout << s[i] << " ";

        if ((i + 1) % 3 == 0)
            cout << endl;
    }
    cout << endl;
}

void solve(string start)
{
    queue<string> q;
    set<string> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        string current = q.front();
        q.pop();

        if (current == goal)
        {
            cout << "Solution found!\n";
            printPuzzle(current);
            return;
        }

        int zero = current.find('0');
        int row = zero / 3;
        int col = zero % 3;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3)
            {
                int newPos = nr * 3 + nc;

                string next = current;
                swap(next[zero], next[newPos]);

                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
    }

    cout << "No solution found.\n";
}

int main()
{
    string start;

    cout << "Enter the puzzle (use 0 for blank): ";
    cin >> start;

    solve(start);

    return 0;
}


           
