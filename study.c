
/*
1. O que são Variadic Arguments?

Normalmente, uma função é definada para receber um número fixo de argumentos.
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


O que é a va_list?

Em C, a va_list é um tipo especial - muitas vezes implementado como um ponteiro ou como uma estrutura -
que armazena/guarda informações sobre o local onde estão os argumentos variáveis na memória e como 
percorrê-los corretamente. 
É definida na biblioteca <stdarg.h>, e tem como objetivo aceder a uma lista indefinida de argumentos que
uma função recebe, que não têm nome na definição da função (são representados por "...").

Pensemos na va_list como um cursor que sabe onde começar a ler os argumentos e como avançar de um 
argumento para o outro. Ou seja, funciona como um cursor para aceder, um por um, aos argumentos
variáveis. 

Como acedemos aos Variadic Arguments?

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
com a macro va_start:

va_start(args, ultimo_argumento_fixo);

    > args é a variável va_list que acabamos de declarar.
    > ultimo_argumento_fixo é o nome do último parâmetro fixo da função (o último argumento com nome que 
	  conhecemosm antes do "...").
	  É necessário para o compilador calcular onde começam as variadic arguments. 
	  Sem isso, a va_list não saberia por onde começar a leitura dos dados. 

Esta macro va_start faz o args apontar para a posição correta na pilha de memória, imediatamente após
o último parâmetro nomeado da função. 
Assim, o va_start vai posicionar o cursor (args) logo após esse último argumento conhecido. 
Sem esta chamada, a va_list estaria "sem rumo", não saberia por onde começar a leitura dos dados.

Após va_start, o args está pronto para percorrer os argumentos que foram passados para além dos fixos. 

Porquê que indicamos o último argumento fixo e o por quê do uso de um argumento fixo antes dos ... 
é importante?

Quando usamos os variadic arguments, é obrigatório ter pelo menos um argumento antes dos "...", porque
a macro va_start precisa de saber a partir de que ponto da memória deve começar a ler os argumentos
variáveis. Para isso, ele utiliza a posição do último argumento fixo como referência.
Se não houver um argumento fixo, o compilador não saberia onde os argumentos variáveis começam na memória.

4. Aceder aos argumentos, um por um, com va_arg

Com a va_list inicializada, podemos agora ler os argumentos um a um ao utilizar va_arg:

tipo valor = va_arg(args, tipo);

    > O tipo é o tipo de dado que esperamos encontrar (por exemplo, int, char *, double, etc.).
    > O va_arg lê o próximo argumento na lista e avança automaticamente o cursor (args) para o argumento
	  seguinte.
	  A cada chamada, va_arg lê o argumento atual e avança a va_list para o próximo argumento. 
	  Este movimento é automático, sempre que invocamos va_arg, o args atualiza internamente a sua posição
	  para ler o próximo valor. 

Exemplo prático:  int numero = va_arg(args, int);
                  char *texto = va_arg(args, char *);

Temos de saber, antecipadamente, o tipo de cada argumento, porque quando usamos va_arg ele não verifica
se estamos a ler o tipo correto. 
Se tentarmos ler um int como char *, vamos obter um comportamento indefinido (e o programa pode crashar!).


A partir de aqui podemos nos perguntar: Como a va_list funciona internamente?

Uma va_list é muitas vezes um ponteiro, ou uma estrutura.
Ela aponta para a posição na pilha onde os argumentos variáveis começam .
Cada chamada a va_arg avança a va_list na memória, para apontar para o argumento seguinte.

Imaginemos que os argumentos variáveis são um conjunto de caixas alinhadas na memória.
A va_list é como um "cursor" que aponta para a primeira caixa, e a cada va_arg o dedo avança para 
a caixa seguinte.

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


1) ÍNICIO DO PRINTF

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	size_t	i;

	if (!format || (*format == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_handle_format(format[++i], args);
			i++;
		}
		else
		{
			len += ft_print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}

1 - Definição da função - int	ft_printf(const char *format, ...)

Esta função é uma variadic function: Ela recebe pelo menos um argumento fixo (const char *format) — que é a 
                                     string de formato (ex: "Hello %s").
                                     Depois, com ..., ela aceita um número variável de argumentos, que irão
									 substituir os placeholders (%s, %d, %c, etc.) do format.

2 - Declaração de variáveis: 

  > va_list args - é a variável que vai gerir o acesso aos argumentos variáveis. 

  > int len - vai armazenar o total de caracteres impressos. 

  > size_t i - é utilizado para percorrer cada caractere da string format (vai percorrer cada caractere
               da string de formato, ex: "Hello %s"). 

3 - Primeira verificação de segurança:

if (!format || (*format == '%' && !format[1]))
	return (-1);

Aqui, duas coisas estão a ser verificadas:

    > !format: Se o ponteiro format for NULL, significa que não há formato para imprimir → erro.

    > (*format == '%' && !format[1]): Se a string começar com '%' mas não houver nada depois, também é 
	                                  inválido (um % sozinho sem especificador de tipo).

Se qualquer um destes casos acontecer, a função retorna -1, indicando erro.

4 - Inicialização da va_list: 

va_start(args, format);

    Aqui inicializamos o args da va_list para começar a percorrer os argumentos variáveis.
    Dizemos que os argumentos variáveis vêm depois do format na pilha de memória.

5 - Loop principal para percorrer a format - while (format[i]): 

Este loop vai percorrer, caracter a caractere, a string format, até encontrar o caractere nulo (\0), 
que indica o fim da string.

Dentro do while, há duas situações possíveis:

  > if (format[i] == '%' && format[i + 1]) : Se o caractere atual é % e existe um caractere a seguir 
                                             (format[i + 1] não é nulo), então encontramos um placeholder.
											 Encontramos assim um % seguido por outro caractere. 

			O que acontece então:  len += ft_handle_format(format[++i], args);
                                   i++;

            > ++i: avança para o caractere após o %, que é o specifier (d, s, c, etc.).
            > ft_handle_format: função que vai tratar o especificador (por exemplo, %d ou %s) e imprimir o
			                    valor correspondente, utilizando os argumentos da va_list args.

            > O valor retornado por ft_handle_format é o número de caracteres impressos para esse 
			  placeholder — por isso adicionamos len += ....

            > i++: avança para o próximo caractere depois do formato.

  > else : Se o caractere atual não é %, é apenas texto normal (por exemplo, letras, espaços, sinais). 
           
           Então: 
		   
		      > ft_print_char(format[i]): imprime o caractere diretamente.

              > len += ...: incrementa len com o número de caracteres impressos (normalmente 1).

              > i++: avança para o próximo caractere.

	5.1) Função ft_handle_format - int	ft_handle_format(char c, va_list args): 

	    Esta função recebe dois parâmetros:

        > char c: o specifier que vem a seguir ao % na variável format (por exemplo, 'd', 's', 'c', etc.).

        > va_list args: a lista dos argumentos variáveis que foram inicializados no ft_printf.

        Retorna: Um int que representa o número de caracteres impressos por aquele formato.

		O objetivo de ft_handle_format é interpretar o tipo de especificador (c, s, d, etc) e chamar a função
		adequada que trata esse tipo especifico de argumento. 
		No fim, retorna o número de caracteres impressos. 

		Todas as funções chamadas (ft_handle_char, ft_handle_string, etc.):

    	> Vão usar va_arg(args, tipo) para procurar o próximo argumento correspondente ao tipo que esperam.
		  Ou seja, a va_list args vai sendo percorrida conforme vamos consumindo argumentos.


		5.1.1 - Se o specifier for 'c' : 

				if (c == 'c')
					return (ft_handle_char(args));

    			Se o formato é %c (caractere), chamamos a função ft_handle_char.

    			Passamos a variável args para ela, porque ela vai retirar da va_list o próximo argumento 
				(normalmente um int que será tratado como char).

                Retornamos quantos caracteres foram impressos (deve ser 1).

		5.1.2 - Se o specifier for 's' :

				if (c == 's')
					return (ft_handle_string(args));

    			Se o formato é %s (string), chamamos ft_handle_string.

    			Ela vai retirar da va_list um ponteiro para uma char * (string).

    			Vai imprimir a string e retornar a quantidade de caracteres impressos.

		5.1.3. Se o specifier for 'd' ou 'i'

				if (c == 'd' || c == 'i')
					return (ft_handle_integer(args));

    			%d e %i significam número inteiro decimal (positivo ou negativo).

    			Chamamos ft_handle_integer.

    			A função irá retirar um int da va_list, converter para string (com itoa ou manualmente) 
				e imprimir.

		5.1.4. Se o specifier for 'u'

				if (c == 'u')
					return (ft_handle_unsigned(args));

    			%u é um número inteiro sem sinal (apenas positivo).

    			Chamamos ft_handle_unsigned.

    			Vai buscar um unsigned int da va_list, converter e imprimir.

		5.1.5. Se o specifier for 'x'

				if (c == 'x')
					return (ft_handle_hexlower(args));

    			%x é um número em hexadecimal minúsculo (ex: 1f).

    			Chamamos ft_handle_hexlower.

    			Vai procurar um unsigned int, converter para base 16 usando letras minúsculas e imprimir.

				[FT_HANDLE_HEXLOWER]

				int	ft_handle_hexlower(va_list args)
				{
					unsigned int	un;
					char			*str;
					int				len;

					un = va_arg(args, unsigned int);
					str = ft_lowerhexa(un);
					if (!str)
						return (0);
					len = ft_print_str(str);
					free(str);
					return (len);
				}

				Parâmetro: Recebe uma va_list args. Esta lista contém todos os argumentos variáveis que foram 
				           passados ao ft_printf.

				Objetivo: Procurar um unsigned int da va_list.
						  Converter esse número para uma string representando o número em hexadecimal
						  minúsculo (0-9, a-f).
						  Imprimir a string.
						  Retornar o número de caracteres que foram impressos.

				Declaração das variáveis:
				
				> un: vai guardar o número inteiro sem sinal que vamos procurar da va_list.
				> str: vai apontar para a string que representa o número em hexadecimal.
				> len: vai guardar o número de caracteres que imprimimos no final.

				a) Procurar o argumento da va_list:  un = va_arg(args, unsigned int);

				Utilizamos va_arg para procurar o próximo argumento da lista args. 
				Dizemos que esperamos um unsigned int. 
				O número é guardado na variável un. 

				Exemplo: se chamarmos ft_printf("%x", 255), iriamos procurar o valor 255. 

				b) Converter o número para uma string hexadecimal:  str = ft_lowerhexa(un);

				Chamamos a função ft_lowerhexa, que:

        			> Recebe o número un.
					> Converte-o para hexadecimal minúsculo.
					> Retorna uma string alocada dinamicamente (com malloc).
					> Esta string é guardada em str.

					Exemplo: Se un = 255, então ft_lowerhexa(255) deve retornar a string "ff".

					[FT_LOWERHEXA]
				
					char	*ft_lowerhexa(unsigned int n)
					{
						char			*str;
						int				x;
						unsigned int	num;

						num = n;
						x = ft_hexa_len(num);
						str = malloc(sizeof(char) * (x + 1));
						if (!str)
							return (NULL);
						str[x] = '\0';
						if (n == 0)
							str[0] = '0';
						while (x > 0)
						{
							x--;
							if ((num % 16) > 9)
								str[x] = (num % 16) + 97 - 10;
							else
								str[x] = (num % 16) + 48;
							num /= 16;
						}
						return (str);
					}

					b1) Declaração - char *ft_lowerhexa(unsigned int n)

					Objetivo: converter o número inteiro n numa string que representa o número em base
							  hexadecimal (base 16) com letras minúsculas (0-9, a-f).

					Retorno: retorna um char * que aponta para a string hexadecimal (o número convertido
					         para hexadecimal) para que depois possa ser utilizado para a impressão na
							 função ft_printf.

					b2) Declaração das Variáveis: 

					> n: é o número que recebemos para converter numa string hexadecimal. 
					> str: É a string final que vai guardar o número convertido.
					       Aloca dinamicamente espaço para guardar os caracteres mais o '\0' no final. 
						   Durante o while, cada posição de str será preenchida com o dígito correspondente. 
					> x: armazena o número de digitos necessários para representar num em hexadecimal 
					     (tamanho da string).
					> num: é uma cópia de n, para manipular o número sem alterar n diretamente.
					       Guardamos o valor original n dentro de num, porque:

    							> Durante a conversão, vamos dividir e modular (%) o número várias vezes.
								> Se alterássemos n diretamente, perderíamos o seu valor original.
								> Então, alteramos apenas num, deixando n intacto para outros usos 
								  (por exemplo, o tratamento especial de n == 0).

					b3) Guardar o valor de n em num  -  num = n;

    				Guardamos n em num para podermos trabalhar com num livremente durante a conversão.

    				Isto evita modificar o valor original recebido pela função (n).

					b4) Calcular o comprimento da string  -  x = ft_hexa_len(num);

    				Chamamos ft_hexa_len(num), que calcula quantos dígitos são necessários para representar 
					num em hexadecimal.

    				Por exemplo: 255 → "ff" → 2 dígitos → x = 2
								 16 → "10" → 2 dígitos → x = 2
								 1 → "1" → 1 dígito → x = 1
								 
					O valor de x é o tamanho necessário da string (sem contar o \0 ainda).

					b5) Alocar memória para a string  -  str = malloc(sizeof(char) * (x + 1));

    				Alocamos memória suficiente para armazenar a string hexadecimal, garantindo que temos
					espaço para os caracteres hexadecimais mais o caractere nulo '\0'. 

					b6) Terminar a string com '\0'   -   str[x] = '\0';

    				Colocamos o caractere nulo '\0' na última posição da string.
					Isto marca o fim da string em C.

					b7) Tratar o caso especial do número ser 0: 

									if (n == 0)
										str[0] = '0';

    				Se o número for 0, colocamos diretamente o carácter '0' na primeira posição da string.
					Em hexadecimal, o número 0 é representado simplesmente como "0".

					b8) Converter o número para hexadecimal:

								while (x > 0)
								{
									x--;
									if ((num % 16) > 9)
										str[x] = (num % 16) + 97 - 10;
									else
										str[x] = (num % 16) + 48;
									num /= 16;
								}
					O loop vai converter o número de base 16 para uma string, caractere a caractere,
					começando do último digito até ao primeiro. A operação é feita de forma invertida
					(do fim da string para o começo) de modo a que o resultado final esteja na ordem
					correta. 

					while (x > 0): O loop continua enquanto ainda tivermos digitos para processar.

					x--: Decrementamos x e começamos a preencher a string de trás para a frente.
						 Primeiro preenchemos a última posição válida (antes do \0), depois a anterior, 
						 e assim sucessivamente.

					num % 16: Calculamos o dígito em hexadecimal.
							  Obtemos o resto da divisão de num por 16.
							  O resto representa o próximo dígito em hexadecimal.

					Agora vamos decidir o que vamos escrever na string str que alocamos:
					
						> Se o resto (num % 16) for maior que 9: Significa que estamos nas letras do hexadecimal: 
						  a (10), b (11), ..., f (15).

                          Para transformar em caracter: > 'a' tem valor ASCII 97.
														> Por isso, fazemos: (num % 16) + 97 - 10.

						  Exemplo:  Se num % 16 == 10, então:
					                10 + 97 - 10 = 97
									97 é o código ASCII da letra 'a'.

    					> Se o resto for de 0 a 9: Queremos um número ('0' a '9').
												   '0' tem ASCII 48, então fazemos (num % 16) + 48.

						   Exemplo: Se num % 16 == 5, então:

        							5 + 48 = 53

        							53 é o código ASCII do carácter '5'.

					num /= 16: Atualizamos o número.
							   Dividimos o número por 16.
							   Isto remove o dígito que acabámos de converter.
							   Preparamo-nos para o próximo dígito.

					b9) Retornar a string  -  return (str);

    				No final, retornamos a string já completamente construída.




				c) Verificar se a conversão foi bem sucedida:

								if (!str)
									return (0);

				> Verificamos se str é NULL.
				> Se for NULL, significa que houve erro na malloc dentro do ft_lowerhexa.
				> Se isso acontecer, não imprimimos nada e retornamos 0.
				
				Importante: Sempre que alocamos memória dinamicamente, temos de proteger o programa 
				            contra falha de alocação.

				d) Imprimir a string:  len = ft_print_str(str);

    			Chamamos a função ft_print_str que:

        			> Recebe a string str.
					> Imprime-a caractere a caractere.
					> Retorna o número de caracteres impressos.

                Guardamos este valor em len.

				Exemplo: Se str é "ff", imprimimos ff no terminal e len fica com o valor 2.

				e) Libertar a memória alocada: free(str);

    			Libertamos a memória que foi alocada com malloc em ft_lowerhexa.
				Isto é importante para não criar leaks de memória.

				f) Retornar o número de caracteres impressos:  return (len)

				Retornamos quantos caracteres foram impressos.
				O ft_printf usa este valor para ir somando o total de caracteres que imprime no final.

																 




		5.1.6. Se o specifier for 'X'

				if (c == 'X')
					return (ft_handle_hexupper(args));

    			%X é um número em hexadecimal maiúsculo (ex: 1F).

    			Chamamos ft_handle_hexupper.

    			Vai fazer a mesma coisa do %x, mas com letras maiúsculas.

		5.1.7. Se o specifier for 'p'

				if (c == 'p')
					return (ft_handle_pointer(args));

    			%p é para imprimir um endereço de memória (ponteiro).

    			Chamamos ft_handle_pointer.

    			Vai buscar um void * da va_list, converter o valor para hexadecimal com prefixo 0x e imprimir.

		5.1.8. Se o specifier for '%'

				if (c == '%')
					return (ft_print_char('%'));

    			Se o formato é %%, significa imprimir o caractere % literal.

    			Apenas chamamos ft_print_char('%') para imprimir um %.

		5.1.9. Se não for nenhum dos anteriores  -  return (ft_print_char(c));

    		   Se o caractere c não corresponder a nenhum dos formatos conhecidos, simplesmente:

        	   Imprimimos o próprio caractere c como se fosse texto normal.

    		   Isto é uma proteção para que o programa não crash se encontrar um %z, %y, etc. 
			   (formatos inválidos).

6 - Finalizar a va_list - va_end(args) : 

    Depois de todos os argumentos forem utilizados, chamamos va_end para limpar a va_list. 
	É obrigatório para garantir um uso correto da memória e manter o código portátil. 

7 - Retornar o total de caracteres impressos - return (len) : 

    No final, ft_printf retorna o número total de caracteres que foram impressos com sucesso. 















   

  



















*/