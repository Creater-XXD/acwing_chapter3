#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int N = 150010;

int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m;

typedef pair<int, int> PII;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[1] = 0;
	heap.push({ 0,1 });

	while (!heap.empty())
	{
		auto t = heap.top(); heap.pop();
		int vec = t.second, distance = t.first;

		if (st[vec]) continue;
		
		st[vec] = true;

		for (int i = h[vec]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[vec] + w[i])
			{
				dist[j] = dist[vec] + w[i];
				heap.push({ dist[j],j });
			}
		}
	}

	if (dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}

	printf("%d", dijkstra());

	return 0;
}