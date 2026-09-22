# Documentação Técnica — Sistema para Lanchonete

## 1. Descrição do projeto

O projeto consiste em um sistema de gerenciamento para uma lanchonete, desenvolvido em Python e executado diretamente pelo terminal.

O sistema permite:

* Cadastrar produtos;
* Listar produtos cadastrados;
* Pesquisar produtos;
* Alterar preços;
* Remover produtos;
* Realizar pedidos;
* Controlar o estoque;
* Listar pedidos realizados;
* Gerar relatório de vendas;
* Identificar o produto mais vendido;
* Consultar o total vendido no dia;
* Exportar os pedidos para um arquivo CSV;
* Criar uma cópia de segurança dos dados;
* Armazenar os dados permanentemente em um arquivo JSON.

O programa utiliza arquivos locais para armazenamento, não dependendo de um banco de dados externo.

---

# 2. Tecnologias utilizadas

## Python

A aplicação foi desenvolvida utilizando Python.

## Bibliotecas utilizadas

O código utiliza as seguintes bibliotecas:

### `json`

Responsável pela leitura e gravação dos dados no arquivo JSON.

```python
import json
```

É utilizada principalmente nas funções `load_data()` e `save_data()`.

### `os`

Utilizada para verificar a existência do arquivo de dados.

```python
import os
```

A função principal utilizada é:

```python
os.path.exists()
```

### `csv`

Utilizada para criar o relatório de vendas em formato CSV.

```python
import csv
```

### `datetime`

Utilizada para obter a data atual no momento em que um pedido é realizado.

```python
from datetime import datetime
```

### `shutil`

Utilizada para realizar a cópia do arquivo JSON e criar o backup dos dados.

```python
import shutil
```

---

# 3. Arquivo de armazenamento

O sistema utiliza o arquivo:

```text
lanchonete_dados.json
```

Esse arquivo armazena duas informações principais:

* Produtos;
* Pedidos.

O nome do arquivo é definido pela constante:

```python
DATA_FILE = "lanchonete_dados.json"
```

A estrutura básica do arquivo é:

```json
{
    "products": [],
    "orders": []
}
```

Quando existem dados cadastrados, os arrays passam a conter os respectivos objetos.

---

# 4. Variáveis globais

O sistema possui duas listas globais:

```python
products = []
orders = []
```

## `products`

Armazena todos os produtos cadastrados.

Cada produto possui:

| Campo   | Tipo   | Descrição                        |
| ------- | ------ | -------------------------------- |
| `code`  | string | Código identificador do produto  |
| `name`  | string | Nome do produto                  |
| `price` | float  | Preço do produto                 |
| `stock` | int    | Quantidade disponível em estoque |

Exemplo:

```json
{
    "code": "001",
    "name": "X-Burger",
    "price": 15.90,
    "stock": 20
}
```

## `orders`

Armazena os pedidos realizados.

Cada pedido possui:

| Campo           | Tipo   | Descrição                          |
| --------------- | ------ | ---------------------------------- |
| `customer_name` | string | Nome do cliente                    |
| `product_code`  | string | Código do produto comprado         |
| `product_name`  | string | Nome do produto comprado           |
| `quantity`      | int    | Quantidade comprada                |
| `total`         | float  | Valor total do pedido              |
| `date`          | string | Data em que o pedido foi realizado |

Exemplo:

```json
{
    "customer_name": "João",
    "product_code": "001",
    "product_name": "X-Burger",
    "quantity": 2,
    "total": 31.80,
    "date": "2026-09-22"
}
```

---

# 5. Função `load_data()`

```python
def load_data():
```

## Objetivo

Carregar os produtos e pedidos armazenados no arquivo JSON para as listas utilizadas pelo programa.

## Funcionamento

Primeiro, a função verifica se o arquivo existe:

```python
if not os.path.exists(DATA_FILE):
```

Caso o arquivo não exista, as listas são inicializadas vazias:

```python
products = []
orders = []
```

Caso o arquivo exista, ele é aberto no modo de leitura:

```python
with open(DATA_FILE, "r", encoding="utf-8") as file:
```

Em seguida, o conteúdo JSON é convertido para uma estrutura Python:

```python
data = json.load(file)
```

Os produtos e pedidos são recuperados:

```python
products = data.get("products", [])
orders = data.get("orders", [])
```

