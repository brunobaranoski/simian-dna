// Verifica se existe sequência de 4 letras iguais em uma direção específica
// di=passo na linha, dj=passo na coluna
function checkSequence(dna, di, dj) {
    const n = dna.length;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {

            // verifica se os próximos 3 passos cabem na matriz
            if (i + di * 3 >= n || j + dj * 3 >= n || j + dj * 3 < 0) {
                continue;
            }

            const base = dna[i][j];

            if (base === dna[i + di][j + dj] &&
                base === dna[i + di * 2][j + dj * 2] &&
                base === dna[i + di * 3][j + dj * 3]) {
                return true;
            }
        }
    }

    return false;
}

// Valida se o DNA é uma matriz NxN e contém apenas caracteres válidos (A, T, C, G)
function isValidDNA(dna) {
    if (!dna || dna.length === 0) return false;
    const n = dna.length;

    for (let i = 0; i < n; i++) {
        // Verifica se a matriz é quadrada (NxN)
        if (dna[i].length !== n) return false;

        for (let j = 0; j < n; j++) {
            const c = dna[i][j];
            // Verifica se o caractere é uma base nitrogenada válida
            if (c !== 'A' && c !== 'T' && c !== 'C' && c !== 'G') return false;
        }
    }

    return true;
}

// Retorna true se o DNA pertence a um símio
function isSimian(dna) {
    if (!isValidDNA(dna)) throw new Error('DNA invalido');

    // early return: para na primeira sequência encontrada
    if (checkSequence(dna, 0, 1))  return true; // horizontal
    if (checkSequence(dna, 1, 0))  return true; // vertical
    if (checkSequence(dna, 1, 1))  return true; // diagonal
    if (checkSequence(dna, 1, -1)) return true; // diagonal inversa

    // Nenhuma sequência encontrada, DNA é humano
    return false;
}

module.exports = { isSimian };