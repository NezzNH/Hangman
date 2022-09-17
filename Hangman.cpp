#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
using namespace std;



int main () {
    bool prevGuessed = false;
    bool won = false;
    bool lost = false;
    int gameWon = 0;
    int gameLost = 0;
    int i2;
    int bannedLettersCounter = 0;
    char discovered[10];
    char bannedLetters[6];
    char easyWords[][10] = {

        {"apple"},
        {"pear"},
        {"chair"},
        {"coding"},
        {"this"},
        {"america"},
        {"canada"},
        {"africa"},
        {"pencil"},
        {"pen"},
        {"cool"},
        {"sans"},
        {"cheats"}

    };
    char mediumWords[][15] = {

        {"gravitational"},
        {"forceful"},
        {"programmed"},
        {"displayed"},
        {"document"},
        {"elizabeth"},
        {"validate"},
        {"leaving"}

    };
    char hardWords[][20] = {
        {"phenomenon"},
        {"onomatopeia"},
        {"worcestershire"},
        {"colonel"},
        {"draught"},
        {"quinoa"},
        {"anemone"}
    };
    char a;
    char filler;
    int guessedLength=0;
    char letter;
    bool guessed;
    int difficulty;
    int lives = 6;
    int i;
    int phraseLength = 0;
    char phrase[20];
    bool validInput = false;
    while (1) {
        i=0;
        while (validInput != true) {
            if (gameWon > 0 || gameLost > 0) {
                system("CLS");
                cout << "Scores:    Won: " << gameWon << endl;
                cout << "          Lost: " << gameLost << endl;
            }
            cout << "Hangman:" << endl;
            cout << "1. Play" << endl;
            cout << "2. Credits" << endl;
            cout << "Please type a number: ";
            cin >> a;
            switch (a) {
                case '1':
                validInput = true;
                system("CLS");
                break;

                case '2':
                system("CLS");
                validInput = false;
                break;

                default:
                validInput = false;
                system("CLS");
                break;
            }
        }
        validInput = false;
        a = '0';
            while (validInput != true) {
            cout << "Please pick a difficulty:" << endl;
            cout << "1. Easy" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Hard" << endl;
            cin >> a;
            switch (a) {

                case '1':
                validInput = true;
                i2 = rand() % 13;
                for (i=0;easyWords[i2][i] != '\0';i++) {
                    phrase[i] = easyWords[i2][i];
                    phraseLength++;
                }
                break;

                case '2':
                validInput = true;
                i2 = rand() % 8;
                for (i=0;mediumWords[i2][i] != '\0';i++) {
                    phrase[i] = mediumWords[i2][i];
                    phraseLength++;
                }
                break;

                case '3':
                validInput = true;
                break;
                i2 = rand() % 7;
                for (i=0;hardWords[i2][i] != '\0';i++) {
                    phrase[i] = hardWords[i2][i];
                    phraseLength++;
                }
                default:
                a = '0';
                system("CLS");
                cout << "Wrong Input! Try again!" << endl;
                cout << endl;
                break;

            }
        
        }
        const int guessedLetterSize = phraseLength;
        int guessedLetterPosition[guessedLetterSize];
        for (i=0;i<phraseLength;i++) {
            guessedLetterPosition[i] = 0;
        }
            while (1) {
                guessed = false;
                system("CLS");
                cout << "Last Letter: " << letter << endl;
                cout << "Lives: " << lives << endl;
                for (i=0;i<phraseLength;i++) {
                    cout << "_ ";
                }

                cout << "        Banned Letters:";

                for (i=0;i<bannedLettersCounter;i++) {
                    cout << "" << bannedLetters[i];
                }

                cout << endl;

                for (i=0;i<phraseLength;i++) {
                    if (guessedLetterPosition[i] == 1) {
                        cout << "" << discovered[i] << " ";
                    }
                    else {
                        cout << "  ";
                    }
                }

                cout << endl;

                cout << "Input a letter:";
                cin >> letter;
                if (letter >= 0x41 && letter <= 0x5A) {
                    
                }

                for (i=0;i<=phraseLength;i++) {
                    if (letter == phrase[i]) {
                        discovered[i] = letter;
                        guessed = true;
                        guessedLetterPosition[i] = 1;
                        guessedLength++;
                    }
                }

                if (guessed == false) {
                    for (i=0;i<=bannedLettersCounter;i++) {
                        if (letter == bannedLetters[i]) {
                            prevGuessed = true;
                        }
                    }
                    if (prevGuessed == false) {
                        lives--;
                        bannedLetters[bannedLettersCounter] = letter; 
                        bannedLettersCounter++;
                    }
                }

                if (lives <= 0) {
                    lost = true;
                    gameLost++;
                    break;
                }

                if (guessedLength == phraseLength) {
                    won = true;
                    gameWon++;
                    break;
                }
                prevGuessed = false;
            }
        validInput = false;
        lives = 6;
        a = 0;
        bannedLettersCounter = 0;
        bannedLetters[6];
        guessedLength = 0;
        system("CLS");
        if (lost == true) {     
            cout << "YOU'VE LOST" << endl;
            cout << "The word was: ";
            for (i=0;i<phraseLength;i++) {
                cout << "" << phrase[i];
            }
            cout << endl;
            phraseLength = 0;
            cout << "1. Go Back To Menu" << endl;
            cout << "2. Exit" << endl;
            cin >> filler;
            lost = false;
            if (filler == '2') {
                filler = '0';
                break;
            }
            else {
                continue;
            }

        }
        else {
            cout << "YOU'VE WON!" << endl;
            cout << "Where's the confetti? Why this is a terminal program of course!" << endl;
            cout << "1. Go Back To Menu" << endl;
            cout << "2. Exit" << endl;
            cin >> filler;
            won = false;
            if (filler == '2') {
                filler = '0';
                break;
            }
            else {
                continue;
            }
        }
    }
}