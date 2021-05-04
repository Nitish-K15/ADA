#include <limits.h> 
#include <stdio.h> 

#define V 5

int minDistance(int dist[], bool Set[])
{
	int min = INT_MAX;

	for (int v = 0; v < V; v++)
		if (Set[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min = v;
		}
	return min;
}

void printSol(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 

	bool visited[V]; 

	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
			visited[i] = false;
	}

	
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) 
	{
		int u = minDistance(dist, visited);
		visited[u] = true;
		for (int v = 0; v < V; v++)
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSol(dist);
}

int main()
{
	int graph[V][V] = { {0,3,0,0,5},
						{0,0,8,5,3},
						{0,0,0,0,0},
						{0,0,2,0,0},
						{0,0,0,4,0} };

	dijkstra(graph, 0);

	return 0;
}
