#include "racing_kings.h"
#include "movegen.h"
#include "evaluate.h"
#include "position.h"

// Move generation for Racing Kings
std::vector<Move> generateRacingKingsMoves(const Position& position) {
    return position.possibleMoves(); // Generate normal moves
}

// Evaluation for Racing Kings
int evaluateRacingKings(const Position& position) {
    return distanceToEighthRank(position.getKing(WHITE)) -
           distanceToEighthRank(position.getKing(BLACK)); // Reward progress toward the eighth rank
}
