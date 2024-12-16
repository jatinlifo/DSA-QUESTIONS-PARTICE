// Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.

// Note: Do traverse in the same order as they are in the adjacency list.
// Examples:

// Input: adj = [[2,3,1], [0], [0,4], [0], [2]]

// Output: [0, 2, 4, 3, 1]
// Explanation: Starting from 0, the DFS traversal proceeds as follows: 
// Visit 0 → Output: 0 
// Visit 2 (the first neighbor of 0) → Output: 0, 2 
// Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
// Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
// Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
// Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

// Output: [0, 1, 2, 3, 4]
// Explanation: Starting from 0, the DFS traversal proceeds as follows: 
// Visit 0 → Output: 0 
// Visit 1 (the first neighbor of 0) → Output: 0, 1 
// Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
// Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
// Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution{
    public:
    

    void dfs(unordered_map<int,vector<int>>& adj, vector<bool>&visited, vector<int>& result, int u) {

        if(visited[u] == true){
            return;
        }
        visited[u] = true;
        result.push_back(u);

        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(adj,visited,result,v);
            }
        }
    }
    
    vector<int> DFSofGraph(unordered_map<int,vector<int>>& adj) {
        
        int v = adj.size();
        vector<int> result;
        vector<bool> visited(v,false);

        dfs(adj,visited,result,0);

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
    vector<int> ans = obj.DFSofGraph(adj);

    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
    cout<<endl;
    return 0;
}