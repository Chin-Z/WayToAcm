#include <cstdio>
#include <algorithm>

#define M 1000

using namespace std;

int dp1[M],dp2[M],t[M],n,imax;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		dp1[i] = 1;dp2[i] = 1;
	}
	dp1[0] = 0;dp1[1] = 1;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j < i; j++) {
			if(t[i]>t[j]&&dp1[j]+1>dp1[i]) dp1[i] = dp1[j]+1;
		}
	dp2[0] = 0;dp2[1] = 1; 
	for(int i = n-1; i >= 1; i--) 
		for(int j = n; j > i; j--) {
			if(t[i]>t[j]&&dp2[j]+1>dp2[i]) dp2[i] = dp2[j]+1;
		}
	imax = 0;
	for(int i = 1; i <= n; i++) {
		if(dp1[i]+dp2[i]>imax) imax = dp1[i] + dp2[i];
	}
	printf("%d",n - imax + 1);
}
