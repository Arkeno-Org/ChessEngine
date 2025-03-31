#include "movegen.h"

std::vector<Move> generateMoves(const Position& position, Variant variant) {
    switch (variant) {
        case STANDARD:
            return generateStandardMoves(position);
        case CHESS960:
            return generateStandardMoves(position); // Same as standard
        case RACING_KINGS:
            return generateRacingKingsMoves(position);
        case CRAZYHOUSE:
            return generateCrazyhouseMoves(position);
        case ANTICHESS:
            return generateAntichessMoves(position);
        case THREE_CHECK:
            return generateThreeCheckMoves(position);
    }
    return {};
}

std::vector<Move> generateRacingKingsMoves(const Position& position) {
    // Generate moves prioritizing king movement
    return position.possibleMoves();
}

std::vector<Move> generateCrazyhouseMoves(const Position& position) {
    auto moves = position.possibleMoves();
    for (auto piece : position.getHand()) {
        for (auto square : position.getEmptySquares()) {
            moves.push_back(Move::drop(piece, square));
        }
    }
    return moves;
}

std::vector<Move> generateAntichessMoves(const Position& position) {
    auto moves = position.captureMoves();
    if (moves.empty()) {
        moves = position.possibleMoves();
    }
    return moves;
}

std::vector<Move> generateThreeCheckMoves(const Position& position) {
    return position.possibleMoves(); // Add logic to track checks separately
}