O método `.get()` permite utilizar uma lista vazia caso uma das chaves não exista.

---

# 6. Função `save_data()`

```python
def save_data():
```

## Objetivo

Salvar os dados atuais dos produtos e pedidos no arquivo JSON.

A função cria um dicionário:

```python
data = {
    "products": products,
    "orders": orders
}
```

Depois, abre o arquivo para escrita:

```python
with open(DATA_FILE, "w", encoding="utf-8") as file:
```

E grava os dados em formato JSON:

```python
json.dump(data, file, indent=4, ensure_ascii=False)
```

O parâmetro `indent=4` deixa o arquivo organizado e legível.

O parâmetro `ensure_ascii=False` permite manter caracteres como:

```text
ã
ç
é
```

---

# 7. Função `register_product()`

```python
def register_product():
```

## Objetivo

Cadastrar um novo produto no sistema.

## Funcionamento

O usuário informa o código:

```python
code = input("Código do produto: ")
```

O sistema verifica se já existe um produto com esse código:

```python
if find_product_by_code(code) is not None:
```

Caso exista, o cadastro é interrompido.

Depois são solicitados:

* Nome;
* Preço;
* Quantidade em estoque.

```python
name = input("Nome do produto: ")
price = float(input("Preço do produto: "))
stock = int(input("Quantidade em estoque: "))
```

Um novo dicionário é criado:

```python
product = {
    "code": code,
    "name": name,
    "price": price,
    "stock": stock
}
```

O produto é adicionado à lista:

```python
products.append(product)
```

Por fim, os dados são salvos.

---

# 8. Função `list_products()`

```python
def list_products():
```

## Objetivo

Exibir todos os produtos cadastrados.

Primeiramente, verifica se existem produtos:

```python
if len(products) == 0:
```

Caso existam produtos, a função percorre a lista:

```python
for product in products:
```

São exibidos:

* Código;
* Nome;
* Preço;
* Estoque.

O preço é formatado com duas casas decimais:

```python
f"R$ {product['price']:.2f}"
```

---

# 9. Função `find_product_by_code()`

```python
def find_product_by_code(code):
```

## Objetivo

Localizar um produto utilizando seu código.

A função percorre todos os produtos:

```python
for product in products:
```

Quando encontra um código correspondente:

```python
if product["code"] == code:
```

retorna o produto.

Caso nenhum produto seja encontrado, retorna:

```python
None
```

Essa função é utilizada, principalmente, durante o cadastro e a realização de pedidos.

---

# 10. Função `make_order()`

```python
def make_order():
```

## Objetivo

Registrar uma venda e atualizar o estoque.

## Fluxo

Primeiro, verifica se existem produtos cadastrados.

Depois solicita o nome do cliente:

```python
customer_name = input("Nome do cliente: ")
```

Os produtos são exibidos utilizando:

```python
list_products()
```

O usuário informa o código do produto.

O produto é localizado através de:

```python
find_product_by_code(code)
```

Depois é solicitada a quantidade.

O sistema verifica se a quantidade é válida:

```python
if quantity <= 0:
```

Também verifica se existe estoque suficiente:

```python
if quantity > product["stock"]:
```

O valor total é calculado através de:

```python
total = quantity * product["price"]
```

O estoque é reduzido:

```python
product["stock"] -= quantity
```

Depois, um novo pedido é criado.

A data é registrada utilizando:

```python
datetime.now().strftime("%Y-%m-%d")
```

O pedido é adicionado à lista:

```python
orders.append(order)
```

Por fim, os dados são salvos.

---

# 11. Função `list_orders()`

```python
def list_orders():
```

## Objetivo

Exibir todos os pedidos realizados.

A função verifica se existem pedidos.

Caso existam, percorre a lista `orders` e apresenta:

* Cliente;
* Produto;
* Quantidade;
* Valor total;
* Data.

Para pedidos antigos que eventualmente não possuam o campo `date`, é utilizado:

```python
order.get("date", "Data não registrada")
```

---

# 12. Função `show_menu()`

```python
def show_menu():
```

## Objetivo

Exibir o menu principal do sistema.

As opções disponíveis são:

