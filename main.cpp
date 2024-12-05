#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // For library functions

using namespace std;

// Function to display instructions to the player
void displayInstructions() {
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Try to guess the number from 1 to 100." << endl;
}

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1; 
}

// Function to validate the user's input
int getValidatedGuess() {
    int guess; // Inputted guess to see if guess matches random number
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (!cin.fail() && guess >= 1 && guess <= 100) {
            return guess;
        }

        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input! Please enter a number between 1 and 100." << endl;
    }
}

// Function to play the guessing game
void playGame() {
    int randomNumber = generateRandomNumber(); // Generates random number between 0 and 100
    int attempts = 0; // The number of attempts to guess random number
    bool guessedCorrectly = false; // Bool to check loop until guess matches random number

    displayInstructions(); // Calls void function to introduce game

    while (!guessedCorrectly) {
        int guess = getValidatedGuess(); // Calls function to get a valid guess
        attempts++; 

        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            guessedCorrectly = true;
        }
    }
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    char playAgain;

    do {
        playGame(); // Calls void function to play game

        // Ask the player if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        system("cls"); // Clears the screen
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;
    return 0;
}
