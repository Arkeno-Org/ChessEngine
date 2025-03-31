#include "antichess.h"
#include "movegen.h"
#include "evaluate.h"
#include "position.h"

// Move generation for Antichess
std::vector<Move> generateAntichessMoves(const Position& position) {
    auto moves = position.captureMoves(); // Generate capture moves
    if (moves.empty()) {
        moves = position.possibleMoves(); // If no captures, generate all possible moves
    }
    return moves;
}

// Evaluation for Antichess
int evaluateAntichess(const Position& position) {
    return -position.materialValue(); // Negative score rewards losing pieces
}
