#include <hf-risc.h>
#include <hf-unit.h>



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

// testes
void teste1(); // testa base negativa
void teste2();
void teste3();
void teste4();
void teste5();
void teste6();


// main test
void hfunit_run_tests(){
	teste1();
	teste2();
	teste3();
	teste4();
	teste5();
	teste6();
}

// testa com uma base negativa, deve acusar erro
void teste1(){
	
 /* //char szNumbers[] = "2001";
  char * pEnd;
  long int result;
  int expected = 2001;
  
  result = strtol (2001,NULL,-8);
  //testa_hfunit_base(-8, "Teste falhou");
 
  //printf (result);
  
  hfunit_comp_float(result,expected, ("strtol(\"2001\",NULL,-8)"));
*/
}

// testa com base maior que 32 ( deve falhar )
void teste2(){
	
  char szNumbers[] = "teste2";
  char * pEnd;
  long int li1;
  
  li1 = strtol (szNumbers,&pEnd,56);
  testa_hfunit_base(56, "Teste falhou");
 
  printf (li1);
}

// testa com base=4 ( deve funcionar )
void teste3(){
	
  int string = 1000;
  //char * pEnd;
  int resultado;
  int base = 4;
  int expected = 1000;
  
  resultado = strtol (string,0,base);
  //testa_hfunit_base(4, "Teste passou");
  hfunit_comp_float(resultado,expected," ");
 
  printf ("Equivalente em decimal: %d\n", resultado);
}

// testa com base=0 ( deve mostrar o resultado normalmente em decimal, caso nao seja especificado "0x" na string )
void teste4(){
  
  int string = 1000;  // base4 = 33220
  //char * pEnd;
  int resultado;
  int base = 0;
  int expected = 1000;
  
  resultado = strtol (string,0,base);
  //testa_hfunit_base(4, "Teste passou");
  hfunit_comp_float(resultado,expected," ");
 
  printf ("Equivalente em decimal: %d\n", resultado);
  printf ("Equivalente esperado: %d\n", expected);
}

// testa com base=16 , "0x"
void teste5(){
	
  char szNumbers[] = "0xffff";
  char * pEnd;
  long int li1;
  
  li1 = strtol (szNumbers,&pEnd,0);
  testa_hfunit_base(0, "Teste passou");
 
  printf ("Equivalente em decimal: %ld\n", li1);
}

// testa com base=NULL, reconhece como base=0 e imprime em decimal
void teste6(){
	
  char szNumbers[] = "-teste";
  char * pEnd;
  long int li1;
  
  li1 = strtol (szNumbers,NULL,NULL);
  testa_hfunit_base(NULL, "Teste passou");
 
  printf ("Equivalente em decimal: %ld\n", li1);
}




