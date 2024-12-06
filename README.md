# Number Guessing Game with Bug Fixes and Clean Coding

## Overview

This is a simple number guessing game where the player tries to guess a randomly generated number between 1 and 100. The player will receive feedback after each guess, indicating whether the guess is too high, too low, or correct. After guessing the correct number, the player has the option to play again.

## Features
- The game generates a random number between 1 and 100 for each session.
- The player is given feedback on their guess (too high, too low, or correct).
- The game tracks the number of attempts it takes for the player to guess the correct number.
- After completing the game, the player is prompted to play again.

## Key Components

1. **`display_instructions()`**:
   - A function that introduces the game and explains the rules to the player.

2. **Random Number Generation**:
   - The program uses C++ function `srand(static_cast<unsigned int>(time(0)))` to generate a random number between 1 and 100 each time the game is played.

3. **Game Loop**:
   - The game runs in a `while` loop until the player guesses the correct number.
   
4. **Decision Making**:
   - `if-else` statements are used to provide feedback on the player's guess (too high, too low, or correct).
   
5. **Replay Option**:
   - After a successful guess, the player is asked whether they want to play again. If yes, the game restarts.

6. **Random Win Message**:
   - Upon winning a game, the program will congratulate the player with a random winning message.

7. **Score System**:
   - The score system will take the max amount of points a player can win (250) and divide it by the amount of attempts it took the player to guess.


## Initial Errors 

### Issue 1: Insufficient Documentiation

- Without proper documentation, a programmer that has not seen this code will have trouble deciphering each variable.

 **Code Snippet:**
```cpp
//No documentation
int main() {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    bool guessedCorrectly = false;
    char playAgain;
```

### Issue 2: Inefficient Replay Mechanism

- Directly calling main from within itself is generally considered a very bad programming practice as it can easily cause infinite loops and crash the program due to stack overflow

**Code Snippet:**
```cpp// Ask if the player wants to play again
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        // Restart game by recalling main (this should have a do loop preceding it instead of recalling main)
        main();
    } else {
        cout << "Thank you for playing!" << endl;
```
### Issue 3: Lack of Input Validation

   - The program lacks input validation for non-numeric inputs or guesses outside the valid range, which may result in unexpected behavior or endless loops.

   **Code Snippet:**
```cpp
while (!guessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> guess; 
	// Should include input validation
        attempts++;

    // Check the guess
        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            guessedCorrectly = true;
        }
    }
```
## Enhancements and Refactoring

### Enhancements

1. **Replay Mechanism**:

   - The previous method of recalling the main() function was replaced by a do-while loop to handle the replay functionality. This avoids potential issues like infinite recursion.

2. **Input Validation**:

   - Input validation was added to ensure the player can only input integers between 1 and 100, including some library functions from `<limits>` to complete the validation. If an invalid input is entered, the program will prompt the player to re-enter the guess.

3. **Global Score and Point System**

   - Created a global score variable and point system. The score system will take the max amount of points a player can win (250) and divide it by the amount of attempts it took the player to guess, points are totaled after play is done.

4. **Randomized Winning Message**

   - Upon winning a game, the program will congratulate the player including the library function <vector> to create a random winning message from an array of winning messages.
   
### Refactoring


1. **Modularized Code**:

   - The code was refactored into smaller functions to improve readability and maintainability. The main gameplay logic is now in separate functions (playGame(), generateRandomNumber(), getValidatedGuess()) to make it easier to manage.


2. **Game Instructions**:

   - The introductory message was updated to explicitly state that both 1 and 100 are valid guesses.

3. **Clear Screen**:

   - The system("cls") command was added to clear the screen when the player chooses to replay the game.

## Code Snippets
Here are some key code snippets to demonstrate the changes:
1. **New Replay**
```cpp
// Better replay mechanic
do { 
        playGame();

        // Ask the player if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        system("cls"); // Clears the screen
    } while (playAgain == 'y' || playAgain == 'Y');
```
2. **Random Number Generation**
```cpp
// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1; 
}
```
3. **Input Validation**

```cpp
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
```
4. **Game Loop**
```cpp
// Function to play the guessing game
void playGame() {
    int randomNumber = generateRandomNumber(); // Generates random number between 0 and 100
    int attempts = 0; // The number of attempts to guess random number
    bool guessedCorrectly = false; // Bool to check loop until guess matches random number

    displayInstructions();

    while (!guessedCorrectly) {
        int guess = getValidatedGuess();
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
```
5. **Main Function and Replay Mechanisim**

```cpp
// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    char playAgain;

    do { // Better replay mechanic
        playGame();

        // Ask the player if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        system("clear"); // Clears the screen
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;
    return 0;
}
```

6. **Library functions added and Global Variable Initialized**

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // For library functions
#include <vector>// For vector function
using namespace std;

int globalScore; // global variable for the score

```

7. **Random winning message**

```cpp
// Returns a random winning message to the player
string randomWinMessage(){
    srand(time(0));

    // random message enum
    vector<string> messages = {
        "Nice!",
        "Good Job!",
        "Awesome!",
        "Super!",
        "You rock!",
        "Congratulations!"
    };

    // generates random number based on index size
    int randomMessageIndex = rand() % messages.size();

    return messages[randomMessageIndex];
}
```

8. **Point System using Global Variable**
   
```cpp
 // Point system: 250 / total attempts
int pointSystem(int attempts) {
    int maxPoints = 250;
    int pointsToAdd = maxPoints / attempts;

    globalScore = globalScore + pointsToAdd;

    return pointsToAdd;
}
```
9. **Function to return total score added up in Global Variable**
```cpp
// Returns total score
int getTotalScore(){
    return globalScore;
}
```

## Known Issues

   - Potential Screen Clear Improvement: The system("cls") function works on Windows but may not function as expected on other operating systems. A cross-platform solution for clearing the screen could be implemented in future versions.

   - Edge Case Handling: While input validation is now present, handling edge cases like spaces could still be improved further.

## Future Improvements

   - Cross-platform Compatibility: The code could be enhanced to work more reliably across different platforms (e.g., using a better clear function.

  - Difficulty Levels: Future updates could introduce different difficulty levels (e.g., changing the range of numbers to guess from).




