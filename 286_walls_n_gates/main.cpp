//Textbook BFS implementation, rememer it (e.g. initialize distance panel with INF and don't consider neighbor.dist <= curr.dist+1)
#define INF 2147483647
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    void BFS(vector<vector<int> >& rooms, int i_, int j_, int rows_, int cols_){
        queue<pair<int,int> > q;
        pair<int,int> vpos[] = {make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
        
        q.push(make_pair(i_,j_));
        while ( !q.empty() ){
            pair<int,int> curr_node = q.front();
            q.pop();
            for ( int i = 0; i < 4; i++ ){
                pair<int,int> adj_node = make_pair(curr_node.first+vpos[i].first, curr_node.second+vpos[i].second);
                if ( adj_node.first >= 0 && adj_node.second >= 0 && adj_node.first < rows_ && adj_node.second < cols_){
                    if ( rooms[adj_node.first][adj_node.second] > rooms[curr_node.first][curr_node.second]+1 ){//the adjacent node is accessible
                        //update the shortest distance
                        rooms[adj_node.first][adj_node.second]= rooms[curr_node.first][curr_node.second]+1;
                        //push the adjacent node into the node queue
                        q.push(adj_node);
                    }
                }
            }
            
            
        }
        
    }
    void wallsAndGates(vector<vector<int> >& rooms) {
        int rows = rooms.size();
        int cols = 0;
        if ( rooms.size() != 0){
            cols = rooms[0].size();
        }
        else return;
        
        for ( int i = 0; i < rows; i++ ){
            for ( int j = 0; j < cols; j++ ){
                if ( rooms[i][j] == 0 ){
                    //BFS for each gate
                    BFS(rooms,i,j,rows,cols);
                    
                }
            }
        }

    }
};

int main(){
    vector<vector<int> > v(4,vector<int>(4,0));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> v[i][j];
        }
    }
    
    for ( int i = 0; i < v.size(); i++ ){
        for ( int j = 0; j < v[0].size(); j++ ){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    Solution sls;
    sls.wallsAndGates(v);
    
    for ( int i = 0; i < v.size(); i++ ){
        for ( int j = 0; j < v[0].size(); j++ ){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

