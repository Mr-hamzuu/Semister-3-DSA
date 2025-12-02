#include <iostream>
using namespace std;

int main()
{
    string names[8] = {"fsd", "isd", "khi", "lhr", "mtn", "pwr", "rwp", "swl"};
    int matrix[8][8] = {
        {1, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 1}};

    for (int i = 0; i < 8; i++)
    {
        cout << "\t" << names[i];
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << names[i] << "\t";
        for (int j = 0; j < 8; j++)
        {

            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int k = 0; k < 8; k++)
    {
        for (int i = 0; i < 8; i++)
        {

            for (int j = 0; j < 8; j++)
            {
                matrix[i][j] = matrix[i][j] | (matrix[i][k] & matrix[k][j]);
            }
        }
    }
    
    cout << endl;

     for (int i = 0; i < 8; i++)
    {
        cout << "\t" << names[i];
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << names[i] << "\t";
        for (int j = 0; j < 8; j++)
        {

            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
