notesapp: objects
	g++ -c notesapp obj/functions.o obj/notes.o  

objects: src/functions.cpp src/main.cpp headers/references.h headers/vars.h
	g++ -o bin/functions.o src/functions.cpp
       	g++ -o bin/notes.o src/notes.cpp


