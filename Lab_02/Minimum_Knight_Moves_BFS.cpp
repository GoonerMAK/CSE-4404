#include<bits/stdc++.h>
using namespace std;

int xMoves[] = { 2, 2, -2, -2, 1, 1, -1, -1 };            /// all the possible movements of a knight
int yMoves[] = { -1, 1, 1, -1, 2, -2, 2, -2 };


class Node         /// A node of an N-ary tree
{
public:

    int x, y, distance;

    Node(int x, int y, int distance):
    x(x), y(y), distance(distance) {}

};


class Tree
{
public:                                 ///  in case we want to run a lot of cases : shared_ptr

    vector<shared_ptr<Node>> nodes;   /// to have all the possible moves

    Tree(){}

    void addNode(shared_ptr<Node> child)
    {
        nodes.push_back(child);
    }

    bool CheckInsideBoard(int x, int y)   /// checking the validity of the coordinates
    {
        if(x>=0 && x<8 && y>=0 && y<8)
            return true;

        return false;
    }

    int MinimumSteps(int startX, int startY, int endX, int endY)  /// calculating the minimum steps
    {
        if(!CheckInsideBoard(startX, startY) )
        {
            cout << "Position outside the board" << endl;
        }

        /// creating nodes
        shared_ptr<Node> root(new Node(startX, startY, 0) );  ///  initializing the distance as 0

        shared_ptr<Tree> tree(new Tree);

        shared_ptr<Node> currentNode;

        int x, y;
        bool endGoalReached = false;

        vector<vector<bool>> visited(8, vector<bool>(8, false));  /// Matrix to keep track of visited cells in chess board

        visited[root->x][root->y] = true;    /// the root cell is visited (by default)

        const int numberOfPossibleMoves = 8;
        int nodeNumber = 0;

        currentNode = root;       /// the current node is the root node

        while(!endGoalReached)
        {
            if(currentNode->x == endX  &&  currentNode->y == endY)
            {
                visited.clear();
                return currentNode->distance;
            }

            for(int i=0 ; i < numberOfPossibleMoves ; i++)
            {
                x = currentNode->x + xMoves[i];        /// getting all the possible moves
                y = currentNode->y + yMoves[i];

                if(CheckInsideBoard(x, y)  &&  !visited[x][y] )    /// if one of the possible moves is not visited...
                {                                                 ///  and it's inside the board --> we insert it into the tree
                    visited[x][y] = true;

                    shared_ptr<Node> newNode( new Node(x, y, currentNode->distance + 1) );   /// one of the new moves that's possible

                    tree->addNode(newNode);       /// adding it to the tree
                }

            }

            currentNode = tree->nodes[nodeNumber++];   /// setting the current node to the next possible move/node in the tree

        }

        visited.clear();                    /// clearing memory

        return -1;
    }

};



int main()
{
    Tree tree;

    string from, to;
    cin >> from >> to;

    cout << "Minimum moves: " << tree.MinimumSteps( (from[0]-'a'), (from[1]-'1'), (to[0]-'a'), (to[1]-'1')) << endl;

    return 0;
}


///  Here, we are adding all the possible nodes/moves into the tree...
///  Then we are doing a Breadth-First-Search to find the node/move that will match with destination node

