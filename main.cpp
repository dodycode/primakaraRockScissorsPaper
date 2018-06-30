#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "CustomStack.h"
 
#define MAX_HEALTH 100
#define HEALTH 5

// DEFINISIKAN VARIABLE ANGKA YANG AKAN DIGUNAKAN AGAR LEBIH MUDAH DIBACA
#define SCISSORS 1
#define ROCK 2
#define PAPER 3

#define START_GAME 1
#define EXIT_GAME 2
 
using namespace std;

void tampilStackDarah(CustomStack<string> darahPemain, CustomStack<string> darahBot) {
    // Munculkan status darah
    cout << "Your health: ";
    while (!darahPemain.isEmpty()) {
        cout << " " << darahPemain.getTop() << " ";
        darahPemain.pop();
    }
    cout << endl;
 
    cout << "BOT Health: ";
    while (!darahBot.isEmpty()) {
        cout << " " << darahBot.getTop() << " ";
        darahBot.pop();
    }
    cout << endl;
}

void play() {
	CustomStack<string> darahPemain(MAX_HEALTH);
	CustomStack<string> darahBot(MAX_HEALTH);
 
    // Inisialisasi darah
    for (int i = 0; i < HEALTH; i++) {
    	darahPemain.push("*");
    	darahBot.push("*");
	}
 
    srand(time(0));
    int round = 0;
 
    while (!darahPemain.isEmpty() && !darahBot.isEmpty()){
        system("cls");
        tampilStackDarah(darahPemain, darahBot);
        round++;
        int acak = rand() % 3 + 1;
        cout << endl;
        cout << "Round: " << round << endl;
        cout << "1. Scissors" << endl;
        cout << "2. Rock" << endl;
        cout << "3. Paper" << endl;
        
		int pil;
        cout << "Please choose: "; cin >> pil;
        switch (pil) {
            case SCISSORS:
                cout << "You choose: Scissors" << endl;
                if (acak == SCISSORS) {
                    cout << "Bot choose: Scissors" << endl;
                    cout << "-- DRAW --" <<endl;
                } else if (acak == ROCK) {
                    cout << "Bot choose: Rock" << endl;
                    cout << "-- Oops haha, BOT win! Don't give up!' --" << endl;
                    if (!darahPemain.isEmpty()) {
                        // Kurangi darah pemain
                        darahPemain.pop();
                    } else {
						break;
                    }
                } else if (acak == PAPER) {
                    cout << "Bot choose: Paper" << endl;
                    cout << "-- Wow, you defeat BOT!" <<endl;
                    if (!darahBot.isEmpty()) {
                        // Kurangi darah bot
                        darahBot.pop();
                    } else {
                        break;
                    }
                } else {
                    cout << "Oops, something went wrong!" << endl;
                }
            break;
 
            case ROCK:
                cout << "You choose: Rock" << endl;
                if (acak == SCISSORS) {
                    cout << "Bot choose: Scissors" << endl;
                    cout << "-- Wow, you defeat BOT! --" << endl;
                    if (!darahBot.isEmpty()) {
                        // Kurangi darah bot
                        darahBot.pop();
                    } else {
                        break;
                    }
                } else if (acak == ROCK) {
                    cout << "Bot choose: Rock" << endl;
                    cout << "-- DRAW --" << endl;
                } else if (acak == PAPER) {
                    cout << "Bot choose: Paper" << endl;
                    cout << "-- Oops haha, BOT win! Don't give up!' --" << endl;
                    if (!darahPemain.isEmpty()) {
                        // Kurangi darah pemain
                        darahPemain.pop();
                    } else {
                        break;
                    }
                } else {
                    cout << "Oops, something went wrong!" << endl;
                }
            break;
 
            case PAPER:
                cout << "You choose: Paper" << endl;
                if (acak == SCISSORS) {
                    cout << "Bot choose: Scissors" << endl;
                    cout << "-- Oops haha, BOT win! Don't give up!' --" << endl;
                    if (!darahPemain.isEmpty()) {
                        // Kurangi darah pemain
                        darahPemain.pop();
                    } else {
                        break;
                    }
                } else if (acak == ROCK) {
                    cout << "Bot choose: Rock" << endl;
                    cout << "-- Wow! You defeat BOT! --" << endl;
                    if (!darahBot.isEmpty()) {
                        // Kurangi darah bot
                        darahBot.pop();
                    } else {
                        break;
                    }
                } else if (acak == PAPER) {
                    cout << "Bot choose: Paper" << endl;
                    cout << "-- DRAW --" << endl;
                } else {
                    cout << "Oops, something went wrong!" << endl;
                }
            break;
 
            default:
				cout << "Please choose correctly! " << endl;
				
            system("pause");
        }
        system("pause");
    }
    
    // Setelah game selesai, keluarkan pesan
    cout << endl;
    if (darahPemain.isEmpty()) {
        cout << "Game over!" << endl;
    } else if (darahBot.isEmpty()) {
        cout << "Congrats! You're win!" << endl;
    } else {
        cout << "Oops! something went wrong!" << endl;
    }
    system("pause");
}

int main(int argc, char** argv) {
	bool ulang = true;
    do {
        system("cls");
        cout << "=============== Primakara Scissors, Rock and Paper ==================" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Exit Game" << endl;
        
		int menu;
        cout << "Please choose: "; cin >> menu;
        switch (menu) {
            case START_GAME:
                // Jalankan permainan
                play();
            break;
 
            case EXIT_GAME:
                ulang = false;
                cout << "Game will close shortly..." << endl;
            break;
        }
    } while (ulang);
}
