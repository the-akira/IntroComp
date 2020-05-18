# Hardware

Os computadores possuem duas partes principais: **Hardware** e **Software**

O Hardware do computador inclui as partes físicas de um computador, como **unidade central de processamento (CPU)**, **monitor de vídeo**, **teclado**, **armazenamento de dados do computador**, **placa gráfica**, **placa de som**, **alto-falantes** e **placa-mãe**.

O Software é o conjunto de instruções que podem ser armazenadas e executadas pelo Hardware. O Hardware é denominado "*hard*" por ser "rígido" em relação às alterações, enquanto o Software é "*soft*" por ser "flexível" e fácil de alterar.

O Hardware normalmente é dirigido pelo Software para executar quaisquer comandos/instruções. Uma combinação entre Hardware e Software forma um sistema de computação utilizável.

## Componente Principais

A **unidade central de processamento (CPU)**, **memória de acesso aleatório (RAM)** e o **armazenamento persistente (HD/Flash)** são os elementos principais de um computador e são encontrados em todos eles: **laptops**, **smartphones**, **tablets** e **desktops**.

![img](https://i.ibb.co/F3RKbXR/PComputer.png)

### 1. CPU

A **unidade central de processamento (CPU)**, também chamado de processador central ou processador principal, é o circuito eletrônico dentro de um computador que executa instruções que compõem um programa de computador. A CPU executa operações aritméticas básicas, lógicas, de controle e de Input/Output(I/O) especificadas pelas instruções no programa.

- Atua como o cérebro: segue as instruções definidas no código
- Executa computações, por exemplo: adicionar dois números
- Atua em conjunto com RAM e armazenamento persistente
- Gigahertz = 1 bilhão de operações por segundo

A CPU executa as intruções dos códigos, manipulando dados, enquanto os outros componentes possuem uma função mais passiva, como o armazenamento de dados. Quando dizemos que um computador pode "adicionar dois números, um bilhão de vezes por segundo", esse é o CPU. 

#### Exemplos

- Executar um script que imprime informações na tela e faz cálculos matemáticos.
- Treinar uma rede neural artificial com uma conjunto de dados de imagens

### 2. RAM

A **memória de acesso aleatório (RAM)** é uma forma de memória de computador que pode ser lida e alterada em qualquer ordem, normalmente usada para armazenar dados de trabalho e código de máquina. Um dispositivo de memória de acesso aleatório permite que os itens de dados sejam lidos ou gravados quase na mesma quantidade de tempo, independentemente da localização física dos dados na memória. 

A RAM contém circuitos de multiplexação e desmultiplexação, para conectar as linhas de dados ao armazenamento endereçado para leitura ou gravação da entrada. Geralmente, mais de um bit de armazenamento é acessado pelo mesmo endereço.

- Atua como um quadro em branco/bloco de notas
- Bytes de armazenamento temporários em funcionamento
- RAM armazena ambos o código e os dados (temporariamente)
- Exemplo: abrir uma imagem no GIMP, os dados da imagem são carregados nos bytes da RAM

**Persistência**: RAM não é persistente. O estado desaparece quando a energia é desligada.

Por exemplo: Quando estamos trabalhando em um documento e a energia é desligada repentinamente, caso não tenhamos salvo esse documento em uma memória persistente, o trabalho será perdido.

RAM é a memória de trabalho, o "bloco de notas" que o computador usa para armazenar código e dados que estão sendo usados ativamente. 

A RAM é efetivamente uma área de armazenamento de bytes sob o controle da CPU. A RAM é relativamente rápida e capaz de recuperar o valor de qualquer byte específico em alguns nanossegundos (1 nanossegundo é 1 bilionésimo de segundo). A outra característica principal da RAM é que ela apenas mantém seu estado enquanto for fornecida com energia: a RAM não é um armazenamento "persistente".

#### Exemplos

- Um programa executando em nossa máquina, o código do programa está armazenado em RAM
- Um programa que manipula imagens: os dados da imagem está em RAM
- Cada aba aberta em um Web Browser ocupa uma certa quantidade de RAM

### 3. Armazenamento Persistente: Hard Drive / Flash Drive

Uma unidade de disco rígido (HDD), disco rígido ou disco fixo é um dispositivo eletromecânico de armazenamento de dados que usa armazenamento magnético para armazenar e recuperar dados digitais usando um ou mais discos rígidos de rotação rápida revestidos com material magnético. Os discos são emparelhados com cabeças magnéticas, geralmente dispostas em um braço atuador em movimento, que lê e grava dados nas superfícies do disco. Os dados são acessados de maneira aleatória, significando que blocos individuais de dados podem ser armazenados e recuperados em qualquer ordem. Hard Drives são um tipo de armazenamento não volátil, mantendo os dados armazenados mesmo quando desligados.

- Armazenamento persistente de bytes
- "Persistente" significa preservado mesmo quando não está energizado
- Disco rígido - armazena bytes como um padrão magnético em um disco giratório
- Os discos rígidos são a principal tecnologia de armazenamento persistente há muito tempo

Porém atualmente a memória Flash está se tornando muito popular.

- "Flash" é uma tecnologia de armazenamento persistente do tipo transistor:
- "Estado Sólido" - sem partes móveis
- Também conhecidos como pendrives/SSD's
- O Flash é melhor do que um disco rígido em todos os aspectos: mais rápido, mais confiável, menos energia

Armazenamento persistente - armazenamento de longo prazo para bytes como arquivos e pastas. 

Persistente significa que os bytes são armazenados, mesmo quando a energia é removida. Um laptop pode usar um disco rígido giratório (também conhecido como "disco rígido") para armazenamento persistente de arquivos. Ou poderia usar uma "unidade flash", também conhecida como SSD (Solid State Disk), para armazenar bytes em chips flash. O disco rígido lê e grava padrões magnéticos em um disco de metal giratório para armazenar os bytes, enquanto o flash é "estado sólido": sem partes móveis, apenas chips de silício com pequenos grupos de elétrons para armazenar os bytes. Nos dois casos, o armazenamento é persistente, pois mantém seu estado mesmo quando a energia está desligada.

Uma unidade flash é mais rápida e consome menos energia que um disco rígido. No entanto, por byte, o flash é significativamente mais caro que o armazenamento no disco rígido. O Flash está ficando mais barato, por isso pode assumir nichos à custa dos discos rígidos. O flash é muito mais lento que a RAM, portanto, não é um bom substituto para a RAM.

## Sistema de Arquivos (File System)

Na computação, o File System (frequentemente abreviado como fs) controla como os dados são armazenados e recuperados. Sem um sistema de arquivos, os dados colocados em uma mídia de armazenamento seriam um grande corpo de dados, sem nenhuma maneira de sabermos quando um fragmento de dados termina e o próximo inicia. Ao separar os dados em partes e dar um nome a cada parte, os dados são facilmente isolados e identificados. Tomando seu nome da maneira como o sistema de gerenciamento de dados em papel é nomeado, cada grupo de dados é chamado de "arquivo". As regras de estrutura e lógica usadas para gerenciar os grupos de dados e seus nomes são chamadas de "sistema de arquivos".

- O File System oorganiza os bytes de armazenamento persistente: arquivos (files) e diretórios (folders)
- "File" - um nome, um identificador para um bloco de bytes
- Exemplo: `photo.png` se refere à 70KB de bytes de dados da imagem

![img](https://i.ibb.co/8D9STgN/filesystem.png)

Essencialmente, cada arquivo no sistema de arquivos refere-se a um bloco de bytes; portanto, o nome `photo.png` refere-se a um bloco de 70KB de bytes, que são os dados dessa imagem. O sistema de arquivos em vigor fornece ao usuário um nome (e possivelmente um ícone) para um bloco de bytes de dados e permite que o usuário execute operações nesses dados, como movê-lo ou copiá-lo ou abri-lo com um programa. O sistema de arquivos também rastreia informações sobre os bytes: quantos existem, a hora em que foram modificados pela última vez.

A Microsoft usa o sistema de arquivos NTFS proprietário e o Mac OS X possui o equivalente HFS+ da Apple. Muitos dispositivos (câmeras, MP3 players) usam o antigo sistema de arquivos Microsoft FAT32 em seus cartões de memória flash.