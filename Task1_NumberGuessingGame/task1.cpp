#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator
    int secretNumber = rand() % 100 + 1;  // Random number between 1 and 100
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a number between 1 and 100. Try to guess it!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
// End of the Number Guessing Game program