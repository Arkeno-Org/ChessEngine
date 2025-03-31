#ifndef ENGINE_H
#define ENGINE_H

#include "position.h"
#include "movegen.h"
#include "evaluate.h"
#include "antichess.h"
#include "three_check.h"
#include "racing_kings.h"

enum Variant { STANDARD, CHESS960, RACING_KINGS, CRAZYHOUSE, ANTICHESS, THREE_CHECK };

class Engine {
public:
    Engine(Variant variant);
    void setAILevel(int level);
    void startGame();

private:
    Variant variant;
    int aiLevel;
    int searchDepth;
};

#endif
