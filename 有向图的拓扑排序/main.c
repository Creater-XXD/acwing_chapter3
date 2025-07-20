#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define N 100010
int h[N], e[N], ne[N], idx;
int q[N], hh, tt = -1;
int in[N];
int n, m;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

bool topsort()
{
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0) q[++tt] = i;
	}

	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			in[j]--;
			if (in[j] == 0) q[++tt] = j;
		}
	}
	return tt == n - 1;
}
int main(void)
{
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		in[b]++;
	}

	if (topsort())
	{
		puts("Yes");
		for (int i = 0; i < n; i++)
			printf("%d ", q[i]);
	}
	else puts("No");

	return 0;
}