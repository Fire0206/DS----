#include <iostream>
using namespace std;

class Board {
private:
    char board[16][16];

public:
    Board() {
        for (int i = 1; i <= 15; i++) {
            for (int j = 1; j <= 15; j++) {
                board[i][j] = '0';
            }
        }
    }

    bool isLegal(char color, int x, int y) {
        if (x < 1 || x > 15 || y < 1 || y > 15 || board[x][y] != '0') {
            return false;
        }
        return true;
    }

    void change(char color, int x, int y) {
        if (color == 'o')
            board[x][y] = '@';
        else if (color == 'u')
            board[x][y] = '#';
    }

    int check() {
        // 检查水平方向
        for (int i = 1; i <= 15; i++) {
            for (int j = 1; j <= 11; j++) {
                if (board[i][j] == '@' && board[i][j + 1] == '@' && board[i][j + 2] == '@' && board[i][j + 3] == '@' && board[i][j + 4] == '@') {
                    return 1;
                }
                if (board[i][j] == '#' && board[i][j + 1] == '#' && board[i][j + 2] == '#' && board[i][j + 3] == '#' && board[i][j + 4] == '#') {
                    return 2;
                }
            }
        }
        // 检查垂直方向
        for (int i = 1; i <= 11; i++) {
            for (int j = 1; j <= 15; j++) {
                if (board[i][j] == '@' && board[i + 1][j] == '@' && board[i + 2][j] == '@' && board[i + 3][j] == '@' && board[i + 4][j] == '@') {
                    return 1;
                }
                if (board[i][j] == '#' && board[i + 1][j] == '#' && board[i + 2][j] == '#' && board[i + 3][j] == '#' && board[i + 4][j] == '#') {
                    return 2;
                }
            }
        }
        // 检查正斜方向
        for (int i = 1; i <= 11; i++) {
            for (int j = 1; j <= 11; j++) {
                if (board[i][j] == '@' && board[i + 1][j + 1] == '@' && board[i + 2][j + 2] == '@' && board[i + 3][j + 3] == '@' && board[i + 4][j + 4] == '@') {
                    return 1;
                }
                if (board[i][j] == '#' && board[i + 1][j + 1] == '#' && board[i + 2][j + 2] == '#' && board[i + 3][j + 3] == '#' && board[i + 4][j + 4] == '#') {
                    return 2;
                }
            }
        }
        // 检查反斜方向
        for (int i = 1; i <= 11; i++) {
            for (int j = 5; j <= 15; j++) {
                if (board[i][j] == '@' && board[i + 1][j - 1] == '@' && board[i + 2][j - 2] == '@' && board[i + 3][j - 3] == '@' && board[i + 4][j - 4] == '@') {
                    return 1;
                }
                if (board[i][j] == '#' && board[i + 1][j - 1] == '#' && board[i + 2][j - 2] == '#' && board[i + 3][j - 3] == '#' && board[i + 4][j - 4] == '#') {
                    return 2;
                }
            }
        }
        return 0;
    }

    void print() {
        for (int i = 1; i <= 15; i++) {
            for (int j = 1; j <= 15; j++) {
                if (board[i][j] == '0')
                    cout << '.';
                else
                    cout << board[i][j];
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        Board board;
        char color;
        int game = 0;
        int n, x, y;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> color >> x >> y;
            if (game == 0 && board.isLegal(color, x, y)) {
                board.change(color, x, y);
                int result = board.check();
                if (result == 1)
                    game = 1;
                else if (result == 2)
                    game = 2;
            }
        }
        board.print();
        if (game == 1)
            cout << "白子胜" << endl;
        else if (game == 2)
            cout << "黑子胜" << endl;
        else {
            if (color == 'o')
                cout << "白子继续" << endl;
            else
                cout << "黑子继续" << endl;
        }
        if (k < t - 1)
            cout << endl;
    }
    return 0;
}    
