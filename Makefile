all:
	gcc -o SoKoBan SoKoban.c -lncurses
clean:
	rm -rf SoKoBan
