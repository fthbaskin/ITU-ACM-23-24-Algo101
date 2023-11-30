#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ÖRNEK TEST CASE
(Graph'ın görseli ders slaytında bulabilirsiniz)
5 7
1 3 6
1 2 5
2 4 4
1 4 14
3 4 2
3 5 6
4 5 2

ÖRNEK ÇIKTI
0 5 6 8 10
*/

int main()
{
	// N: Node sayısı, Q: Edge sayısı
	int N, Q; cin >> N >> Q;

	// Graph içerisindeki her bir node'un komşularını tutan bir vector
	vector<vector<pair<int, int>>> adj(N + 1);

	// Q adet edge bilgisi alıyoruz
	for (int i = 0; i < Q; ++i)
	{
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	// Her bir node'a olan uzaklığı tutan vector
	vector<int> distance(N + 1, INT_MAX);
	// Her bir node'un ziyaret edilip edilmediğini tutan vector
	vector<bool> visited(N + 1, false);
	// Şu anda ulaşılabilen en kısa yolun uzunluğunu ve node'u tutan priority queue
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// Başlangıç node'u 1 olduğu için ona olan uzaklığı 0 olarak ayarlıyoruz
	distance[1] = 0;
	// Başlangıç node'unu pq'ya ekliyoruz
	pq.push({0, 1});

	// pq boşalana kadar devam ediyoruz
	while (!pq.empty())
	{
		// Şu anda ulaşılabilen en kısa yolun uzunluğunu ve node'unu alıyoruz
		int a = pq.top().second;
		pq.pop();

		// Eğer bu node'u daha önce ziyaret ettiysek devam ediyoruz
		if (visited[a])
			continue;

		// Eğer bu node'u daha önce ziyaret etmediysek ziyaret ettiğimizi işaretliyoruz
		visited[a] = true;

		// Bu node'un komşularını geziyoruz
		for (auto edges : adj[a])
		{
			// Komşu node'unu ve aralarındaki uzaklığı alıyoruz
			int b = edges.first;
			int w = edges.second;

			// Eğer bu node'a olan uzaklık + aralarındaki uzaklık, komşu node'a olan uzaklıktan küçükse
			if (distance[a] + w < distance[b])
			{
				distance[b] = distance[a] + w;
				// Komşu node'u pq'ya ekliyoruz
				pq.push({distance[b], b});
			}
		}
	}

	// Her bir node'a olan uzaklığı yazdırıyoruz
	for (auto x : distance)
		cout << x << " ";

	return 0;
}