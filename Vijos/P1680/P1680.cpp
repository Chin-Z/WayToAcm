#include <cstdio>
#include <cstring>
#include <algorithm>

#define M 2000+10

using namespace std;

int dp[M][M],sl,ssl,k;
char s[M],ss[M];

int main() {
	scanf("%s",s);scanf("%s",ss);scanf("%d",&k);
	sl = strlen(s);ssl = strlen(ss);
	memset(dp,0,sizeof(dp));
	dp[0][0]=0;
	for(int i = 1; i <=sl; i++) dp[i][0] = dp[i-1][0]+k;
	for(int i = 1; i <=ssl; i++) dp[0][i] = dp[0][i-1]+k;
	for(int i = 1; i <= sl; i++) {
		for(int j = 1; j <= ssl; j++) {
			dp[i][j] = dp[i-1][j-1] + abs(s[i-1]-ss[j-1]);
			dp[i][j] = min(dp[i][j],min(dp[i-1][j]+k,dp[i][j-1]+k));
		}
	}
	printf("%d",dp[sl][ssl]);
	return 0;
}	
