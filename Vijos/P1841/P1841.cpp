#include <cstdio>
#include <iostream>

#define MAXN 1000

typedef long long ll;

using namespace std;

ll n, m, x,t(0),p(0),temp;
ll k;

ll qpow(ll x, ll y) {
	ll re = 1;
	ll a ,b;
	a = x; b = y;
	while(b) {
		if(b&1) re*=a,re%=n;
		a*=a;
		a%=n;
		b>>=1;
	}
	return re;
}

int main() {
	cin>>n>>m>>k>>x;
	t = qpow(10, k);
	ll ans = (x + m*t)%n;
	printf("%lld", ans);
} 
