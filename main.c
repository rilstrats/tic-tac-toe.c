#include <stdio.h>
#include <stdbool.h>

int WIN_CASES[8][3] = {
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},
	{0, 4, 8},
	{2, 4, 6},
};

void player_take_turn(char player, char *board) {
	printf("\nPlayer %c's turn\n", player);
	board_display(board);
	int square_num = board_get_user_square_num(board);
	board_claim_square(board, square_num, player);
}

char player_switch(char player) {
	if (player == 'X') {
		return 'O';
	} else {
		return 'X';
	}
}

bool board_win_check(char *board, char player) {
	for (int i = 0; i < 8; i++) {
		if (
			board[WIN_CASES[i][0]] == player &&
			board[WIN_CASES[i][1]] == player &&
			board[WIN_CASES[i][2]] == player
		) {
			return true;
		}
	}
	return false;
}

void board_display(char *board) {
	printf(" %c | %c | %c \n", board[0], board[1], board[2]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[3], board[4], board[5]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

void board_claim_square(
	char *board,
	int square_num,
	char player
) {
	board[square_num - 1] = player;
}

int board_get_user_square_num(char *board) {
	int user_input, user_amount;
	while (true) {
		printf("Please choose a square to claim: ");
		user_amount = scanf("%d", &user_input);
		if (user_amount == EOF) {
			printf("\nPlease enter a number!\n");
			continue;
		} else if (user_amount == 0) {
			printf("\nPlease enter a number!\n");
			continue;
		} else if (user_input < 1 || user_input > 9) {
			printf("\nPlease enter a number between 1 and 9!\n");
			continue;
		} else if (board[user_input-1] == 'X' || board[user_input-1] == 'O') {
			printf("\nPlease enter a number that hasn't been selected!\n");
			continue;
		} else {
			return user_input;
		}
	}

}

int main() {
	char board[9] = {
		'1',
		'2',
		'3',
		'4',
		'5',
		'6',
		'7',
		'8',
		'9',
	};
	char player = 'X';
	for (int i = 0; i < 9; i++) {
		player_take_turn(player, board);
		if (board_win_check(board, player)) {
			printf("\nPlayer %c wins!\n", player);
			board_display(board);
			return 0;
		}
		player = player_switch(player);
	}
	printf("\nCat. No one wins.\n");
	board_display(board);
	return 0;
}

