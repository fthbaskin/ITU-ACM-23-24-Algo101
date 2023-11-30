#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ÖRNEK TEST CASE
5 7
1 4
2 2 4
3 2 5
2 1 3
3 1 4
2 3 4
3 1 4

ÖRNEK ÇIKTI
4 0 0 1 
*/

// Fonksiyonların içinde kullanacağımız vector'leri global olarak tanımlıyoruz
vector <int> parent; 
vector <int> group_size;

// x'in ait olduğu grubu bulma
int find(int x)
{
    if (parent[x] == x) // Eğer x'in parent'i kendisiyse x'i döndürüyoruz
        return x;
    else // Eğer x'in parent'i kendisi değilse x'in parent'ini bulup onu döndürüyoruz
    {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

// a ve b'nin aynı grupta olup olmadığını kontrol etme
int same(int a, int b)
{
    return find(a) == find(b);
}

// a ve b'yi aynı gruba ekleme
void unite(int a, int b)
{
    // a ve b'nin ait olduğu grupları buluyoruz
    a = find(a);
    b = find(b);

    // Eğer a ve b zaten aynı gruptaysa bir şey yapmıyoruz
    if (a == b)
        return;

    // Eğer a ve b'nin ait olduğu gruplar farklıysa küçük olanı büyüğe bağlıyoruz
    if (group_size[a] < group_size[b])
    {
        parent[a] = b;
        group_size[b] += group_size[a];
    }
    else
    {
        parent[b] = a;
        group_size[a] += group_size[b];
    }
}

int main()
{
    // N: Node sayısı, Q: Query sayısı
    int N, Q;
    cin >> N >> Q;

    // parent ve group_size vector'lerini N + 1 boyutunda tanımlıyoruz
    parent.resize(N + 1);
    group_size.resize(N + 1);

    // Her bir node'un parent'ini kendisi olarak, group_size'ını 1 olarak ayarlıyoruz
    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
        group_size[i] = 1;
    }

    // Q adet query alıyoruz
    for (int i = 0; i < Q; ++i)
    {
        // q_type: Query tipi
        int q_type;
        cin >> q_type;

        if (q_type == 1) // Hangi grupta olduğunu bulma
        {
            int a; cin >> a;
            cout << find(a) << endl;
        }
        if (q_type == 2) // Aynı gruba ekleme
        {
            int a, b; cin >> a >> b;
            unite(a, b);
        }
        if (q_type == 3) // Aynı gruplarda olup olmadıklarını kontrol etme
        {   
            int a, b; cin >> a >> b;
            cout << same(a, b) << endl;
        }
    }
}