#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
const int M = 200010;
const int INF = 0x3f3f3f3f;

int p[N];
struct Edge
{
	int a, b, w;

	/*bool operator <(const Edge& rhs)
	{
		return w < rhs.w;
	}*/
}edges[M];

int n, m;

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int kruskal()
{
	sort(edges, edges + m, cmp);
	for (int i = 1; i <= n; i++)
		p[i] = i;

	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);

		if (a != b)
		{
			p[a] = b;
			res += w;
			cnt++;
		}
	}

	if (cnt < n - 1) return INF;
	else return res;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		edges[i] = { a,b,w };
	}

	int t = kruskal();

	if (t == INF) puts("impossible");
	else printf("%d", t);

	return 0;
}