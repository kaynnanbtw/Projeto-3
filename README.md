# Ataque de dicionário

**Descrição:**

Este programa em C realiza um ataque de dicionário para quebrar senhas. O programa recebe como entrada dois arquivos: um arquivo de usuários com senhas criptografadas e um arquivo de senhas fracas. O programa então compara cada senha fraca com cada senha criptografada dos usuários. Se uma correspondência for encontrada, o programa imprime um relatório de quebra de senha.

**Requisitos:**

* O programa requer o compilador C.
* O programa requer as bibliotecas `stdio.h`, `stdlib.h` e `string.h`.

**Como usar:**

Para usar o programa, execute o seguinte comando:

```
$ ./quebra-senha <arquivo-usuarios> <arquivo-senhas-fracas> <arquivo-relatorio>
```

Onde:

* `<arquivo-usuarios>` é o caminho do arquivo de usuários.
* `<arquivo-senhas-fracas>` é o caminho do arquivo de senhas fracas.
* `<arquivo-relatorio>` é o caminho do arquivo de relatório de quebra.

**Exemplo:**

O seguinte exemplo mostra como usar o programa para quebrar senhas:

```
$ ./quebra-senha usuarios.txt senhas-fracas.txt relatorio.txt
```

O arquivo `usuarios.txt` contém os seguintes dados:

```
João da Silva
12/03/1980
joaosilva
123456
01/01/2023

Maria das Dores
20/07/1990
mariadores
abc123
02/02/2022
```

O arquivo `senhas-fracas.txt` contém os seguintes dados:

```
123456
abc123
senha123
senhaforte
```

O arquivo `relatorio.txt` será gerado com o seguinte conteúdo:

```
joaosilva 123456 João da Silva 12/03/1980
---
mariadores abc123 Maria das Dores 20/07/1990
```

**Como melhorar:**

O programa pode ser melhorado de várias maneiras, incluindo:

* Adicionar suporte para outros algoritmos de hash, além do SHA256.
* Adicionar suporte para outras bases de dados de senhas fracas.
* Melhorar a eficiência do algoritmo de comparação de senhas.