| Opção | Função                      |
| ----- | --------------------------- |
| 1     | Cadastrar produto           |
| 2     | Listar produtos             |
| 3     | Fazer pedido                |
| 4     | Ver pedidos realizados      |
| 5     | Alterar preço do produto    |
| 6     | Remover produto             |
| 7     | Relatório de vendas         |
| 8     | Pesquisar produto por nome  |
| 9     | Produto mais vendido        |
| 10    | Total vendido no dia        |
| 11    | Exportar relatório para CSV |
| 12    | Criar backup do JSON        |
| 13    | Sair                        |

---

# 13. Função `change_price()`

```python
def change_price():
```

## Objetivo

Alterar o preço de um produto já cadastrado.

A função lista os produtos e solicita o nome do produto:

```python
nome_do_produto = input(
    "Qual o nome do produto que você quer mudar o valor?: "
)
```

A comparação não diferencia letras maiúsculas e minúsculas:

```python
product["name"].lower() == nome_do_produto.lower()
```

Quando o produto é encontrado, um novo preço é solicitado:

```python
novo_valor = float(
    input("Digite o novo valor deste produto: ")
)
```

O preço é atualizado e os dados são salvos.

---

# 14. Função `remove_product()`

```python
def remove_product():
```

## Objetivo

Remover um produto do sistema.

O usuário informa o nome do produto.

A função percorre a lista e compara os nomes ignorando diferenças entre maiúsculas e minúsculas.

Quando encontra o produto:

```python
products.remove(product)
```

O produto é removido e os dados são salvos.

---

# 15. Função `sales_report()`

```python
def sales_report():
```

## Objetivo

Apresentar um resumo geral das vendas.

A função calcula:

* Quantidade de pedidos;
* Quantidade total de produtos vendidos;
* Faturamento total.

A quantidade de pedidos é obtida através de:

```python
len(orders)
```

A quantidade de produtos é acumulada:

```python
produtos_vendidos += order["quantity"]
```

O faturamento é calculado através:

```python
total_faturado += order["total"]
```

---

# 16. Função `search()`

```python
def search():
```

## Objetivo

Pesquisar um produto pelo nome.

O usuário informa o nome desejado.

A comparação é feita sem diferenciar letras maiúsculas e minúsculas:

```python
product["name"].lower() == busca.lower()
```

Caso seja encontrado, o sistema informa que o produto está cadastrado.

Caso contrário, informa que não existe um produto com aquele nome.

---

# 17. Função `most_sold_product()`

```python
def most_sold_product():
```

## Objetivo

Identificar o produto com maior quantidade de unidades vendidas.

A função cria um dicionário:

```python
vendas = {}
```

Cada produto recebe como chave seu nome e como valor a quantidade vendida.

Quando um produto aparece novamente em outro pedido, sua quantidade é acumulada:

```python
vendas[nome] += order["quantity"]
```

Depois, a função utiliza:

```python
max(vendas, key=vendas.get)
```

para encontrar o produto com maior quantidade vendida.

O resultado apresenta:

* Nome do produto;
* Quantidade total vendida.

---

# 18. Função `total_sold_today()`

```python
def total_sold_today():
```

## Objetivo

Calcular o faturamento realizado na data atual.

A data atual é obtida através de:

```python
hoje = datetime.now().strftime("%Y-%m-%d")
```

A função percorre todos os pedidos e verifica quais possuem a mesma data:

```python
if order.get("date") == hoje:
```

Os valores correspondentes são somados:

```python
total += order["total"]
```

Ao final, o sistema exibe o total vendido no dia.

---

# 19. Função `export_csv()`

```python
def export_csv():
```

## Objetivo

Exportar os pedidos para um arquivo CSV.

O arquivo criado possui o nome:

```text
relatorio_vendas.csv
```

O arquivo é aberto utilizando:

```python
with open(
    csv_file,
    "w",
    newline="",
    encoding="utf-8"
) as file:
```

O objeto `csv.writer` é utilizado para escrever os dados.

Primeiro são criados os cabeçalhos:

```text
Cliente
Produto
Quantidade
Total
Data
```

Depois, cada pedido é gravado como uma linha do arquivo.

O relatório pode ser aberto em programas como:

* Microsoft Excel;
* LibreOffice Calc;
* Google Sheets;
* Outros programas compatíveis com CSV.

---

# 20. Função `backup_json()`

```python
def backup_json():
```

## Objetivo

Criar uma cópia de segurança do arquivo principal de dados.

Primeiramente, o sistema verifica se o arquivo existe.

