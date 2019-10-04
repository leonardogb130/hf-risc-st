/*
This matrix lib can work with 3 different types: fixed, float, and double.
just change the variable MATRIX_TYPE in the makefile
*/

#include <mat_type.h> // this include define the type of the matrix
#include <matrix.h>   // the functions under test are defined here
#include <hf-risc.h>
#include <hf-unit.h>

// função testada sera a matriz identidade, onde se i=j ,deve-se ser 1, caso contrario 0
struct Matrix setEye(int order);

// Lista de testes 
/* CLASSES DE EQUIVALENCIA
   Entrada 		 			 		Classes Válidas 			 Classes Inválidas
   Seta '1' caso i=j         		i=j  						 i!=j
   
   Ordem da matriz					Ordem é um número inteiro    Ordem é um número inteiro menor ou igual a 0
									positivo                     Ordem não é um número inteiro

  CASOS DE TESTE DE EQUIVALENCIA
  Seta '1' caso i=j				 	 Ordem da matriz					 			Saida esperada
  i=3 e j=3                      	 -                                              '1'
  i=1 e j=2                          -                                              '0'
  -                                  1												Matriz 1x1
  -                                  0												Erro: A ordem deve ser um número inteiro positivo
  -                                  -3												Erro: A ordem deve ser um número inteiro positivo
  
 
  CASOS DE TESTE VALOR LIMITE
  Seta '1' caso i=j				 	 Ordem da matriz					 			Saida esperada
  -                                  0.99											Erro: A ordem deve ser um número inteiro positivo
  -                                  6700000000000000000000000000					Erro: Excedido o tamanho máximo permitido de tipo int

*/

// lista de testes
void teste1();
void teste2();
void teste3();
void teste4();
void teste5();
void teste6();


// main tests
void hfunit_run_tests(){
	teste1();
	teste2();
	teste3();
	teste4();
	teste5();
	teste6();

}
//printa matriz identidade de tamanho 3, onde i=j, deve funcionar
void teste1() {

struct Matrix M1;

printf("Identity Matrix of size %d by %d:\n", 3, 3);
M1 = setEye(3);
testa_hfunit_matriz(3, "Teste passou");
print_matrix(M1);

}

//printa matriz identidade de ordem 1, deve funcionar
void teste2() {

struct Matrix M1;

printf("Identity Matrix of size %d by %d:\n", 1, 1);
M1 = setEye(1);
testa_hfunit_matriz(1, "Teste passou");
print_matrix(M1);

}

//printa matriz identidade de ordem 0, deve acusar erro
void teste3() {

struct Matrix M1;

M1 = setEye(0);
testa_hfunit_matriz(0, "Teste falhou");
print_matrix(M1);

}

//printa matriz identidade de ordem negativa, deve acusar erro
void teste4() {

struct Matrix M1;

M1 = setEye(-3);
testa_hfunit_matriz(-3, "Teste falhou");
print_matrix(M1);

}

//teste de limites da matriz, limite minimo, deve falhar pois não é um núumero inteiro
void teste5() {

struct Matrix M1;

M1 = setEye(0.99);
testa_hfunit_matriz(0.99, "Teste falhou");
print_matrix(M1);

}

//teste de limites da matriz, limite maximo, deve falhar pois ultrapassa limite de tipo int
void teste6() {

struct Matrix M1;

M1 = setEye(5);
testa_hfunit_matriz(6700000000000000000000000000, "Teste falhou");
print_matrix(M1);

}


