#include <bits/stdc++.h>

using namespace std;
#define max_time 999

vector<int> dijkstra(vector<vector<int>> m,int s){

    vector<bool> visited(m.size());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    vector<int> dist(m.size(),INT_MAX);

    q.push(make_pair(0, s));
    dist[s] = 0;

    while (!q.empty()){
         int curr = q.top().second;
         q.pop();
    
        if(visited[curr] == false){
            visited[curr] = true;
            for(int i = 0 ; i< m.size();i++){
                if(m[curr][i] > 0 && !visited[i] && i != curr){
                    if(dist[curr]+m[curr][i] < dist[i]){
                        dist[i] = dist[curr]+m[curr][i];
                        q.push(make_pair(dist[curr]+m[curr][i],i));
                    }
                }
            }
        }
    }



    return dist;

}
int main(){
    vector<vector<int>> m{{0,10,max_time,max_time,15,5},
                            {10,0,10,30,max_time,max_time},
                            {max_time,10,0,12,5,max_time},
                            {max_time,30,12,0,max_time,20},
                            {15,max_time,5,max_time,0,max_time},
                            {5,max_time,max_time,20,max_time,0}};

    int origin = 0;
    vector<int>  pp = dijkstra(m,origin);
    int time = 0;

    for(int i = 0 ; i< pp.size();i++){
        cout<<"The shortest time from "<<origin<<" to " <<i<<" is "<<pp[i]<<endl;
        time+=pp[i];
    }
    cout<<"Average time taken is "<< 1.0*time/(m.size()-1)<<endl;
}


        