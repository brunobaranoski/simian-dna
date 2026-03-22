const express = require('express');
const { isSimian } = require('./simian');

const swaggerUi = require('swagger-ui-express');
const swaggerJsdoc = require('swagger-jsdoc');
const app = express();
app.use(express.json()); // permite receber JSON no body

const PORT = 3000;

// POST /simian - recebe array de DNA e retorna 200 se símio, 403 se humano
/**
 * @swagger
 * /simian:
 *   post:
 *     summary: Verifica se um DNA pertence a um símio
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             properties:
 *               dna:
 *                 type: array
 *                 items:
 *                   type: string
 *             example:
 *               dna: ["CTGAGA", "CTGAGC", "TATTGT", "AGAGGG", "CCCCTA", "TCACTG"]
 *     responses:
 *       200:
 *         description: DNA símio
 *       403:
 *         description: DNA humano
 *       400:
 *         description: DNA inválido ou formato incorreto
 */
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

const swaggerOptions = {
    definition: {
        openapi: '3.0.0',
        info: {
            title: 'Simian DNA API',
            version: '1.0.0',
            description: 'API para detectar se um DNA pertence a um símio ou humano'
        }
    },
    apis: ['./src/app.js']
};

const swaggerDocs = swaggerJsdoc(swaggerOptions);
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocs));

app.listen(PORT, () => {
    console.log(`Servidor rodando na porta ${PORT}`);
});