# Linguagens de Programação

![img](/materiais/Linguagens%20de%20Programa%C3%A7%C3%A3o/Imagens/Linguagens.png)

Existem diversas definições sobre o que são as Linguagens de Programação. 

Pode-se dizer que:

Uma linguagem de programação é uma linguagem artificial que pode ser usada para controlar o comportamento de uma máquina, principalmente de um computador. 

Uma linguagem de programação é um vocabulário e um conjunto de regras gramaticais para instruir um computador ou dispositivo de computação a executar tarefas específicas.

Linguagens de programação, como linguagens humanas, são definidas pelo uso de regras sintáticas e semânticas, para determinar a estrutura e o significado, respectivamente.

Cada linguagem de programação possui um conjunto exclusivo de palavras-chave (palavras que é capaz de entender) e uma sintaxe especial para organizar as instruções do programa.

Linguagens de programação são usadas para facilitar a comunicação sobre a tarefa de organizar e manipular informações e para expressar algoritmos com precisão.

Milhares de linguagens de programação diferentes foram criadas e novas são criadas a cada ano.

## Propósito

Muitos linguagens foram projetados do zero, alteradas para atender à novas necessidades, combinados com outras linguagens e eventualmente caindo em desuso. Embora tenha existido tentativas de projetar uma linguagem de computador "universal" que atenda a todos os propósitos, todos eles falharam ao serem aceitos nessa função. A necessidade de diversas linguagens de computador surge da diversidade de contextos em que as linguagens são usadas:

- Os programas variam de pequenos scripts escritos por entusiastas individuais a enormes sistemas escritos por centenas de programadores.
- Os programadores variam em conhecimento, desde iniciantes que precisam de simplicidade acima de tudo até especialistas que podem se sentir confortáveis com uma complexidade considerável.
- Os programas devem equilibrar velocidade, tamanho e simplicidade em sistemas que variam de microcontroladores a supercomputadores.
- Os programas podem ser escritos uma vez e não mudar por gerações, ou podem sofrer modificações quase constantes.
- Finalmente, os programadores podem simplesmente diferir em seus gostos: eles podem estar acostumados a discutir problemas e expressá-los em uma linguagem específica.

Uma tendência comum no desenvolvimento de linguagens de programação tem sido adicionar mais capacidade de resolver problemas usando um nível mais alto de abstração. As linguagens de programação mais antigas estavam intimamente ligadas ao hardware subjacente do computador. À medida que novas linguagens de programação se desenvolvem, são adicionados recursos que permitem que os programadores expressem idéias que são mais removidas da tradução simples em instruções de hardware subjacentes. Como os programadores estão menos vinculados às necessidades do computador, seus programas podem fazer mais computação com menos esforço do programador. Isso permite que eles escrevam mais programas na mesma quantidade de tempo.

## Elementos das Linguagens de Programação

Existem cinco elementos básicos de programação que estão presentes em praticamente todas as linguagens.

- **Variáveis:** será assim que os dados são representados. Pode variar de algo muito simples, como a idade de uma pessoa, a algo muito complexo, como um registro de estudantes universitários com seus nomes, idades, endereços, quais cursos eles fizeram e as notas obtidas.
- **Loops:** Isso nos permitirá manter a execução de um grupo de comandos um certo número de vezes.
- **Condicionais:** Isso especificará a execução de um grupo de instruções, dependendo de alguma condição ser satisfeita ou não.
- **Input**(Entrada) / **Output**(Saída): Isso permitirá a interação do programa com entidades externas. Isso pode ser tão simples quanto imprimir algo na tela do terminal, ou capturar algum texto que o usuário digita no teclado, ou pode envolver a leitura e / ou gravação em arquivos.
- **Sub-rotinas** e **Funções**: Isso permitirá que você coloque trechos de código usados com frequência em um local que pode ser usado repetidamente / reaproveitado.

## Características das Linguagens de Programação

O estudo de qualquer linguagem, natural ou artificial, concentra-se nos dois fundamentos da linguagem: **sintaxe** e **semântica**. 

A síntaxe do idioma leva em consideração o formato, a forma e a estrutura composicional do idioma. Por exemplo, a frase: *"caxorro asul"*, é sintaticamente incorreta. A sintaxe de uma linguagem de computador é definida como a forma de suas expressões, instruções e unidades de programa. 

