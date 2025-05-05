/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:05:37 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/05/05 01:01:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

1. O que são Variadic Arguments?

Normalmente, uma função é definida para receber um número fixo de argumentos.
Por exemplo, uma função que soma dois números pode ser declarada da seguinte forma:

int add(int a, int b);

Aqui a função add sempre espera receber exatamente dois argumentos do tipo int. 

No entanto, algumas situações exigem que uma função seja capaz de receber uma quantidade variável
de argumetos, depedendo da chamada. 
Um bom exemplo disso é a função printf, que pode ser chamada de várias formas diferentes: 

printf("Hello, World!\n");
printf("Número: %d\n", 42);
printf("%s tem %d anos.\n", "Ricardo", 22);

De uma forma generalizada: printf("format specifier",arg1, arg2, arg3, . . .); 

Notamos que o número de argumentos depois da string do formato ("Hello, World!", "Número: %d\n", etc)
pode mudar. 
Para resolver esta necessidade, a linguagem C permite que as funções sejam declaradas como variadic functions,
ou seja, funções que aceitam um número variável e indefinido de argumentos/parâmetros. 
É um número indefinido, pois não sabemos antecipadamente quantos argumentos a função vai receber. 

O principal objetivo é permitir criar funções mais flexíveis, que podem tratar diferentes quantidades e
tipos de dados sem precisar de múltiplas versões da função. 
Sem as variadic functions, teriamos que criar uma função diferentes para cada quantidade de argumentos,
o que seria impraticável. 

Uma Variadic Function em C é uma função capaz de aceitar um número variável de argumentos, além dos
parâmetros fixos definidos. Este tipo de função é especialmente útil quando o número ou o tipo de dados
que precisam de ser processados não é conhecido no momento da escrita do programa. Para gerir estes 
argumentos adicionais, a linguagem C utiliza o conceito de Variadic Arguments, que são lidos sequencialmente
através de mecanismos especiais definidos na biblioteca <stdarg.h>. Este processo é feito com o auxílio de
macros como a va_list, a va_start, a va_arg e a va_end, que permitem inicializar, percorrer e finalizar a
lista de argumentos de forma segura e controlada. Assim, Variadic Functions oferecem uma maneira poderosa 
de escrever funções genéricas e flexíveis, como o printf, capazes de adaptar o seu comportamento a diferentes
quantidades e tipos de entrada sem alterar a sua assinatura principal.

Os variadic arguments referem-se aos argumentos variáveis passados para uma função que foi declarada para
aceitar um número indefinido de parâmetros. A função pode ser chamada com diferentes quantidades de
argumentos.
A existência dos variadic arguments torna possível criar funções altamente flexíveis e genéricas, que se
adaptam a diferentes cenários de uso sem necessitar de alterar a sua estrutura principal. 

Em C, uma variadic function é definida para ter, pelo menos, um argumento fixo, seguido de um símbolo "..."
para indicar que uma função aceita variadic arguments. Este símbolo permite ao compilador fazer o parsing 
(análise) de um número variável de argumentos. 

Síntaxe das Variadic Functions:  return_type function_name(type arg1, ...);

 - O type arg1 é um argumento fixo;
 - "..." indica que, após o primeiro argumento (arg1), pode vir qualquer quantidade (inclusive zero) de
   argumentos adicionais. 

Por exemplo, quando escrevemos:  printf("Número: %d, String: %s\n", 42, "Hello");

Internamente, o printf está a trabalhar com variadic arguments:

   > O primeiro argumento fixo é o "Número: %d, String: %s\n".
   > A seguir, vêm os variadic arguments: 42 e "Hello".

A função precisa então de interpretar o formato da string para saber:

    > quantos argumentos foram fornecidos,
    > de que tipo são,
    > como devem ser apresentados.

Este processamento é feito com muito cuidado utilizando va_list, va_start, va_arg e va_end, uma vez que os
tipos dos variadic arguments não são conhecidos em tempo de compilação.

Quando usamos argumentos variáveis, como no ft_printf, o comportamento é o seguinte:

    > Determinação do Número de Argumentos: O número de argumentos não é especificado de forma explícita. 
	  A função depende da string de formato para determinar quantos e quais tipos de argumentos serão fornecidos. 
	  Por exemplo, no caso do %d, ft_printf sabe que ele espera um inteiro. Já para %s, ele espera um ponteiro para 
	  uma string.

    > Leitura dos Argumentos: Para ler os argumentos, usamos va_arg(args, type) dentro da função. A macro va_arg acessa 
	  os argumentos na ordem em que foram passados, e precisamos de especificar o tipo de cada argumento (como int, char*,
	  etc.).


