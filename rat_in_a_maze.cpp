#include<bits/stdc++.h>
using namespace std;

bool visited[1001][1001],solution[1001][1001];

bool RatinMaze(char maze[][1001],int i,int j,int m,int n){  
    if(i==m && j==n){
        solution[i][j] = 1;
        for(int x=0;x<=m;x++){
            for(int y=0;y<=n;y++){
                cout<<solution[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(visited[i][j]){
        return false;
    }
    visited[i][j] = 1;
    solution[i][j] = 1;
    if(j+1<=n && !visited[i][j+1]){
        bool rightsuccess = RatinMaze(maze,i,j+1,m,n);
        if(rightsuccess==true){
            return true;
        }
    }
    if(i+1<=m && !visited[i+1][j]){
        bool downsuccess = RatinMaze(maze,i+1,j,m,n);
        if(downsuccess==true){
            return true;
        }
    }
    solution[i][j] = 0;
    return false;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char maze[1001][1001];
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='X')
                visited[i][j]=1;
        }
    }
    m--;
    n--;
    bool Y = RatinMaze(maze,0,0,m,n);
    if(!Y){
        cout<<"-1";
    }
    return 0;
}