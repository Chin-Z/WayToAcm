#include <cstdio>
#include <algorithm>
#include <cstring>
#define M 10000
using namespace std;

int dp[M][M],t,m,time[M],v[M],i,j;

int main() {
	scanf("%d%d",&t,&m);
	memset(dp,0,sizeof(dp));
	for(i = 1; i <= m; i++) {
		scanf("%d%d",&time[i],&v[i]);
	}
	for(i = 1; i <= m; i++) {
		for(j = t; j > 0; j--) {
			if(j >= time[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-time[i]] + v[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d",dp[m][t]);
}
