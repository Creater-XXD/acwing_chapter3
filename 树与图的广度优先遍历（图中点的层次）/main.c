#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 100010

int h[N], e[N], ne[N], idx;
int d[N];
int n, m;
int q[N], hh, tt = -1;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

int bfs()
{
	d[1] = 0;
	q[++tt] = 1;

	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)
			{
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	return d[n];
}

int main(void)
{
	memset(h, -1, sizeof h);
	memset(d, -1, sizeof d);

	scanf("%d%d", &n, &m);

	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}

	printf("%d", bfs());
	return 0;
}