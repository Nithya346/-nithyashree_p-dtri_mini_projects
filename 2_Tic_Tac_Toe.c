#include <stdio.h>

void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
int isEmpty(int row, int col, char board[3][3]);
int checkWin(char player, char board[3][3]);
int isFull(char board[3][3]);

int main() {
  char board[3][3];

  initializeBoard(board);

  int player = 1;
  char mark;

  while (1) {
    printBoard(board);

    printf("Player %d, enter a row (1-3) and column (1-3): ", player);
    int row, col;
    scanf("%d %d", &row, &col);
    row--;
    col--;

    if (!isEmpty(row, col, board)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    mark = (player == 1) ? 'X' : 'O';

    board[row][col] = mark;

    if (checkWin(mark, board)) {
      printBoard(board);
      printf("Player %d wins!\n", player);
      break;
    }

    if (isFull(board)) {
      printBoard(board);
      printf("It's a tie!\n");
      break;
    }

    player = (player % 2) + 1;
  }

  return 0;
}

void initializeBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void printBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c | ", board[i][j]);
    }
    printf("\n");
    if (i != 2) {
      printf("--|---|---|\n");
    }
  }
}

int isEmpty(int row, int col, char board[3][3]) {
  return board[row][col] == ' ';
}

int checkWin(char player, char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  for (int i = 0; i < 3; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }

  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  return 0;
}


int isFull(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (isEmpty(i, j, board)) {
        return 0;
      }
    }
  }
  return 1;
}
