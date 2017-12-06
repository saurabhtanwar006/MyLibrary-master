#include <iostream>
#include <stack>
#define UP 1
#define LEFT 2
#define UPLEFT 3

using namespace std;
int a1[10] = {15, 14, 10, 5, 6, 7, 9, 1, 2, 4};
int a2[12] = {15, 3, 25, 14, 10, 5, 4, 7, 9, 1, 3, 4};
const int size1 = 10;
const int size2 = 12;
int L[size1 + 1][size2 + 1];
int c[size1 + 1][size2 + 1];

void LCS(int ar1[], int length1, int ar2[], int length2)
{
    for(int i = 0; i < length1; ++i)
    {
        for(int j = 0; j < length2; ++j)
        {
            if(ar1[i] == ar2[j])
            {
                L[i+1][j+1] = L[i][j] + 1;
                c[i+1][j+1] = UPLEFT;
            }
            else if(L[i+1][j] > L[i][j+1])
            {
                L[i+1][j+1] = L[i+1][j];
                c[i+1][j+1] = LEFT;
            }
            else
            {
                L[i+1][j+1] = L[i][j+1];
                c[i+1][j+1] = UP;
            }
        }
    }
}
void print_lcs()
{
    stack<int> s;
    int l1, l2;
    l1 = size1;l2=size2;
    while(l1 != 0 && l2 != 0)
    {
        if(c[l1][l2] == UPLEFT)
        {
            s.push(a1[l1-1]);
            --l1;--l2;
        }
        else if(c[l1][l2] == UP) --l1;
        else --l2;
    }
    //printing the the right order
    while(!s.empty())
    {
        int onTop = s.top();
        s.pop();
        cout<<" "<<onTop<<" ";
    }
}

int main()
{
    LCS(a1, size1, a2, size2);
    print_lcs();
    return 0;
}
