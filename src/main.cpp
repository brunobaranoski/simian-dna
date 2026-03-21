#include <iostream>
#include "simian.h"

int main() {
    std::cout << "Detector de DNA Simio\n";

    // Exemplos de DNA para teste
    std::vector<std::string> dnaSimio = {"CTGAGA", "CTGAGC", "TATTGT", "AGAGGG", "CCCCTA", "TCACTG"};
    std::vector<std::string> dnaHumano = {"ATGCGA", "CAGTGC", "TTATTT", "AGACGG", "GCGTCA", "TCACTG"};

    bool checkSimian = isSimian(dnaSimio);
    std::cout << (checkSimian ? "O DNA e simio!\n" : "O DNA nao e simio!\n");

    checkSimian = isSimian(dnaHumano);
    std::cout << (checkSimian ? "O DNA e simio!\n" : "O DNA nao e simio!\n");

    return 0;
}