#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //Biblioteca para trabalhar com strings
#include <conio.h>

#define TAM 500

typedef struct  cadastro_produto    //Registro
{
        int CodProd, Estoq;             //Guarda Cód.Produto e Estoque
        char DescProd[100];             //Guarda Descrição do produto
        float VlrCompra, VlrVenda;      //Guarda valor de compra e venda Unitário do produto.        
} cadastro;   //Apelido do Registo

main ()

{
     //Variaveis
     int entrada_estoq=0, i=1, j, qtdevenda, venda, k;	 //Variavel contadora 'i'(só é alterada quando cadastra o produto)
     float valor_total;
     char opcao, saida='n', saidaestoq='n', nome_user[100], saida_np='n', svenda='n';
     cadastro c1[TAM];         //Variavel declarada do Registro
     //c1[0].CodProd=0;
     c1[0].CodProd=0;
     c1[0].Estoq=0;
     
     system ("color a");       //Identificação do Usuário
     printf ("Informe seu nome: ");
     fflush (stdin);		//Limpa endereço de memória onde será inserido dados para Variavel seguinte.
     gets (nome_user);		//gets, imprime tudo o que tem depois dos espaços '/0'
     
     //Inicio Primeiro Principal
     do
     {
           //Tela Inicial (Menu)
           system ("cls");
           system ("color a");    //Muda a cor das letras para verde
	       printf ("                        _______________________________"); printf ("\n");
	       printf ("-----------------------|                               |-----------------------");    printf ("\n");
	       printf ("                       | ** Play & Business Control ** |");                   printf ("\n");   
	       printf ("-----------------------|_______________________________|-----------------------");                 printf ("\n\n");
           printf ("Bem-Vindo %s, escolha uma das opcoes para iniciar o programa:", nome_user);       printf ("\n\n");
           printf ("1 - Cadastro de Produtos");      printf ("\n");
           printf ("2 - Frente de Caixa");           printf ("\n");
           printf ("3 - Consultar Estoque");         printf ("\n");
           printf ("4 - Entrada de Produtos");       printf ("\n");
           printf ("5 - Listagem de Produtos");      printf ("\n");
           printf ("6 - Sair");                      printf ("\n\n");
           printf ("-------------------------------------------------------------------------------"); printf ("\n");
           scanf (" %c", &opcao);

           //Decisão no Menu
           switch (opcao)
           {
                  case '1':
                  {
                       do
                       {
                       system ("cls");      //Limpa a tela
                       printf ("\t\tCadastro de Produtos");             printf ("\n");
                       printf ("----------------------------------------------------------\n\n");
                       printf("Codigo do Produto: %i\n\n", i);
                       printf ("Informe a descricao do produto");       printf ("\n");

                            fflush(stdin);
                            gets (c1[i].DescProd);
                            for (k = 0 ; k < i ; k++)
                            {
                                if (_stricmp(c1[i].DescProd,c1[k].DescProd)==0)
                                   break; 
                            }
                            if (k < i)
                            {
                                printf ("Produto ja existente.");
                                memset(c1[i].DescProd,0,sizeof(c1[i].DescProd));      //Limpa espaço de memoria da variavel, caso já tenha algum produto com nome igual
                                printf ("\n\n\aPressione qualquer tecla");
                                scanf("%*c");                               
                            }

                       }
                       while(k < i);
                            //Código do produto
                       printf ("\nInforme preco de Compra: R$");
                       scanf (" %f", &c1[i].VlrCompra);                      printf ("\n");
                       printf ("Informe preco de Venda: R$");
                       scanf (" %f", &c1[i].VlrVenda);                      printf ("\n");
                       printf ("Informe a quantidade adquirida: ");
                       scanf ("%i", &c1[i].Estoq);
                       i++;
                       getche();
                       break;
                  }    //Fecha estrutura 'case 1'
                  case '2':
                  {
                       system ("cls");
                       printf ("\t\tFrente de Caixa");          printf ("\n");
                       printf ("----------------------------------------------------------\n\n");
                       if (i == 1)
                       {
                           printf ("Nao existem produtos cadastrados!");
                           getch ();
                           break;
                       }
                       printf ("Informe o codigo do produto a ser vendido: ");
                       scanf ("%i", &j);
                       if (j>=0 && j < i)
                       {       
                           printf ("----------------------------------------------------------\n");
                           printf ("Codigo Produto: %i", j);    printf ("\n");
                           printf ("Descricao do Produto: %s", c1[j].DescProd);  printf ("\n");
                           printf ("Preco de Venda: R$%.2f", c1[j].VlrVenda);      printf ("\n");
                           printf ("Informe a quantidade de venda: ");
                           scanf ("%i", &qtdevenda);
                           venda = c1[j].Estoq - qtdevenda; //Verifica quanto vai sobrar no estoque, se negativo uma mensagem aparece.
                           if (i < 0) 
                           {
                                 printf ("\nCodigo do produto invalido, por favor informe um codigo valido");      
                           }
                           if (venda < 0)
                           {
                              printf ("\n\nQuantidade Insuficiente!");
                              printf ("\n\nQuantidade em Estoque: %i", c1[j].Estoq);
                              getch ();
                              break;                
                           }
                           c1[j].Estoq = c1[j].Estoq - qtdevenda;
                           valor_total = qtdevenda*c1[j].VlrVenda;
                           printf ("Valor total dos produtos: R$%.2f", valor_total);   printf ("\n");
                           printf ("----------------------------------------------------------"); 
                           getch ();
                       }
			           else
                       {
                           system ("cls");
                           printf ("Codigo do produto invalido, por favor informe um codigo valido");
                           getch ();
                       }                                        
                       break;
                  }    //Fecha estrutura 'case 2'
                  case '3':
                  {
                       system ("cls");
                       if (i == 1)
                       {
                           printf ("\t\tConsultar Estoque");        printf ("\n");
                           printf ("----------------------------------------------------------\n\n");
                           printf ("Nao existem produtos cadastrados!");
                           getch ();
                           break;
                       }
                       do
                       {
                                 system ("cls");
                                 printf ("\t\tConsultar Estoque");        printf ("\n");
                                 printf ("----------------------------------------------------------\n\n");
                                 printf ("Informe o codigo a ser listado: ");
                                 scanf ("%i", &j);
                              if (j>=0 &&j < i)
                              {
                                    printf ("----------------------------------------------------------\n\n");
                                    printf ("Codigo Produto: %i", j);     printf ("\n");
                                    printf ("Descricao do Produto: %s", c1[j].DescProd);     printf ("\n");
                                    printf ("Preço de Compra: R$%.2f", c1[j].VlrCompra);     printf ("\n");
                                    printf ("Preço de Venda: R$%.2f", c1[j].VlrVenda);       printf ("\n");
                                    printf ("Estoque: %i", c1[j].Estoq);                     printf ("\n\n");
                                    printf ("Deseja fazer outra busca? <S/N>");
                                    scanf (" %c", &saidaestoq);
                              }
                              else
                              {
                                    printf ("----------------------------------------------------------\n\n");
                                    printf ("Codigo invalido!") ;                            printf ("\n\n");
                                    printf ("Deseja fazer outra busca? <S/N> ");
                                    scanf (" %c", &saidaestoq);
                                    system ("cls");
                              }
                       }
                       while (saidaestoq == 's' || saidaestoq == 'S');
                       break;
                  }    //Fecha estrutura 'case 3'
                  case '4':
                  {
                       system ("cls");   //Limpa tela
                       printf ("\t\tEntrada de Estoque");       printf ("\n");
                       printf ("----------------------------------------------------------\n\n");
                       if (i == 1)
                       {
                           printf ("Nao existem produtos cadastrados!");
                           getch ();
                           break;
                       }
                       printf ("Informe o Codigo do Produto ");
                       scanf ("%i", &j);      //Lê cod do produto
                       if (j>=0 && j < i)
                       {
                             printf ("\n");
                             printf ("Produto: %s", c1[j].DescProd);     printf ("\n\n");
                             printf ("Informe a quantidade comprada para dar entrada no estoque: ");
                             scanf ("%i", &entrada_estoq);          //Lê a quantidade para estoque
                             c1[j].Estoq = c1[j].Estoq + entrada_estoq;   //Atualiza estoque
                             printf ("Deseja alterar o valor dos produtos? <S/N>  ");
                             scanf (" %c", &saida_np);
                             if (saida_np == 's' || saida_np == 'S')
                             {
                                          printf ("----------------------------------------------------------\n\n");
                                          printf ("Informe o novo Preco de Compra: R$");
                                          scanf ("%f", &c1[j].VlrCompra);           printf ("\n");
                                          printf ("Informe o novo Preco de Venda: R$");
                                          scanf ("%f", &c1[j].VlrVenda);
                                          getch ();
                             }
                       }
                       else
                       {
                             system ("cls");
                             printf ("Codigo do produto invalido, por favor informe um codigo valido");
                             getch ();
                       }
                       break;
                  }    //Fecha estrutura 'case 4'
                  case '5':
                  {	
                       system ("cls");
                       printf ("\t\tListagem de Produtos");     printf ("\n");
                       printf ("----------------------------------------------------------\n\n");
		               if (i > 1)
		               {	
                          for(j=1;j<i;j++)
                          {
                                          fflush (stdin);
                                          printf ("Codigo: %i\n", j);
                                          printf ("Descricao: %s\n", c1[j].DescProd);
                                          printf ("Preco Compra: R$ %.2f\n", c1[j].VlrCompra);
                                          printf ("Preco Venda: R$ %.2f\n", c1[j].VlrVenda);
                                          printf ("Estoque do produto: %i\n", c1[j].Estoq);     printf ("\n");
                                          printf ("----------------------------------------------------------");     printf("\n");
                          
                                          if (j % 2 == 0)
                                          {
                                                if (i > 3)
                                                {
                                                   printf ("\n\t\tPressione qualquer tecla para continuar a listagem");
                                                   getch ();
                                                   system ("cls");
                                                   printf ("\t\tListagem de Produtos");     printf ("\n");
                                                   printf ("----------------------------------------------------------\n\n");
                                                }
                                          }
                          }
                       }
                       getch ();
		               if (i <= 1)
		                {
                    		printf ("Aviso!\n");
			                printf ("Nao existem produtos cadastrados!");
     	            		getch ();
                        }
                       break;
                  }    //Fecha estrutura 'case 5'
                  case '6':
                  {
                       system ("cls");
                       printf ("Deseja mesmo fechar o programa?\t<S/N>\n");
                       scanf (" %c", &saida);
                       break;
                  }    //Fecha estrutura 'case 6'
                  default:
                  {
                          system ("cls");
                          printf ("Opcao invalida, por favor digite uma opcao do menu.");
                          getch ();
                          system ("cls");
                          break;
                  }      //Fecha estrutura 'default'
           }      //Fecha estrutura 'switch'
     }     //Fecha 'do'
     //Termino Primeiro Laço
     while (saida != 's');
     system ("cls");
     printf ("Software desenvolvido por Renato Oliveira - Cod. 7510 - Faculdades COC"); printf ("\n");
     printf ("Docentes: Marcos Chiodi, Henrique Gagliardi");
     getch ();
}    //Fecha bloco do programa
