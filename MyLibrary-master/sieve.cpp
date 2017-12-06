#include<bits/stdc++.h>
using namespace std;
const int size = 1e6 + 9;
int phi[size],chk[size];
vector < int > prime;
void preprocess(void)
{
	int i, j;

	for(i=1 ; i<size ; i++)
	{
		phi[i]=i;
		chk[i]=1;
	}
	chk[0]=chk[1] = 0;
	for(i=2 ; i<size ; i++)
	{
		if(chk[i]==1)
		{
			prime.push_back(i);
			for(j = i;j<size;j+=i){
				if(j!=i)
					chk[j]=0;
				phi[j] /=i;
				phi[j] *= i-1;
			}
		}
	}
}
int main(){
	preprocess();
	int i;
	for(i=0;i<size/100;i++)
		printf("%d\n",prime[i]);
}