2. O que é a va_list?

A va_list é um tipo de dado definido na biblioteca padrão de C (stdarg.h) que serve para gerir
uma lista de argumentos variáveis. No caso do ft_printf, os argumentos passados para a função não
são conhecidos no momento da compilação, ou seja, a quantidade e tipo dos argumentos podem variar 
a cada chamada do ft_printf. A va_list é utilizada para manipular esses argumentos variáveis.

Em C, a va_list é um tipo especial - muitas vezes implementado como um ponteiro ou como uma estrutura -
que armazena/guarda informações sobre o local onde estão os argumentos variáveis na memória e como 
percorrê-los corretamente. 
É definida na biblioteca <stdarg.h>, e tem como objetivo aceder a uma lista indefinida de argumentos que
uma função recebe, que não têm nome na definição da função (são representados por "...").

Como ela funciona e como acedemos aos variadic arguments?

Em C, para uma função que aceita um número variável de argumentos, os argumentos são passados diretamente 
na memória e são acessados usando as macros definidas em stdarg.h. 
Essas macros permitem aceder aos argumentos um a um, em sequência, sem precisar de saber o tipo de cada um
no momento da chamada.

    Macros principais da stdarg.h:

        va_start(va_list args, last_param): Inicializa a lista de argumentos. A partir deste ponto, 
											podemos aceder aos argumentos.

        va_arg(va_list args, type): Lê o próximo argumento na lista, de acordo com o tipo especificado.

        va_end(va_list args): Finaliza o uso da lista de argumentos. Deve ser chamada após o uso de todos
		                      os argumentos.

Assim: 

Quando criamos uma função com "..." para aceitar variadic arguments, o compilador não cria uma estrutura
automática para fazer a gestão desses argumentos. 
Em C, para aceder corretamente aos variadic arguments (ou seja, os argumentos variáveis de uma função),
precisamos de seguir um procedimento especifico utilizando a biblioteca <stdarg.h> que fornece um conjunto
de macros para trabalhar com os argumentos recebidos pelo simbolo "...". 

Nós precisamos de: 

- Declarar uma variável va_list. 
- Inicializá-la com va_start. 
- Utilizá-la para aceder aos argumentos um a um com va_arg. 
- Finalizá-la com va_end. 

Assim, a va_list serve como ponte entre o programador e a memória onde os variadic arguemtns estão guardados. 

1 - Incluir a biblioteca correta

Antes de qualquer coisa, devemos incluir a biblioteca que fornece as macros necessárias:

#include <stdarg.h>

Sem este #include, não temos acesso a va_list, va_start, va_arg e va_end, que são essenciais para 
trabalhar com os argumentos variáveis.

2. Declarar uma variável do tipo va_list

Depois, dentro da função, devemos declarar uma variável especial do tipo va_list:

va_list args;

Esta variável será utilizada para acedermos a todos os argumetos variáveis.
Não podemos aceder diretamente aos argumentos pela va_list, precisamos sempre de usar va_arg. 
Aqui, args é simplesmente uma variável que ainda não está associada a nenhum argumento - ela precisa de
ser inicializada primeiro. 

3. Inicializar a lista com va_start

Após declarar a va_list e antes de começarmos a ler os argumentos variáveis, precisamos de inicializá-la
com a macro va_start. 
va_start é a macro que prepara a va_list para aceder aos argumentos variáveis passadas para a função. 

va_start(args, format);

    > args é a variável do tipo va_list que acabamos de declarar, que vai armazenar todos os argumentos
	  passados para a função ft_printf e será utilizada para iterar sobre os argumentos que são passados 
	  para a função, ou seja, é usada para aceder aos argumentos variáveis. 
	  
    > format é o nome do último parâmetro fixo da função antes dos argumentos variáveis, ou seja, é o 
	  último argumento com nome que não é variável, antes do "...".
	  
      O parametro format é necessário para a macro va_start funcionar, porque o compilador precisa de saber
	  onde os argumentos variáveis começam para conseguir ler os valores corretos.
      No caso do ft_printf, o format é a string que contém os especificadores de formato (como %d, %s, %c, etc.).
	  A função ft_printf usa essa string para determinar como processar os argumentos seguintes.

      Por exemplo: ft_printf("Hello %s, your age is %d", "Ricardo", 22);

	  Aqui: O format seria -> "Hello %s, your age is %d".

    A função ft_printf sabe que ela vai precisar de processar dois argumentos variáveis: uma string ("Ricardo") e 
	um inteiro (22).
    É necessário para o compilador calcular onde começam as variadic arguments. 
	Sem isso, a va_list não saberia por onde começar a leitura dos dados. 

	Assim: Quando usamos os variadic arguments, é obrigatório ter pelo menos um argumento antes dos "...", porque
	a macro va_start precisa de saber a partir de que ponto da memória deve começar a ler os argumentos
    variáveis. Para isso, ele utiliza a posição do último argumento fixo como referência.
    Se não houver um argumento fixo, o compilador não saberia onde os argumentos variáveis começam na memória.

