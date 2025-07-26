#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int N = 2010;
const int M = 10010;

int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int cnt[N];
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

bool spfa()
{
	queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		st[i] = true;
	}

	while (!q.empty())
	{
		int t = q.front(); q.pop();
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;

				if (cnt[j] >= n) return true;

				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	if (spfa()) puts("Yes");
	else puts("No");

	return 0;
}