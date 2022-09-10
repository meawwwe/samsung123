#include<stdio.h>
#define qSize 10001
#define mSize 1001
 
struct positions
{
	int x, y;
};
 
struct positions Queue[qSize];
 
int front, rear;
 
void Push(int x, int y)
{
	if (rear == qSize)
	{
		rear = 0;
	}
 
	Queue[rear].x = x;
	Queue[rear].y = y;
	rear++;
}
 
struct positions Pop()
{
	if (front == qSize)
	{
		front = 0;
	}
 
	return Queue[front++];
}
 
 
 
int Up[8] = { 0, 1, 1, 0, 1, 0, 0, 1 };
int Down[8] = { 0, 1, 1, 0, 0, 1, 1, 0 };
int Left[8] = { 0, 1, 0, 1, 0, 0, 1, 1 };
int Right[8] = { 0, 1, 0, 1, 1, 1, 0, 0 };
 
int matrix[mSize][mSize], nodeDist[mSize][mSize];
 
int visited[mSize][mSize];
 
int row, col, startX, startY, length, maxVisitedCell;
 
int main()
{
	int test;
 
	scanf("%d", &test);
 
	while (test--)
	{
		scanf("%d %d %d %d %d", &row, &col, &startX, &startY, &length);
 
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				scanf("%d", &matrix[i][j]);
 
				visited[i][j] = nodeDist[i][j] = 0;
			}
		}
 
		front = rear = 0;
 
		maxVisitedCell = 0;
 
		if (0 != matrix[startX][startY])
		{
			visited[startX][startY] = 1;
 
			nodeDist[startX][startY] = 1;
 
			Push(startX, startY);
		}
 
		while (!(front == rear))
		{
			struct positions hand = Pop();
 
			int x = hand.x;
			int y = hand.y;
 
			maxVisitedCell++;
 
			int dist = nodeDist[x][y] + 1;
 
			if (dist > length)
			{
				continue;
			}
 
			if (x - 1 >= 0 && Up[matrix[x][y]] && Down[matrix[x - 1][y]] && !visited[x - 1][y])
			{
				visited[x - 1][y] = 1;
 
				nodeDist[x - 1][y] = dist;
 
				Push(x - 1, y);
			}
 
			if (x + 1 < row && Down[matrix[x][y]] && Up[matrix[x + 1][y]] && !visited[x + 1][y])
			{
				visited[x + 1][y] = 1;
 
				nodeDist[x + 1][y] = dist;
 
				Push(x + 1, y);
			}
 
			if (y - 1 >= 0 && Left[matrix[x][y]] && Right[matrix[x][y - 1]] && !visited[x][y - 1])
			{
				visited[x][y - 1] = 1;
 
				nodeDist[x][y - 1] = dist;
 
				Push(x, y - 1);
			}
 
			if (y + 1 < col && Right[matrix[x][y]] && Left[matrix[x][y + 1]] && !visited[x][y + 1])
			{
				visited[x][y + 1] = 1;
 
				nodeDist[x][y + 1] = dist;
 
				Push(x, y + 1);
			}
 
		}
 
 
		printf("%d\n", maxVisitedCell);
	}
 
	return 0;
}

