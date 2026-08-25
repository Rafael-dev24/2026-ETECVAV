# Computação Quântica

Site estático desenvolvido como trabalho escolar sobre **Computação Quântica**, explorando conceitos fundamentais, aplicações práticas, desafios da área e as fontes utilizadas na pesquisa.

## 🔗 Páginas

| Arquivo | Descrição |
|---|---|
| `index.html` | Página inicial — introdução ao tema, história e conceito de qubits. |
| `parte2.html` | Aplicações (medicina, química, IA, criptografia) e principais desafios (decoerência, correção de erros). |
| `algo.html` | Cards com os conceitos fundamentais: Superposição, Entrelaçamento e Interferência (usa Bootstrap 5). |
| `fontes.html` | Referências bibliográficas no formato ABNT NBR 6023. |

## 🎨 Estilo

Todo o visual é controlado pelo arquivo `style.css`, com um tema escuro (dark mode):

- Paleta principal: fundo `#0F172A`, destaques em azul `#3B82F6`
- Navbar fixa com estado ativo por página
- Cards com efeito hover (`algo.html`)
- Layout responsivo com breakpoints em `640px` e `380px`

## 🖼️ Imagens

As imagens usadas nas páginas devem estar na pasta `imagens/` (referenciada como `./imagens/...` no HTML):

- `images.jpg`
- `computador_fodastico-1920x1080.jpg`
- `imagem_gemini.png`
- `imagem_gemini2.png`
- `imagem3.png`

> ⚠️ Certifique-se de criar a pasta `imagens/` na raiz do projeto e colocar os arquivos de imagem nela, pois os caminhos no HTML apontam para `./imagens/`.

## 📁 Estrutura de pastas sugerida

```
projeto/
├── index.html
├── parte2.html
├── algo.html
├── fontes.html
├── style.css
├── README.md
└── imagens/
    ├── images.jpg
    ├── computador_fodastico-1920x1080.jpg
    ├── imagem_gemini.png
    ├── imagem_gemini2.png
    └── imagem3.png
```

## 🛠️ Tecnologias utilizadas

- HTML5
- CSS3
- [Bootstrap 5.3.3](https://getbootstrap.com/) (via CDN, usado em `algo.html`)

## 📚 Fontes

As referências completas, no padrão ABNT, estão disponíveis na página `fontes.html`, incluindo Wikipédia, CNN Brasil, InfoMoney, IT Forum e MIT Technology Review Brasil.

## ▶️ Como visualizar

Basta abrir o arquivo `index.html` em qualquer navegador — não é necessário servidor ou instalação de dependências.

---
© 2026 Computação Quântica. Todos os direitos reservados.
