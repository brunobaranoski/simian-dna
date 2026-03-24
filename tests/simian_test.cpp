#include <iostream>
#include <vector>
#include "../src/simian.h"

// Função para imprimir o DNA
void printDNA(const std::vector<std::string>& dna) {
    std::cout << "[";
    for (size_t i = 0; i < dna.size(); i++) {
        std::cout << "\"" << dna[i] << "\"";
        if (i < dna.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

// Função de teste
void test(const std::string& nome, bool esperado, const std::vector<std::string>& dna){
    try {
        bool resultado = isSimian(dna);

        std::cout << (resultado == esperado ? "[PASSOU] " : "[FALHOU] ")
                  << nome
                  << " (esperado: " << esperado
                  << ", obtido: " << resultado << ")\nDNA: ";
        printDNA(dna);
        std::cout << "\n\n";

    } catch(const std::invalid_argument& e){
        if(!esperado){
            std::cout << "[PASSOU] " << nome
                      << " (excecao esperada: " << e.what() << ")\nDNA: ";
        } else {
            std::cout << "[FALHOU] " << nome
                      << " (excecao inesperada: " << e.what() << ")\nDNA: ";
        }

        printDNA(dna);
        std::cout << "\n\n";
    }
}

int main(){
    std::cout << "=== Testes isSimian ===\n\n";

    // DNAs símios

    test("simio horizontal",
        true,
        {"CTGAGA", "CTGAGC", "TATTGT", "AGAGGG", "CCCCTA", "TCACTG"});

    test("simio vertical",
        true,
        {"ATGCGA", "ATGTGC", "ATATGT", "ATAAGG", "CCGCTA", "TCACTG"});

    test("simio diagonal",
        true,
        {"GCTACG", "CGCTAC", "TAGGCT", "ACTGGG", "CCTACG", "TGCACT"});

    test("simio diagonal inversa",
        true,
        {"ATGCGC", "CAGTCG", "TTACCT", "AGCCGG", "TGCATG", "GCATGC"});

    // DNA humano

    test("humano",
        false,
        {"ATGCGA", "CAGTGC", "TTATTT", "AGACGG", "GCGTCA", "TCACTG"});

    // DNAs inválidos

    test("invalido - caractere X",
        false,
        {"ATGCGA", "CAGTGC", "TTATXX", "AGACGG", "GCGTCA", "TCACTG"});

    test("invalido - nao quadrado",
        false,
        {"ATGCGA", "CAGTGC", "TTT", "AGACGG", "GCGTCA", "TCACTG"});

    test("invalido - vazio",
        false,
        {});

    std::cout << "=== Fim dos testes ===\n";
    return 0;
}