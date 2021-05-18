#include <stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int M, A, B, i, j, v1, v2, len_graph, curr_vertex;
    long int weight_sum = 0, weight, min_dist;
    cin >> M >> A >> B;
    int visited[100];
    long int adj_matrix[100][100] = { 0 };

    int max = -1;

    for (i = 0; i < M; i++) {
        cin >> v1 >> weight >> v2;
        adj_matrix[v1 - 1][v2 - 1] = weight;
        adj_matrix[v2 - 1][v1 - 1] = weight;
        weight_sum += weight;
        visited[v1 - 1] = visited[v2 - 1] = 0;
        if (max < v1) max = v1;
        if (max < v2) max = v2;
    }
    len_graph = max;

    long int distance[1001];

    for (i = 0; i < len_graph; i++)
    {
        distance[i] = weight_sum + 1;
    }

    distance[A - 1] = 0;
    for (i = 0; i < len_graph; i++)
    {
        min_dist = weight_sum;
        for (j = 0; j < len_graph; j++)
        {
            if (visited[j] == 0 && distance[j] < min_dist)
            {
                min_dist = distance[j];
                curr_vertex = j;
            }
        }
        visited[curr_vertex] = 1;

        for (j = 0; j < len_graph; j++)
        {
            if (j == curr_vertex)
            {
                continue;
            }
            if (adj_matrix[curr_vertex][j] != 0 && distance[j] > distance[curr_vertex] + adj_matrix[curr_vertex][j])
            {
                distance[j] = distance[curr_vertex] + adj_matrix[curr_vertex][j];
            }
        }
    }

    if (visited[B - 1] == 1)
    {
        cout << "YES\n";
        cout << distance[B - 1];
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}