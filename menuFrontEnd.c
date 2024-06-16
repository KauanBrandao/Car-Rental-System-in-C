#include <stdio.h>
#include <string.h>

#include "menuFuncionario.h"
#include "menuCliente.h"
#include "menuFrontEnd.h"

void printBannerL(char lines[8][20]) {
    char l[8][20] = {
        " .--------------- ",
        "|    _____        ",
        "|   |_   _|       ",
        "|     | |         ",
        "|     | |   _     ",
        "|    _| |__/ |    ",
        "|   |________|    ",
        " '--------------- "
    };
    for (int i = 0; i < 8; i++) {
        strcpy(lines[i], l[i]);
    }
}

void printBannerO(char lines[8][20]) {
    char o[8][20] = {
        " --------------   ",
        "     ____         ",
        "   .'    `.       ",
        "  /  .--.  \\      ",
        "  | |    | |      ",
        "  \\  `--'  /      ",
        "   `.____.'       ",
        " --------------   "
    };
    for (int i = 0; i < 8; i++) {
        strcpy(lines[i], o[i]);
    }
}

void printBannerC(char lines[8][20]) {
    char c[8][20] = {
        " --------------   ",
        "     ______       ",
        "   .' ___  |      ",
        "  / .'   \\_|      ",
        "  | |             ",
        "  \\ `.___.'\\      ",
        "   `._____.'      ",
        " --------------   "
    };
    for (int i = 0; i < 8; i++) {
        strcpy(lines[i], c[i]);
    }
}

void printBannerA(char lines[8][20]) {
    char a[8][20] = {
        " --------------   ",
        "      __          ",
        "     /  \\         ",
        "    / /\\ \\        ",
        "   / ____ \\       ",
        " _/ /    \\ \\_     ",
        "|____|  |____|    ",
        " --------------   "
    };
    for (int i = 0; i < 8; i++) {
        strcpy(lines[i], a[i]);
    }
}

void printBannerN(char lines[8][20]) {
    char n[8][20] = {
        " --------------   ",
        " ____  _____      ",
        "|_   \\|_   _|     ",
        "  |   \\ | |       ",
        "  | |\\ \\| |       ",
        " _| |_\\   |_      ",
        "|_____\\____|      ",
        " --------------   "
    };
    for (int i = 0; i < 8; i++) {
        strcpy(lines[i], n[i]);
    }
}

void printBannerI(char lines[8][20]) {
    char bannerI[8][20] = {
        " --------------.  ",
        "   _____       |  ",
        "  |_   _|      |  ",
        "    | |        |  ",
        "    | |        |  ",
        "   _| |_       |  ",
        "  |_____|      |  ",
        " --------------'  "
    };
    for (int j = 0; j < 8; j++) {
        strcpy(lines[j], bannerI[j]);
    }
}

void printCompleteBanner() {
    char linesL[8][20], linesO[8][20], linesC[8][20], linesA[8][20], linesN[8][20], linesI[8][20];

    printBannerL(linesL);
    printBannerO(linesO);
    printBannerC(linesC);
    printBannerA(linesA);
    printBannerN(linesN);
    printBannerI(linesI);

    for (int i = 0; i < 8; i++) {
        printf("%s %s %s %s %s %s %s\n", linesL[i], linesO[i], linesC[i], linesA[i], linesN[i], linesA[i], linesI[i]);
    }
}