A semântica, por outro lado, tem a ver com o significado por trás do que está sendo expresso. A frase: *"cavalos teste céu em outro"*, é sintaticamente correta, mas não têm significado semântico. A semântica, na linguagem de programação, refere-se ao significado das expressões, instruções e unidades de programa na sintaxe da linguagem.

### Síntaxe

A sintaxe de uma linguagem pode ajudar a determinar a popularidade e a facilidade de uso de uma linguagem de programação específica. Se um programador se encontra enfrentando dificuldades com a sintaxe de um idioma, ele pode facilmente mudar para um dos outros idiomas atualmente disponíveis. 

Como as linguagens naturais, as linguagens de programação têm símbolos chamados caracteres. Esses caracteres são reunidos em cadeias e essas cadeias se combinam para formar sentenças. A forma mais simples dessas strings é chamada lexeme. Lexemes também são separados em grupos, chamados identificadores, por vários critérios. Os critérios para separação podem incluir métodos, classes ou nomes de variáveis. As categorias às quais esses lexemes pertencem são chamadas de tokens. Por exemplo, o lexeme, index, está no identificador chamado token. Esses tokens são então analisados. A análise reconhece os tokens em uma frase e determina sua estrutura relacionada à gramática formal do idioma. A gramática formal de um idioma está relacionada às regras de sintaxe implementadas. A gramática formal refere-se apenas à forma e não ao conteúdo. 

A imagem a seguir apresenta alguns lexemes na linguagem de programação C.

![img](/materiais/Linguagens%20de%20Programa%C3%A7%C3%A3o/Imagens/lexemes_C.png)

A gramática das linguagens de programação pode ser classificada em várias categorias usando a hierarquia de Chomsky, um sistema desenvolvido por Noam Chomsky em meados da década de 1950. A hierarquia consiste em 4 classes para gramática; Tipo 0, Tipo 1, Tipo 2 e Tipo 3. 

- O tipo 0 consiste nas gramáticas irrestritas. Ele contém todas as gramáticas formais e eles geram todos os idiomas que podem ser reconhecidos por uma máquina de Turing. Esses tipos de idiomas também são conhecidos como idiomas recursivamente enumeráveis. 

- O tipo 1 é composto por gramáticas sensíveis ao contexto, que geram linguagens sensíveis ao contexto. 

- O tipo 2 inclui gramáticas sem contexto, que geram idiomas sem contexto. Linguagens livres de contexto geralmente são a base para a sintaxe da maioria das linguagens de programação. 

- O tipo 3 consiste em gramáticas regulares, que criam idiomas regulares. Embora existam outras formas de gramática, elas não são incluídas na hierarquia.

### Semântica

Uma vez que a sintaxe de uma linguagem de programação é revelada e compreendida, a semântica da linguagem deve ser definida. A semântica formal de uma linguagem de programação pode ser abordada em três métodos.

- A primeira é a semântica denotacional, em que cada frase no idioma é feito uma imagem em uma frase em um idioma diferente. Normalmente, o idioma da imagem é baseado matematicamente. Essa é a idéia básica por trás da compilação de linguagens.

- A segunda classe de semântica é a semântica operacional. A semântica operacional executa o idioma apresentado diretamente, em vez de traduzir para outro idioma. Essa classe dá sentido aos elementos no código, descrevendo as alterações que eles fazem dos vários estados da máquina.

- A terceira classe é a semântica axiomática, onde o significado é atribuído a várias frases relacionando os axiomas lógicos que se aplicam a cada frase individual. Não há diferença entre o significado real da frase e as fórmulas usadas para descrevê-la. Essa forma de semântica é baseada em métodos e fórmulas lógicas.

### Tipos

Os dados podem ser vistos como uma coleção de bits, em uma determinada ordem. As linguagens de programação podem pegar esses bits e criar todos os dados a partir deles. Isso pode formar uma máquina dentro do computador e incorporá-la como parte da linguagem de programação usada.

Esses dados podem ser classificados em certos tipos de dados. Um tipo de dados é um conjunto de valores, juntamente com um conjunto de operações nos valores que possuem determinadas propriedades.

Um sistema de tipos exibe esses tipos de dados e define como uma linguagem de programação atribui certas expressões e valores a eles. Esses sistemas existem para garantir que os programas estejam livres de erros e detectem muitos erros no código.

Às vezes, os sistemas de tipos funcionam muito bem e encontram erros no código perfeitamente escrito. Para contornar esses problemas, muitos programadores podem construir brechas e contornar o sistema de tipos.

