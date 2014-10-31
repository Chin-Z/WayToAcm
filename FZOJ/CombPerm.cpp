#include <cstdio>

int n, a[100],v[100]={0};

void perm(int k) {
	if(k>n) {
		for(int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	for(int i = 1; i <= n; i++) {
		if(!v[i]) {
			a[k] = i;
			v[i] = 1;
			perm(k+1);
			v[i] = 0;
			a[k] = 0;
		}
	}
}

void comb(int k) {
	for(int i = 1; i < k; i++) {
		printf("%d ", a[i]);
	}
	if(k!=1)printf("\n");
	for(int i = a[k-1]+1; i <= n; i++) {
		if(!v[i]) {
			a[k] = i;
			v[i] = 1;
			comb(k+1);
			v[i] = 0;
			a[k] = 0;
		}
	}
}

int main() {
//	freopen("CombPerm.in", "r", stdin);
//	freopen("CombPerm.out", "w", stdout);
	scanf("%d", &n);
	perm(1);
	a[0] = 0;
	comb(1);
	return 0;
}
