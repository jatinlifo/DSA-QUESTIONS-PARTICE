// Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.

// Note: Do traverse in the same order as they are in the adjacency list.

// Examples:

// Input: adj = [[2,3,1], [0], [0,4], [0], [2]]

// Output: [0, 2, 3, 1, 4]
// Explanation: Starting from 0, the BFS traversal will follow these steps: 
// Visit 0 → Output: 0 
// Visit 2 (first neighbor of 0) → Output: 0, 2 
// Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
// Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 
// Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
// Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

// Output: [0, 1, 2, 3, 4]
// Explanation: Starting from 0, the BFS traversal proceeds as follows: 
// Visit 0 → Output: 0 
// Visit 1 (the first neighbor of 0) → Output: 0, 1 
// Visit 2 (the next neighbor of 0) → Output: 0, 1, 2 
// Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3 
// Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4
// Input: adj = [[1], [0, 2, 3], [1], [1, 4], [3]]
// Output: [0, 1, 2, 3, 4]
// Explanation: Starting the BFS from vertex 0:
// Visit vertex 0 → Output: [0]
// Visit vertex 1 (first neighbor of 0) → Output: [0, 1]
// Visit vertex 2 (first unvisited neighbor of 1) → Output: [0, 1, 2]
// Visit vertex 3 (next neighbor of 1) → Output: [0, 1, 2, 3]
// Visit vertex 4 (neighbor of 3) → Final Output: [0, 1, 2, 3, 4]


#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;

class Solution{
    public:
    

    void bfs(unordered_map<int,vector<int>>& adj, vector<bool>&visited, vector<int>& result, int u) {

        queue<int> que;
        que.push(u);
        visited[u] = true;
        result.push_back(u);

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    
    vector<int> BFSofGraph(unordered_map<int,vector<int>>& adj) {
        
        int v = adj.size();
        vector<int> result;
        vector<bool> visited(v,false);

        bfs(adj,visited,result,0);

        return result;
    }

};

int main () {
    
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    int E;
    cout<<"Enter the number of Edges : ";
    cin>>E;

    unordered_map<int,vector<int>> adj;
    
    cout<<"Enter Edges : ";
    cout<<endl;

    for(int i=0; i<E; i++){
        int u,v;
        cout<<"Edge "<< i+1 <<" : ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Printing the adjacency list
    cout << "\nAdjacency List: \n";
    for (auto& pair : adj) {
        cout << pair.first << " -> [";
        for (size_t i = 0; i < pair.second.size(); i++) {
            cout << pair.second[i];
            if (i != pair.second.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;  // Ensure proper line break
    }

    cout<<endl;

    Solution obj;
    cout<<"Answer Graph ";
    cout<<endl;
    vector<int> ans = obj.BFSofGraph(adj);

    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
    cout<<endl;
    return 0;
}