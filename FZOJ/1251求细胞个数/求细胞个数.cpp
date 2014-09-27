#include <cstdio>
#include <cstring>

#define MAXSIZE 1000

int x[4]={0,0,1,-1}, y[4]={1,-1,0,0};
char g[MAXSIZE][MAXSIZE];
int id[MAXSIZE][MAXSIZE];
int n,m,s;

void dfs(int i, int j, int idx) {
	if(i<0||j<0||i>=n||j>=m) return;
	if(id[i][j]!=0||g[i][j]=='0') return;
			id[i][j] = idx;
			for(int z=0;z<4;z++){
				dfs(i+x[z],j+y[z],idx);
			}
}

int main() {
	memset(id, 0, sizeof(id));
	s=0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &g[i]);
		g[i][m]='0';
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(g[i][j]!='0'&&id[i][j]==0){
				dfs(i,j,++s);
			}
		}
	}
	printf("%d", s);
}
