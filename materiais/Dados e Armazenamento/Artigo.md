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