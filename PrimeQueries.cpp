#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long int LL;
const int N = 1555567;
const int M = 100005;

vector<bool> vec(N,true);
vector<LL> prime;
LL sum[M];

void sieve()
{
	vec[0]=vec[1]=false;
	for(LL i=2;i*i<N;i++)
	{
		for(LL j=i*i;j<N;j+=i)
		{
			vec[j]=false;
		}
	}
	prime.pb(-1);
	for(LL i=2;i<N;i++)
	{
		if(vec[i])
		{
			prime.pb(i);
		}
	}
}

void pre()
{
	sum[0]=0;
	for(LL i=1;i<M;i++)
	{
		sum[i]=sum[i-1]+prime[i];
	}
}
void run()
{
	sieve();
	pre();
}

bool isPrime(LL n)
{
	return vec[n];
}

LL nthPrime(LL n)
{
	return prime[n];
}

LL primeSmallerThan(LL n)
{
	LL k=lower_bound(prime.begin(),prime.end(),n)-prime.begin();
	return prime[k-1];
}

LL primeGreaterThan(LL n)
{
	LL k=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
	return prime[k];
}

LL nearestPrime(LL n)
{
	LL x;
	x=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
	return (abs(prime[x-1]-n)<(abs(prime[x]-n))) ? prime[x-1] : prime[x];
}

LL numberofPrimesInRange(LL l,LL r)
{
	LL x,y;
	x=lower_bound(prime.begin(),prime.end(),l)-prime.begin();
	y=upper_bound(prime.begin(),prime.end(),r)-prime.begin();
	return (y-x);
}

LL sumofFirstNprimes(LL n)
{
	return sum[n];
}

LL sumofPrimesInRange(LL l,LL r)
{
	LL x,y;
	x=lower_bound(prime.begin(),prime.end(),l)-prime.begin();
	y=upper_bound(prime.begin(),prime.end(),r)-prime.begin();
	return sum[y-1]-sum[x-1];
}

int main() 
{
	run();
	cout<<nthPrime(145)<<"\n";
	cout<<primeSmallerThan(7856)<<"\n";
	cout<<primeGreaterThan(4000)<<"\n";
	cout<<numberofPrimesInRange(12,455)<<"\n";
	cout<<sumofPrimesInRange(12,1345)<<"\n";
	return 0;
}