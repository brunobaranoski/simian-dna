# simian-dna
Simian DNA detection algorithm and API challenge

Detecta se uma sequência de DNA pertence a um símio ou humano.

Um DNA é considerado símio se contiver uma ou mais sequências de 4 letras 
iguais consecutivas nas direções horizontal, vertical ou diagonal.

## Nível 1 — Algoritmo em C++

### Pré-requisitos
- g++ com suporte a C++17

### Como compilar e rodar

#### Programa principal
```bash
g++ src/main.cpp src/simian.cpp -o simian
./simian
```

#### Testes
```bash
g++ tests/simian_test.cpp src/simian.cpp -o simian_test
./simian_test
```

## Níveis
- [x] Nível 1 — Algoritmo em C++
- [ ] Nível 2 — API REST em Node.js
- [ ] Nível 3 — Banco de dados e stats