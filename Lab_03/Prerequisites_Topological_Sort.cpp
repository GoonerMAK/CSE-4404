#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

bool canFinishCourses(vector<vector<int> > &prerequisites, int numCourses, vector<int> &inDegree, vector<int> &ans)
{
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        /// will push all the nodes with the indegree 0 in the queue (All the prerequisites are done for the course)
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    int Count = 0;
    while (!q.empty())
    {
        /// one by one we will take every element of the queue and will traverse the adjacency list of it
        /// and will remove that node and will reduce the indegree of the adjacent nodes which are
        /// prerequisites for it.
        int current = q.front();
        q.pop();
        for (auto a : prerequisites[current])
        {
            inDegree[a] -= 1;

            if (inDegree[a] == 0)                   /// and will push the node having 0 indegree in the queue
            {
                q.push(a);
            }

        }

        ans.push_back(current);       /// After processing current node, will push it in the ans
        Count++;
    }

    if (Count != numCourses)     /// checking for DAG.
    {
        return false;
    }

    return true;

}


vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = prerequisites.size();

    vector<vector<int>> adj(numCourses); /// Adjacency matrix

    vector<int> inDegree(numCourses, 0); /// indegree array
    /// traversing all the nodes of the graph.
    for (int i = 0; i < n; i++)
    {
        /// filling adjacency matrix for all the nodes of the graph.
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        /// also filling indegree value for all nodes.
        inDegree[prerequisites[i][0]] += 1;
    }

    vector<int> ans;

    if (canFinishCourses(adj, numCourses, inDegree, ans))     /// if graph is a DAG and All courses can be done then return the ans
    {
        return ans;
    }


    return{};     /// otherwise return the empty vector
}



int main()
{
    int numCourses, num;
    cin >> numCourses;

    vector<vector<int>> prerequisites;

    for (int i=0 ; i<numCourses ; i++)
    {
        vector<int> v1;             /// Vector to store column elements

        for (int j=0 ; j<numCourses; j++)
        {
            cin >> num;
            v1.push_back(num);
        }

        prerequisites.push_back(v1);       ///  Pushing back above 1D vector to create the 2D vector
    }

    vector<int> answer = findOrder(numCourses, prerequisites);


    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }


}
