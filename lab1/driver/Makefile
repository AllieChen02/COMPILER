#
demo:	compiler/demo.c parser scanner  compiler/demo.h \
	compiler/timestamp.o
	cc -g compiler/demo.c compiler/parser.o compiler/scanner.o compiler/timestamp.o
	mv a.out demo

#
parser:	DEMOgram.y compiler/demo.h
	bison -vd --debug DEMOgram.y

	mv DEMOgram.tab.c compiler/parser.c
	mv DEMOgram.tab.h compiler/tokens.h
	cc -c -g compiler/parser.c
	mv parser.o compiler/parser.o

#
scanner:	DEMOgram.l compiler/tokens.h compiler/demo.h
	flex DEMOgram.l

	mv lex.yy.c compiler/scanner.c
	cc -c -g compiler/scanner.c
	mv scanner.o compiler/scanner.o

#
timestamp.o: compiler/timestamp.c compiler/demo.h
	cc -c -g compiler/timestamp.c
#
clean:	
	rm compiler/*.o
	rm compiler/parser.c compiler/scanner.c