Após va_start, o args está pronto para percorrer os argumentos que foram passados para além dos fixos. 

Como Funciona va_start?

A função va_start é utilizada para inicializar a va_list (representada pela variável args) e prepará-la para começar 
a acessar os argumentos após o parâmetro fixo.

O Que Acontece Internamente:

    > Passagem de Argumentos para a Função: Quando chamamos uma função com argumentos variáveis, o compilador passa os 
	  argumentos por ordem, sem saber quantos são nem os tipos de cada um. 
	
	  Por exemplo: ft_printf("Hello %s, your age is %d", "Ricardo", 22);

      O compilador armazena "Ricardo" e 22 na pilha de argumentos.

    > va_start Inicializa args: Ao chamar va_start(args, format), o compilador usa a posição do parâmetro fixo (neste caso, 
	  format) para calcular onde começam os argumentos variáveis. Ele então inicializa a va_list args para que possamos
	  aceder esses argumentos.

4. Aceder aos argumentos, um por um, com va_arg

Com a va_list inicializada, podemos agora ler os argumentos um a um ao utilizar va_arg:

tipo valor = va_arg(args, tipo);

    > O tipo é o tipo de dado que esperamos encontrar (por exemplo, int, char *, double, etc.).
    > O va_arg lê o próximo argumento na lista e avança automaticamente o cursor (args) para o argumento
	  seguinte.
	  A cada chamada, va_arg lê o argumento atual e avança a va_list para o próximo argumento. 
	  Este movimento é automático, sempre que invocamos va_arg, o args atualiza internamente a sua posição
	  para ler o próximo valor. 

Quando usamos argumentos variáveis, como no ft_printf, o comportamento é o seguinte:

    > Determinação do Número de Argumentos: O número de argumentos não é especificado de forma explícita. 
	  A função depende da string de formato para determinar quantos e quais tipos de argumentos serão fornecidos. 
	  Por exemplo, no caso do %d, ft_printf sabe que ele espera um inteiro. Já para %s, ele espera um ponteiro para 
	  uma string.

    > Leitura dos Argumentos: Para ler os argumentos, usamos va_arg(args, type) dentro da função. A macro va_arg acessa 
	  os argumentos na ordem em que foram passados, e precisamos de especificar o tipo de cada argumento (como int, char*,
	  etc.).


Assim: Depois de chamarmos va_start, podemos usar a macro va_arg(args, type) para acessar os argumentos. Cada vez que
chamarmos va_arg, ele lê o próximo argumento na lista.

va_arg permite extrair o próximo argumento da lista args (inicializada por va_start) e interpretá-lo como sendo do tipo de
dado esperado (ex: int, char *, etc).

O tipo de dado precisa de corresponder ao tipo original passado para a função. Se dissermos que é char quando na verdade 
foi passado como int, o resultado será indefinido.

Exemplo de Acesso com va_arg:

Para a string "Ricardo" e o número 22, o código dentro de ft_printf pode ficar assim:

char *name = va_arg(args, char*);
int age = va_arg(args, int);

Aqui: Primeiro va_arg acessa "Ricardo" como uma string (tipo char*).
      Segundo va_arg acessa 22 como um inteiro (tipo int).

Vejamos outro exemplo: 

O va_list args funciona como um ponteiro que vai avançando pela lista de argumentos conforme chamamos va_arg.

ft_printf("Char: %c, Hex: %x", 'B', 255);

Internamente:

    va_start(args, format);

    args aponta para 'B' (promovido para int)

    va_arg(args, int) → extrai o 'B' como int

    args agora aponta para 255

    va_arg(args, int) → extrai 255 como int

    args aponta para nada (fim)

