#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define N 510
#define M 100010

int h[N], e[M], ne[M], idx;
bool st[N];
int match[N];
int n1, n2, m;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

bool find(int x)
{
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	memset(h, -1, sizeof h);
	scanf("%d%d%d", &n1, &n2, &m);

	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		add(a, b);
	}

	int res = 0;
	for (int i = 1; i <= n1; i++)
	{
		memset(st, false, sizeof st);
		if (find(i)) res++;
	}

	printf("%d", res);

	return 0;
}