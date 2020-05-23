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
O valor ASCII de ( = 40 = 28
O valor ASCII de ) = 41 = 29
O valor ASCII de * = 42 = 2a
O valor ASCII de + = 43 = 2b
O valor ASCII de , = 44 = 2c
O valor ASCII de - = 45 = 2d
O valor ASCII de . = 46 = 2e
O valor ASCII de / = 47 = 2f
O valor ASCII de 0 = 48 = 30
O valor ASCII de 1 = 49 = 31
O valor ASCII de 2 = 50 = 32
O valor ASCII de 3 = 51 = 33
O valor ASCII de 4 = 52 = 34
O valor ASCII de 5 = 53 = 35
O valor ASCII de 6 = 54 = 36
O valor ASCII de 7 = 55 = 37
O valor ASCII de 8 = 56 = 38
O valor ASCII de 9 = 57 = 39
O valor ASCII de : = 58 = 3a
O valor ASCII de ; = 59 = 3b
O valor ASCII de < = 60 = 3c
O valor ASCII de = = 61 = 3d
O valor ASCII de > = 62 = 3e
O valor ASCII de ? = 63 = 3f
O valor ASCII de @ = 64 = 40
O valor ASCII de A = 65 = 41
O valor ASCII de B = 66 = 42
O valor ASCII de C = 67 = 43
O valor ASCII de D = 68 = 44
O valor ASCII de E = 69 = 45
O valor ASCII de F = 70 = 46
O valor ASCII de G = 71 = 47
O valor ASCII de H = 72 = 48
O valor ASCII de I = 73 = 49
O valor ASCII de J = 74 = 4a
O valor ASCII de K = 75 = 4b
O valor ASCII de L = 76 = 4c
O valor ASCII de M = 77 = 4d
O valor ASCII de N = 78 = 4e
O valor ASCII de O = 79 = 4f
O valor ASCII de P = 80 = 50
O valor ASCII de Q = 81 = 51
O valor ASCII de R = 82 = 52
O valor ASCII de S = 83 = 53
O valor ASCII de T = 84 = 54
O valor ASCII de U = 85 = 55
O valor ASCII de V = 86 = 56
O valor ASCII de W = 87 = 57
O valor ASCII de X = 88 = 58
O valor ASCII de Y = 89 = 59
O valor ASCII de Z = 90 = 5a
O valor ASCII de [ = 91 = 5b
O valor ASCII de \ = 92 = 5c
O valor ASCII de ] = 93 = 5d
O valor ASCII de ^ = 94 = 5e
O valor ASCII de _ = 95 = 5f
O valor ASCII de ` = 96 = 60
O valor ASCII de a = 97 = 61
O valor ASCII de b = 98 = 62
O valor ASCII de c = 99 = 63
O valor ASCII de d = 100 = 64
O valor ASCII de e = 101 = 65
O valor ASCII de f = 102 = 66
O valor ASCII de g = 103 = 67
O valor ASCII de h = 104 = 68
O valor ASCII de i = 105 = 69
O valor ASCII de j = 106 = 6a
O valor ASCII de k = 107 = 6b
O valor ASCII de l = 108 = 6c
O valor ASCII de m = 109 = 6d
O valor ASCII de n = 110 = 6e
O valor ASCII de o = 111 = 6f
O valor ASCII de p = 112 = 70
O valor ASCII de q = 113 = 71
O valor ASCII de r = 114 = 72
O valor ASCII de s = 115 = 73
O valor ASCII de t = 116 = 74
O valor ASCII de u = 117 = 75
O valor ASCII de v = 118 = 76
O valor ASCII de w = 119 = 77
O valor ASCII de x = 120 = 78
O valor ASCII de y = 121 = 79
O valor ASCII de z = 122 = 7a
O valor ASCII de { = 123 = 7b
O valor ASCII de | = 124 = 7c
O valor ASCII de } = 125 = 7d
O valor ASCII de ~ = 126 = 7e
```