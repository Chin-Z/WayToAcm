#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int i, j, s, w, n, a[100];
	scanf("%d", &s);
	for(i = 0; i < s; i++) {
		int x, y, count;
		scanf("%d%d", &w, &n);
		for(j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}

		sort(a, a+n);
		x = 0; y=n-1;count = 0;
		while(x <= y) {
			if(a[x] + a[y] <= w) {
				count++;
				x++;
				y--;
			}else{
				count++;
				y--;
			}
		}
		printf("%d\n", count);
	}
}
