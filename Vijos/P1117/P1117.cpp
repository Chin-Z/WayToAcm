#include<cstdio>

int dp[200][10], n, k;

int main() {
	scanf("%d%d", &n, &k);
	dp[1][1] = 1;	
	for(int i = 2; i <= n; i++) {
		dp[i][1] = 1;
		for(int j = 2; j <= n; j++) {
			if(i>=j&&j<=k) dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
		}
	}
	printf("%d", dp[n][k]);
	return 0;
}