Caso exista, o arquivo:

```text
lanchonete_dados.json
```

é copiado para:

```text
lanchonete_dados_backup.json
```

A cópia é realizada através de:

```python
shutil.copy(
    DATA_FILE,
    backup_file
)
```

---

# 21. Função `main()`

```python
def main():
```

## Objetivo

Controlar o funcionamento principal da aplicação.

Primeiramente, os dados são carregados:

```python
load_data()
```

Depois, o programa entra em um loop infinito:

```python
while True:
```

A cada repetição, o menu é apresentado:

```python
show_menu()
```

O usuário escolhe uma opção:

```python
option = input("Escolha uma opção: ")
```

A estrutura `if/elif` direciona a execução para a função correspondente.

Por exemplo:

```python
if option == "1":
    register_product()
```

Para a opção 13, os dados são salvos e o programa é encerrado:

```python
elif option == "13":
    save_data()
    print("Sistema encerrado.")
    break
```

Caso o usuário digite uma opção inexistente, o programa apresenta:

```text
Opção inválida.
```

---

# 22. Execução do programa

No final do código existe:

```python
main()
```

Essa instrução executa a função principal e inicia o sistema.

O fluxo geral é:

```text
Início
  |
  v
Carregar dados do JSON
  |
  v
Exibir menu
  |
  v
Usuário escolhe uma opção
  |
  +--> Cadastrar produto
  |
  +--> Listar produtos
  |
  +--> Fazer pedido
  |
  +--> Listar pedidos
  |
  +--> Alterar preço
  |
  +--> Remover produto
  |
  +--> Relatório de vendas
  |
  +--> Pesquisar produto
  |
  +--> Produto mais vendido
  |
  +--> Total vendido hoje
  |
  +--> Exportar CSV
  |
  +--> Criar backup
  |
  +--> Sair
          |
          v
        Fim
```

---

# 23. Arquivos gerados pelo sistema

O sistema pode trabalhar com três arquivos principais.

## `lanchonete_dados.json`

Arquivo principal de armazenamento.

Contém:

* Produtos;
* Pedidos.

## `relatorio_vendas.csv`

Arquivo gerado pela opção de exportação.

Contém os dados dos pedidos em formato tabular.

## `lanchonete_dados_backup.json`

Cópia do arquivo principal, criada através da opção de backup.

---

# 24. Regras de negócio implementadas

O sistema possui algumas regras importantes.

### Código de produto deve ser único

Antes de cadastrar um produto, o sistema verifica se já existe outro produto com o mesmo código.

### Não é possível realizar pedido sem produto cadastrado

O sistema verifica a existência de produtos antes de iniciar um pedido.

### A quantidade do pedido deve ser maior que zero

Pedidos com quantidade menor ou igual a zero são rejeitados.

### O estoque deve ser suficiente

O sistema não permite vender uma quantidade superior ao estoque disponível.

### O estoque é atualizado após uma venda

Quando um pedido é realizado, a quantidade vendida é subtraída do estoque.

### O pedido é armazenado

Após uma venda, os dados do pedido são adicionados à lista `orders`.

### Os dados são persistidos

Após operações que alteram os dados, o sistema chama `save_data()` para atualizar o arquivo JSON.

---

# 25. Estrutura lógica do sistema

O programa pode ser dividido em quatro áreas principais.

## Gerenciamento de produtos

Responsável por:

* Cadastro;
* Listagem;
* Pesquisa;
* Alteração de preço;
* Remoção;
* Consulta por código.

Funções:

```text
register_product()
list_products()
find_product_by_code()
change_price()
remove_product()
search()
```

## Gerenciamento de pedidos

Responsável pela realização e consulta das vendas.

Funções:

```text
make_order()
list_orders()
```

## Relatórios

Responsável pela análise das vendas.

Funções:

```text
sales_report()
most_sold_product()
total_sold_today()
export_csv()
```

## Persistência e backup

Responsável por armazenar e proteger os dados.

Funções:

```text
load_data()
save_data()
backup_json()
```

---

# 26. Tratamento de erros

O código possui verificações básicas para evitar algumas operações inválidas.

São tratados, por exemplo:

* Produto inexistente;
* Código de produto duplicado;
* Estoque insuficiente;
* Quantidade menor ou igual a zero;
* Ausência de produtos;
* Ausência de pedidos;
* Ausência do arquivo JSON;
* Opção de menu inválida.