Temos de saber, antecipadamente, o tipo de cada argumento, porque quando usamos va_arg ele não verifica
se estamos a ler o tipo correto. 
Se tentarmos ler um int como char *, vamos obter um comportamento indefinido (e o programa pode crashar!).

Assim: Dentro das funções de manipulação de cada especificador (por exemplo, ft_handle_char, ft_handle_integer, etc.), 
       a va_list é passada como argumento, e os valores reais dos argumentos são acessados com a macro va_arg.

	   Exemplo de como funciona dentro de ft_handle_char:
										
	   c = (char)va_arg(args, int);

	   Aqui, va_arg está a aceder ao próximo valor na va_list e a convertê-lo para char (note que a conversão é
	   feita para int primeiro, porque o va_arg exige um tipo convertido para int ou unsigned int).

Exemplo: Se tivermos uma função  -  ft_printf("%d %d", 42, 100);

Na memória pode estar algo assim:

Endereço	  Valor	     Tipo
0x100	    "formato"	 char *
0x104	        42	      int
0x108	       100	      int

A va_list começa a apontar para o endereço 0x104.

 > A primeira chamada a va_arg(args, int) lê 42.
 > A segunda chamada a va_arg(args, int) lê 100.

A cada chamada avançamos o ponteiro da va_list para o próximo argumento.

Depois de acedermos ao valor com va_arg, ele é processado pela função apropriada. 
Por exemplo, para um número inteiro (%d ou %i), ele é convertido em string através da função ft_itoa. 
Para strings (%s), o valor é um ponteiro para o início da string, que é impresso diretamente.


5. Finalizar o uso da lista com va_end

Depois de terminar a leitura de todos os argumentos necessários da va_list, é obrigatório chamar va_end
para indicar que o processo terminou: 

va_end(args);

   > Limpa eventuais recursos associados à va_list.
   > Informa ao compilador que terminamos o uso da lista de argumentos variáveis.

É obrigatório chamar va_end para garantir a portabilidade e o comportamento correto em todos os sistemas.
Não devemos aceder a uma va_list após chamarmos va_end. 

O que acontece se não usarmos va_start/va_end?

   > Se não usarmos va_start, a va_list não será inicializada e ao acedermos a ela resultará num
     comportamento indefinido.
   > Se não usarmos va_end, pode causar leaks internos de registos ou problemas da stack.


Em suma, a va_list é a "chave" que permite às funções variádicas aceder e percorrer argumentos que não 
foram fixados na assinatura da função.
Com ela, conseguimos criar funções muito mais flexíveis e dinâmicas, como o printf, adaptando o 
comportamento de uma função conforme os dados recebidos durante a execução.






    


	
Exemplo de fluxo de execução:

Se chamarmos a função:  ft_printf("Valor: %d, Letra: %c", 42, 'A');

A execução pode ser explicada passo a passo assim:

    va_start(args, format) inicializa a va_list com os dois argumentos: 42 e 'A'.

    A string format é percorrida. Quando o % é encontrado, o próximo especificador ('d' para número inteiro) 
	é passado para ft_handle_format.

    Em ft_handle_format, quando o especificador é 'd', a macro va_arg(args, int) acessa o valor 42 e chama 
	ft_handle_integer, que o converte para string e o imprime.

    Em seguida, o próximo especificador %c é encontrado, e va_arg(args, int) acessa o valor 'A'.

    A função ft_printchar imprime 'A'.

    No final, va_end(args) é chamada para libertar os recursos da va_list.













Objetivo do ft_printf

Imprimir uma string com substituições de formatos, como %d, %s, %x, etc., usando
argumentos variáveis, e retornar o número total de caracteres impressos.

Exemplo de uso: ft_printf("Olá %s, tens %d anos", "Maria", 30);

Passo a passo do funcionamento

Exemplo:

ft_printf("Olá %s, tens %d anos", "Maria", 30);

1. Início

va_start(args, format);

    args agora aponta para o primeiro argumento após "Olá %s, tens %d anos", ou seja, "Maria".

2. Loop principal percorre a string - while (format[i])  :

    Lê format[i] caractere por caractere.

3. Se não for %: 
	
	else
		len += ft_printchar(format[i]);

    Imprime normalmente com write(1, &c, 1) e soma 1 ao total de caracteres.

4. Quando encontra %  -  if (format[i] == '%')  :

    Verifica se encontrou um especificador de formato.

    Verifica também se há caractere a seguir (format[i + 1]) — senão, retorna -1.

