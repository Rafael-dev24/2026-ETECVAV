import json
import os
import csv
from datetime import datetime
import shutil

DATA_FILE = "lanchonete_dados.json"

products = []
orders = []


def load_data():
    global products, orders

    if not os.path.exists(DATA_FILE):
        products = []
        orders = []
        return

    with open(DATA_FILE, "r", encoding="utf-8") as file:
        data = json.load(file)
        products = data.get("products", [])
        orders = data.get("orders", [])


def save_data():
    data = {
        "products": products,
        "orders": orders
    }

    with open(DATA_FILE, "w", encoding="utf-8") as file:
        json.dump(data, file, indent=4, ensure_ascii=False)


def register_product():
    code = input("Código do produto: ")

    if find_product_by_code(code) is not None:
        print("Já existe um produto com este código.")
        return

    name = input("Nome do produto: ")
    price = float(input("Preço do produto: "))
    stock = int(input("Quantidade em estoque: "))

    product = {
        "code": code,
        "name": name,
        "price": price,
        "stock": stock
    }

    products.append(product)
    save_data()

    print("Produto cadastrado com sucesso!")


def list_products():
    if len(products) == 0:
        print("Nenhum produto cadastrado.")
        return

    print("\n--- Produtos cadastrados ---")

    for product in products:
        print(f"Código: {product['code']}")
        print(f"Nome: {product['name']}")
        print(f"Preço: R$ {product['price']:.2f}")
        print(f"Estoque: {product['stock']}")
        print("-" * 30)


def find_product_by_code(code):
    for product in products:
        if product["code"] == code:
            return product

    return None


def make_order():
    if len(products) == 0:
        print("Nenhum produto cadastrado.")
        return

    customer_name = input("Nome do cliente: ")

    list_products()

    code = input("Digite o código do produto: ")

    product = find_product_by_code(code)

    if product is None:
        print("Produto não encontrado.")
        return

    quantity = int(input("Quantidade desejada: "))

    if quantity <= 0:
        print("Quantidade inválida.")
        return

    if quantity > product["stock"]:
        print("Estoque insuficiente.")
        return

    total = quantity * product["price"]

    product["stock"] -= quantity

    order = {
        "customer_name": customer_name,
        "product_code": product["code"],
        "product_name": product["name"],
        "quantity": quantity,
        "total": total,
        "date": datetime.now().strftime("%Y-%m-%d")
    }

    orders.append(order)

    save_data()

    print("Pedido realizado com sucesso!")
    print(f"Total: R$ {total:.2f}")


def list_orders():
    if len(orders) == 0:
        print("Nenhum pedido realizado.")
        return

    print("\n--- Pedidos realizados ---")

    for order in orders:
        print(f"Cliente: {order['customer_name']}")
        print(f"Produto: {order['product_name']}")
        print(f"Quantidade: {order['quantity']}")
        print(f"Total: R$ {order['total']:.2f}")
        print(f"Data: {order.get('date', 'Data não registrada')}")
        print("-" * 30)


def show_menu():
    print("\n=== Sistema para Lanchonete ===")
    print("1 - Cadastrar produto")
    print("2 - Listar produtos")
    print("3 - Fazer pedido")
    print("4 - Ver pedidos realizados")
    print("5 - Alterar preço do produto")
    print("6 - Remover produto")
    print("7 - Relatório de vendas")
    print("8 - Pesquisar produto por nome")
    print("9 - Produto mais vendido")
    print("10 - Total vendido no dia")
    print("11 - Exportar relatório para CSV")
    print("12 - Criar backup do JSON")
    print("13 - Sair")


def change_price():
    if len(products) == 0:
        print("Nenhum produto cadastrado.")
        return

    list_products()

    nome_do_produto = input(
        "Qual o nome do produto que você quer mudar o valor?: "
    )

    for product in products:
        if product["name"].lower() == nome_do_produto.lower():

            novo_valor = float(
                input("Digite o novo valor deste produto: ")
            )

            product["price"] = novo_valor

            save_data()

            print("Valor alterado com sucesso!")
            return

    print("Produto não encontrado.")


