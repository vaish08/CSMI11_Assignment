#include<iostream>
#include<vector>
/*Minimum spanning tree*/

using namespace std;

class DSU{
    int *p, *rank;

    public: 
    DSU(int n){
        p = new int[n];
        rank = new int[n];

        for(int i = 0; i < n; i++){
            p[i] = -1;
            rank[i] = -1;
        }
    }

    int find(int i){
        if(p[i] == -1){
            return i;
        }
        return p[i] = find(p[i]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                p[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                p[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};  


class Graph{
    vector<vector<int> > e;
    int V;

    public:

    Graph(int V){
        this -> V = V;
    }

    void addedge(int w, int x, int y){
        vector<int> t;
        t.push_back(w);
        t.push_back(x);
        t.push_back(y);

        e.push_back(t);
        t.clear();
    }

    void mini_spanning_tree(){
        sort (e.begin(), e.end());
        DSU s(V);

        int ans = 0;
        for(auto ed : e){
            int w = ed[0], x = ed[1], y = ed[2];

            if(s.find(x) != s.find(y)){
                s.unite(x, y);
                ans += w;
                cout << x << " ---- " << y << " == " << w << endl;  
            }

        }
        cout << "Minimum_spanning tree cost is: " << ans << endl;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        g.addedge(x, y, z);
    }
    g.mini_spanning_tree();
    return 0;
}