#ZIPFILE = examples_cc.zip
ALLFILES = run_all_examples.cc
PROGS += 
#pack:
#	zip -u $(ZIPFILE) makefile $(ALLFILES)
#crunch: clean
#	zip -m -u $(ZIPFILE) $(ALLFILES) 
#unpack:
#	unzip -u -o $(ZIPFILE)
TO_CLEAN_FILES += *.cc *.h  recipes.zip 

install-h:
install-lib:

#WWWOBJS = examples.zip
#WWWDIR = /home/bernt/public_html/gcc_prog/recipes
#install-www: $(WWWOBJS)
#	cp -f $(WWWOBJS) $(WWWDIR)

#examples.zip:  makefile fin_recipes.h normdist.h makefile
#	zip   examples makefile readme
#	zip -m  examples *.cc *.h 

CXX = gcc
CXXFLAGS = -c -O2
 %.o : %.cc
	$(CXX) $(CXXFLAGS) $*.cc

LIBOBJS += 
fin_recipes.h:
	cp ../all_cc_progs/fin_recipes.h .
normdist.h:
	cp ../all_cc_progs/normdist.h .
run_all_examples.o: fin_recipes.h normdist.h $(LIB)

LIB = librecipes.a 
librecipes.a: 
	cp ../build/librecipes.a .
run_all_examples: run_all_examples.o librecipes.a
	g++ run_all_examples.o   -L. -lrecipes  -o run_all_examples 
TO_CLEAN_FILES += $(LIB) run_all_examples *~
TO_CLEAN_FILES += *.o

clean:
	rm -f $(TO_CLEAN_FILES) 
realclean: clean
run: run_all_examples
	./run_all_examples