Para garantir a execução adequada do código, um sistema de policiamento deve ser mantido para solidificar e reforçar a gramática. A verificação de tipo é usada para procurar erros no código. Verificação de tipo é o processo pelo qual um tradutor passa para verificar se todas as construções em um programa fazem sentido em termos dos tipos de suas várias entidades. É utilizado um algoritmo que verifica a equivalência entre expressões e instruções. Existem dois tipos de verificação de tipo, estática e dinâmica.

#### Verificação de Tipo Estática

A verificação de tipo estático determina os tipos de objetos e expressões do texto real do programa. A verificação é realizada antes da execução do programa. A verificação estática permite que os compiladores aloquem memória e gerem código que manipula os dados com eficiência, aumentando a eficiência da execução. Também reduz a quantidade de código que deve ser compilada, melhorando a eficiência da tradução. Esse tipo de verificação também captura muitos erros antecipadamente, o que melhora a capacidade de gravação de um idioma. A verificação de tipo estático cria um conjunto de regras mais rígido e reduz a flexibilidade do programador.

#### Verificação de Tipo Dinâmica

A verificação dinâmica do tipo, por outro lado, é verificada durante a execução do programa e tende a ser mais flexível que a verificação estática. Certas linguagens de programação como JavaScript, devido à sua ligação de tipo dinâmico, permitem apenas a verificação de tipo dinâmico.

É possível determinar a força do tipo de verificação de tipo de uma linguagem de programação. A *strong typing* é uma característica altamente valiosa de uma linguagem de programação. Um programa é *strong typed* se erros no código sempre são detectados. Isso requer que todos os elementos da operação possam ser determinados especificamente usando métodos de verificação de tipo dinâmico ou estático. Por outro lado, uma linguagem *weakly typed* permite que um elemento seja criado como um tipo de elemento diferente. Embora isso possa ser útil em muitos casos, isso pode causar estragos, permitindo que muitos erros passem pelo processo de detecção de erros.

### Bibliotecas

A década de 1990 colocou em foco o uso de bibliotecas. Bibliotecas são uma coleção de classes ou sub-rotinas usadas para desenvolver software. Historicamente, as bibliotecas eram consideradas sem importância nas linguagens de programação, porque não faziam parte da linguagem real. Elas foram vistas como um problema de interface e não como uma preocupação de codificação ou programação. Algumas linguagens ignoraram completamente o uso de bibliotecas e optaram por incluir as funções de entrada e saída na própria linguagem. 

No entanto, com a evolução da tecnologia para os altos níveis do século XXI, a idéia de bibliotecas é essencial. Bibliotecas cheias de recursos avançados, estão sendo escritas de maneiras independentes do sistema, estão sendo incorporadas às próprias linguagens. Essa nova abordagem para bibliotecas é imprescindível para ter uma linguagem bem-sucedida e altamente funcional. 

Um exemplo perfeito de uma linguagem moderna e altamente usada que depende de bibliotecas é o Java. Como uma das linguagens mais populares do mundo, o Java pode ter desaparecido no reino das linguagens de programação perdidas se não tivesse usado a Interface do Programa de Aplicativos Java. O C++, outra linguagem extremamente popular, usa uma biblioteca padrão que contém muitos utilitários que tornam o C++ a linguagem de sucesso que é.

A imagem a seguir apresenta a biblioteca padrão da linguagem C.

![img](/materiais/Linguagens%20de%20Programa%C3%A7%C3%A3o/Imagens/C_stdlib.png)

#### Tipos de Bibliotecas

Assim como as linguagens de programação e a tecnologia evoluíram do começo humilde para as poderosas forças motrizes do século XXI, o mesmo aconteceu com as bibliotecas. As bibliotecas iniciais eram bastante simples e não estavam tão envolvidas quanto as forças gigantes que se tornaram. Os vários tipos de bibliotecas são:

- **Bibliotecas estáticas:** as bibliotecas estáticas foram as primeiras bibliotecas existentes. Originalmente, todas as bibliotecas eram estáticas e denominadas arquivos. Esses arquivos foram feitos de rotinas, que foram copiadas por um *linking agent*, geralmente um compilador, para o aplicativo desejado. Esse ato, chamado de construção estática, produziu *object files* e um arquivo executável. O *linking agent* carrega todos os códigos e bibliotecas no local apropriado da memória, o que pode levar muito tempo, dependendo da operação. Algumas linguagens incorporaram o conceito de *smart linking*, o que permite ao compilador reconhecer as bibliotecas necessárias e usar apenas os aspectos essenciais necessários. Isso reduz o uso de memória e o tempo de execução.

