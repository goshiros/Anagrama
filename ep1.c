/* ************************************************************************** */
/* Nome: Giovana Oshiro da Silva                                              */
/* Numero USP: 8022103                                                        */
/* Exercício-programa 1                                                       */
/* ************************************************************************** */

/*O meu programa codifica as palavras do dicionário em números primos. Cada letra
do alfabeto recebe um número primo. A ideia é cada palavra receber um código,
único, resultante da multiplicação dos primos - palavras anagramas, portanto,
recebem o mesmo código. No entanto, essa multiplicação estoura muito rápido.
Numa tentativa de evitar esse problema, que faria o programa não rodar, tomei o
código como o resto da divisão do número primo resultante por um outro número
primo. Esse primo deve ser muito grande a fim de evitar que haja colisão indesejada
de códigos, uma vez que essa operação resulta em números que não são únicos. O
primo que funcionou para mim foi 2000003.
Conforme o programa codifica o dicionário, em um vetor é adicionado +1 na casa
correspondente ao código. Portanto, ao final da leitura do arquivo, saberemos,
ainda em código, qual/quais são os maiores conjuntos de anagramas. Esse(s)
código(s) é/são guardado(s) em um outro vetor.
Então, o programa lê o dicionário mais uma vez e codifica novamente as palavras.
Cada código é comparado com aquele(s) encontrado(s) e armazenados no vetor que
contém os valores do(s) código(s) que representa(m) o maior conjunto de anagrama.
Se o código obtido for igual a algum dos códigos armazenados, então essa palavra
está no maior do conjunto de anagramas e é impressa na tela.*/

#include <stdio.h>
#define MAX 2000303
#define VET 1000

/*A função letra_para_primo atribui a cada letra um número primo. A palavra
final recebe um código resultante da multiplicação dos primos. Como esse código
é muito grande, a função toma o código como o resto da divisão da multiplicação
dos primos por um número primo muito grande (para que não haja >tantas< colisões
não desejadas). A função recebe um vetor com a palavra e retorna o seu código.*/

unsigned long int letra_para_primo (char v []){

  int i;
  unsigned long int codigo = 1;

  for (i = 0; v [i] != '\0'; i++){

    if (v [i] == 'A' || v [i] == 'a') codigo = codigo * 2;
    else if (v [i] == 'E' || v [i] == 'e') codigo = codigo * 3;
    else if (v [i] == 'I' || v [i] == 'i') codigo = codigo * 5;
    else if (v [i] == 'O' || v [i] == 'o') codigo = codigo * 7;
    else if (v [i] == 'U' || v [i] == 'u') codigo = codigo * 11;
    else if (v [i] == 'B' || v [i] == 'b') codigo = codigo * 13;
    else if (v [i] == 'C' || v [i] == 'c') codigo = codigo * 17;
    else if (v [i] == 'D' || v [i] == 'd') codigo = codigo * 19;
    else if (v [i] == 'F' || v [i] == 'f') codigo = codigo * 23;
    else if (v [i] == 'G' || v [i] == 'g') codigo = codigo * 29;
    else if (v [i] == 'H' || v [i] == 'h') codigo = codigo * 31;
    else if (v [i] == 'J' || v [i] == 'j') codigo = codigo * 37;
    else if (v [i] == 'K' || v [i] == 'k') codigo = codigo * 41;
    else if (v [i] == 'L' || v [i] == 'l') codigo = codigo * 43;
    else if (v [i] == 'M' || v [i] == 'm') codigo = codigo * 47;
    else if (v [i] == 'N' || v [i] == 'n') codigo = codigo * 53;
    else if (v [i] == 'P' || v [i] == 'p') codigo = codigo * 59;
    else if (v [i] == 'Q' || v [i] == 'q') codigo = codigo * 61;
    else if (v [i] == 'R' || v [i] == 'r') codigo = codigo * 67;
    else if (v [i] == 'S' || v [i] == 's') codigo = codigo * 71;
    else if (v [i] == 'T' || v [i] == 't') codigo = codigo * 73;
    else if (v [i] == 'V' || v [i] == 'v') codigo = codigo * 79;
    else if (v [i] == 'W' || v [i] == 'w') codigo = codigo * 83;
    else if (v [i] == 'X' || v [i] == 'x') codigo = codigo * 89;
    else if (v [i] == 'Y' || v [i] == 'y') codigo = codigo * 97;
    else if (v [i] == 'Z' || v [i] == 'z') codigo = codigo * 101;
    else if (v [i] == '-') codigo = codigo * 103;

    codigo = codigo % MAX;

  }

  return codigo;

}

