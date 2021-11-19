#include <iostream>

using std::cin;
using std::cout;

const int N = 500;
int tempArray[N];

void sumSquare (int grid[],const int &size, const char &key)
{
    for (int i = 0; i < size; ++i)
    {
        tempArray[i] = 0;
    }
    if (key == 'a')
    {
        int pos = 0;
        for (int i = 0; i < size; ++i)
        {
            if (grid[i] == 0) continue;
            if (pos == 0)
            {
                tempArray[pos] = grid[i];
                pos++;
            }
            else if (tempArray[pos - 1] == 2048)
            {
                tempArray[pos] = grid[i];
                pos++;
            }
            else if (tempArray[pos - 1] == grid[i])
            {
                tempArray[pos - 1] *= -2;
            }
            else 
            {
                tempArray[pos] = grid[i];
                pos++;
            }
        }
    }
    else if (key == 'd')
    {
        int pos = size - 1;
        for (int i = size - 1; i >= 0; --i)
        {
            if (grid[i] == 0) continue;
            if (pos == size - 1)
            {
                tempArray[pos] = grid[i];
                pos--;
            }
            else if (tempArray[pos + 1] == 2048)
            {
                tempArray[pos] = grid[i];
                pos--;
            }
            else if (tempArray[pos + 1] == grid[i])
            {
                tempArray[pos + 1] *= -2;
            }
            else 
            {
                tempArray[pos] = grid[i];
                pos--;
            }
        }
    }
    for (int i = 0; i < size; ++i)
    {
        grid[i] = tempArray[i];
    }
}

void printRow (int grid[], const int &size)
{
    for (int j = 0; j < size; ++j)
    {
        if (grid[j] != 0) cout << std::abs(grid[j]);
        else cout << "_";
        cout << " ";
    }
    cout << '\n';
}

int main ()
{
    int Grid[N][N];
    int size;
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> Grid[i][j];
        }
    }
    char move;
    cin >> move;
    cout << "Grid:\n";
    for (int i = 0; i < size; ++i)
    {
        printRow(Grid[i], size);
        sumSquare(Grid[i], size, move);
    }
    cout << "Next move:\n";
    for (int i = 0; i < size; ++i)
    {
        printRow(Grid[i], size);
    }
    return 0;
}