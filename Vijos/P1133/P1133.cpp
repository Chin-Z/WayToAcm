#include <cstdio>
#include <algorithm>
#include <cstring>
#define M 10000
using namespace std;

int dp[M][M],i,j,V,n,w[M];

int main() {
	memset(dp,0,sizeof(dp));
	memset(w,0,sizeof(w));
	scanf("%d", &V);
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d",&w[i]);
	for(i = 1; i <= n; i++) {
		for(j = V; j > 0; j--) {
			if(j >= w[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + w[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d",V - dp[n][V]);
}
