#ifndef EVALUATE_H
#define EVALUATE_H

#include "position.h"

int evaluatePosition(const Position& position, Variant variant);
int evaluateStandard(const Position& position);
int evaluateRacingKings(const Position& position);
int evaluateCrazyhouse(const Position& position);
int evaluateAntichess(const Position& position);
int evaluateThreeCheck(const Position& position);

#endif
