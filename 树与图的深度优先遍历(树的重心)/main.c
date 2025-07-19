#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define N 100010

int h[N], e[N * 2], ne[N * 2], idx;
bool st[N];
int ans = N;
int n;

int max(int a, int b)
{
	return a >= b ? a : b;
}

int min(int a, int b)
{
	return a <= b ? a : b;
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

int dfs(int u)
{
	st[u] = true;
	int sum = 1, res = 0;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			int s=dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;
}

int main(void)
{
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	
	dfs(1);
	printf("%d", ans);
	return 0;
}