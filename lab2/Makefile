#
.PHONY: test
test: 
	make demo;
	./grading.sh

demo:	demo.c parser.o scanner.o  demo.h \
	timestamp.o
	cc -g demo.c parser.o scanner.o timestamp.o
	mv a.out demo

#
parser.o:	DEMOgram.y demo.h
	bison -vd --debug DEMOgram.y
	mv DEMOgram.tab.c parser.c
	mv DEMOgram.tab.h tokens.h
	cc -c -g parser.c

#
scanner.o:	DEMOgram.l tokens.h demo.h
	flex DEMOgram.l
	mv lex.yy.c scanner.c
	cc -c -g scanner.c


#
timestamp.o: timestamp.c demo.h
	cc -c -g timestamp.c
#
clean:	
	rm *.o 

