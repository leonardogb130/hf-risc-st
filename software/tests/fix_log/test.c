#include <hf-risc.h>
#include <hf-unit.h>
#include "fixed.h"

// função testada sera a fix_logaritmo
fixed_t fix_log(fixed_t fp, fixed_t base);

// funcao para comparação
void assert(int test, const char * message){
	if (test == 0) {
		printf("Error: %s\n", message);
		failed_tests++;
	}
	executed_tests++;
}

// Lista de testes 
/* CLASSES DE EQUIVALENCIA
   Entrada 		 Classes Válidas 			 Classes Inválidas
   
   fp/base         	 fp/base é um numero > 0   		fp/base é um numero <= 0

  CASOS DE TESTE DE EQUIVALENCIA
  fp/base 		Saida esperada
  5				0.6989
  0				Erro: numero deve ser > 0
  -3			Erro: numero deve ser > 0
  z    			Erro: deve ser informado um numero
  
   CASOS DE TESTE VALOR LIMITE
   fp/base 		 Saida esperada
   0			 Erro: numero deve ser > 0
   0.9			 -0.045
   472700090348091277312‬		Excedido limite de float
*/

// testes
void teste1();
void teste2();

// main test
void hfunit_run_tests(){
	teste1();
	teste2();
}

// testa se funciona com um valor inteiro positivo, com fix, deve funcionar
void teste1(){

        // setando o valor em fixed
        fixed_t input = fix_val(5.5f);
	// atribuicao do valor fixed a funcao fix_ln
	fixed_t result = fix_log(input,10);

	int8_t buf[30];
	fixtoa(result, buf, 6);

	assert(buf[0] == '1' && buf[1] == '.' && buf[2] == '7' && buf[3] == '0', "Log de 1.5f deve ser aproximadamente 1.704748");
}



 testa limite com fix
void teste2(){
	
	 // setando o valor em fixed
        fixed_t input = fix_val(472700090348091277312);
	// atribuicao do valor fixed a funcao fix_log
	fixed_t result = fix_log(input,10);
}



