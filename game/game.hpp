#include <iostream>
#include "../random-cpp/random/randint.hpp"




class Casino { 
    private:
        int wallet;
    
    public:
        int bet;
        
        // easy
        int easy_number = randNum(0, 20);
        int easy_hint = randNum(0, easy_number);
        int easy_guess;
        
        // medium 
        int medium_number = randNum(0, 50);
        int medium_hint = randNum(0, medium_number);
        int medium_guess;

        // hard
        int hard_number = randNum(0, 70);
        int hard_hint = randNum(0, hard_number);
        int hard_guess;

        // extreme
        int extreme_number = randNum(0, 100);
        int extreme_hint = randNum(0, extreme_number);
        int extreme_guess;

        Casino() {
            wallet = 200;
        }
        
        /* Difficulty games */
        void easy() {
            std::cout << "How much do you bet?: ";
            std::cin >> bet;

            while (bet > wallet or bet <= 0) {
                std::cout << "You cannot do that!\n";
                std::cout << "How much do you bet?: ";
                std::cin >> bet;
                if (bet <= wallet and bet <= 0) {
                    break;
                    continue_easy();
                } else {
                    continue;
                }
            } while (bet <= wallet and bet > 0) {
                continue_easy();
                break;
            }
        }
        void continue_easy() {
            wallet -= bet;
            std::cout << "Hint number is: " << easy_hint << "\n";
            std::cout << "Guess the number!: ";
            std::cin >> easy_guess;   
            if (easy_guess == easy_number) {
                wallet = wallet + (bet * 2);
                std::cout << "Congratulations!\n";
                std::cout << "Your wallet is now " << wallet << "\n";
            } else {
                std::cout << "You lost!\n";
                std::cout << "Your wallet is now " << wallet << " and you lost " << bet << " amount of money\n";
            }
        }
        void medium() {
            std::cout << "How much do you bet?: ";
            std::cin >> bet;
            while (bet > wallet or bet <= 0) {
                std::cout << "You cannot do that!\n";
                std::cout << "How much do you bet?: ";
                std::cin >> bet; 
                if (bet <= wallet and bet > 0) {
                    break;
                    continue_medium();
                } else {
                    continue;
                }
            } while (bet <= wallet and bet > 0) {
                break;
                continue_medium();
            }
        }
        void continue_medium() {
            wallet -= bet;
            std::cout << "Hint number is: " << medium_hint << "\n";
            std::cout << "Guess the number!: ";
            std::cout << medium_guess;
            if (medium_guess == medium_number) {
                std::cout << "Congratulations!\n";
                wallet = wallet + (bet * 2);
                std::cout << "Your wallet is now " << wallet << "\n";
            
            } else {
                std::cout << "You lost!\n";
                std::cout << "Your wallet is now " << wallet << "\n";
            }
        }

        void hard() {
            std::cout << "How much do you bet?: ";
            std::cin >> bet;  
            while (wallet < bet or bet <= 0) {
                std::cout << "You cannot do that!\n";
                std::cout << "How much do you bet?: ";
                if (wallet >= bet and bet > 0) {
                    break;
                    continue_hard();
                } else {
                    continue;
                }
            } while (wallet >= bet and bet > 0) {
                break;
                continue_hard();
            }
        }
        void continue_hard() {
            wallet -= bet;
            std::cout << "Hint number is: " << hard_hint << "\n";
            std::cout << "Guess the number!: ";
            std::cin >> hard_guess;
            if (hard_number == hard_guess) {
                std::cout << "Congratulations!\n";
                wallet = wallet + (bet * 2);
                std::cout << "Your wallet is now " << wallet << "\n";
            } else {
                std::cout << "You lost!\n";
                std::cout << "Your wallet is now " << wallet << "\n";
            }
        }
        void extreme() {
            std::cout << "How much do you bet?: "; 
            std::cin >> bet;  
            while (bet > wallet or bet <= 0) {
                std::cout << "You cannot do that!\n";
                std::cout << "How much do you bet?: ";
                std::cin >> bet;
                if (bet > 0 and bet < wallet) {
                    break;
                    continue_extreme();
                } else {
                    continue;
                }
            } while (bet < wallet and bet > 0) {
                break;
                continue_extreme();
            }
        }
        void continue_extreme() {
            wallet -= bet; 
            std::cout << "Hint number is: " << extreme_hint; 
            std::cout << "Guess the number!: ";
            std::cin >> extreme_guess;
            if (extreme_guess == extreme_number) {
                std::cout << "Congratulations!\n";
                wallet = wallet + (bet * 2);
                std::cout << "Your wallet is now " << wallet << "\n";
            } else {
                std::cout << "You lost!\n";
                std::cout << "Your wallet is now " << wallet << "\n"; 
            }
        }
};