5. Lê o especificador  -  len += ft_handle_format(format[++i], args) :

    Avança o i e lê o caractere seguinte: 's', 'd', etc.

    Chama ft_handle_format, que decide que função usar com base no especificador:

        %s → ft_handle_string

        %d ou %i → ft_handle_integer

        %x → ft_handle_hex

        %p → ft_handle_pointer

        etc.

Como funciona a leitura dos argumentos

Exemplo 1: %s

	int ft_handle_string(va_list args)
	{
		char *str = va_arg(args, char *);
		return ft_printstring(str);
	}

    va_arg(args, char *) extrai o próximo argumento como char *, que no nosso exemplo é "Maria".

Exemplo 2: %d

	int ft_handle_integer(va_list args)
	{
		int n = va_arg(args, int);
		// converte para string com ft_itoa, depois imprime
	}

    va_arg(args, int) extrai o próximo argumento como int, que no exemplo é 30.

Exemplo 3: %c → Caractere

Formato:  ft_printf("Letra: %c", 'A');

Internamente:

    ft_printf encontra %

    Olha o próximo caractere: 'c'

    Chama: ft_handle_format('c', args)

    Dentro da função: c = (char)va_arg(args, int);

	va_arg: O caractere 'A' é promovido para int
			va_arg(args, int) lê 65 (ASCII de 'A')
			Convertido de volta para char

	Impressão: write(1, &c, 1) → imprime 'A'

Exemplo 4: %s → String

Formato: ft_printf("Nome: %s", "Ricardo");

Internamente:

    % seguido de 's'

    Chama: ft_handle_format('s', args)

    Dentro da função: str = va_arg(args, char *);

	va_arg: "Ricardo" é um literal → passado como ponteiro (char *)
			 va_arg(args, char *) retorna o endereço da string

    Impressão: Cada caractere da string é impresso com write em loop

Exemplo 5: %d → Inteiro com sinal

Formato: ft_printf("Número: %d", -42);

Internamente:

    % seguido de 'd'

    Chama: ft_handle_format('d', args)

    Dentro da função: n = va_arg(args, int);
    				  str = ft_itoa(n);

	va_arg: -42 é um int
			va_arg(args, int) lê diretamente o valor -42 da va_list

	Impressão: ft_itoa(-42) → string "–42"

    Impressa com write


Exemplo 6: %u → Inteiro sem sinal

Formato: ft_printf("Valor: %u", 4294967295U);

    Internamente:

    % seguido de 'u'

    Chama: ft_handle_format('u', args)

    Dentro da função: un = va_arg(args, unsigned int);
                      str = ft_uitoa(un);

    va_arg: Valor é unsigned int (máximo 32 bits)
		    va_arg(args, unsigned int) lê o valor diretamente

	Impressão: ft_uitoa(4294967295) → "4294967295"

Exemplo 7: %x → Hexadecimal minúsculo

Formato: ft_printf("Hex: %x", 48879);

    Internamente:

    % seguido de 'x'

    Chama: ft_handle_format('x', args)

    Dentro da função: un = va_arg(args, unsigned int);
                      str = ft_uitoabase(un, "0123456789abcdef");

    va_arg: Valor decimal 48879 → lido como unsigned int

    Impressão: Convertido para hexadecimal: "beef"

    Impresso: "beef"

Exemplo 8: %X → Hexadecimal maiúsculo

Formato: ft_printf("Hex: %X", 48879);

Igual ao %x, mas base em maiúsculas

	va_arg: va_arg(args, unsigned int) → 48879

	Impressão: Convertido com base "0123456789ABCDEF"


Exemplo 9: %p → Endereço de ponteiro

Formato: int x = 42;
		 ft_printf("Endereço: %p", &x);

    Internamente:

    % seguido de 'p'

    Chama: ft_handle_format('p', args)

    Dentro da função:

    addr = va_arg(args, unsigned long long);
    str = ft_ulltoabase(addr, "0123456789abcdef");

    va_arg: Ponteiros são promovidos para void *, lidos como unsigned long long

    Impressão: Endereço convertido para hexadecimal com prefixo "0x"

    Por exemplo: "0x7ffeab34"

Exemplo 10: %% → Porcentagem literal

Formato: ft_printf("Percentagem: %%");

    Internamente:

    % seguido de outro %

    Não há argumento na va_list para esse caso

	va_arg: Nenhuma chamada a va_arg
			Apenas ft_printchar('%') é chamada

	Impressão: Imprime diretamente o caractere %

*/