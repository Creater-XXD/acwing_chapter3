#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 510
#define INF 0x3f3f3f3f

int g[N][N];
int dist[N];
bool st[N];
int pre[N];
int n, m;

int min(int a, int b)
{
	return a <= b ? a : b;
}

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int res = 0;

	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}

		if (dist[t] == INF) return INF;

		res += dist[t];
		st[t] = true;

		for (int j = 1; j <= n; j++)
		{
			if (dist[j] > g[t][j])
			{
				dist[j] = g[t][j];
				pre[j] = t;
			}
		}
	}
	return res;
}
int main(void)
{
	memset(g, 0x3f, sizeof g);
	memset(pre, -1, sizeof pre);
	scanf("%d%d", &n, &m);

	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	}

	int t = prim();

	if (t == INF) puts("impossible");
	else printf("%d\n", t);

	for (int i = 1; i <= n; i++)
		printf("%d ", pre[i]);

	return 0;
}