ifndef VERBOSE
.SILENT:
endif
OS := $(shell uname)
CC =  --coverage -Wall -Werror -Wextra -lstdc++ -std=c++17
FLAGS = -lgtest -ftest-coverage -fprofile-arcs

ifeq ($(OS),Darwin)
	OPEN_CMD = open
else
	FLAGS += -lm -lrt 
	OPEN_CMD = xdg-open
endif

all: clean test gcov_report

calc_controler.a:
	g++ $(CC) -c controller/calc_controler.cc
	ar -crs calc_controler.a calc_controler.o
	# clear

back_model.a:
	g++ $(CC) -c back_model/back_model.cc
	ar -crs back_model.a back_model.o
	# clear



test: clean back_model.a calc_controler.a
	g++ $(CC) tests/test_back.cc back_model.a calc_controler.a $(FLAGS) -o test
	./test
	# clear


gcov_report: clean test
	lcov -t "./test"  -o report.info --no-external --ignore-errors inconsistent,format,usage  -c -d .
	genhtml -o report report.info 
	$(OPEN_CMD) ./report/index.html
	clear
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o *.a test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info
	rm -rf build
	rm -rf Archive_CPP3_SMARTCALC_V2.0-1.0.tgz
	clang-format -style=Google -i **/*.h **/*.cc
	clear

install: uninstall clean
	mkdir build
	cd calc/ && qmake && make && make clean && rm Makefile && mv ../calc/*.app ../build

uninstall:
	rm -rf build*

dvi: clean
	open dvi/dvi.html

dist:clean install
	rm -rf Archive_CPP3_SMARTCALC_V2.0-1.0/
	mkdir Archive_CPP3_SMARTCALC_V2.0-1.0/
	mkdir Archive_CPP3_SMARTCALC_V2.0-1.0/src
	cp -R build/ Archive_CPP3_SMARTCALC_V2.0-1.0/src/
	tar cvzf Archive_CPP3_SMARTCALC_V2.0-1.0.tgz Archive_CPP3_SMARTCALC_V2.0-1.0/
	rm -rf Archive_CPP3_SMARTCALC_V2.0-1.0/