Entretanto, algumas entradas do usuário ainda podem causar erros.

Por exemplo:

```python
price = float(input("Preço do produto: "))
```

Se o usuário digitar:

```text
abc
```

ocorrerá um `ValueError`.

O mesmo pode acontecer ao utilizar:

```python
int(input(...))
```

para quantidades.

Uma melhoria futura seria utilizar `try/except` para validar essas entradas.

---

# 27. Limitações atuais

Apesar de possuir várias funcionalidades, o sistema possui algumas limitações.

### Entrada de dados

Os valores de preço e quantidade não possuem tratamento completo para entradas inválidas.

### Identificação de produtos

Algumas operações utilizam o nome do produto em vez do código.

Isso pode gerar problemas caso existam produtos com nomes iguais.

### Pedidos

Cada pedido representa apenas um produto.

O sistema não possui, atualmente, um carrinho com vários produtos no mesmo pedido.

### Valores monetários

Os preços são armazenados utilizando `float`.

Para sistemas financeiros mais rigorosos, seria mais adequado utilizar `Decimal`.

### Banco de dados

O armazenamento é feito em JSON. Para uma aplicação maior ou com múltiplos usuários, um banco de dados seria mais adequado.

### Concorrência

O sistema foi projetado para execução local e individual. Não existe controle para múltiplos usuários modificando os mesmos dados simultaneamente.

### Validação

Ainda podem ser adicionadas validações para:

* Preços negativos;
* Estoque negativo;
* Nome vazio;
* Código vazio;
* Produtos duplicados por nome;
* Formatos inválidos de entrada.

---

# 28. Possíveis melhorias futuras

Algumas melhorias que podem ser implementadas são:

1. Adicionar tratamento de exceções com `try/except`.
2. Impedir preços negativos.
3. Impedir estoque negativo.
4. Permitir pedidos com vários produtos.
5. Criar um carrinho de compras.
6. Utilizar o código do produto para alterar e remover produtos.
7. Criar uma interface gráfica.
8. Utilizar banco de dados SQLite.
9. Criar sistema de usuários e autenticação.
10. Adicionar diferentes formas de pagamento.
11. Registrar horário completo das vendas.
12. Criar relatórios por período.
13. Permitir pesquisa parcial pelo nome.
14. Criar relatórios financeiros mais detalhados.
15. Melhorar o sistema de backup.
16. Adicionar confirmação antes da remoção de produtos.
17. Organizar o código em diferentes módulos.
18. Adicionar testes automatizados.

---

# 29. Resumo das funções

| Função                   | Responsabilidade                   |
| ------------------------ | ---------------------------------- |
| `load_data()`            | Carrega dados do JSON              |
| `save_data()`            | Salva dados no JSON                |
| `register_product()`     | Cadastra produtos                  |
| `list_products()`        | Lista produtos                     |
| `find_product_by_code()` | Busca produto por código           |
| `make_order()`           | Realiza pedidos e atualiza estoque |
| `list_orders()`          | Lista pedidos                      |
| `show_menu()`            | Exibe o menu                       |
| `change_price()`         | Altera o preço                     |
| `remove_product()`       | Remove produtos                    |
| `sales_report()`         | Exibe relatório geral de vendas    |
| `search()`               | Pesquisa produto por nome          |
| `most_sold_product()`    | Identifica o produto mais vendido  |
| `total_sold_today()`     | Calcula vendas do dia              |
| `export_csv()`           | Exporta vendas para CSV            |
| `backup_json()`          | Cria backup dos dados              |
| `main()`                 | Controla a execução do sistema     |

---

# 30. Conclusão

O sistema implementa uma solução simples de gerenciamento para uma lanchonete, utilizando Python e arquivos locais para persistência dos dados.

Sua estrutura está organizada em funções independentes, cada uma responsável por uma operação específica. O sistema contempla tanto o gerenciamento de produtos e estoque quanto o registro de pedidos e a geração de relatórios.

A utilização de JSON torna o projeto simples de executar e adequado para aplicações pequenas, estudos e projetos acadêmicos. Para uma aplicação comercial de maior escala, recomenda-se posteriormente migrar a persistência para um banco de dados e implementar mecanismos mais robustos de validação, segurança, autenticação e tratamento de erros.
