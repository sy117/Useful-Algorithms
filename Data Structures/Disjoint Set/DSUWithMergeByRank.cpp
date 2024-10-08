#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity:- O(logN)
                      O(4 * aplha) with path compression
    Space Complexity:- O(N)
*/

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int a) {
        if(a == parent[a]) {
            return a;
        }
        return parent[a] = findParent(parent[a]); // path compression
    }

    void merge(int a, int b) {
        int parentA = findParent(a);
        int parentB = findParent(b);

        int rankParentA = rank[parentA];
        int rankParentB = rank[parentB];

        if(rankParentA < rankParentB) {
            parent[parentA] = parentB;
        } else {
            parent[parentB] = parentA;
            if(rankParentA == rankParentB) rank[parentA]++;
        }
    }


    int numberOfComponents() {
        int count = 0;
        for(int i=0; i<parent.size(); i++) {
            if(i == parent[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
	
    DisjointSet disjointSet(10);

    disjointSet.merge(0, 2);
    disjointSet.merge(1, 3);
    disjointSet.merge(4, 5);
    disjointSet.merge(1, 5);


    cout << "1 and 2 belongs to: ";
    if(disjointSet.findParent(1) == disjointSet.findParent(2)) {
        cout << "same component\n";
    } else {
        cout << "different component\n";
    }
    disjointSet.merge(2, 3);
    cout << "After merging 2 and 3\n";
    


    cout << "1 and 2 belongs to: ";
    if(disjointSet.findParent(1) == disjointSet.findParent(2)) {
        cout << "same component\n";
    } else {
        cout << "different component\n";
    }
	return 0;
}