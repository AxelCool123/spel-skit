#include <iostream>
#define SIZE 10

char maze[SIZE][SIZE] = {
	// 0 är en väg, 1 är en stig. 
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
	{'0', '1', '0', '0', '0', '0', '0', '0', '1', '0'},
};

void printMaze() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			std::cout << maze[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int playerX = 0;
int playerY = 0;

void movePlayer(char key) {
    switch (key) {
    case 'w':
        if (playerY > 0 && maze[playerY - 1][playerX] == '1') {
            playerY--;
        }
        break;
    case 's':
        if (playerY < SIZE - 1 && maze[playerY + 1][playerX] == '1') {
            playerY++;
        }
        break;
    case 'a':
        if (playerX > 0 && maze[playerY][playerX - 1] == '1') {
            playerX--;
        }
        break;
    case 'd':
        if (playerX < SIZE - 1 && maze[playerY][playerX + 1] == '1') {
            playerX++;
        }
        break;
    }
}

int main() {
    printMaze();
    char key;
    while (std::cin >> key) {
        movePlayer(key);
        printMaze();
    }
    return 0;
}
