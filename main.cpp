#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "CustomStack.h"
#include "CustomQueue.h"
 
#define MAX_HEALTH 100
#define HEALTH 5
#define GUESS_IT_UNTIL_END_ROUND 5

// DEFINISIKAN VARIABLE ANGKA YANG AKAN DIGUNAKAN AGAR LEBIH MUDAH DIBACA
#define SCISSORS 1
#define ROCK 2
#define PAPER 3

#define START_GAME 1
#define EXIT_GAME 2

#define GAME_MENU_NORMAL 1
#define GAME_MENU_GUESS_IT_UNTIL_END 2
#define GAME_MENU_SPESIAL_NORMAL 3
#define GAME_MENU_SPESIAL_GUESS_IT_UNTIL_END 4
#define GAME_MENU_EXIT 5

#define WIN 1
#define LOSE 2
#define DRAW 3
#define ERROR 4
 
using namespace std;

struct CompareResult {
	int isPlayerWin;
	string playerChoice;
	string botChoice;
};

CompareResult compareChoices(int playerChoice, int botChoice) {
	CompareResult output;
	
	if (botChoice == SCISSORS) {
    	output.botChoice = "Scissors";
    } else if (botChoice == ROCK) {
    	output.botChoice = "Rock";
    } else if (botChoice == PAPER) {
    	output.botChoice = "Paper";
    }
    
	switch (playerChoice) {
	    case SCISSORS:
	        output.playerChoice = "Scissors";
	        if (botChoice == SCISSORS) {
	            output.isPlayerWin = DRAW;
	        } else if (botChoice == ROCK) {
	            output.isPlayerWin = LOSE;
	        } else if (botChoice == PAPER) {
	            output.isPlayerWin = WIN;
	        } else {
	            output.isPlayerWin = ERROR;
	        }
	    	break;
	
	    case ROCK:
	        output.playerChoice = "Rock";
	        if (botChoice == SCISSORS) {
	            output.isPlayerWin = WIN;
	        } else if (botChoice == ROCK) {
	            output.isPlayerWin = DRAW;
	        } else if (botChoice == PAPER) {
	            output.isPlayerWin = LOSE;
	        } else {
	            output.isPlayerWin = ERROR;
	        }
	    	break;
	
	    case PAPER:
	        output.playerChoice = "Paper";
	        if (botChoice == SCISSORS) {
	            output.isPlayerWin = LOSE;
	        } else if (botChoice == ROCK) {
	            output.isPlayerWin = WIN;
	        } else if (botChoice == PAPER) {
	            output.isPlayerWin = DRAW;
	        } else {
	            output.isPlayerWin = ERROR;
	        }
	    	break;
	
	    default:
			output.isPlayerWin = ERROR;
	}
			
	return output;
}

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

void normalGame() {
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
		do {
			cout << "Please choose: "; cin >> pil;
		} while (pil < SCISSORS || pil > PAPER);
		
		CompareResult compareResult = compareChoices(pil, acak);
		cout << "You choose: " << compareResult.playerChoice << endl;
		cout << "Bot choose: " << compareResult.botChoice << endl;
		
		if (compareResult.isPlayerWin == WIN) {
			cout << "-- Wow, you defeat BOT!" <<endl;
			darahBot.pop();
		} else if (compareResult.isPlayerWin == LOSE) {
			cout << "-- Oops haha, BOT win! Don't give up!' --" << endl;
			darahPemain.pop();
		} else {
			cout << "-- DRAW --" <<endl;
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

void guessItUntilEndGame() {
	system("cls");
	cout << "Choose it for " << GUESS_IT_UNTIL_END_ROUND << " times" << endl;
	
    srand(time(0));
    
    CustomQueue<int> pilihanBot(GUESS_IT_UNTIL_END_ROUND);
    for (int i = 0; i < GUESS_IT_UNTIL_END_ROUND; i++) {
    	int acak = rand() % 3 + 1;
    	pilihanBot.enqueue(acak);
	}
	
    cout << endl;
    cout << "1. Scissors" << endl;
    cout << "2. Rock" << endl;
    cout << "3. Paper" << endl;
    cout << endl;
    
    CustomQueue<int> pilihanPemain(GUESS_IT_UNTIL_END_ROUND);
    for (int i = 0; i < GUESS_IT_UNTIL_END_ROUND; i++) {
    	int pilihan;
    	do {
			cout << "Choice " << i + 1 << ": "; cin >> pilihan;
		} while (pilihan < SCISSORS || pilihan > PAPER);
		pilihanPemain.enqueue(pilihan);
	}
	cout << endl;
	
	int playerScore = 0;
	int botScore = 0;
	for (int i = 0; i < GUESS_IT_UNTIL_END_ROUND; i++) {
		int pilihanPemainNow = pilihanPemain.dequeue();
		int pilihanBotNow = pilihanBot.dequeue();
		CompareResult compareResult = compareChoices(pilihanPemainNow, pilihanBotNow);
		string winStatus;
		if (compareResult.isPlayerWin == WIN) {
			winStatus = "Win";
			playerScore++;
		} else if (compareResult.isPlayerWin == LOSE) {
			winStatus = "Lose";
			botScore++;
		} else {
			winStatus = "Draw";
		}
		
    	cout << "Fight " << i + 1 <<": ";
    	cout << compareResult.playerChoice;
    	cout << " vs ";
    	cout << compareResult.botChoice;
    	cout << " (" << winStatus << ")";
    	cout << endl;
	}
	
	cout << endl;
	cout << "Score: ";
	cout << playerScore;
	cout << " vs ";
	cout << botScore;
	cout << endl;
	
	if (playerScore > botScore) {
		cout << "YOU WIN!";
	} else if (playerScore < botScore) {
		cout << "YOU LOSE!";
	} else {
		cout << "DRAW!";
	}
	
	cout << endl << endl;
	
	system("pause");
}

void gameMenu() {
	bool ulang = true;
	do {
		system("cls");
		cout << "Choose your game mode:" << endl;
		cout << "1. Normal" << endl;
		cout << "2. Guess It Until End" << endl;
		cout << "3. Spesial (Normal)" << endl;
		cout << "4. Spesial (Guess It Until End)" << endl;
		cout << "5. Back" << endl;
		
		int gameMenu;
		cout << "Please choose: "; cin >> gameMenu;
		
		switch (gameMenu) {
			case GAME_MENU_NORMAL:
				normalGame();
				break;
			case GAME_MENU_GUESS_IT_UNTIL_END:
				guessItUntilEndGame();
				break;
			case GAME_MENU_EXIT:
				ulang = false;
		}
	} while (ulang);
}

void mainMenu() {
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
				gameMenu();
            break;
 
            case EXIT_GAME:
                ulang = false;
                cout << "Game will close shortly..." << endl;
            break;
        }
    } while (ulang);
}

int main(int argc, char** argv) {
	mainMenu();
}
