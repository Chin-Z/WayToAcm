#include <cstdio>
#include <cmath>

int a[100], n;

bool f(int k,int j) {
	for(int i = 1; i < k; i ++) {
			if(j==a[i]) {
				return false;
		}
	}
	return true;
}
bool isPrime(int t) {
	int d = 1;
	for(int i =2; i<=sqrt(t); i++) {
		if(t%i == 0) {
			d=0;
			break;
		}
	}
	if(d==1) return true;
	else return false;
}
void bt(int k) {
	if(k > n && isPrime(a[n] + a[1])) {
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}else{
		for(int i = 2; i <= n; i++) {
			if(f(k, i) && isPrime(i + a[k-1])) {
				a[k] = i;
				bt(k+1);
				a[k]=0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	a[1] = 1;
	bt(2);
}
