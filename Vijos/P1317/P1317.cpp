#include <cstdio>
#include <algorithm>
#include <cstring>
#define M 10000
using namespace std;

int dp[100][30010],N,m,p[M],v[M],i,j;

int main() {
	scanf("%d%d",&N,&m);
	memset(dp,0,sizeof(dp));
	for(i = 1; i <= m; i++) {
		scanf("%d%d",&v[i],&p[i]);
	}
	for(i = 1; i <= m; i++) {
		for(j = N; j > 0; j--) {
			if(j >= v[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]] + v[i]*p[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d",dp[m][N]);
}
