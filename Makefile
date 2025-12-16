all: 
	g++ -Wextra -o day_one_p2.exe day_one_p2.cpp

two: 
	g++ -Wextra -o day_two.exe day_two.cpp

three: 
	g++ -Wextra -o day_three.exe day_three.cpp

four:
	g++ -Wextra -o day_four.exe day_four.cpp

five: 
	g++ -std=c++20 -Wextra -o day_five.exe day_five.cpp
	./day_five.exe input_day_five.txt

exec_four: 
	./day_four.exe input_day_four.txt

exec_three: 
	./day_three.exe input_day_three.txt

exec_two: 
	./day_two.exe input_day_two.txt

exec: 
	./day_one_p2.exe test_p2.txt

clean:
	rm -f *.exe