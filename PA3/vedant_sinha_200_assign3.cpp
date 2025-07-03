#include <iostream>
#include <iomanip> // For formatting currency output (setprecision, fixed)
#include <string>
#include "vedant_sinha_coin.h"  // Include the Coin class definition


/**
 * @brief Simulates one round of tossing for a player.
 * @param quarter The quarter Coin object.
 * @param dime The dime Coin object.
 * @param nickel The nickel Coin object.
 * @return The total value earned from heads in this round.
 */
double runRound(Coin& quarter, Coin& dime, Coin& nickel);

/**
 * @brief Displays the current balances of the player and computer.
 * @param playerBalance The player's current balance.
 * @param computerBalance The computer's current balance.
 */
void displayBalances(double playerBalance, double computerBalance);

/**
 * @brief Determines and prints the winner based on the final balances.
 * @param playerBalance The player's final balance.
 * @param computerBalance The computer's final balance.
 */
void determineWinner(double playerBalance, double computerBalance);


// ----- Main Function -----

int main() {
    // Seed the random number generator. This should only be done ONCE.
    srand(static_cast<unsigned int>(time(0)));

    // Set up cout to display currency values
    std::cout << std::fixed << std::setprecision(2);

    // Create the three coin objects
    Coin quarter;
    Coin dime;
    Coin nickel;

    // Initialize balances
    double playerBalance = 0.0;
    double computerBalance = 0.0;
    int roundNumber = 1;

    // Display starting balances
    std::cout << "Starting Balances:" << std::endl;
    displayBalances(playerBalance, computerBalance);

    // Game loop: continues as long as NO player has reached $1.00
    while (playerBalance < 1.00 && computerBalance < 1.00) {
        std::cout << "\n----- Round " << roundNumber++ << " -----" << std::endl;

        // Player's turn
        double playerWinnings = runRound(quarter, dime, nickel);
        playerBalance += playerWinnings;

        // Computer's turn
        double computerWinnings = runRound(quarter, dime, nickel);
        computerBalance += computerWinnings;

        // Display current balances after the round
        std::cout << "Round Balances:" << std::endl;
        displayBalances(playerBalance, computerBalance);
    }

    // Display final results
    std::cout << "\n----- GAME OVER -----" << std::endl;
    std::cout << "Final Balances:" << std::endl;
    displayBalances(playerBalance, computerBalance);

    // Determine and announce the winner
    determineWinner(playerBalance, computerBalance);

    return 0;
}


// ----- Function Implementations -----

double runRound(Coin& quarter, Coin& dime, Coin& nickel) {
    double roundTotal = 0.0;

    // Toss and check the quarter
    quarter.toss();
    if (quarter.getSideUp() == "heads") {
        roundTotal += 0.25;
    }

    // Toss and check the dime
    dime.toss();
    if (dime.getSideUp() == "heads") {
        roundTotal += 0.10;
    }

    // Toss and check the nickel
    nickel.toss();
    if (nickel.getSideUp() == "heads") {
        roundTotal += 0.05;
    }

    return roundTotal;
}

void displayBalances(double playerBalance, double computerBalance) {
    std::cout << "Player: $" << playerBalance << std::endl;
    std::cout << "Computer: $" << computerBalance << std::endl;
}

void determineWinner(double playerBalance, double computerBalance) {
    std::cout << "\nOutcome: ";
    // Case 1: Both players are at or over $1.00
    if (playerBalance >= 1.00 && computerBalance >= 1.00) {
        if (playerBalance == computerBalance) {
            std::cout << "It's a tie!" << std::endl;
        } else if (playerBalance < computerBalance) {
            std::cout << "Player wins! (Lower score wins when both are over $1.00)" << std::endl;
        } else {
            std::cout << "Computer wins! (Lower score wins when both are over $1.00)" << std::endl;
        }
    }
    // Case 2: Only the player is at or over $1.00
    else if (playerBalance >= 1.00) {
        std::cout << "Player wins!" << std::endl;
    }
    // Case 3: Only the computer is at or over $1.00
    else if (computerBalance >= 1.00) {
        std::cout << "Computer wins!" << std::endl;
    }
}