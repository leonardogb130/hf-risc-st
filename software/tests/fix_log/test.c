#include <hf-risc.h>
#include <hf-unit.h>
#include "fixed.h"

// função testada sera a fix_logaritmo
fixed_t fix_log(fixed_t fp, fixed_t base);

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
void teste3();
void teste4();
//void teste5();


// main test
void hfunit_run_tests(){
	teste1();
	teste2();
	teste3();
	teste4();
	//teste5();
}

// testa se funciona com um valor inteiro positivo, normal e com fix, deve funcionar
void teste1(){
	
	float result;
	fixed_t result2;
	
	testa_hfunit_log(5, "Teste passou");
	result = log(5);
	result2 = fix_log(5,5);
 
	printf("Valor do log: %f\n", result);
	printf("Valor do fix_log: %f\n", result2);
}

// testa se funciona com valor = 0 ( deve falhar )
void teste2(){
	
	float result;
	fixed_t result2;
	
	testa_hfunit_log(0, "Teste falhou");
	result = log(0);
	result2 = fix_log(0,0);
 
	printf("Valor do log: %f\n", result);
	printf("Valor do fix_log: %f\n", result2);
}

// testa se funciona com valor = -3 ( deve falhar )
void teste3(){
	float result;
	fixed_t result2;
	
	testa_hfunit_log(-3, "Teste falhou");
	result = log(-3);
	result2 = fix_log(-3,-3);
 
	printf("Valor do log: %f\n", result);
	printf("Valor do fix_log: %f\n", result2);
}

// testa se funciona letra = Z ( deve falhar )
void teste4(){
	float result;
	fixed_t result2;
	
	testa_hfunit_log('Z', "Teste falhou");
	result = log('Z');
	result2 = fix_log('Z','Z');
 
	printf("Valor do log: %f\n", result);
	printf("Valor do fix_log: %f\n", result2);
}

// testa limite com e sem fix, deve acusar erro
/*void teste5(){
	float result;
	fixed_t result2;
	
	testa_hfunit_log(472700090348091277312‬, "Teste falhou");
	result = log(472700090348091277312‬);
	result2 = fix_log(‭472700090348091277312‬,‭472700090348091277312‬);
 
	printf("Valor do log: %f\n", result);
	printf("Valor do fix_log: %f\n", result2);
}*/