- **Dynamic Linking:** o *Dynamic Linking* ajuda a reduzir o tempo de compilação carregando as sub-rotinas de uma biblioteca. Todos os arquivos .DLL que acompanham os aplicativos são responsáveis por acelerar as ações executadas durante a execução do aplicativo. Esse é um dos motivos pelos quais muitos programas modernos podem levar algum tempo durante a inicialização, mas são muito rápidos na execução de solicitações. Uma desvantagem da *Dynamic Linking* é que o aplicativo em execução depende do *linking agent* para localizar e ordenar as bibliotecas armazenadas. Se alguma das bibliotecas for excluída, extraviada, renomeada, danificada, incompleta ou movida, a biblioteca não poderá ser copiada e o arquivo executável falhará.

- **Bibliotecas compartilhadas:** as bibliotecas compartilhadas são outra classificação de bibliotecas, relacionada à disponibilidade da biblioteca para uma variedade de programas. Dois conceitos são incorporados em bibliotecas compartilhadas. Primeiro, uma biblioteca é compartilhada se compartilhar código localizado no disco local por outros programas não relacionados entre si. Segundo, é quando a biblioteca compartilha o código com a memória ou RAM. As bibliotecas dinâmicas quase sempre são compartilhadas, enquanto a estática nunca pode ser compartilhada devido à sua natureza estática. Os sistemas operacionais mais populares usam bibliotecas compartilhadas porque permitem apenas um carregador e, em segundo lugar, os aplicativos e outros arquivos executáveis a serem usados como bibliotecas dinâmicas.

- **Bibliotecas remotas:** bibliotecas remotas são bibliotecas localizadas em outro servidor ou computador. Essas bibliotecas são acessadas em uma rede usando uma chamada de procedimento remoto. Isso permite que um computador ou máquina localizado em um país diferente use as mesmas bibliotecas nos Estados Unidos.

- **Bibliotecas orientadas a objetos:** Assim como a programação orientada a objetos aumentou em popularidade, só faz sentido que as bibliotecas de objetos sigam. A programação orientada a objetos requer vários dados que não são encontrados nas bibliotecas normais. Essas bibliotecas especiais devem conter uma lista de objetos dos quais os *entry points* e os nomes do código dependem. Os aplicativos e sistemas *cross-platform* geralmente usam bibliotecas de objetos para expandir seu público geral. Muitos desenvolvedores como IBM, COBRA e Sun Microsystems aproveitaram rapidamente essas oportunidades para aumentar seus lucros.

- **Bibliotecas de Classes:** Muito semelhantes às bibliotecas de objetos são as bibliotecas de classes. Bibliotecas de classes representam bibliotecas de objetos, mas geralmente estão relacionadas a códigos de tipos mais antigos. Essas bibliotecas de classes ajudam a descrever métodos e características de objetos.

### Paradigmas de Programação

Linguagens de programação imitam as operações do computador em que estão sendo executadas. Portanto, o computador para o qual foram projetados tem um efeito significativo de como a linguagem de programação é criada e quais características são atribuídas à linguagem. Vários atributos de uma linguagem de programação determinarão o paradigma computacional da linguagem. A seguir, são apresentados paradigmas diferentes.

- **Paradigma Imperativo:** As instruções são executadas sequencialmente, as variáveis são usadas para representar os locais da memória e as atribuições são usadas para alterar os valores das variáveis. Linguagens imperativas também são chamadas de linguagens procedurais, devido à sequência de instruções que representam os comandos. A maioria das linguagens de programação atualmente usadas é imperativa.

- **Paradigma Funcional:** baseado na matemática e na noção abstrata de uma função no cálculo lambda. Este paradigma baseia a descrição da computação na avaliação de funções ou na aplicação de funções a valores conhecidos. As linguagens que incorporam o paradigma funcional às vezes são chamadas linguagens de aplicação. O paradigma funcional usa uma chamada funcional, onde o programa avalia uma função, transfere valores como parâmetros para determinadas funções e retorna valores das funções. LISP é um exemplo de uma linguagem de programação funcional.

