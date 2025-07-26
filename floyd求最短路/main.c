#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define N 210
#define INF 1e9

int d[N][N];
int n, m, q;

int min(int a, int b)
{
	return a <= b ? a : b;
}

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(void)
{
	scanf("%d%d%d", &n, &m, &q);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		d[a][b] = min(d[a][b], c);
	}

	floyd();

	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		if (d[a][b] > INF / 2) puts("impossible");
		else printf("%d\n", d[a][b]);
	}

	return 0;
}