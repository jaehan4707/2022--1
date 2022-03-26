#include <iostream>
#include <vector>

using namespace std;
int threshold;
void tromino(vector<vector<int>>& maze,int row, int col);
void printmaze(vector<vector<int>>& maze);
void partition(vector<vector<int>>& maze, vector<vector<int>>& maze1, vector<vector<int>>& maze2, vector<vector<int>>& maze3, vector<vector<int>>& maze4); //사분면으로 나누기
void fillmaze(vector<vector<int>>& maze,int row, int col);
void combine(vector<vector<int>>& maze, vector<vector<int>>& maze1, vector<vector<int>>& maze2, vector<vector<int>>& maze3, vector<vector<int>>& maze4);
int hole(vector<vector<int>>& maze, int row, int col); // row col은 구멍있는 위치
int n, row, col, cnt = 1, H = 0, N = 0;
int main()
{

    cin >> n >> row >> col;
    vector<vector<int>> maze(n, vector<int>(n, 0)); // n*n의 배열을 \1으로 초기화시킴
    maze[row][col] = -1;                             //입력받은 좌표에 구멍을 뚫음
    tromino(maze, row, col);
    maze[row][col] = 0;
    printmaze(maze);
}
void printmaze(vector<vector<int>>& maze) //출력함수
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze.size(); j++)
        {
            if (j < maze.size() - 1)
            {
                cout << maze[i][j] << " ";
            }
            else
                cout<<maze[i][j];
        }
        if (i < maze.size() - 1)
        {
            cout << "\n";
        }
    }
}
void tromino(vector<vector<int>>& maze,int row, int col) //row col 구멍좌표
{
    H++;
    n = maze.size() / 2;
    
    int ROW = 0, COL = 0;
    int location = 0;
    
    vector<vector<int>> maze1(n, vector<int>(n, 0)); // 1사분면
    vector<vector<int>> maze2(n, vector<int>(n, 0)); // 2사분면
    vector<vector<int>> maze3(n, vector<int>(n, 0)); // 3사분면
    vector<vector<int>> maze4(n, vector<int>(n, 0)); // 4사분면
    if (n<= 1)
    {
        fillmaze(maze,row, col);
      
    }
    else
    {
        partition(maze, maze1, maze2, maze3, maze4); //배열4개를 큰배열로 4개 할당시켜줌.
        location=hole(maze, row, col); //구멍뚫린 사분면 위치가 나옴 5,5  size=8
        if (location == 1) //1사분면에 있다면
        {
            maze2[maze2.size() - 1][0] = H;
            maze3[0][maze3.size() - 1]=H;
            maze4[0][0] = H;
            tromino(maze1, row,col);
            tromino(maze2, maze2.size() - 1, 0);
            tromino(maze3, 0, maze3.size() - 1);
            tromino(maze4, 0, 0);
        }
        if (location == 2)
        {
            
            maze1[maze1.size() - 1][maze1.size() - 1] = H;
           
            maze3[0][maze3.size() - 1]=H;
            maze4[0][0] = H;
            //가짜구멍           
            tromino(maze1, maze1.size() - 1, maze1.size() - 1); 
            tromino(maze2, row, col-maze2.size()); //진짜구멍
            tromino(maze3, 0, maze3.size() - 1);
            tromino(maze4, 0, 0);

        }
        if (location == 3)
        {
           
            maze1[maze1.size() - 1][maze1.size() - 1] = H;
            maze2[maze2.size() - 1][0] = H;
          
            maze4[0][0] = H;
            tromino(maze1, maze1.size() - 1, maze1.size() - 1);
            tromino(maze2, maze2.size()-1, 0);
            tromino(maze3, row-maze3.size(), col);
            tromino(maze4, 0, 0);
            
        }
        if (location == 4) 
        {
            maze1[maze1.size() - 1][maze1.size() - 1] = H;
            maze2[maze2.size() - 1][0] = H;
            maze3[0][maze3.size() - 1]=H;
       
         
            tromino(maze1, maze1.size() - 1, maze1.size() - 1);
            tromino(maze2,maze2.size() - 1,0);
            tromino(maze3, 0, maze3.size()-1);
            tromino(maze4, row-maze4.size(), col-maze4.size());
        }
        combine(maze, maze1, maze2, maze3, maze4); // combine if문 나가고 있는게 나아ㅡㄹ듯
    }
}
int hole(vector<vector<int>>& maze,int row, int col) // row col은 구멍있는 위치 row1 col 2 size=4
{
    int size;
    size = maze.size();
    if (row < size/2 && col < size/2) //구멍이 1사분면에 있다
    {
        return 1;
    }
    else if (row >= size/2 && col < size/2)
    {
        return 3;
    }
    else if (row < size/2 && col >= size/2)
    {
        return 2;
    }
    else if (row >= size/2 && col >= size/2)
    {
        return 4;
    }
}
void combine(vector<vector<int>>& maze, vector<vector<int>>& maze1, vector<vector<int>>& maze2, vector<vector<int>>& maze3, vector<vector<int>>& maze4)
{
    int m = maze.size() / 2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = maze1[i][j];
            maze[i][j + m] = maze2[i][j];
            maze[i + m][j] = maze3[i][j];
            maze[i + m][j + m] = maze4[i][j];
        }
    }
}
void partition(vector<vector<int>>& maze, vector<vector<int>>& maze1, vector<vector<int>>& maze2, vector<vector<int>>& maze3, vector<vector<int>>& maze4) //사분면으로 나누기
{
    int m = maze.size() / 2; // 2분의n까지
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze1[i][j] = maze[i][j];
            maze2[i][j] = maze[i][j + m];
            maze3[i][j] = maze[i + m][j];
            maze4[i][j] = maze[i + m][j + m];
        }
    }
}
void fillmaze(vector<vector<int>>& maze,int row, int col) // row,col은 구멍 0,1
{
    N = H;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze.size(); j++)
        {
            //가짜구멍일때 가짜구멍은 h로 해줫음 H==1
            if (i==row&&j==col)
            {
                continue;
            }
            else
                maze[i][j] = N;
        }
    }
}