#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000]={0}, b[100000]={0};

int binary_search(int beg, int end, int key) {
	int mid = beg + (end - beg)/2;
	if(beg > end) return -1;
	else if(key > a[mid]) {
		return binary_search(mid + 1, end, key);
	}else if(key < a[mid]) {
		return binary_search(beg, mid - 1, key);
	}else if(key == a[mid]) {
		return mid;
	}
}

int main() {
	int N, Q, i, t;
	scanf("%d%d", &N, &Q);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < Q; i++)
	{
		scanf("%d", &b[i]);
	}	
	sort(a, a+N);
	for (i = 0; i < Q; i++)
	{
		t = binary_search(0, N-1, b[i]);
		if(t == -1) {
			printf("%d not found\n", b[i]);
		}else {
			printf("%d found at %d\n", b[i], t+1);
		}
	}
	return 0;
}
