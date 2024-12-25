# cc = g++
# source = $(shell find ./src/ -type f \( -iname "*.cpp" ! -iname "HelloWorld*" \))
# cflags = -std=c++11  -lgtest -lpthread -Wfatal-errors
# output = bin/ut_all

# .PHONY: all
# all: directories ut

# hello: src/HelloWorld.cpp
# 	$(cc) $(source) src/HelloWorld.cpp -o bin/HelloWorld

# ut: test/ut_main.cpp 
# 	$(cc) $(source) test/ut_main.cpp -o $(output) $(cflags)

# gcovr: test/ut_main.cpp 
# 	$(cc) $(source) test/ut_main.cpp -o $(output) $(cflags)

# directories:
# 	mkdir -p ./bin

# .PHONY: clean
# clean:
# 	rm -rf bin *.gcov *.gcda *.gcno *.html *.css


###HW
cc = g++
output_ut_all = bin/ut_all
output_ut_all_gcovr = bin/ut_all_gcovr

.PHONY: directories clean stat

all: directories bin/ut_all gcovr

bin/ut_all: test/ut_main.cpp
	$(cc) -std=c++14 src/mybike.h  src/bike.h src/electric_bike.h src/bike_factory.h src/bike_rms.h test/ut_main.cpp -o $(output_ut_all) -lgtest -lpthread

gcovr: test/ut_main.cpp 
	$(cc) -std=c++14 src/mybike.h  src/bike.h src/electric_bike.h src/bike_factory.h src/bike_rms.h test/ut_main.cpp -o $(output_ut_all_gcovr) -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0

directories:
	mkdir -p ./bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

valgrind:
	valgrind --error-exitcode=2 --track-origins=yes --leak-check=full ./bin/ut_all

stat:
	wc src/* test/*


###############################
## gcovr --exclude test
## gcovr --exclude test --html-details report.html

## git rm src/length.h --cached
## git add src/