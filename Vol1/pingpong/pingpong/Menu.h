#pragma once
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
#include<windows.h>
#include<vector>
#include<ctime>//cronometro
#include<cstdlib>//
using namespace std;



class Menu {

public:
	void pintar_portada(int& a) 
	{
        char portada[18][71] =
        {
        "                                                                      ",
        "     aaaaaaaas                                                        ",
        "   aaaaaaaaaaass                             1.- HUMANO VS HUMANO     ",
        "   aa       aass                             2.- HUMANO VS CPU        ",
        "   aa       aass                                                      ",
        "   aa       aass                                                      ",
        "   aaaaaaaaaass                                                       ",
        "   aaaaaaaaas                                                         ",
        "   aass                                                               ",
        "   aass    aaaas    aaas   aas   aaaaas                               ",
        "   aass  aa    aas  aasas  aas  aa    as                              ",
        "   aass  aa    aas  aas as aas  aa                                    ",
        "   aass  aa    aas  aas  asaas  aa  aaaa                              ",
        "   aass  aa    aas  aas   aaas  aa    aas                             ",
        "   aass  aa    aas  aas    aas  aaaaaaaas                             ",
        "   aass    aaaas    aas    aas   aaaaa a                              ",

        };

        for (int i = 0; i < 18; i++) {

            for (int j = 0; j < 71; j++) {

                gotoxy(j+5, i+5);
                printf("%c", portada[i][j]);
            }
            
        }
    a = getch();
    for (int i = 0; i < 18; i++) {

        for (int j = 0; j < 71; j++) {

            gotoxy(j + 5, i + 5);
            printf(" ");
        }

    }
    }


};