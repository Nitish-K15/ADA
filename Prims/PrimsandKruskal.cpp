#include<iostream>
#include<cstring>
using namespace std;

#define V 5
#define HIGH 99999

void main()
{
	int G[V][V] = { {0,4,0,5,2},
					{4,0,1,3,0},
					{0,1,0,8,0},
					{5,3,8,0,2},
					{2,0,0,2,0} };
	int visited[V];
	memset(visited, false, sizeof(visited));
	visited[0] = true;
	cout << "Edge : Weight\n";
	int edges = 0;
	while (edges < V - 1)
	{
		int min = HIGH;
		int r, c = 0;
		for (int i = 0; i < V;++i)
		{
			if (visited[i])
			{
				for (int j = 0; j < V; j++)
				{
					if (min > G[i][j])
					{
						if(!visited[j] && G[i][j])
						{
							min = G[i][j];
							r = i;
							c = j;
						}
					}
				}
			}
		}
		cout << " " << r << ":" << c << ": " << G[r][c] << endl;
		visited[c] = true;
		edges++;
	}


}
