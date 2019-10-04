#include <hf-risc.h>
#include <hf-unit.h>

// função testada sera a logaritmo
float log(float arg);

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

// testa se funciona com um valor inteiro positivo
void teste1(){
	
	float v = log(5.0);
	float expected = 0.69;
	hfunit_comp_float(v,expected, "log(5.0)");
 
}

// testa se funciona com valor = 0 ( deve falhar )
void teste2(){
	
	float result;
	
	testa_hfunit_log(0, "Teste falhou");
	result = log(0);
 
}

// testa se funciona com valor = -3 ( deve falhar )
void teste3(){
	float result;
	
	testa_hfunit_log(-3, "Teste falhou");
	result = log(-3);
 
}

// testa se funciona letra = Z ( deve falhar )
void teste4(){
	float result;
	char letra = 'Z';
	
	testa_hfunit_log(letra, "Teste falhou");
	result = log(letra);
 
}

// testa limite de float, deve falhar
void teste5(){
	float result;
	
	testa_hfunit_log(472700090348091277312, "Teste falhou");
	result = log(472700090348091277312);
 
}



