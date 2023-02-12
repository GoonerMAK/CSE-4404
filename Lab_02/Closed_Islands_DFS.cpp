#include<iostream>
#include<vector>
using namespace std;

bool isClosed( vector<vector<int>> &grid, int row, int col)
{
    if( row < 0  ||  col < 0  ||  row >= grid.size() || col >= grid[0].size()  )   ///  Base case: if we're out of bounds
    {
        return false;
    }

    if( grid[row][col] == 1 )   return true;     /// stop traversing when we see 1

    grid[row][col] = 1;      /// explored an unexplored cell... assigning it 1 so that we don't come here again while traversing

    bool left = isClosed( grid, row, col-1);        /// Checking the cell's all 4 neighbors
    bool right = isClosed( grid, row, col+1);
    bool top = isClosed( grid, row-1, col);
    bool bottom = isClosed( grid, row+1, col);

    return (left && right && top && bottom);      /// checking if all the neighbors (paths) return true or not
}


int closedIsland( vector<vector<int>> &grid)
{
    int ans = 0;

    for( int i=0 ; i<grid.size() ; i++ )
    {
        for(int j=0 ; j<grid[0].size() ; j)
        {
            if( grid[i][j] == 0 )          /// Running a DFS, because we found a 0 (this could be a potential island)
            {
                if( isClosed(grid, i, j) )
                    ans++;
            }
        }
    }
    return ans;
}


int main()
{
     int row, col;
     cin >> row >> col;

    vector<vector<int>> grid;

     for(int i = 0; i < row; i++)
     {
         vector<int> v1;

         for(int j = 0; j < col; j++)
         {
             int n;
             cin >> n;
             v1.push_back(n);
         }

         grid.push_back(v1);
     }

    cout  << closedIsland(grid) << endl;

    return 0;
}


//  grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};


