#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define N 510
#define M 10010

typedef struct
{
	int a, b, w;
}Edge;
Edge edges[M];
int dist[N], backup[N];
int n, m, k;

int min(int a, int b)
{
	return a <= b ? a : b;
}

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for (int i = 0; i < k; i++)
	{
		memcpy(backup, dist, sizeof dist);

		for (int j = 0; j < m; j++)
		{
			Edge e = edges[j];
			int a = e.a, b = e.b, w = e.w;

			dist[b] = min(dist[b], backup[a] + w);
		}
	}
}

int main(void)
{
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i].a = a;
		edges[i].b = b;
		edges[i].w = w;
	}
	
	bellman_ford();

	if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
	else printf("%d", dist[n]);

	return 0;
}