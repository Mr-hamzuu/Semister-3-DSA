#include <iostream>
using namespace std;

int min(int x,int y){
    if (x==-1)
    {
        return y;
    }
    if (y==-1)
    {
        return x;
    }
    if (x<y)
    {
        return x;
    }
    
    return y;
}

int sum(int x,int y){
    if (x==-1)
    {
        return x;
    }
    if (y==-1)
    {
        return y;
    }
    
    return x+y;
}
int main()
{
    string names[6] = {"v1", "v2", "v3", "v4", "v5", "v6"};
    int matrix[6][6] = {
        {0, 3, -1, 8, -1, 6},
        {-1, 0, -1, -1, 4, 2},
        {-1, -1, 0, 5, -1, 4},
        {-1, 4, -1, 0, 6, -1},
        {-1, -1, -1, -1, 0, -1},
        {-1, -1, -1, -1, -1, 0}};

    for (int i = 0; i < 6; i++)
    {
        cout << "\t" << names[i];
    }
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << names[i] << "\t";
        for (int j = 0; j < 6; j++)
        {

            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int k = 0; k < 6; k++)
    {
        for (int i = 0; i < 6; i++)
        {

            for (int j = 0; j < 6; j++)
            {
                matrix[i][j] = min( matrix[i][j] ,sum(matrix[i][k] , matrix[k][j]));
            }
        }
    }

    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "\t" << names[i];
    }
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << names[i] << "\t";
        for (int j = 0; j < 6; j++)
        {

            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