def remove_product():
    if len(products) == 0:
        print("Nenhum produto cadastrado.")
        return

    list_products()

    nome_do_produto = input(
        "Qual produto você deseja remover?: "
    )

    for product in products:
        if product["name"].lower() == nome_do_produto.lower():

            products.remove(product)

            save_data()

            print("Produto removido com sucesso!")
            return

    print("Produto não encontrado.")


def sales_report():
    if len(orders) == 0:
        print("Nenhuma venda realizada.")
        return

    produtos_vendidos = 0
    total_faturado = 0.0

    for order in orders:
        total_faturado += order["total"]
        produtos_vendidos += order["quantity"]

    print("\n--- RELATÓRIO DE VENDAS ---")
    print(f"Total de pedidos: {len(orders)}")
    print(f"Produtos vendidos: {produtos_vendidos}")
    print(f"Faturamento total: R$ {total_faturado:.2f}")


def search():
    if len(products) == 0:
        print("Nenhum produto registrado.")
        return

    busca = input(
        "Digite um produto que você queira procurar: "
    )

    for product in products:
        if product["name"].lower() == busca.lower():

            print(
                f"Há um produto registrado com o nome: {busca}"
            )

            return

    print(
        f"Não há nenhum produto registrado com o nome: {busca}"
    )


def most_sold_product():
    if len(orders) == 0:
        print("Nenhuma venda realizada.")
        return

    vendas = {}

    for order in orders:

        nome = order["product_name"]

        if nome in vendas:
            vendas[nome] += order["quantity"]

        else:
            vendas[nome] = order["quantity"]

    produto_mais_vendido = max(
        vendas,
        key=vendas.get
    )

    print("\n--- PRODUTO MAIS VENDIDO ---")
    print(f"Produto: {produto_mais_vendido}")
    print(
        f"Quantidade vendida: "
        f"{vendas[produto_mais_vendido]}"
    )


def total_sold_today():
    if len(orders) == 0:
        print("Nenhuma venda realizada.")
        return

    hoje = datetime.now().strftime("%Y-%m-%d")

    total = 0.0

    for order in orders:

        if order.get("date") == hoje:
            total += order["total"]

    print("\n--- TOTAL VENDIDO HOJE ---")
    print(f"Data: {hoje}")
    print(f"Total vendido: R$ {total:.2f}")


def export_csv():
    if len(orders) == 0:
        print("Nenhum pedido para exportar.")
        return

    csv_file = "relatorio_vendas.csv"

    with open(
        csv_file,
        "w",
        newline="",
        encoding="utf-8"
    ) as file:

        writer = csv.writer(file)

        writer.writerow([
            "Cliente",
            "Produto",
            "Quantidade",
            "Total",
            "Data"
        ])

        for order in orders:

            writer.writerow([
                order["customer_name"],
                order["product_name"],
                order["quantity"],
                f"{order['total']:.2f}",
                order.get(
                    "date",
                    "Data não registrada"
                )
            ])

    print(
        f"Relatório exportado com sucesso para: "
        f"{csv_file}"
    )


def backup_json():
    if not os.path.exists(DATA_FILE):
        print("O arquivo de dados ainda não existe.")
        return

    backup_file = "lanchonete_dados_backup.json"

    shutil.copy(
        DATA_FILE,
        backup_file
    )

    print(
        f"Backup criado com sucesso: "
        f"{backup_file}"
    )


def main():
    load_data()

    while True:

        show_menu()

        option = input("Escolha uma opção: ")

        if option == "1":
            register_product()

        elif option == "2":
            list_products()

        elif option == "3":
            make_order()

        elif option == "4":
            list_orders()

        elif option == "5":
            change_price()

        elif option == "6":
            remove_product()

        elif option == "7":
            sales_report()

        elif option == "8":
            search()

        elif option == "9":
            most_sold_product()

        elif option == "10":
            total_sold_today()

        elif option == "11":
            export_csv()

        elif option == "12":
            backup_json()

        elif option == "13":
            save_data()
            print("Sistema encerrado.")
            break

        else:
            print("Opção inválida.")


main()
