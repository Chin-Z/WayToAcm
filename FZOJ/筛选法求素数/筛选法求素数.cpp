#include<cstdio>
#include<cstring>

using namespace std;

void prime(int n) {
	bool primeArr[300000];
	int i, j, k, increment[6] = {0,4,0,0,0,2};
	memset(primeArr, true, sizeof(primeArr));
	primeArr[0] = false;
	for(i = 2; i <= n; i++) {
		if(primeArr[i]) {
			k = 2;
			while(k*i <= n) {
				primeArr[k*i] = false;
				k++;
			}
		}
	}
	for(i = 2; i < n; i++) {
		if(primeArr[i]) printf("%d ", i);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	prime(n);
}
