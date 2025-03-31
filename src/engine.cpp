#include "engine.h"
#include "position.h"
#include "evaluate.h"
#include "movegen.h"

Engine::Engine(Variant variant) : variant(variant) {}

void Engine::setAILevel(int level) {
    aiLevel = level;
    // Adjust search depth based on AI level
    searchDepth = level * 2;
}

void Engine::startGame() {
    Position position;
    position.initializeVariant(variant);

    while (!position.isGameOver()) {
        Move move = generateBestMove(position, aiLevel);
        position.makeMove(move);
        std::cout << position.toString() << std::endl;
    }
}
