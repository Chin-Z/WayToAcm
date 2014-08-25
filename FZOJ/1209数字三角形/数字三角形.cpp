#include <cstdio>
#include <cstdlib>
#include <cstring>

int max(int a, int b) {
	if(a > b) return a;
	else return b;
}

int main() {
	int i, j, n, a[25][25], f[25][25];
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	memset(f, 0, sizeof(a));
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = n; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if(i == n) {
				f[i][j] = a[i][j];
			}else
			f[i][j] += a[i][j] + max(f[i+1][j],f[i+1][j+1]);
		}
	}
	printf("%d", f[1][1]);
}
