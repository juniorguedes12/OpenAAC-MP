# OpenAAC
- Para utilização do OpenACC é necessário possuir a versão 7 para cima do gcc.
- Para verificar: gcc --version

## Instalação Windows
  
  1) Instalar o GCC pelo executavel [daqui](https://sourceforge.net/projects/mingw-w64/) (Versão 7.3.0)

  2) Caso ocorra algum erro na instalação anterior, baixar [este arquivo](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/), e extrair em alguma pasta de seu interesse. 

  3) Após ter feito algum dos dois, entrar na pasta criada e depois na pasta bin
  Ex: C:\mingw32\bin

  4) Apertar Windows + R, e digitar sysdm.cpl

  5) Na tela que abriu, na aba avançado ir em variaveis de ambiente

  6) Na parte de variaveis do sistema, encontrar o 'Path', selecionar e clicar em editar
  - Caso você ja possua alguma versão anterior do GCC, por gentileza remover ela do Path para evitar conflitos.

  7) Adicionar o caminho para a pasta bin do item 3

## Instalação no Linux
não sei


## Execução

gcc -fopeanacc nomedoarquivo.c


#### Outras opções
Caso alguem queira, instalar o compilador [daqui](https://www.pgroup.com/products/community.htm?utm_source=dev_nvidia_oacc&utm_medium=web_link&utm_term=download_button), ele é mais facil de usar, só é maior o download mesmo (mas ele funciona bonitinho, ainda mais pra usuários de Nvidia). 
#### Para executar ele 
pgcc -acc -Minfo=accel nomedoarquivo.c

