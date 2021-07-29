/*Pequeno Jogo donâmico de um Jogo chamado "jogo Da Velha", nada demais, apenas uma pratica dos meus estudos, espero que gostem do jogo da velha usando matriz, até breve!!*/

// Creditos & Salves:
// Wagner, Enormity, Ch4r0nN, Sasaki, flavio, Thomas.

#include <stdio.h>
#include <stdlib.h>

char jogo[3][3];
char jogador1[50], jogador2[50];

// iniciação da matriz;
void inicializarMatriz() {
    int i,j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            jogo[i][j] = ' ';
        }
    }
}

    int eValido(char letra) {
    if(letra == 'x' || letra == '0')
        return 1;
    else
        return 0;
}

    int coordenadaEhValida(int x, int y) {
    if(x >= 0 && x < 3) {
        if(y >= 0 && y < 3)
            return 1;
    }
    return 0;
}

    int posicaVazia(int x, int y) {
    if(jogo[x][y] != 'x' && jogo[x][y] != '0')
        return 1;
    return 0;
}

    int ganhouLinhas() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(eValido(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

    int ganhouColunas() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(eValido(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

    int ganhoudiagPrincipal() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(eValido(jogo[i][i]) && jogo[i][i] == jogo[i+1][i+1])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

    int ganhoudiagSecundaria() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(eValido(jogo[i][3-i-1]) && jogo[i][3-i-1] == jogo[i+1][3-i-2])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

void imprimir() {
    int lin, col;

    printf("\n\t    0  1  2\n");
    for(lin = 0; lin < 3; lin++) {
        printf("\t%d ", lin);
        for(col = 0; col < 3; col++) {
            if(col < 2)
          
                printf(" %c |", jogo[lin][col]);
            else
                printf(" %c ", jogo[lin][col]);
        }
        if(lin < 2)
            printf("\n\t   ---------\n");
    }
}

void jogar() {
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;

    do {
        do {
            imprimir();
            printf("\nDigite a que deseja jogar: ");
            scanf("%d%d", &x, &y);
            valida = coordenadaEhValida(x, y);
            if(valida == 1)
                valida += posicaVazia(x, y);
        } while(valida != 2);
        if(ordem == 1)
            jogo[x][y] = 'x';
        else
            jogo[x][y] = '0';
        jogadas++;
        ordem++;
        if(ordem == 3)
            ordem = 1;
        ganhou += ganhouLinhas();
        ganhou += ganhouColunas();
        ganhou += ganhoudiagPrincipal();
        ganhou += ganhoudiagSecundaria();
    } while(ganhou == 0 && jogadas < 9);

    if(ganhou != 0) {
        imprimir();
        if(ordem - 1 == 1)
            printf("\nVoce ganhou %s\n", jogador1);
        else
            printf("\nVoce ganhou %s\n", jogador2);
    } else
        printf("\Ninguem venceu!\n\n");
}

int main() {

    int op;
    printf("JOGO DA VELHA EM C\n\n");
    printf("creditos: Wagner, Enormity, Ch4r0nN.\n ");
    printf("\nJogar 1 digite seu nome: ");
    fgets(jogador1, 50, stdin);
    printf("Jogar 2 digite seu nome: ");
    fgets(jogador2, 50, stdin);

    do {
        inicializarMatriz();
        jogar();
        printf("Você Deseja Jogar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &op);
    } while(op == 1);

    return 0;
}

/*este foi meu primeiro joguinho rsrs, obrigado á todos por acompanhar!!*/
