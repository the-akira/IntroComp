# Debugging 

A história por trás do termo **[Debugging](https://en.wikipedia.org/wiki/Debugging)**

O termo "bug" foi usado pela pioneira em informática Grace Hopper, que divulgou a causa de um mau funcionamento em um computador eletromecânico inicial. 

![img](https://i.ibb.co/ZS4Tb1H/firstbug.png)

<figure>
    <blockquote>
        <p>Uma página do registro do computador eletromecânico de Harvard Mark II, com uma mariposa morta que foi removida do dispositivo.</p>
    </blockquote>
</figure>

Em 1946, quando [Admiral Grace Hopper](https://en.wikipedia.org/wiki/Admiral_Grace_Hopper) foi liberada do serviço ativo, ingressou na Faculdade Harvard no Laboratório de Computação, onde continuou seu trabalho nos computadores Mark II e III. Os operadores localizaram um erro no Mark II em uma mariposa presa em um relé, cunhando assim o termo [bug](https://en.wikipedia.org/wiki/Software_bug). Este bug foi cuidadosamente removido e colado no livro de registro. A partir do primeiro bug, hoje chamamos de erros ou falhas em um programa um bug e a remoção deles de **[debug](https://en.wikipedia.org/wiki/Debugging)**, que seria remover o problema/erro do programa.

![img](https://i.ibb.co/HGY2Sx9/markII.jpg)

<figure>
    <blockquote>
        <p>Fotografia do computador Mark II, onde foi encontrado o primeiro "bug", nessa época este computador precisava de aproximadamente 2 horas para calcular uma função arctan.</p>
    </blockquote>
</figure>

## Sobre Debugging

O que seria então Debugging dentro do contexto atual de programação / desenvolvimento de Softwares?

Debugging é o processo de encontrar e resolver defeitos ou problemas em um programa de computador que impede a operação correta do software ou sistema.

As táticas/estratégias de Debugging podem envolver *interactive debugging*, análise de controle de fluxo, *[unit testing](https://en.wikipedia.org/wiki/Unit_testing)*, *[integration testing](https://en.wikipedia.org/wiki/Integration_testing)*, [análises de arquivos log](https://en.wikipedia.org/wiki/Logfile), monitoramento em nível de aplicação ou sistema, *[memory dumps](https://en.wikipedia.org/wiki/Memory_dump)* e *[profiling](https://en.wikipedia.org/wiki/Profiling_(computer_programming))*.

## Formas de Debugging

Existem fundamentalmente duas maneiras eficazes de executar o Debugging de um programa:

- Ferramentas (conhecidas também como [Debuggers](https://en.wikipedia.org/wiki/Debugger))
- Utilizando [print statements](http://www.personal.psu.edu/jhm/f90/statements/print.html)

Aspectos importantes que nos ajudam no processo de Debugging:

- Por que o programa produziu este resultado?
- Estudar os dados disponíveis (texto do programa & resultados de testes).
- Formular uma hipótese que deve ser consistente com os dados.
- Construir e executar um experimento que possa ser **repetido**.
- Para que esse experimento seja útil, ele deve possuir o potencial de refutar a hipótese.