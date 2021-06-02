# Dados e Armazenamento

## Bits e Bytes

### Bit

O **bit** é uma unidade básica de informação em teoria da informação, computação e comunicações digitais. O nome **bit** se refere a união das palavras *binary* + *digit*.

Como **dígito binário**, o **bit** representa um estado lógico, possuindo apenas um de dois valores. Pode ser implementado fisicamente com um dispositivo de dois estados. Esses valores geralmente são representados como **0** ou **1**, mas outras representações como **verdadeiro**/**falso**, **sim**/**não**, **+**/**−** ou **ativado**/**desativado** são comuns em linguagens de programação.

Um bit pode ser armazenado por um dispositivo digital ou outro sistema físico existente em um de dois [estados](https://en.wikipedia.org/wiki/State_(computer_science)) distintos possíveis. Estes podem ser os dois estados estáveis de um [flip-flop](https://en.wikipedia.org/wiki/Flip-flop_(electronics)), duas posições de um [interruptor elétrico](https://en.wikipedia.org/wiki/Switch), dois níveis distintos de [tensão](https://en.wikipedia.org/wiki/Voltage) ou [corrente](https://en.wikipedia.org/wiki/Electric_current) permitidos por um [circuito](https://en.wikipedia.org/wiki/Electrical_network), dois níveis distintos de [intensidade de luz](https://en.wikipedia.org/wiki/Irradiance), duas direções de [magnetização](https://en.wikipedia.org/wiki/Magnetism) ou [polarização](https://en.wikipedia.org/wiki/Electrical_polarity), entre outras possibilidades.

- O bit é atômico: ele é a menor unidade de armazenamento
- O bit armazena apenas **0** ou **1**
- Qualquer elemento com dois estados separados pode armazenar 1 bit
- Em um chip: carga elétrica = **0**/**1**
- Em um disco rígido: pontos de magnetismo Norte/Sul = 0/1
- O bit é pequeno demais para ser útil
- Um grupo de **8 bits** forma **1 byte**

"Tudo em um computador são 0's e 1's. O bit armazena apenas 0 ou 1: é o menor componente básico de armazenamento."

![img](https://i.ibb.co/z8NLHyX/Bits-Bytes.png)

<figure>
    <blockquote>
        <p>A figura acima ilustra a representação do número 255 na base binária, decimal e hexadecimal.</p>
    </blockquote>
</figure>

**Tabela de Padrões**

| Número de Bits  | Padrões Diferentes  | Cálculo  |
|---|---|---|
| 1  | 0 1  | 2^1  |
| 2  | 00 01 10 11  | 2^2  |
| 3  | 000 001 010 011 100 101 110 111  | 2^3 |

- **1 Byte** = 256 padrões = 2^8
- 8 bits são capazes de criar 256 padrões diferentes
- 1 byte pode guardar um número entre 0 e 255
- Os bytes são excelentes para guardarmos letras/caracteres
- Nos computadores, os componentes de cores RGB são definidos de maneira padrão em uma escala de 0 a 255, que é de 8 bits ou 1 byte, estes são frequentemente representados como números decimais ou hexadecimais.

![img](https://i.ibb.co/FnMjsRY/RGBColors.png)

<figure>
    <blockquote>
        <p>A figura acima ilustra a representação das cores <b>Vermelho</b>(Binário), <b>Verde</b>(Decimal) e <b>Azul</b>(Hexadecimal), uma cor no modelo de cores RGB é descrita indicando quanto de cada vermelho, verde e azul está incluído.</p>
    </blockquote>
</figure>

### Byte

O **byte** é uma unidade de informação digital que geralmente consiste em oito bits. Historicamente, o byte era o número de bits usado para codificar um único caractere de texto em um computador e, por esse motivo, é a menor unidade de memória endereçável em muitas arquiteturas de computadores.

- Todo o armazenamento é medido em bytes, apesar das diferenças entre hardwares
- **Kilobyte**, KB, 1 mil bytes
- **Megabyte**, MB, 1 milhão de bytes
- **Gigabyte**, GB, 1 bilhão de bytes
- **Terabyte**, TB, 1 trilhão de bytes

### Bytes e Caracteres - Código ASCII

**ASCII** abreviatura de **American Standard Code for Information Interchange**, é um padrão de codificação de caracteres para comunicação eletrônica. Os códigos ASCII representam texto em computadores, equipamentos de telecomunicações e outros dispositivos. A maioria dos esquemas de codificação de caracteres modernos são baseados em ASCII, embora eles suportem muitos caracteres adicionais.

- [ASCII](https://en.wikipedia.org/wiki/ASCII) é uma codificação que representa cada caractere digitado por um número
- Cada número é armazenado em um byte (portanto, o número está entre 0...255)
- **A** é 65
- **G** é 71
- "[Unicode](https://en.wikipedia.org/wiki/Unicode)" é uma codificação para idiomas mandarim, grego, árabe, etc., normalmente 2 bytes por "caractere"

O programa em C a seguir imprime os valores decimais e hexadecimais dos caracteres ASCII de 33 até 126.

```c
#include <stdio.h>

int main()
{
    int i;
    for(i = 33; i < 127; i++)
    {
        printf("O valor ASCII de %c = %d = %x\n", i, i, i);
    }
}
```

Podemos compilar ele com o seguinte comando: `cc -O -o ascii.out ascii.c` e executá-lo com `./ascii.out`, que nos retornará:

```
O valor ASCII de ! = 33 = 21
O valor ASCII de " = 34 = 22
O valor ASCII de # = 35 = 23
O valor ASCII de $ = 36 = 24
O valor ASCII de % = 37 = 25
O valor ASCII de & = 38 = 26
O valor ASCII de ' = 39 = 27
...
O valor ASCII de x = 120 = 78
O valor ASCII de y = 121 = 79
O valor ASCII de z = 122 = 7a
O valor ASCII de { = 123 = 7b
O valor ASCII de | = 124 = 7c
O valor ASCII de } = 125 = 7d
O valor ASCII de ~ = 126 = 7e
```

### Kilobytes, Megabytes, Gigabytes e Terabytes

O tamanho das informações no computador é medido principalmente em **kilobytes**, **megabytes**, **gigabytes** e **terabytes**.

#### Kilobyte ou KB

- Kilobyte KB - cerca de 1 mil bytes
- Um email sem imagens tem cerca de 2 KB
- Um documento de cinco páginas pode ter 100 KB
- O texto é compacto, exigindo poucos bytes em comparação com imagens, som ou vídeo
- **Exemplo**: 23.000 bytes têm cerca de 23 KB

Um kilobyte (KB) é uma coleção de cerca de 1000 bytes. Uma página de texto alfabético romano comum leva cerca de 2 kilobytes para armazenar (cerca de um byte por letra). Um e-mail curto típico também ocuparia apenas 1 ou 2 kilobytes. O texto é um dos tipos de dados mais naturalmente compactos, com aproximadamente um byte, necessário para armazenar cada letra. Em alfabetos não romanos, como o mandarim, o armazenamento ocupa 2 ou 4 bytes por "letra", o que ainda é bastante compacto comparado ao áudio e imagens.

#### Megabyte ou MB

- Megabyte (MB) - cerca de 1 milhão de bytes ou 1000 KB
- O áudio MP3 é de cerca de 1 megabyte por minuto
- Uma imagem digital de alta qualidade tem cerca de 2-5 megabytes
- **Exemplo**: 45,400 KB é 45.4 MB

Um megabyte tem cerca de 1 milhão de bytes (ou cerca de 1000 kilobytes). Um arquivo de áudio MP3 de alguns minutos ou uma imagem de 10 milhões de pixels de uma câmera digital normalmente ocupa alguns megabytes. A regra geral para o áudio MP3 é que 1 minuto de áudio ocupa cerca de 1 megabyte. Dados de áudio e imagem e vídeo normalmente armazenados em formato "compactado", sendo o MP3 um exemplo. Um disco de CD de dados armazena cerca de 700 MB. O áudio em um CD não é compactado, e é por isso que ocupa muito mais espaço que o MP3. A série de bits é representada como um caminho espiral de pequenas cavidades no material prateado do disco.

#### Gigabyte ou GB

- Gigabyte GB = cerca de um bilhão de bytes = 1000 MB
- GB é uma unidade comum para o hardware moderno
- Um computador comum tem cerca de 4 GB de RAM e em média 500 GB de armazenamento persistente

#### Terabyte ou TB

Um terabyte (TB) tem cerca de 1000 gigabytes, ou aproximadamente 1 trilhão de bytes. É possível obter discos rígidos de 4 TB atualmente, portanto, estamos começando o momento em que esse termo entrará em uso comum. Gigabyte também costumava ser um termo exótico, até que a lei de Moore tornou ele comum.