#include <cstdio>
#include <cstring>

#define MAXN 10000

int father[MAXN],rank[MAXN];

void makeset() {
	for(int i = 0; i < MAXN; i++) {
		father[i] = i;
		rank[i] = 1;
	}
}

int findset(int x) {
	return x != father[x] ? father[x] = findset(father[x]) : x;
}

void unionset(int x, int y) {
	int a = findset(x);
	int b = findset(y);
	if(a == b) return;
	if(rank[a] >= rank[b]){
		father[b] = a;
		rank[a] += rank[b];
	}else {
		father[a] = b;
		rank[b] += rank[a];
	}
}
int main() {
	int n,m,p;
	makeset();
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		unionset(x, y);
	}
	for(int i = 0; i < p; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(findset(a) == findset(b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
