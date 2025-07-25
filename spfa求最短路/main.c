#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 100010

int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int q[N], hh, tt = -1;
bool st[N];
int n, m;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

int spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	q[++tt] = 1;
	st[1] = true;

	while (hh <= tt)
	{
		int t = q[hh++];
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];

			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q[++tt] = j;
					st[j] = true;
				}
			}
		}
	}

	return dist[n];
}

int main(void)
{
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}

	int t = spfa();

	if (t == 0x3f3f3f3f) puts("impossible");
	else printf("%d", t);

	return 0;
}