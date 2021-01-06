#include <iostream>
#include "./game/game.hpp"


enum difficulties_number {
    Easy=1,
    Medium=2,
    Hard=3,
    Extreme=4
};


int main() {
    /* Initializing classes, enums, creating variables */
    bool running = true;
    int tries = 0;
    Casino casino;
    char choice;
    int choice_difficulty;
    difficulties_number difficulties_number;
    
    // beginning of the game
    while (running) { 
        if (tries == 0) {
            std::cout << "Would you like to play? [y/n]: ";
        } else {
            std::cout << "Would you like to play again? [y/n]: ";
        }
        std::cin >> choice;
        if (choice == 'y') {
            tries++;
            std::cout << "What difficulty would you like to choose?\nDifficulties are: 1 (Easy), 2 (Medium), 3 (Hard), 4 (Extreme)\n";
            std::cin >> choice_difficulty;
            switch (choice_difficulty) {
                case Easy:
                    casino.easy();
                    break;
                case Medium:
                    casino.medium();
                    break;
                case Hard:
                    casino.hard();
                    break;
                case Extreme:
                    casino.extreme();
                    break;
                }
        } else {
            return 0;
        }
    }
}
