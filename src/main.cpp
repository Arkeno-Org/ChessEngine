#include <iostream>
#include "engine.h"

enum Variant {
    STANDARD,
    CHESS960,
    RACING_KINGS,
    CRAZYHOUSE,
    ANTICHESS,
    THREE_CHECK
};

int main() {
    std::cout << "Welcome to Fairy Chess Engine\n";
    std::cout << "Select a variant:\n";
    std::cout << "1. Standard\n2. Chess960\n3. Racing Kings\n4. Crazyhouse\n5. Antichess\n6. Three-Check\n";
    int choice;
    std::cin >> choice;

    Engine engine(static_cast<Variant>(choice - 1));

    std::cout << "Select AI Level (1-5): ";
    int aiLevel;
    std::cin >> aiLevel;
    engine.setAILevel(aiLevel);

    engine.startGame();

    std::cout << "Game Over!\n";
    return 0;
}
