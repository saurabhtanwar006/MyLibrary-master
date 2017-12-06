#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000
#define LMT 10000
#define LEN 5761456

unsigned flag[MAX/64];
int a[LEN+10], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve()
{
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				isc(j);
	a[0] = -1;
	a[1] = 2;
	for(i=3,j=2; i<MAX; i+=2)
		if(!ifc(i))
			a[j++] = i;
	total = j;
}
int main(){
	freopen("output.txt","w+",stdout);
	sieve();
	int i;
	for(i=0;i<1000000;i++)
		printf("%d\n",a[i]);
		//cout<<a[i]<<endl;
}
