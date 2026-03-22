const { Pool } = require('pg');
require('dotenv').config();

// Conexão com o banco de dados
const pool = new Pool({
    connectionString: process.env.DATABASE_URL
});

// Cria a tabela se não existir
async function initDB() {
    await pool.query(`
        CREATE TABLE IF NOT EXISTS dna_checks (
            id SERIAL PRIMARY KEY,
            dna TEXT UNIQUE NOT NULL,
            is_simian BOOLEAN NOT NULL
        )
    `);
}

// Salva o DNA no banco, ignorando duplicatas
async function saveDNA(dna, isSimian) {
    const dnaString = dna.join(',');
    await pool.query(
        `INSERT INTO dna_checks (dna, is_simian) VALUES ($1, $2) ON CONFLICT (dna) DO NOTHING`,
        [dnaString, isSimian]
    );
}

// Retorna as estatísticas
async function getStats() {
    const result = await pool.query(`
        SELECT
            COUNT(*) FILTER (WHERE is_simian = true) AS count_mutant_dna,
            COUNT(*) FILTER (WHERE is_simian = false) AS count_human_dna
        FROM dna_checks
    `);

    const { count_mutant_dna, count_human_dna } = result.rows[0];
    const simians = parseInt(count_mutant_dna);
    const humans = parseInt(count_human_dna);
    const ratio = humans > 0 ? simians / humans : 0;

    return { count_mutant_dna: simians, count_human_dna: humans, ratio };
}

module.exports = { initDB, saveDNA, getStats };