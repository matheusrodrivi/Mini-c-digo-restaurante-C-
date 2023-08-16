#include <cstring>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

void exibirCardapio() {
  cout << "========================================" << endl;
  cout << "|          Cardapio do Restaurante      |" << endl;
  cout << "========================================" << endl;
  cout << "| 1. Lasanha - R$ 20,00                 |" << endl;
  cout << "| 2. Frango a Parmegiana - R$ 25,00     |" << endl;
  cout << "| 3. Pizza - R$ 30,00                   |" << endl;
  cout << "| 4. Sair                               |" << endl;
  cout << "========================================" << endl;
}

void fazerLogin() {
  string usuario, senha;
  int digitarcpf;

  cout << "Digite seu nome de usuario: ";
  cin >> usuario;
  cout << "Digite sua senha: ";
  cin >> senha;

  if (usuario == "usuario" && senha == "senha") {
    cout << "Login efetuado com sucesso!" << endl;
  } else {
    cout << "Nome de usuario ou senha incorretos." << endl;
    cout << "Programa encerrado, recarregue para tentar novamente" << endl;
    exit(0);
  }
}



void encerrarPrograma() {
    printf("Encerrando programa...");
    exit(0);
}

bool validarCPF(string cpf) {
    int soma1 = 0, soma2 = 0;
    int j = 10, k = 11;

    for (int i = 0; i < 9; i++) {
        soma1 += (cpf[i] - '0') * j;
        j--;
    }

    soma1 %= 11;
    soma1 = (soma1 < 2) ? 0 : 11 - soma1;

    for (int i = 0; i < 9; i++) {
        soma2 += (cpf[i] - '0') * k;
        k--;
    }

    soma2 += soma1 * 2;
    soma2 %= 11;
    soma2 = (soma2 < 2) ? 0 : 11 - soma2;

    return (soma1 == cpf[9] - '0') && (soma2 == cpf[10] - '0');
}

int main() {
  
  int opcao;
  int saida;
  int opcao2;
  float precoFinal = 0;
  float preco;
  int item;
  int opcao3;
  float desconto = 0;
  int cpfDigitado;
  float desconto2 = 0;
  string cpf;
  
  
  
  printf("======================= BEM-VINDO AO RESTAURANTE DOCE LAR   "
         "======================= \n");

  while(true){
    printf("Digite 1 para se registrar ou logar\n");
    scanf("%d", &opcao2);

    switch(opcao2){
    case 1:
      fazerLogin();
      break;
      
    default:
      printf("Opcao invalida. Reinicie para tentar novamente\n");
      exit(0);
    }
    break;
  }

  while (true) {
    printf("Escolha uma opcao:\n");
    printf("2 - Exibir Cardapio\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 2:
      exibirCardapio();
    
      while (true) {
        printf("Escolha um item do cardapio (1-4): \n");
        scanf("%d", &item);
        if (item == 1) {
          printf("Voce escolheu Lasanha. Bom apetite!\n\n");
          break;
        } else if (item == 2) {
          printf("Voce escolheu Frango a Parmegiana. Bom apetite!\n\n");
          break;
        } else if (item == 3) {
          printf("Voce escolheu Pizza. Bom apetite!\n\n");
          break;
        } else if (item == 4) {
          printf("Voltando ao menu principal.\n\n");
          break;
        } else {
          printf("Opcao invalida. Tente novamente.\n\n");
        }
      }
      
      break;
      default:
      printf("Opcao invalida.\n\n");
      break;
    }

    if(item == 1){
        preco = 20.00;
        precoFinal = precoFinal + preco;
      }
    else if (item == 2){
        preco = 25.00;
        precoFinal = precoFinal + preco;
    }
    else if (item == 3){
        preco = 30.00;
        precoFinal = precoFinal + preco;
    }

    desconto = precoFinal * 0.05;
    desconto2 = precoFinal - desconto;

    printf("============= O valor da compra é %.2f =============\n\n\n", precoFinal); 
    printf ("============= Pagamento ============= \n 1. Dinheiro \n 2. Cartao de credito\n 3. Cartão de debito \n\n\n");
    printf ("*Compras no cartão de debito possuem 5 porcento de desconto\n\n\n");
    printf ("*Para conseguir o desconto é necessario o fornecimento do CPF  \n\n\n");

    scanf ("%d", &opcao3);
    
   switch (opcao3){

      case 1:
        printf ("Pagamento de %.2f Efetuado \n", precoFinal);
        printf ("Volte sempre \n\n");
        exit(0);

      case 2:
        printf ("Pagamento Efetuado de %.2f \n", precoFinal);
        printf ("Volte sempre");
        exit(0);
      
      case 3:

        cout << "Digite o CPF sem pontos e tracos: ";
        cin >> cpf;
        
    if (validarCPF(cpf)) {
        cout << "CPF valido!" << endl;
        printf ("O total a ser pago pelo pedido %d é %.2f \n", item, desconto2);
        printf ("Volte sempre \n");
        exit(0);
      
    } else {
        cout << "CPF invalido!" << endl;
        encerrarPrograma();    
    }
  }
    return 0;
  }
}
