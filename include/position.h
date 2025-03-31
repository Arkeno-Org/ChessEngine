#ifndef POSITION_H
#define POSITION_H

#include <vector>
#include <string>
#include "move.h"

enum Color { WHITE, BLACK };
enum SquareType { EMPTY, OCCUPIED };
enum Variant { STANDARD, CHESS960, RACING_KINGS, CRAZYHOUSE, ANTICHESS, THREE_CHECK };

class Position {
public:
    Position(); // Constructor to initialize the position
    void initializeVariant(Variant variant); // Set up the board for the selected variant

    std::vector<Move> possibleMoves() const; // Generate all possible moves
    std::vector<Move> captureMoves() const; // Generate mandatory capture moves (e.g., for Antichess)
    std::vector<Square> getEmptySquares() const; // Retrieve all empty squares on the board

    bool makeMove(const Move& move); // Apply a move to the position
    bool isKingInCheck(Color color) const; // Check if the king is in check
    bool isGameOver() const; // Determine if the game is over

    int materialValue() const; // Evaluate the material score
    int handValue() const; // Evaluate the hand score for Crazyhouse

    Square getKing(Color color) const; // Get the position of the king for Racing Kings
    int getCheckCounter(Color color) const; // Get the check counter for Three-Check
    void incrementCheckCounter(Color color); // Increment the check counter

    void setBackRank(const std::vector<Square>& positions); // Set Chess960 back rank
    std::string toString() const; // Convert the position to a string representation (for debugging purposes)

private:
    // Board state representation
    Square board[8][8]; // 8x8 board representation
    int checkCounter[2]; // Tracks checks for WHITE and BLACK (used for Three-Check)

    void initializeStandard(); // Standard chess setup
    void initializeChess960(); // Randomized setup for Chess960
    void initializeCrazyhouse(); // Initialize Crazyhouse logic
};

#endif
