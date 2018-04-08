#include<iostream>
#include <vector>
using namespace std;

vector<int> adj[10];
int main()
{
	int nodes, edges, i, j, x, y;
	cout<<"Enter no. of nodes and edges :";
	cin>>nodes>>edges;
	for(i=1; i<=nodes; i++)
	{
		cout<<"Enter the nodes connected with node "<<i<<" or -1 to move on to next node : ";
		for(j=0; j!=-1; j++)
		{
			cin>>x;
			adj[i].push_back(x);
			adj[x].push_back(i);	
		}
	}
	for(i=1; i<=nodes; ++i){
		cout<<"Adjacency list of node "<<i<<" is "<<i<<"-->";
		for(j=0; j<adj[i].size(); ++j){
			if(j == adj[i].size()-1){
				cout<<adj[i][j]<<endl;
			} else {
				cout<<adj[i][j]<<"-->";
			}
		}
	}
	return 0;
}