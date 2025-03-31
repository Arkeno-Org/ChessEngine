#include "chess960.h"
#include "movegen.h"
#include "evaluate.h"
#include "position.h"

// Logic to initialize Chess960 position
void initializeChess960(Position& position) {
    // Randomize placement of bishops, knights, rooks, queen, and king
    int bishop1 = randomSquare(SQUARE_WHITE);
    int bishop2 = randomSquare(SQUARE_BLACK);
    std::vector<Square> positions = randomizePositions({bishop1, bishop2});
    position.setBackRank(positions);
}

// Move generation for Chess960
std::vector<Move> generateChess960Moves(const Position& position) {
    return position.possibleMoves(); // Generate moves like standard chess
}

// Evaluation for Chess960 (same as standard chess)
int evaluateChess960(const Position& position) {
    return position.materialValue();
}
