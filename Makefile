notesapp: notes functions
	gcc -o bin/notesapp obj/notes.o obj/functions.o

notes: src/notes.c
	gcc -c src/notes.c -o obj/notes.o

functions: src/functions.c
	gcc -c src/functions.c -o obj/functions.o
