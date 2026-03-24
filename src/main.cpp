#include <iostream>
#include "simian.h"

// Função para imprimir o DNA
void printDNA(const std::vector<std::string>& dna) {
    for (const auto& row : dna) {
        std::cout << row << "\n";
    }
}

int main() {
    std::cout << "=== Detector de DNA Simio ===\n\n";

    // Exemplo de DNA símio
    std::vector<std::string> dna = {"CTGAGA", "CTGAGC", "TATTGT", "AGAGGG", "CCCCTA", "TCACTG"};

    std::cout << "DNA analisado:\n";
    printDNA(dna);
    std::cout << "\n";

    try {
        bool result = isSimian(dna);

        std::cout << "Resultado: " << (result ? "O DNA e simio!\n" : "O DNA nao e simio!\n");

    } catch(const std::invalid_argument& e) {
        std::cout << "Erro: " << e.what() << "\n";
    }

    return 0;
}