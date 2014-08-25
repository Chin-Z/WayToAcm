#include <cstdio>

int a[14]={0}, n, count=0;

void queen(int k) {
	int i, j;
	if(k > n) {
		count++;
		return;
	}

	for (i = 1; i <= n; i++)
	{
		int t=0;
		for(j = 1; j < k; j++) {
			if(a[j] == i || (a[j]+k-j==i||a[j]-k+j==i)) {
				t++;
			}
		}	
		if(t == 0){
			a[k] = i;
			queen(k+1);
		}
	}
}

int main() {
	scanf("%d", &n);
	a[0]=1;
	a[1]=1;
	queen(1);
	printf("%d", count);
	return 0;
}
