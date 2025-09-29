#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct Position {
	int x;
	int y;
	Position(int x,int y):x(x),y(y){}
};

bool isValid(int x, int y, int n, const vector<vector<int>>& maze, const vector<vector<bool>>& visited) {
	return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0 && !visited[x][y]);
}

stack<Position> findPath(int n, const vector<vector<int>>& maze)  {
	stack<Position> path;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	int dx[] = { -1,0,1,0 };//上右下左
	int dy[] = { 0,1,0,-1 };
	if (maze[0][0] == 1) return path;
	path.push(Position(0, 0));
	visited[0][0] = true;
	while (!path.empty()) {
		Position current = path.top();
		if (current.x == n - 1 && current.y == n - 1) {
			return path;
		}
		bool found = false;
		//尝试四个方向
		for (int i = 0; i < 4; i++) {
			int next_x = current.x + dx[i];
			int next_y = current.y + dy[i];
			if (isValid(next_x, next_y, n, maze, visited)) {
				path.push(Position(next_x, next_y));
				visited[next_x][next_y] = true;
				found = true;
				break;
			}
		}
		if (!found) {
			path.pop();
		}
	}
	return path;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> maze(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> maze[i][j];
			}
		}

		stack<Position> path = findPath(n, maze);

		if (!path.empty()) {
			stack<Position> path1;
			while (!path.empty()) {
				path1.push(path.top());
				path.pop();
			}
			int i = 0;
			while (!path1.empty()) {
				Position cpos = path1.top();
				if ((++i) % 4 == 0) {
					cout << '[' << cpos.x << ',' << cpos.y << ']' << "--" << endl;
				}
				else {
					cout << '[' << cpos.x << ',' << cpos.y << ']' << "--";
				}
				path1.pop();
			}
			cout << "END" << endl;
		}
		else {
			cout << "no path" << endl;
		}
	}
	return 0;
}