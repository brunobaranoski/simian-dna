#pragma once
#include <vector>
#include <string>

// Retorna true se o DNA pertence a um símio
// Um DNA é símio se contém 4 letras iguais consecutivas em qualquer direção
bool isSimian(const std::vector<std::string> &dna);

// Verifica se existe sequência de 4 letras iguais em uma direção específica
// di=passo na linha, dj=passo na coluna
// ex: (0,1)=horizontal, (1,0)=vertical, (1,1)=diagonal, (1,-1)=diagonal inversa
bool checkSequence(const std::vector<std::string> &dna, int di, int dj);

// Valida se o DNA é uma matriz NxN e contém apenas caracteres válidos (A, T, C, G)
bool isValidDNA(const std::vector<std::string>& dna);