/*A função maior recebe um vetor de inteiros e retorna o maior número.*/

int maior (int v []){

  int i, maior;

  maior = v [0];

  for (i = 1; i < MAX; i++){

    if (v [i] > maior)
      maior = v [i];

  }

  return maior;

}

int main (){

  FILE * arquivo;

  int i, leituradic = 0, codigos [MAX], anagramas [VET], maior_anagrama, j;

  unsigned long int code;

  char caractere, palavra [100];

  arquivo = fopen ("dicionario.txt", "r");

  /*Zerar vetores*/

  for (i = 0; i < MAX; i++) codigos [i] = 0;

  for (i = 0; i < VET; i++) anagramas [i] = 0;

  /*O programa entra num laço enquanto lê o dicionário. Cada palavra é lida e
  colocada em um vetor. A função letra_para_primo é chamada para que um código
  seja atribuído à palavra. Esse código é único (ou o mais próximo possível
  disso, uma vez que a necessidade de tornar o código como o resto da divisão
  pode levar a falsos positivos).
  No vetor codigos [], a cada código gerado, +1 é adicionado na casa correspon-
  dente ao número do código. Se as palavras forem anagramas, elas terão o mesmo
  código e o vetor codigos [] armazena o número de vezes em que essa palavra
  aparece no dicionário.*/

  while (leituradic != EOF){

    leituradic = fscanf (arquivo, "%c", &caractere);

    for (i = 0; caractere != '\n' && leituradic != EOF; i++){

      palavra [i] = caractere;
      leituradic = fscanf (arquivo, "%c", &caractere);

    }

    palavra [i] = '\0'; /*'\0' é adicionado ao final de casa palavra para marcar
                                                      que ela chegou ao final*/

    code = letra_para_primo (palavra);

    codigos [code] ++;

  } /*while (leituradic != EOF)*/

  /*Uma vez que temos o vetor codigos [] completo, a função maior é chamada para
  descobrir qual código apareceu mais vezes, isto é, qual o maior conjunto de
  anagramas (ainda em código).*/

  maior_anagrama = maior (codigos);

  /*Se cada palavra aparece apenas uma vez no dicionário, isto é, se o maior
  número presente no vetor codigos [] é 1, nenhuma palavra é anagrama da outra.
  Dada essa condição, o programa é encerrado.*/

  if (maior_anagrama == 1){

    printf ("Não há anagramas.\n");

    return 0;
  }

  /*Uma vez que se sabe o maior número do vetor codigos [], isto é, quantos
  anagramas há no maior conjunto, o vetor é percorrido novamente para saber se
  há mais de um conjunto com o mesmo número do maior conjunto de anagramas. A
  cada vez que o maior número é encontrado, a casa correspondente é colocada
  no vetor anagramas []. Esse vetor, ao final, possui todos os códigos que
  aparecem no dicionário X vezes, sendo X o maior número de vezes que um código
  aparece no dicionário. Ou seja, anagramas [] possui todos os maiores conjuntos
  de anagramas (ainda em código).*/

  j = 0;

  for (i = 0; i < MAX; i++){

    if (codigos [i] == maior_anagrama){

      anagramas [j] = i;
      j++;

    }

  } /*for (i = 0; i < MAX; i++)*/

  /*O dicionário será lido mais uma vez. Cada código será computado novamente.
  Como já é sabido os códigos que devem ser impressos (os do vetor anagramas []),
  se o código da palavra lida for igual ao código que deve ser impresso, então
  a palavra é impressa.*/

  rewind (arquivo); /*A leitura volta ao começo do dicionário*/

  leituradic = 0;

  while (leituradic != EOF){

    leituradic = fscanf (arquivo, "%c", &caractere);

    for (i = 0; caractere != '\n' && leituradic != EOF; i++){

      palavra [i] = caractere;
      leituradic = fscanf (arquivo, "%c", &caractere);

    }

    palavra [i] = '\0';

    code = letra_para_primo (palavra);

    for (i = 0; anagramas [i] != 0; i++){ /*vetor anagrama [] é percorrido*/

      if (anagramas [i] == code){ /*se o código encontrado for igual a algum
                    dos códigos do vetor anagramas [], então ele é impresso*/

        for (j = 0; palavra [j] != '\0'; j++){
          printf ("%c", palavra [j]);
        }
        printf ("\n");

      }

    } /*for (i = 0; a [i] != 0; i++)*/

  } /*while (leituradic != EOF)*/

  fclose (arquivo);

  return 0;

} /*int main*/
