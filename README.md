# OpenAAC

## Instalação Windows
  1) Instalar GCC pelo executavel [daqui](https://sourceforge.net/projects/mingw-w64/) (Versão 7.3.0)
  
  Se o passo 1 deu certo, pule para o 3

  2) Caso ocorra algum erro, baixar [este arquivo](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/), e extraia em alguma pasta de seu interesse. 

  3) Após ter feito algum dos dois, entrar na pasta criada e depois na pasta bin
  Ex: C:\mingw32\bin

  4) Apertar Windows + R, e digitar sysdm.cpl

  5) Na tela que abriu, na aba avançado ir em variaveis de ambiente

  6) Na parte de variaveis do sistema, encontrar o 'Path', selecionar e clicar em editar

  7) Adicionar o caminho para a pasta bin do item 3


## Instalação no Linux

não sei ainda


## Execução

gcc -fopeanacc nomedoarquivo.c
