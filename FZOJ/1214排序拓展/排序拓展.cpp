#include <cstdio>
#include <algorithm>

using namespace std;

int cmp(int a, int b) {
	return a < b;
}

int main() {
	int n, a[100000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n, cmp);
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}	
}