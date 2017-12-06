#include<bits/stdc++.h>
using namespace std;
const int size = 1e6 + 9;
#define ll long long 
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
#define i64 unsigned long long
 
i64 mulmod(i64 a, i64 b, i64 c)
{
  i64 x = 0, y = a%c;
  while(b>0)
  {
    if(b&1) x = (x+y)%c;
    y = (y<<1)%c;
    b = b>>1;
  }
  return x;
}
 
i64 modulo(i64 a, i64 b, i64 c)
{
  i64 x = 1, y = a%c;
  while(b>0)
  {
    if(b&1) x = mulmod(x,y,c);
    y = mulmod(y,y,c);
    b = b>>1;
  }
  return x;
}
 
bool miller(i64 p, int iter)
{
  if(p<2) return false;
  if(p==2) return true;
  if(!(p&1)) return false;
  i64 s = p-1, a, temp, mod;
  while(!(s&1)) s = s>>1;
  for(int i=0; i<iter; i++)
  {
    a = rand()%(p-1)+1;
    temp = s;
    mod = modulo(a, temp, p);
    while(temp!=p-1 && mod!=1 && mod!=p-1)
    {
      mod = mulmod(mod, mod, p);
      temp = temp<<1;
    }
    if(mod!=p-1 && !(temp&1)) return false;
  }
  return true;
}
bool isprime(ll num){
	return miller(num,20);
}
bool is_square_prime(ll num){
	ll x = sqrt(num);
	if(x*x!=num)
		return 0;
	return isprime(x);
}
ll num_div(ll num){
	ll ans = 1;
	int i;
	for(i=0;i<prime.size();i++){
		ll p = prime[i];
		if(p*p*p>num)
			break;
		ll cnt = 0;
		while(num%p==0){
			num/=p;
			cnt++;
		}
		ans *= (cnt+1);
	}
	if(isprime(num)==1){
		ans*=2;
	}
	else if(is_square_prime(num)==1){
		ans*=3;
	}
	else if(num!=1){
		ans *=4;
	}
	return ans;
}
int main(){
	preprocess();
	int t;
	scanf("%d",&t);
	while(t--){
		ll num;
		scanf("%lld",&num);
		printf("%lld\n",num_div(num));
	}
	return 0;
}
