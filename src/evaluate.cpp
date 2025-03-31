#include "evaluate.h"

int evaluatePosition(const Position& position, Variant variant) {
    switch (variant) {
        case STANDARD:
            return evaluateStandard(position);
        case CHESS960:
            return evaluateStandard(position); // Chess960 uses standard evaluation
        case RACING_KINGS:
            return evaluateRacingKings(position);
        case CRAZYHOUSE:
            return evaluateCrazyhouse(position);
        case ANTICHESS:
            return evaluateAntichess(position);
        case THREE_CHECK:
            return evaluateThreeCheck(position);
    }
    return 0;
}

int evaluateStandard(const Position& position) {
    // Standard evaluation logic
    return position.materialValue();
}

int evaluateRacingKings(const Position& position) {
    return distanceToEighthRank(position.getKing(WHITE)) -
           distanceToEighthRank(position.getKing(BLACK));
}

int evaluateCrazyhouse(const Position& position) {
    return position.materialValue() + position.handValue();
}

int evaluateAntichess(const Position& position) {
    return -position.materialValue(); // Reward losing pieces
}

int evaluateThreeCheck(const Position& position) {
    return position.getCheckCounter(WHITE) - position.getCheckCounter(BLACK);
}