- **Paradigma Lógico:** a programação lógica é baseada na lógica simbólica. Esses idiomas são baseados em um conjunto de declarações que descrevem a verdade de uma declaração, em vez de fornecer uma sequência de frases restritas para serem executadas de uma maneira específica. Essas linguagens não precisam de loops, e a única necessidade é a declaração das propriedades da computação. Como todas as propriedades são declaradas e não há sequência de execução, a programação lógica é chamada de programação declarativa. A única linguagem baseada em lógica amplamente usada é o Prolog.

- **Paradigma Orientado a Objetos:** este paradigma é baseado na idéia de um objeto. Os objetos podem ser descritos como uma coleção de locais, juntamente com todas as operações que podem alterar os valores desses locais de memória. Um exemplo de um objeto é uma variável. Em muitas linguagens orientadas a objetos, os objetos são colocados em classes que representam todos os objetos com as mesmas características. Essas classes definem quatro coisas. Primeiro, um construtor aloca memória e fornece um valor inicial para os dados de um objeto. Segundo, é determinada uma maneira de acessar o valor da primeira parte da classe. Em seguida, os procedimentos são executados e um valor é definido. A programação orientada a objetos é encontrada em várias novas linguagens e parece ser um item básico para o futuro da programação.

### Prática

Os designers e usuários de uma linguagem devem construir uma série de artefatos que governam e permitem a prática da programação. O mais importante desses artefatos é a especificação e implementação de linguagem.

#### Especificação

A especificação de uma linguagem de programação visa fornecer uma definição que os usuários e implementadores da linguagem possam usar para interpretar o comportamento dos programas ao ler seu código-fonte.

Uma especificação de linguagem de programação pode assumir várias formas, incluindo as seguintes:

- Uma definição explícita da sintaxe e da semântica da linguagem. Embora a sintaxe seja comumente especificada usando uma gramática formal, as definições semânticas podem ser escritas em linguagem natural (por exemplo, a linguagem C) ou em uma semântica formal (por exemplo, nas especificações Standard ML e Scheme).

- Uma descrição do comportamento de um tradutor para o idioma (por exemplo, C++ e Fortran). A sintaxe e a semântica da linguagem devem ser inferidas a partir dessa descrição, que pode ser escrita em linguagem natural ou formal.

- Uma implementação de modelo, às vezes escrita no idioma que está sendo especificado (por exemplo, Prolog). A sintaxe e a semântica da linguagem são explícitas no comportamento da implementação do modelo.

#### Implementação

Uma implementação de uma linguagem de programação fornece uma maneira de executar esse programa em uma ou mais configurações de hardware e software. Existem, de maneira geral, duas abordagens para a implementação da linguagem de programação: **compilação** e **interpretação**. Geralmente é possível implementar uma linguagem usando as duas técnicas.

O *output* de um compilador pode ser executada por hardware ou um programa chamado interpretador. Em algumas implementações que fazem uso da abordagem do interpretador, não há limites distintos entre compilar e interpretar. Por exemplo, algumas implementações da linguagem de programação BASIC compilam e executam a fonte uma linha de cada vez.

Os programas executados diretamente no hardware geralmente executam várias ordens de magnitude mais rapidamente do que os que são interpretados no software.

Uma técnica para melhorar o desempenho de programas interpretados é a compilação *just-in-time*. Aqui, a máquina virtual monitora quais seqüências de bytecode são frequentemente executadas e as converte em código de máquina para execução direta no hardware.

##### Convertendo para Código de Máquina

Independentemente do idioma que você usa, é necessário converter seu programa em linguagem de máquina para que o computador possa entendê-lo. Existem duas maneiras de fazer isso:

1. Compilar o programa.
2. Interpretar o programa.

### Melhor Linguagem de Programação

A questão de qual linguagem é melhor é aquela que consome muito tempo e energia entre os profissionais de Tecnologia da Informação. Toda linguagem tem seus pontos fortes e fracos. Por exemplo, o FORTRAN é uma linguagem particularmente boa para o processamento de dados numéricos, mas não se presta muito bem à organização de programas grandes. Pascal é muito bom para escrever programas bem estruturados e legíveis, mas não é tão flexível quanto a linguagem de programação C. O C++ incorpora poderosos recursos orientados a objetos, mas é complexo e difícil de aprender.

### Considerações sobre a Criação de uma Nova Linguagem de Programação

Criar uma nova linguagem não pode se basear estritamente na sintaxe e na semântica. Certos critérios devem ser atendidos ao projetar um nova linguagem. Um programador deve determinar construtivamente a direção do novo programa com cada um dos seguintes itens:

