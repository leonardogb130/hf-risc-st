/*
This matrix lib can work with 3 different types: fixed, float, and double.
just change the variable MATRIX_TYPE in the makefile
*/

#include <mat_type.h> // this include define the type of the matrix
#include <matrix.h>   // the functions under test are defined here
#include <hf-risc.h>
#include <hf-unit.h>

extern int failed_tests;
extern int executed_tests;

// função testada sera a matriz identidade, onde se i=j ,deve-se ser 1, caso contrario 0
struct Matrix setEye(int order);


// funcao para comparação
void assert(int test, const char * message){
	if (test == 0) {
		printf("Error: %s\n", message);
		failed_tests++;
	}
	executed_tests++;
}


void assert_matrix(struct Matrix m, typ_var * values, int columns, int lines) {
	char * expectedBuffer[16];
	char * valueBuffer[16];
	int err = 0;
	int i = 0;

	for(int x = 0; x < columns; x++) {
		for(int y = 0; y < lines; y++) {
			int value = get_value(m, x, y);
			int expected = values[++i];
			if (value != expected) {
				printf("Matrix value mismatch at line %d, column %d: got %s, expected %s\n", y, x, valueBuffer, expectedBuffer);
				err = 1;
			}
		}
	}
	executed_tests++;
	if (err == 1) {
		failed_tests++;
	}
}

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


// main tests
void hfunit_run_tests(){
	teste1();
	teste2();
	teste3();
	teste4();

}
//printa matriz identidade de tamanho 3, onde i=j, deve funcionar
void teste1() {

struct Matrix M1;

float expected_list[16];

float value_list[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

printf("Identity Matrix of size %d by %d:\n", 3, 3);
M1 = setEye(3);
print_matrix(M1);

	for (int i = 0; i < 16; i++) 
	{
		expected_list[i] = mul(value_list[i], 0);
	}

 assert_matrix(M1, expected_list, 3, 3);

}

//printa matriz identidade de ordem 1, deve funcionar
void teste2() {

struct Matrix M1;

float expected_list[16];

float value_list[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

printf("\nIdentity Matrix of size %d by %d:\n", 1, 1);
M1 = setEye(1);
print_matrix(M1);

	for (int i = 0; i < 16; i++) 
	{
		expected_list[i] = mul(value_list[i], 0);
	}

 assert_matrix(M1, expected_list, 1, 1);

}

//printa matriz identidade de ordem 0, deve acusar erro
void teste3() {

struct Matrix M1;

float expected_list[16];

float value_list[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

M1 = setEye(0);
print_matrix(M1);


	for (int i = 0; i < 16; i++) 
	{
		expected_list[i] = mul(value_list[i], 0);
	}

 assert_matrix(M1, expected_list, 0, 0);

}

//printa matriz identidade de ordem negativa, deve acusar erro
void teste4() {


struct Matrix M1;

float expected_list[16];

float value_list[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

M1 = setEye(-3);
print_matrix(M1);


	for (int i = 0; i < 16; i++) 
	{
		expected_list[i] = mul(value_list[i], 0);
	}

 assert_matrix(M1, expected_list, -3, -3);

}


