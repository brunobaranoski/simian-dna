#include <stdexcept>
#include "simian.h"

bool isSimian(const std::vector<std::string> &dna){
    //Valida o DNA
    if(!isValidDNA(dna)) throw std::invalid_argument("DNA invalido");

    //early return: para na primeira sequência encontrada
    if(checkSequence(dna, 0, 1))  return true;
    if(checkSequence(dna, 1, 0))  return true;
    if(checkSequence(dna, 1, 1))  return true;
    if(checkSequence(dna, 1, -1)) return true;
    
    // Nenhuma sequência encontrada, DNA é humano
    return false;
}

// di e dj definem a direção: di=linha, dj=coluna
// ex: (0,1)=horizontal, (1,0)=vertical, (1,1)=diagonal, (1,-1)=diagonal inversa
bool checkSequence(const std::vector<std::string> &dna, int di, int dj){

    int n=dna.size();

    for(int i=0; i<n; i++){

        for (int j=0; j<n; j++){

            //verifica se os próximos 3 passos cabem na matriz
            if(i + di*3 >= n || j + dj*3 >= n || j + dj*3 < 0){
                continue;
            }

            char base = dna[i][j];

            if(base == dna[i + di][j + dj] &&
               base == dna[i + di*2][j + dj*2] &&
               base == dna[i + di*3][j + dj*3]){
                return true;
            }

        }

    }

    return false;
}

bool isValidDNA(const std::vector<std::string> &dna){
    // Rejeita array vazio
    if(dna.empty()) return false;
    int n = dna.size();

    for(int i = 0; i < n; i++){
        // Verifica se a matriz é quadrada (NxN)
        if(dna[i].size() != n){
            return false;
        }

        for(int j = 0; j < n; j++){
            char c = dna[i][j];
            // Verifica se o caractere é uma base nitrogenada válida
            if(c != 'A' && c != 'T' && c != 'C' && c != 'G'){
                return false;
            }
        }
    }

    return true;
}