**Objetivo:** O programador deve determinar o objetivo geral da linguagem. Se o programa for projetado para uso geral ou para uma tarefa específica, como contabilidade. Ao determinar esse aspecto da linguagem, o programador será mais eficiente em atingir seus objetivos.

**Abstração:** Fatorar padrões e sub-procedimentos recorrentes terá um resultado favorável para futuros programadores da linguagem.

**Simplicidade:** quanto menos complicada for uma linguagem, mais favorável ela será para todos usarem. Ao limitar os conceitos necessários para programar em um idioma específico, simplificará a estrutura geral da linguagem.

**Ortogonalidade:** Entidades básicas devem ser entendidas separadamente e interagir da maneira esperada, separadas de outras entidades.

**Tradução:** um tradutor para qualquer idioma deve ser executado com eficiência e rapidez para permitir uma programação concisa.

**Consistência:** Construções semelhantes devem ter aparência e agir da mesma forma. Construções diferentes devem aparecer e ter um desempenho diferente.

### Breve Histórico

As primeiras linguagens de programação são anteriores ao computador moderno. O século XIX tinha teares "programáveis" e *player piano scrolls* que implementavam o que hoje são reconhecidos como exemplos de linguagens de programação específicas de domínio. O primeiro programa de computador foi criado por Charles Babbage no início do século 19 para executar seu conceitual Analytical Engine. O mecanismo analítico seria capaz de calcular logaritmos e funções trigonométricas usando seu programa de computador. No início do século XX, os cartões perfurados codificaram dados e direcionaram o processamento mecânico. Nas décadas de 1930 e 1940, os formalismos do cálculo lambda Alonzo Church e das máquinas de Turing de Alan Turing forneceram abstrações matemáticas para expressar algoritmos, o cálculo lambda permanece influente no design de linguagens.

Na década de 1940, foram criados os primeiros computadores digitais com alimentação elétrica. Os computadores do início dos anos 1950, principalmente o UNIVAC I e o IBM 701, usavam programas de linguagem de máquina. A programação de linguagem de máquina de primeira geração foi rapidamente substituída por uma segunda geração de linguagens de programação conhecidas como linguagens Assembly. Mais tarde, na década de 1950, a programação em linguagem assembly, que evoluiu para incluir o uso de instruções macro, foi seguida pelo desenvolvimento de três linguagens de programação modernas: FORTRAN, LISP e COBOL. As versões atualizadas de todos eles ainda são de uso geral e, o que é mais importante, cada uma delas influenciou fortemente o desenvolvimento de idiomas posteriores. No final da década de 1950, a linguagem formalizada como Algol 60 foi introduzida, e a maioria das linguagens de programação modernas são, em muitos aspectos, descendentes de Algol. O formato e uso das linguagens de programação iniciais foram fortemente influenciados pelas restrições da interface.

Os anos 70 trouxeram o conceito de programação orientada a objetos. A programação orientada a objetos começou a usar estruturas de dados para criar programas de computador. Diversas linguagens de programação desenvolvidas após esse período incorporaram a programação orientada a objetos em suas idéias básicas. Outra grande conquista durante os anos 70 foi a criação da linguagem de programação C. C ou alguma variação de C é sem dúvida a linguagem de programação mais usada no mundo em 2010.

O boom da Internet nos anos 90 deu origem a muitas das linguagens usadas pelos programadores atualmente. Linguagens de script como Applescript, Javascript e Python nasceram nesta época e abriram o caminho para muitas outras linguagens de programação usadas no mundo virtual da web. Linguagens de programação estão sendo constantemente criadas, atualizadas e usadas. Atualmente, existem dezenas de milhares de linguagens de programação no mundo. Isso não é surpreendente, devido à nossa dependência de tecnologia e acessibilidade de computadores poderosos, os designers têm liberdade para criar qualquer idioma que considerem adequado para resolver qualquer problema. Os idiomas podem ser criados por várias razões, desde o cálculo de salários de uma corporação até o cálculo das notas de estudantes universitários.

### Referências

- [Webopedia](https://www.webopedia.com/TERM/P/programming_language.html)
- [Programming Language](https://en.wikipedia.org/wiki/Programming_language)
- [California State University Northridge](http://www.csun.edu/~vgc30838/Projecth.html)
- [Wikispeedia](https://www.cs.mcgill.ca/~rwest/wikispeedia/wpcd/wp/p/Programming_language.htm)
