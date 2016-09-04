FILE_LIST= \
	cmd_main.cpp \
	telnet_srv.cpp \
	unit_test.cpp \
	test.cpp

all: 
	g++ -o my_cmd -g $(FILE_LIST) -l pthread
	ls -l my_cmd
	./my_cmd
