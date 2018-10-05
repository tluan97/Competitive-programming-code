/*
	POLYGON_REGION
	tested
*/
#include <bits/stdc++.h>
using namespace std;

// Given polygon with N vertices, and M diagonals.
// Diagonals does not intersect in internal point.
// Split polygon into regions.
//
// Usage:
// PolygonRegion a(n);
// for (auto p : diagonals) a.addEdge(p.first - 1, p.second - 1);
// a.init();
// Tested: http://codeforces.com/contest/776/problem/F
const int MN = 300111;
vector<int> ke[MN];  // 0-based index
struct PolygonRegion {  // everything is 0-based index
    int n;
    set<int> vertices;
    vector< pair<int,int> > diagonals;
    vector< vector<int> > regions;

    PolygonRegion(int n) : n(n) {
        vertices.clear();
        for (int i=0;i<n;i++) vertices.insert(i);
        diagonals.clear();
    }

    void addEdge(int a, int b) {
        assert(a != b);
        if (a > b) swap(a, b);
        assert(a + 1 != b);
        if (a == n) assert(b != 1);

        diagonals.emplace_back(b - a, a);
    }

    void init() {
        diagonals.emplace_back(n-1, 0);
        regions.clear();

        for (int i=0;i<n+1;i++) ke[i].clear();

        sort(diagonals.begin(), diagonals.end());
		for (int idiag=0;idiag<diagonals.size();idiag++){
            auto diagonal = diagonals[idiag];

            // (s, t) = current diagonal
            int s = diagonal.second;
            int t = s + diagonal.first;

            // extract polygon
            auto it = vertices.find(s); ++it;
            vector<int> cur;
            cur.push_back(s);
            while (true) {
                if (*it == t) break;
                cur.push_back(*it);
                vertices.erase(it++);
            }
            cur.push_back(t);

            // update adjacent list.
			for (int j=0;j<cur.size()-1;j++) {  // consider all edges except (s, t)
                if (cur[j+1] - cur[j] > 1) {
                    int low = lower_bound(diagonals.begin(), diagonals.end(), make_pair(cur[j+1] - cur[j], cur[j])) - diagonals.begin();
                    ke[low].push_back(idiag);
                    ke[idiag].push_back(low);
                }
            }

            regions.push_back(cur);
        }
    }
};

int main(){
	int n;cin>>n;
	PolygonRegion a(n);
	for (int i=0;i<n-2;i++)
		a.addEdge(i,n-1);
	a.init();
	for (int i=0;i<n;i++){
		for (int j=0;j<ke[i].size();j++){
			cout<<ke[i][j]<<" ";
		}	cout<<"\n";
	}
	return 0;
}
