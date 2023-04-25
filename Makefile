.PHONY: clean, run, doc, all, pack, test, profile

exec := kaukulacka_pro_cumacky

to_zip := *.h *.cpp hodnoceni.txt $(documentation_name).pdf odevzdani.txt 

zipname := xslobo08_xlauer00_xforte03.zip 

documentation_name := documentation

all: $(exec)

srcs := $(wildcard *.cpp)
objs := $(srcs:.cpp=.o)
deps := $(srcs:.cpp=.d)

$(exec): $(objs)
	$(CXX) -o $@ $+ -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< 
	$(CXX) $(CXXFLAGS) -MF $(patsubst %.o,%.d,$@) -M $< 
	
-include $(wildcard *.d)

clean:
	@rm -fv $(objs) $(deps) $(exec) $(documentation_name).pdf $(zipname).zip

run: all
	./$(exec)

doc:
	doxygen Doxyfile
	$(MAKE) -C latex
	cp latex/refman.pdf $(documentation_name).pdf

pack: doc
	zip $(zipname) $(to_zip) 

help:
	echo -e "Pouziti:\n\t-make [all] - zkompiluje a nalinkuje .cpp a hlavickove soubory a vytovri spustitelny soubor $(exec)\n" && echo -e "\t-make pack - zabali projekt tak, aby byl pripraveny k odevzdani\n" && echo -e "\t-make clean - vycisti repozitar od $(objs), $(deps), $(exec),dokumentace a zip souboru\n" && echo -e "\t-make run - zkompiluje, nalinkuje a spusti\n" && echo -e "\t-make profile - zkompiluje, nalinkuje a spusti program a program pro vypocet smerodajne odchylky s ukazkovym testovacim vstupem\n"

profile: all
	./$(exec) < ./profiler <inputs.txt
	gprof $(exec)

