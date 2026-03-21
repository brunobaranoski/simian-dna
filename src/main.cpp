#include <iostream>
#include "simian.h"

int main() {
    std::cout << "Detector de DNA Simio\n";

    std::vector<std::string> dna = {"CTGAGA", "CTGAGC", "TATTGT", "AGAGGG", "CCCCTA", "TCACTG"};

    try {
        bool result = isSimian(dna);
        std::cout << (result ? "O DNA e simio!\n" : "O DNA nao e simio!\n");
    } catch(const std::invalid_argument& e) {
        std::cout << "Erro: " << e.what() << "\n";
    }

    return 0;
}