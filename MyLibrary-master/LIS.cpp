#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
const int size = sizeof arr / sizeof arr[0];
int L[size+1];
int main()
{
    char value = ((1 << 8) - 1) - (1 << 7);
    memset(L, value, sizeof L);
    L[0] = -(1<<20);
    for(int i = 0; i < size; ++i)
    {
        int l = 1, r = size, mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(L[mid] < arr[i]) l = mid + 1;
            else r = mid - 1;
        }
        L[l] = min(L[l], arr[i]);
    }
    cout<<"LIS: ";
    int c = 1;
    while(L[c] < (1<<20))
    {
        cout<<L[c]<<" ";
        ++c;
    }
    return 0;
}
