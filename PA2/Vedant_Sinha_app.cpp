#include <iostream>
#include <string>
#include <limits> 
#include "Vedant_Sinha_Die.h"


/**
 * @brief Manages a single turn for a player (computer or human).
 *
 * This function rolls two dice and adds their sum to the player's total score.
 * It also displays the roll results for the human player.
 *
 * @param die1 A reference to the first die object.
 * @param die2 A reference to the second die object.
 * @param score A reference to the player's current score to be updated.
 * @param isPlayer A boolean to indicate if the current turn is for the human player.
 */
void takeTurn(Die& die1, Die& die2, int& score, bool isPlayer);

/**
 * @brief Displays the final results of the game.
 *
 * This function reveals the computer's score and determines the winner based
 * on the game's rules.
 *
 * @param playerScore The final score of the human player.
 * @param computerScore The final score of the computer.
 */
void displayResults(int playerScore, int computerScore);

/**
 * @brief Clears the input buffer.
 *
 * This function is used to prevent issues with mixed cin types, particularly
 * after reading a char to ensure the newline character is consumed.
 */
void clearInputBuffer();


// --- Main Application Logic ---

int main() {
    const int MAX_SCORE = 21;

    // Comment 6: Here we are creating two instances (objects) of our Die class.
    // These two objects, die1 and die2, will be shared by both the player and
    // the computer throughout the game, as per the game's rules.
    Die die1(6);
    Die die2(6);

    int playerScore = 0;
    int computerScore = 0;
    char playerChoice;

    std::cout << "--- Welcome to Dice Blackjack (21)! ---\n";
    std::cout << "You and the computer will take turns rolling two six-sided dice.\n";
    std::cout << "Try to get as close to 21 as possible without going over.\n\n";

    // Comment 7: This is the computer's one and only turn. The takeTurn function is
    // called for the computer's score, but the 'isPlayer' flag is set to false
    // so that the results of its roll are not displayed to the user, keeping
    // the computer's total hidden until the end of the game.
    std::cout << "The computer is taking its turn...\n";
    takeTurn(die1, die2, computerScore, false);
    std::cout << "The computer's score is hidden.\n\n";


    // Comment 8: This do-while loop controls the player's turn. The loop will
    // continue to execute as long as the player enters 'y' to roll again and
    // their score has not exceeded the maximum of 21.
    do {
        std::cout << "Your current score is: " << playerScore << std::endl;
        std::cout << "Would you like to roll the dice? (y/n): ";
        std::cin >> playerChoice;
        clearInputBuffer(); // Clear the input buffer after reading the character

        if (tolower(playerChoice) == 'y') {
            takeTurn(die1, die2, playerScore, true);
        }

        // Check if player has gone over 21
        if (playerScore > MAX_SCORE) {
            std::cout << "\nOh no! Your score is " << playerScore << ". You have gone over 21!\n";
            break; // Exit the loop if the player busts
        }

    } while (tolower(playerChoice) == 'y');

    // --- Game Over and Results ---
    std::cout << "\n--- Game Over ---\n";
    displayResults(playerScore, computerScore);

    return 0;
}


// --- Function Implementations ---

// Comment 9: This function takes the score variable by reference (using the & symbol).
// This means the function receives the actual score variable from main, not a copy.
// Therefore, when we modify 'score' inside this function, the original
// playerScore or computerScore variable in main() is directly updated.
void takeTurn(Die& die1, Die& die2, int& score, bool isPlayer) {
    die1.roll();
    die2.roll();

    int roll1 = die1.getValue();
    int roll2 = die2.getValue();
    int turnTotal = roll1 + roll2;

    score += turnTotal;

    if (isPlayer) {
        std::cout << "You rolled a " << roll1 << " and a " << roll2 << " for a total of " << turnTotal << ".\n\n";
    }
}

// Comment 10: This function contains the final win/loss logic of the game. It uses a
// series of if-else if statements to check all possible outcomes, such as
// one or both players going over 21, or one player having a higher score
// than the other, and prints the appropriate result message.
void displayResults(int playerScore, int computerScore) {
    const int MAX_SCORE = 21;

    std::cout << "Your final score is: " << playerScore << std::endl;
    std::cout << "The computer's final score is: " << computerScore << std::endl;
    std::cout << "-----------------------------------\n";

    // Determine the winner
    bool playerBust = playerScore > MAX_SCORE;
    bool computerBust = computerScore > MAX_SCORE;

    if (playerBust && computerBust) {
        std::cout << "Both you and the computer went over 21. It's a draw!\n";
    } else if (playerBust) {
        std::cout << "You went over 21. The computer wins!\n";
    } else if (computerBust) {
        std::cout << "The computer went over 21. You win!\n";
    } else if (playerScore > computerScore) {
        std::cout << "Congratulations! You win!\n";
    } else if (computerScore > playerScore) {
        std::cout << "The computer wins. Better luck next time!\n";
    } else { // Scores are equal
        std::cout << "It's a tie! No one wins.\n";
    }
}

// Comment 11: This helper function is important for handling user input reliably.
// When you use `std::cin >> playerChoice;`, it reads the character but leaves the
// newline character (from pressing Enter) in the input buffer. This function
// clears that newline and any other extra characters to prevent issues in future inputs.
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
