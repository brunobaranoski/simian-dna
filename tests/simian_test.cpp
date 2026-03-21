#include <iostream>
#include "../src/simian.h"
 
// Função auxiliar que verifica e printa o resultado do teste
void test(const std::string& nome, bool esperado, const std::vector<std::string>& dna){
    try {
        bool resultado = isSimian(dna);
        if(resultado == esperado){
            std::cout << "[PASSOU] " << nome << "\n";
        } else {
            std::cout << "[FALHOU] " << nome << "\n";
        }
    } catch(const std::invalid_argument& e){
        // Para casos inválidos, esperado = false indica que esperamos uma exceção
        if(!esperado){
            std::cout << "[PASSOU] " << nome << " (excecao: " << e.what() << ")\n";
        } else {
            std::cout << "[FALHOU] " << nome << " - excecao inesperada: " << e.what() << "\n";
        }
    }
}
 
int main(){
    std::cout << "=== Testes isSimian ===\n\n";
 
    // --- DNA símio ---
 
    // Sequência horizontal: CCCC na linha 4
    test("simio horizontal",
        true,
        {"CTGAGA", "CTGAGC", "TATTGT", "AGAGGG", "CCCCTA", "TCACTG"});
 
    // Sequência vertical: AAAA na coluna 0
    test("simio vertical",
        true,
        {"ATGCGA", "ATGTGC", "ATATGT", "ATAAGG", "CCGCTA", "TCACTG"});
 
    // Sequência diagonal (↘): GGGG em [0][0],[1][1],[2][2],[3][3]
    test("simio diagonal",
        true,
        {"GCTACG", "CGCTAC", "TAGGCT", "ACTGGG", "CCTACG", "TGCACT"});
 
    // Sequência diagonal inversa (↙): CCCC em [0][5],[1][4],[2][3],[3][2]
    test("simio diagonal inversa",
        true,
        {"ATGCGC", "CAGTCG", "TTACCT", "AGCCGG", "TGCATG", "GCATGC"});
 
    // --- DNA humano ---
 
    // Nenhuma sequência de 4 letras iguais
    test("humano",
        false,
        {"ATGCGA", "CAGTGC", "TTATTT", "AGACGG", "GCGTCA", "TCACTG"});
 
    // --- DNA inválido (espera exceção = esperado false) ---
 
    // Caractere inválido
    test("invalido - caractere X",
        false,
        {"ATGCGA", "CAGTGC", "TTATXX", "AGACGG", "GCGTCA", "TCACTG"});
 
    // Matriz não quadrada
    test("invalido - nao quadrado",
        false,
        {"ATGCGA", "CAGTGC", "TTT", "AGACGG", "GCGTCA", "TCACTG"});
 
    // Array vazio
    test("invalido - vazio",
        false,
        {});
 
    std::cout << "\n=== Fim dos testes ===\n";
    return 0;
}