#include <hf-risc.h>
#include <hf-unit.h>

extern int failed_tests;
extern int executed_tests;


// função testada sera a logaritmo
float log(float arg);

// funcao para teste
void assert(int test, const char * message){
	if (test == 0) {
		printf("Erro: %s\n", message);
		failed_tests++;
	}
	executed_tests++;
}

// Lista de testes 
/* CLASSES DE EQUIVALENCIA
   Entrada 		 Classes Válidas 			 Classes Inválidas
   
   n         	 n é um numero > 0   		n é um numero <= 0

  CASOS DE TESTE DE EQUIVALENCIA
  n 			Saida esperada
  5				0.6989
  0				Erro: numero deve ser > 0
  -3			Erro: numero deve ser > 0
  z    			Erro: deve ser informado um numero
  
   CASOS DE TESTE VALOR LIMITE
   n 			 Saida esperada
   0			 Erro: numero deve ser > 0
   0.9			 -0.045
   3.5E38		 Excedido limite de float
*/

// testes
void teste1();
void teste2();
void teste3();
void teste4();
void teste5();


// main test
void hfunit_run_tests(){
	teste1();
	teste2();
	teste3();
	teste4();
	teste5();
}

// testa se funciona com um valor inteiro positivo, funciona
void teste1(){
	
	float resultado = log(5.5);
	float expected = 1.704748;
	printf("%f\n", resultado);

	// resultado esperado igual ao resultado, então assert nao dispara
	assert(resultado == expected, "Entrada válida");
 
}

// testa se funciona com valor = 0 ( deve falhar )
void teste2(){
	
	float resultado = log(0);
	// deve gerar como resultado esperado inf
	float inf = ((-1.0)/(0.0));
	//atribuo o inf ao esperado
	float expected = inf;
	printf("%f\n", resultado);
    // comparo o esperado com o resultado
	assert(resultado == expected, "Impossível log(0)");
 
}

// testa se funciona com valor = -3 ( deve falhar )
void teste3(){
	float resultado = log(-3.0);
	float nan = ((0.0)/(0.0));
	float expected = nan;
	printf("%f\n", resultado);

	assert(resultado == expected, "Impossível log(-3)");
 
}

// testa se funciona letra = Z ( deve falhar )
void teste4(){
		
	float resultado = log('z');
	float nan = ((0.0)/(0.0));
	float expected = nan;
	printf("%f\n", resultado);

	assert(resultado == expected, "Entrada inválida");
 
}

// testa limite de float, deve falhar
void teste5(){
	
	float resultado = log(472700090348091277312);
	float expected = 43891613;
	printf("%f\n", resultado);

	assert(resultado > expected, "Excedido limite");
 
}



