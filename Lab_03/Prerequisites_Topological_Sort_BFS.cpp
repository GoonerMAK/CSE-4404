#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) 
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);        // adjacency list
        vector<int> ans;                    
                                                
        for(auto course : prerequisites)             //  [2, 3] indicates that, to take course 2, we need to take course 3
        {
            adj[course[1]].push_back(course[0]);    //  populating the adjacency list
            indegree[course[0]]++;                 //  indegree from a node indicates that the course is a prerequisite for other courses
        }

        for(int i = 0; i < adj.size(); i++)
        {
            for(int j = 0; j < adj[i].size() ; j++)
            {
                cout << "Prerequisite of "<< adj[i][j] << " is " << i << endl;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses; i++){
            if(indegree[i] == 0)                    // the course has no prerequisites
                q.push(i);
        }


        while(!q.empty()){
            int current = q.front();      // the course that has no prerequisites
            q.pop();

            ans.push_back(current);      // completing the prerequisite courses
    
            for(auto neighbours : adj[current])     // BFS
            {
                indegree[neighbours]--;     // since we completed a course (ans.push_back(current)), prerequisites decrease

                if(indegree[neighbours] == 0)    // the course has no prerequisites
                    q.push(neighbours);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};

int main()
{
    int numCourses, a, b;
    cin >> numCourses;

	vector<vector<int>> prerequisites;

    for(int i = 0; i < numCourses; i++)
    {
        cin >> a >> b;
        vector<int> v1;

        v1.push_back(a);
        v1.push_back(b);

        prerequisites.push_back(v1);
    }

   	Solution obj;
	vector<int> ans = obj.findOrder(numCourses, prerequisites);

    for(int i=0 ; i < numCourses ; i++)
    {
        cout << ans[i] << " ";
    }

	return 0;
}

// if there's a cycle... topological sort is not possible (return empty vector)

// Time Complexity: O(E+V)