#include <stdbool.h>
#include <stdio.h>

char jogo[3][3];

void printJogo();

int main() {
    // deixa o mapa do jogo vazio
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            jogo[x][y] = ' ';
        }
    }

    int jogada = 0;
    int xJogados[8] = {0};
    int yJogados[8] = {0};

    printJogo();

    while (1) {
        int player = (jogada % 2) + 1;

        char bloco[3] = {'\0'};
        printf("Player %d, Inserir bloco: ", player);
        fgets(bloco, 3, stdin);
        while (getchar() != '\n');

        if (!((bloco[0] >= 'A') && (bloco[0] <= 'C'))) {
            printf("Entrada incorreta, primeiro caractere incorreto\n");
            continue;
        }
        if (!((bloco[1] >= '0') && (bloco[1] <= '3'))) {
            printf("Entrada incorreta, segundo caractere incorreto\n");
            continue;
        }

        int y = (bloco[0] - 'A');
        int x = (bloco[1] - '0' - 1);

        int restartLoop = 0;
        for (int i = 0; i < jogada; i++) {
            if ((xJogados[i] == x) && (yJogados[i] == y)) {
                printf("Esse Bloco ja foi jogado\n");
				restartLoop = 1;
            }
        }
		if(restartLoop == 1){
			continue;
		}

        xJogados[jogada] = x;
        yJogados[jogada] = y;
        if (player == 1) {
            jogo[x][y] = 'X';
        } else {
            jogo[x][y] = 'O';
        }

        printJogo();

        // verifica horizontalmente
        for (int y = 0; y < 3; y++) {
            int player1count = 0;
            int player2count = 0;
            for (int x = 0; x < 3; x++) {
                if (jogo[y][x] == 'X') {
                    player1count++;
                }
                if (jogo[y][x] == 'O') {
                    player2count++;
                }
            }
            if (player1count == 3) {
                printf("player 1 ganhou o jogo.");
                return 1;
            }
            if (player2count == 3) {
                printf("player 2 ganhou o jogo.");
                return 2;
            }
            player1count = 0;
            player2count = 0;
        }

        // verifica verticalmente
        for (int y = 0; y < 3; y++) {
            int player1count = 0;
            int player2count = 0;
            for (int x = 0; x < 3; x++) {
                if (jogo[x][y] == 'X') {
                    player1count++;
                }
                if (jogo[x][y] == 'O') {
                    player2count++;
                }
            }
            if (player1count == 3) {
                printf("player 1 ganhou o jogo.");
                return 1;
            }
            if (player2count == 3) {
                printf("player 2 ganhou o jogo.");
                return 2;
            }
            player1count = 0;
            player2count = 0;
        }

        // verifica as diagonais
        if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') {
            printf("player 1 ganhou o jogo.");
            return 1;
        }
        if (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') {
            printf("player 2 ganhou o jogo.");
            return 2;
        }

        if (jogo[2][0] == 'X' && jogo[1][1] == 'X' && jogo[0][2] == 'X') {
            printf("player 1 ganhou o jogo.");
            return 1;
        }
        if (jogo[2][0] == 'O' && jogo[1][1] == 'O' && jogo[0][2] == 'O') {
            printf("player 2 ganhou o jogo.");
            return 2;
        }

        // empate
        if (jogada == 8) {
            printf("o jogo empatou.");
            return 0;
        }

        jogada++;
    }
}

void printJogo() {
    printf("    1   2   3 \n\n");
    printf("A   %c | %c | %c\n", jogo[0][0], jogo[1][0], jogo[2][0]);
    printf("    ---------\n");
    printf("B   %c | %c | %c\n", jogo[0][1], jogo[1][1], jogo[2][1]);
    printf("    ---------\n");
    printf("C   %c | %c | %c\n", jogo[0][2], jogo[1][2], jogo[2][2]);
}
