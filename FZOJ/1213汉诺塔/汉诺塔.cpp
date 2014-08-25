#include <cstdio>

void hanio(char a, char b, char c, int n) {
	 if(n==1) printf("%d %c->%c\n", n, a, b);
	 else {
	 	hanio(a, c, b, n-1);
	 	printf("%d %c->%c\n",n, a, b);
	 	hanio(c, b ,a, n-1);
	 }
}

int main() {
	char a = 'A',b = 'B', c='C';
	int n;
	scanf("%d", &n);
	hanio(a, b, c, n);
}
