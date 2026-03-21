const express = require('express');
const { isSimian } = require('./simian');

const app = express();
app.use(express.json()); // permite receber JSON no body

const PORT = 3000;

// POST /simian - recebe array de DNA e retorna 200 se símio, 403 se humano
app.post('/simian', (req, res) => {
    const { dna } = req.body;

    // Valida se o body contém um array de strings
    if (!dna || !Array.isArray(dna) || !dna.every(row => typeof row === 'string')) {
        return res.status(400).json({ message: 'DNA invalido ou formato incorreto' });
    }

    try {
        const result = isSimian(dna);
        if (result) {
            res.status(200).json({ message: 'DNA simio' });
        } else {
            res.status(403).json({ message: 'DNA humano' });
        }
    } catch (e) {
        res.status(400).json({ message: e.message });
    }
});

app.listen(PORT, () => {
    console.log(`Servidor rodando na porta ${PORT}`);
});