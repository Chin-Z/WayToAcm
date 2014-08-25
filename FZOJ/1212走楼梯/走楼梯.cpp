#include <cstdio>

int louti(int n) {
	if(n == 1) return 1;
	else if(n == 2) return 2;
	else if(n > 2) return louti(n-1) + louti(n-2);
}
int main() {
	int n, i;
	scanf("%d", &n);
	i = louti(n);
	printf("%d", i);
}