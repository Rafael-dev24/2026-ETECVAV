# Exercícios de Python

Lista de exercícios em Python voltados à prática de lógica de programação: estruturas condicionais, laços de repetição (`while`), entrada de dados e operações matemáticas básicas.

## 📋 Lista de exercícios

| Arquivo | Descrição |
|---|---|
| `exercicio1.py` | Verifica se um número digitado é positivo, negativo ou zero. |
| `exercicio2.py` | Compara dois números e informa qual é o maior, ou se são iguais. |
| `exercicio3.py` | Exibe a contagem de 0 até o número digitado, usando `while`. |
| `exercicio4.py` | Soma os números pares e ímpares de 1 até o número digitado. |
| `exercicio5.py` | Gera a tabuada (de 0 a 10) de um número entre 1 e 10, validando a entrada. |
| `exercicio6.py` | Calcula a média das notas digitadas, encerrando quando o valor sai do intervalo de 0 a 10. |
| `exercicio7.py` | Lê 10 números e conta quantos são positivos, negativos e zeros. |
| `exercicio8.py` | Verifica se um número é par ou ímpar. |
| `exercicio9.py` | Calcula o fatorial de um número inteiro positivo. |
| `exercicio10.py` | Simula um sistema de senha com número limitado de tentativas. |

## ▶️ Como executar

Cada exercício é independente e pode ser rodado diretamente com Python 3:

```bash
python exercicio1.py
```

(Substitua `exercicio1.py` pelo arquivo desejado.)

## 🛠️ Requisitos

- Python 3.12+ (os arquivos `.pyc` presentes foram compilados para CPython 3.12)
- Nenhuma biblioteca externa é necessária — apenas Python padrão

## 📁 Estrutura

```
projeto/
├── exercicio1.py
├── exercicio2.py
├── exercicio3.py
├── exercicio4.py
├── exercicio5.py
├── exercicio6.py
├── exercicio7.py
├── exercicio8.py
├── exercicio9.py
├── exercicio10.py
├── settings.json
└── README.md
```

> 💡 A pasta `__pycache__` (arquivos `.pyc`) é gerada automaticamente pelo Python ao executar os scripts e não precisa ser versionada — considere adicioná-la a um `.gitignore`.

## 📝 Observações

- `exercicio8.py`: atenção, a lógica atual classifica como "primo" qualquer número ímpar, o que não corresponde à definição real de número primo — pode ser um ponto de revisão/correção futura.
- O arquivo `settings.json` contém uma configuração do VS Code (interpretador Python padrão) e não faz parte da lógica dos exercícios.

## 🎯 Objetivo

Fixar conceitos fundamentais de lógica de programação em Python:
- Estruturas condicionais (`if`, `elif`, `else`)
- Laços de repetição (`while`)
- Entrada e validação de dados (`input`)
- Operadores aritméticos e de comparação
