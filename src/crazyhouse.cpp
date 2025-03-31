#include "crazyhouse.h"
#include "movegen.h"
#include "evaluate.h"
#include "position.h"

// Move generation for Crazyhouse
std::vector<Move> generateCrazyhouseMoves(const Position& position) {
    auto moves = position.possibleMoves(); // Generate normal moves
    for (auto piece : position.getHand()) {
        for (auto square : position.getEmptySquares()) {
            moves.push_back(Move::drop(piece, square)); // Add drop moves
        }
    }
    return moves;
}

// Evaluation for Crazyhouse
int evaluateCrazyhouse(const Position& position) {
    return position.materialValue() + position.handValue(); // Include hand material value
}
