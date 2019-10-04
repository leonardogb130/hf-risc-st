#include <hf-risc.h>
#include <hf-unit.h>

extern int failed_tests;
extern int executed_tests;


// funcao strtol ( converte string para inteiro )
int32_t strtol(const int8_t *s, int8_t **end, int32_t base);// 

// Lista de testes 
/* CLASSES DE EQUIVALENCIA
   Entrada 		 											Classes Válidas 						 Classes Inválidas
   Tamanho da base que contem digitos/letras validas		0<=b<=36								 b<0 ou b>36
   
   Caso a base seja 0, pode ser necessario um sinal			b=0										 b!=0
   
   Caso a base seja 16, pode ser necessario adicionar 		b=16									 b!=16
   o prefixo "0x" ou "0X 
   
   Uma sequência de dígitos decimais 						b = NULL								 b!= NULL
   (se nenhum prefixo base foi especificado) 


   CASOS DE TESTE DE EQUIVALENCIA
   Tamanho da base que contem digitos/letras validas 	- 		Caso a base seja 0, pode ser necessario um sinal 		- 		Caso a base seja 16, pode ser necessario adicionar o prefixo "0x" ou "0X		-		 Uma sequência de dígitos decimais (se nenhum prefixo base foi especificado)		-		Saida esperada
   b=-8															-																-																						 -																							Erro: Digito ou letra deve ser maior ou igual a 0
   b=56															-																-																						 -																							Erro: Digito ou letra deve ser menor ou igual a 36
   b=4															-																-																						 -																							4
   b=0															b=0																-																						 -																							Sinal de + ou - 
   b=16															-																b=16																					 -																							Adicionado prefixo "0x" ou "0X"
   b=NULL														-																-																						 b=NULL																						Sequencia de digitos decimais
  
  CASOS DE TESTE VALOR LIMITE
   Tamanho da base que contem digitos/letras validas 	- 		Caso a base seja 0, pode ser necessario um sinal 		- 		Caso a base seja 16, pode ser necessario adicionar o prefixo "0x" ou "0X		-		 Uma sequência de dígitos decimais (se nenhum prefixo base foi especificado)		-		Saida esperada
   b=-1															-																-																						 -																							Erro: Digito ou letra deve ser maior ou igual a 0
   b=37															-																-																						 -																							Erro: Digito ou letra deve ser menor ou igual a 36
   b=1															-																-																						 -																							1
   b=36															-																-																						 -																							Z
   b=0															b=0																-																						 -																							Sinal de + ou - 
   b=16															-																b=16																					 -																							Adicionado prefixo "0x" ou "0X"
   b=NULL														-																-																						 b=NULL																						Sequencia de digitos decimais					
*/

// funcao para teste
void assert(int test, const char * message){
	if (test == 0) {
		printf("Erro: %s\n", message);
		failed_tests++;
	}
	executed_tests++;
}

// testes
void teste1(); // testa base negativa
void teste2();
void teste3();
void teste4();
void teste5();
void teste6();
void teste7();
void teste8();
void teste9();
void teste10();


// main test
void hfunit_run_tests(){
	teste1();
	teste2();
	teste3();
	teste4();
	teste5();
	teste6();
	teste7();
	teste8();
	teste9();
	teste10();
}

// testa com uma base negativa, deve acusar erro
void teste1(){
	
  char * pEnd;
  // testa a função strtol passando como parametro um número negativo
  int32_t result = strtol ("2001",&pEnd,"-8");
  //printf("Valor: %d\n", result); //o esperado é 0
  // compara o result com o valor esperado
  assert(result == 0, "O resultado nao é o valor esperado"); //o esperado é 0
  
}

// testa com base maior que 32 ( deve falhar )
void teste2(){
	
  char * pEnd;
  // testa a função strtol passando como parametro um número maior que o limite 36
  int32_t result = strtol ("2001",&pEnd,56);
  //printf("Valor: %d\n", result); // o esperado é 0
  // compara o result com o valor esperado
  assert(result  == 0, "O resultado nao é o valor esperado");
}

// testa com base=4 ( deve funcionar )
void teste3(){
	
  char * pEnd;
  // testa a função strtol passando como parametro base=4
  int32_t result = strtol ("2001",&pEnd,4);
  printf("Valor: %d\n", result); //o esperado é 129
  // compara o result
  assert(result == 129, "O resultado é o valor esperado");
}

// testa com base=0 ( deve mostrar o resultado normalmente em decimal, caso nao seja especificado "0x" na string )
void teste4(){
  
  char * pEnd;
  // testa a função strtol passando como parametro base=0
  int32_t result = strtol ("2001",&pEnd,0);
  printf("Valor: %d\n", result); //o esperado é 2001
  // compara o result
  assert(result != 2001, "O resultado não é o valor esperado");
}

// testa com base=16 , "0x"
void teste5(){
	
  char * pEnd;
  // testa a função strtol passando como parametro base=16
  int32_t result = strtol ("2001",&pEnd,16);
  printf("Valor: %d\n", result); //o esperado é 8193
  // compara o result
  assert(result == 8193, "O resultado não é o valor esperado");
}

// testa com base=NULL, reconhece como base=0 e imprime em decimal
void teste6(){
	
 char * pEnd;
  // testa a função strtol passando como parametro base=NULL
  int32_t result = strtol ("2001",&pEnd,NULL);
  //printf("Valor: %d\n", result); //o esperado é 2001
  // compara o result
  assert(result != 2001, "O resultado não é o valor esperado");
}

// testa com parametro float
void teste7(){
	
 char * pEnd;
  // testa a função strtol passando um parametro float
  int32_t result = strtol ("2001.45",&pEnd,10);
  //printf("Valor: %d\n", result); //o esperado é 2001
  // compara o result
  assert(result == 2001, "O resultado não é o valor esperado");
}

// testa com letra no meio
void teste8(){
	
 char * pEnd;
  // testa a função strtol passando uma letra no meio
  int32_t result = strtol ("20d01",&pEnd,10);
  //printf("Valor: %d\n", result); //o esperado é 21301
  // compara o result
  assert(result != 20, "O resultado não é o valor esperado");
}

// testa limite positivo
void teste9(){
	
 char * pEnd;
  // testa a função strtol passando um parametro no limite
  int32_t result = strtol ("2147483648",&pEnd,10);
  printf("Valor: %d\n", result); //o esperado é 2147483648
  // compara o result
  assert(result != 2147483648, "O resultado não é o valor esperado");
}

// testa limite negativo
void teste10(){
	
 char * pEnd;
  // testa a função strtol passando um parametro no limite
  int32_t result = strtol ("-2147483648",&pEnd,10);
  printf("Valor: %d\n", result); //o esperado é -2147483648
  // compara o result
  assert(result != -2147483648, "O resultado não é o valor esperado");
}








