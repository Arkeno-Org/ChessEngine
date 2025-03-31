#ifndef MOVEGEN_H
#define MOVEGEN_H

#include "position.h"

std::vector<Move> generateMoves(const Position& position, Variant variant);
std::vector<Move> generateAntichessMoves(const Position& position);
std::vector<Move> generateThreeCheckMoves(const Position& position);
std::vector<Move> generateRacingKingsMoves(const Position& position);

#endif
