# type of compiler
CC=g++
CFLAGS=-std=c++11 -O3 -Wall  

FILE_NAME=project

all:
# clear the things in the terminal
	clear
# compile
	$(CC) $(CFLAGS) $(FILE_NAME).cpp -lm
#  execute the file -> input in the terminal the file test.in -> output the result int the file result.out
	./a.out <test.in >result.out

step:
	clear
	$(CC) -g -Wall -std=c17 -c $(FILE_NAME).cpp -o $(FILE_NAME).o
	$(CC) -g -Wall -std=c17 $(FILE_NAME).o -o $(FILE_NAME)
	gdb $(FILE_NAME)
# a partir daqui é precico por manualmente
# breakpoint na função resultado (se eu quiser ver todos os breakpoints é só fazer -> info b)
#->	b adaptedKruskal
# run
#->	r
# analisar cada linha
#->	s
# avançar muitas linhas de codigo
#->	n
# analisar o valor da variavel
#->	p <variavel>

clean:
	rm -rf $(FILE_NAME) *.o



# (ignror isto)
# -> comandos do git 
# git init (inicializa o repositorio)
# git config --global user.email "arturkrys@gmail.com"
# git config --global user.name "Artur Krystopchuk"
#
# git status (avisa untracked files e que ficheiros falta dar commit e que branch eu estou)
# git add file.c (em vez de file.c posso fazer git add . para adicionar só o que é novo)
# git commit -m "mensagem"
# git log --pretty=oneline --graph --decorate --all (ver todos os commits) (se tirar --pretty=oneline consigo ver o nome e o e-mail)
#
# git checkout <commit-hash>
# git branch (mostra todas as branches)
# git branch <branchname> (depois preciso dar checkout nessa timeline para fazer as alterações)
# git merge <branchname> (faz as alterações que fiz na outra timeline no master) (é preciso dar checkout no master primeiro)
# git branch --delete <branchname>
#
# -> github (neste caso dei o nome de teste)
# git remote add origin https://github.com/ArturKrys/<name>.git
# git push -u origin <branchname>
# git pull origin <branchname>
#
# projeto de outra pessoa
# git clone git://github.com/myfriend/the_repo
