#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll k,n,ans;

int main(){
	cin>>n>>k;
	ans = k*n;
	for(ll i=1;i<=n;) {
		ll l=i,r=n,mid;
		for(;l!=r;){
			mid = (l+r+1)/2;
			if(k/mid<k/i)r=mid-1;
			else l=mid;
		}
		ans-=(r+i)*(r-i+1)/2*(k/i);
		i=l+1;
	}
	cout<<ans;
	return 0;
}
