#include "three_check.h"
#include "movegen.h"
#include "evaluate.h"
#include "position.h"

// Move generation for Three-Check
std::vector<Move> generateThreeCheckMoves(const Position& position) {
    return position.possibleMoves(); // Generate all possible moves
}

// Evaluation for Three-Check
int evaluateThreeCheck(const Position& position) {
    return position.getCheckCounter(WHITE) - position.getCheckCounter(BLACK);
}

// Logic to increment check counters
void incrementCheckCounter(Position& position, Color color) {
    if (position.isKingInCheck(color)) {
        position.incrementCheckCounter(color);
    }
}
