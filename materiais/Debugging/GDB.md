# Debugging com GDB

O GNU Debugger (GDB) é um depurador portátil que roda em muitos sistemas Unix e funciona para muitas linguagens de programação, incluindo Ada, C, C++, Objective-C, Free Pascal, Fortran, Go.

Para ler o manual completo digite o comando: `info gdb`

Para mais informações você pode acessar o site oficial do GDB: [GDB: The GNU Project Debugger](https://www.gnu.org/software/gdb/)

Cheat Sheets úteis:

- [GDB Cheat Sheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
- [GDB Quick Reference](https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf)
- [GDB Cheat Sheet Gist](https://gist.github.com/rkubik/b96c23bd8ed58333de37f2b8cd052c30)

Para estes exemplos iremos utilizar o seguinte programa escrito em C, sendo assim os exemplos estão em contexto com `factorials.c`

```c
#include <stdio.h>

int main(void)
{
    int num;
    unsigned long long factorial = 1;

    do
    {
        printf("Entre um inteiro positivo: ");
        scanf("%d",&num);
    }
    while(num < 0);

    for(int i = 1; i <= num; i++)
        factorial = factorial * i;
    printf("%d! = %llu\n",num,factorial);
}
```

Ele é um simples programa capaz de computar o fatorial de um determinado número informado pelo usuário.

1. Compilando o Programa com **[GCC](https://gcc.gnu.org/)** usando `-g` de forma a preservar identificadores e símbolos

```
gcc -Wall -g -o factorials factorials.c
```

2. Inicializando o **[GDB](https://www.gnu.org/software/gdb/)** 

```
gdb factorials
```

3. Executando o programa

```
run
r
```

4. Inicializando a execução do programa com **breakpoint** para examiná-lo

```
start
```

5. Listando o código fonte

```
list
```

6. Executando uma instrução do código-fonte

```
step 
s
next
n
```

7. Imprimindo o valor de uma variável

```
print num
p num
p $sp (imprime o stack pointer)
p $eax (imprime o registrador eax)
p $esp (imprime o registrador esp)
```

8. Examinando bytes

```
x
x/200
x &i
x $0
x/5xh &i (halfwords)
x/5i &i (machine instructions)
x/5s &i (string)
```

9. Colocando um "observador" / **watch point** em uma variável

```
watch i
watch i if i > 3
```

10. Inserindo um leitor de **watch point**

```
rwatch i
```

11. Continuar a execução do programa

```
c
cont
continue
```

12. Inserindo um breakpoint em uma determinada linha ou função do programa

```
break main
break 12
b 12
```

13. Obtendo informações

```
info watch
info break
info registers
info address
info locals
whatis i
```

14. Disassemble do código-fonte

```
disassemble
disass main
```

15. Controlando o estilo usado por Disassemble

```
set disassembly-flavor att
set disassembly-flavor intel
show disassembly-flavor
```

16. Reinicializando o programa

```
r
```

17. Limpando um breakpoint

```
clear main
clear 12
```

18. Limpando a Tela

``` 
refresh
ctrl + l
```

19. Habilitando e Desabilitando Text User Interface(TUI)

```
tui enable
tui disable
CTRL + X + A
```

20. Habilitando Segunda Janela

```
CTRL + X + 2
```

21. Utilizando o Interpretador Python

Executando um comando: 

```
python print('Hello World')
```

Criando um script:

```
python
for i in range(5):
    print(i)
end
```

Executando comandos **gdb**:

```
python gdb.execute('start')
python gdb.execute('next')
```

Verificando **breakpoints**:

```
python bps = gdb.breakpoints()
python print(bps)
python print(bps[0].location)
```

Avaliando uma expressão, podemos por exemplo rastrear uma variável ou função

```
python var_num = gdb.parse_and_eval('num')
python main = gdb.parse_and_eval('main')
python print(var_num)
python print(main)
```

Obtendo ajuda com o módulo Python

```
python help(gdb)
```

22. Executando comandos Shell

```
shell ls
shell cat factorials.c
``` 

23. Navegando comandos **anteriores** / **próximos**

```
ctrl + p
ctrl + n
```

24. Habilitando **Recording**

```
record
```

25. Execução Reversa do Programa

```
reverse-stepi
```

26. Alterando Configurações (`.gdbinit`)

```
set history save on
set print pretty on
set pagination off
set confirm off
```

27. Habilitando o Layout ASM

```
layout asm
```

28. Habilitando a Visualização dos Registradores

```
layout reg
run
```

29. Definindo um Breakpoint em uma Instrução Específica

```
break *0x55555555471a
```

30. O comando display serve para exibir valores automaticamente sempre que um ponto de interrupção (**breakpoint**) for atingido

```
display $eax
display $edx
```

31. Saindo do GDB

```
quit
```
