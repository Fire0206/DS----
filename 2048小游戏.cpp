#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
 
void update(int array[4][4]);
void randTwo(int array[4][4]);
int hasEmpty(int array[4][4]);
int isFull(int array[4][4]);
void slide(char c, int array[4][4]);
 
// 分数
static int score = 0;
// 最大分数
static int maxScore = 0;
int operate = 1;
 
int main() {
 
	int array[4][4] = {0};
	char c = ' ';
	while (true) {
		if (hasEmpty(array)==1&&operate==1) {
			randTwo(array);
		}
		update(array);
		if (hasEmpty(array)==0 && isFull(array)==1) {
			break;
		}
		Sleep(400);
		c = _getch();
		if (c == 'q' || c == 'Q')
			exit(0);
		while (c != 'w'&&c != 'W'&&c != 's'&&c != 'S'&&c != 'd'&&c != 'D'&&c != 'a'&&c != 'A') {
			c = _getch();
		}
		slide(c, array);
		system("cls");
	}
	printf("\n失败!");
	system("pause");
}
 
// 更新页面,生成页面信息
void update(int array[4][4]) {
	printf("GAME: 2048\tScore:%d" , score);
	printf("\t\tBEST:%d",  maxScore);
	printf("\n---------------------------------------\n");
	for (int j = 0; j < 4; j++) {
		printf(" ________");
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("|        ");
		}
		printf("|\n");
		for (int j = 0; j < 4; j++) {
			if (array[i][j] == 0) {
				printf("|        ");
			}
			else {
				printf("| %4d   ", array[i][j]);
			}
		}
		printf("|\n");
		for (int j = 0; j < 4; j++) {
			printf("|________");
		}
		printf("|\n");
	}
	printf("\n---------------------------------------\n");
	printf("【W】:UP 【S】:DOWN 【A】:LEFT 【D】:RIGHT 【Q】:EXIT");
}
 
// 随机生成2
void randTwo(int array[4][4]) {
	//以时间为种子，生成随机数
	srand((unsigned)time(NULL));
	int i = abs(rand() % 4);
	int j = abs(rand() % 4);
	//不能在已经是大于0的位置生成2
	while (array[i][j] != 0) {
		i = abs(rand() % 4);
		j = abs(rand() % 4);
	}
	array[i][j] = 2;
}
 
// 判断区域内是否有空位置
int hasEmpty(int array[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (array[i][j] == 0) {
				return 1;
			}
		}
	}
	return 0;
}
 
// 判断是否已经满位而且不可合并，游戏结束
int isFull(int array[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (array[i][j] == array[i][k] || array[i][j] == array[k][j]) {
					return 0;
				}
			}
		}
	}
	return 1;
}
 
void slide(char c, int array[4][4]) {
	if (c == 'a' || c == 'A') {
		operate = 0;
		//扫描开始
		for (int i = 0; i<4; i++) {
			//同一行的操作次数
			int op = 0;
			//特殊情况
			if (array[i][0]!=0&&array[i][2]!=0&&array[i][0] == array[i][1] && array[i][2] == array[i][3]) {
				array[i][0] *= 2;
				array[i][1] = array[i][2]*2;
				array[i][2] = 0;
				array[i][3] = 0;
				continue;
			}
			for (int j = 0; j < 4; j++) {
				int k = j;
				//当左边存在0时，向左移动
				while (k>0 && array[i][k] > 0 && array[i][k - 1] == 0) {
					array[i][k - 1] = array[i][k];
					array[i][k] = 0;
					k--;
					operate = 1;
				}
				//判断相邻的两个是否相等，相等即向左移动
				if (k>0 && array[i][k] == array[i][k - 1]&&op==0) {
					if (array[i][k] != 0) {
						operate = 1;
						score += array[i][k];
						op++;
					}
					array[i][k - 1] *= 2;
					array[i][k] = 0;
				}
			}
		}
		
	}
	else if (c == 'd' || c == 'D') {
		operate = 0;
		for (int i = 0; i<4; i++) {
			//同一行的操作次数
			int op = 0;
			//特殊情况
			if (array[i][0] != 0 && array[i][2] != 0 && array[i][2] != 0 && array[i][0] == array[i][1] && array[i][2] == array[i][3]) {
				array[i][3] *= 2;
				array[i][2] = array[i][1]*2;
				array[i][1] = 0;
				array[i][0] = 0;
				continue;
			}
			for (int j = 3; j >= 0; j--) {
				int k = j;
 
				while (k<3 && array[i][k] > 0 &&array[i][k + 1] == 0) {
					array[i][k + 1] = array[i][k];
					array[i][k] = 0;
					k++;
					operate = 1;
				}
				//判断相邻的两个是否相等，相等即向右移动
				if (k<3 && array[i][k] == array[i][k + 1]&&op==0) {
					if (array[i][k] != 0) {
						operate = 1;
						score += array[i][k];
						op++;
					}
					array[i][k + 1] *= 2;
					array[i][k] = 0;
				}
			}
		}
	}
 
	else if (c == 'w' || c == 'W') {
		operate = 0;
		for (int j = 0; j < 4; j++) {
			
			//特殊情况，同一列4个数完全相同
			if (array[0][j] != 0 && array[0][j] == array[1][j] && array[2][j] == array[3][j]) {
				array[0][j] *= 2;
				array[1][j] = array[2][j]*2;
				array[2][j] = 0;
				array[3][j] = 0;
				continue;
			}
			//同一列的操作次数
			int op = 0;
			for (int i = 0; i<4; i++) {
				int k = i;
				while (k>0 && array[k][j] > 0 && array[k - 1][j] == 0) {
					array[k - 1][j] = array[k][j];
					array[k][j] = 0;
					k--;
					operate = 1;
				}
				//判断相邻的两个是否相等，相等即向上移动
				if (k>0 && array[k][j] == array[k - 1][j]&&op==0) {
					if (array[k][j] != 0) {
						score += array[k][j];
						operate = 1;
						op++;
					}
					array[k - 1][j] *= 2;
					array[k][j] = 0;
				}
			}
		}
	}
	else if (c == 's' || c == 'S') {
		operate = 0;
		for (int j = 3; j >= 0; j--) {
			//特殊情况
			if (array[0][j] != 0 && array[0][j] == array[1][j] && array[2][j] == array[3][j]) {
				array[2][j] = array[1][j] * 2;
				array[1][j] = 0;
				array[0][j] = 0;
				array[3][j] *= 2;
				continue;
			}
			int op = 0;
			for (int i = 3; i>=0; i--) {
				int k = i;
 
				while (k<3 && array[k][j] > 0 && array[k + 1][j] == 0) {
					array[k + 1][j] = array[k][j];
					array[k][j] = 0;
					k++;
					operate = 1;
				}
				//判断相邻的两个是否相等，相等即向下移动
				if (k<3 && array[k][j] == array[k + 1][j]&&op==0) {
					if (array[k][j] != 0) {
						score += array[k][j];
						operate = 1;
						op++;
					}
					array[k + 1][j] *= 2;
					array[k][j] = 0;
				}
			}
		}
	}
}
 
