# OpenAAC/MP
- Para utilização do OpenACC/MP é necessário possuir a versão 7 para cima do gcc.
- Para verificar: gcc --version

## Instalação Windows

  1) Baixe [este arquivo](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/), e extraia em alguma pasta de seu interesse. 

  2) Após ter feito, entrar na pasta criada e depois na pasta bin
  Ex: C:\mingw32\bin

  3) Apertar Windows + R, e digitar sysdm.cpl

  4) Na tela que abriu, na aba avançado ir em variaveis de ambiente

  5) Na parte de variaveis do sistema, encontrar o 'Path', selecionar e clicar em editar
  - Caso você ja possua alguma versão anterior do GCC, por gentileza remover ela do Path para evitar conflitos.

  6) Adicionar o caminho para a pasta bin do item 2

## Execução

- OpenACC: gcc -fopeanacc nomedoarquivo.c

- OpenMP: gcc -fopenmp nomedoarquivo.c


## Outras opções para OpenACC
Caso alguem queira, instalar o compilador [daqui](https://www.pgroup.com/products/community.htm?utm_source=dev_nvidia_oacc&utm_medium=web_link&utm_term=download_button), ele é maior o download mas tem a vantagem de vir tudo pronto, entretanto é uma versão de teste de 30 dias.

## Para executar ele 
pgcc -acc -Minfo=accel nomedoarquivo.c

