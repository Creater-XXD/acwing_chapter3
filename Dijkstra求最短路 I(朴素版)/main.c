#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 510
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int min(int a, int b)
{
	return a <= b ? a : b;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (t == -1 || dist[j] < dist[t])) 
				t = j;
		}
		
		st[t] = true;

		for (int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
	}

	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main(void)
{
	memset(g, 0x3f, sizeof g);
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = min(g[a][b], c);
	}

	printf("%d", dijkstra());

	return 0;
}