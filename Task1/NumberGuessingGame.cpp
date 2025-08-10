#include <iostream>
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()

using namespace std;

int main() {
    // Internship Project: Number Guessing Game
    // Author: Shivanshu Tiwari
    // Date: Aug 2025

    // Seeding random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generating a random number between 1 and 100
    int target = (rand() % 100) + 1;

    int userGuess = 0;
    int tries = 0;

    cout << "--------------------------------------\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "--------------------------------------\n";
    cout << "I have selected a number between 1 and 100.\n";
    cout << "Your job is to guess it!\n\n";

    // Loop until correct guess
    while (true) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Increment tries for each guess
        tries++;

        if (userGuess < target) {
            cout << "Hint: Your guess is too LOW.\n";
        } 
        else if (userGuess > target) {
            cout << "Hint: Your guess is too HIGH.\n";
        } 
        else {
            cout << "\n Congratulations! You guessed it right in " 
                 << tries << " attempts.\n";
            break; // Exit loop when correct guess
        }
    }

    cout << "Thanks for playing! Exiting game...\n";

    return 0;
}
