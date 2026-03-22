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

## Nível 2 — API REST em Node.js

### URL pública
https://simian-dna-production.up.railway.app

> **Nota:** a API está hospedada no plano gratuito do Railway e pode demorar alguns segundos para responder na primeira requisição.

### Pré-requisitos
- Node.js v22+
- npm v10+

### Como rodar localmente
```bash
npm install
npm run dev
```

### Documentação
Acesse a documentação interativa via Swagger em:
http://localhost:3000/api-docs

### Endpoints

**POST /simian**
```json
{
  "dna": ["ATGCGA", "CAGTGC", "TTATGT", "AGAAGG", "CCCCTA", "TCACTG"]
}
```
Retorna `200 OK` se símio, `403 Forbidden` se humano.

**GET /stats**

Retorna estatísticas dos DNAs verificados:
```json
{"count_mutant_dna": 1, "count_human_dna": 1, "ratio": 1}
```

### Testando a API
```bash
# DNA símio — esperado: 200 OK
curl -i -X POST https://simian-dna-production.up.railway.app/simian -H "Content-Type: application/json" -d "{\"dna\": [\"CTGAGA\", \"CTGAGC\", \"TATTGT\", \"AGAGGG\", \"CCCCTA\", \"TCACTG\"]}"

# DNA humano — esperado: 403 Forbidden
curl -i -X POST https://simian-dna-production.up.railway.app/simian -H "Content-Type: application/json" -d "{\"dna\": [\"ATGCGA\", \"CAGTGC\", \"TTATTT\", \"AGACGG\", \"GCGTCA\", \"TCACTG\"]}"

# DNA inválido — esperado: 400 Bad Request
curl -i -X POST https://simian-dna-production.up.railway.app/simian -H "Content-Type: application/json" -d "{\"dna\": [\"ATGCGA\", \"CAGTGC\", \"TTATXX\", \"AGACGG\", \"GCGTCA\", \"TCACTG\"]}"

# Stats — esperado: 200 OK
curl -i https://simian-dna-production.up.railway.app/stats
```

## Níveis
- [x] Nível 1 — Algoritmo em C++
- [x] Nível 2 — API REST em Node.js
- [x] Nível 3 — Banco de dados e stats