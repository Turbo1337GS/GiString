all: GigaSoft

GigaSoft: main.cpp
	g++ ./*.cpp ./*.hpp -o GigaSoft

clean:
	rm -f GigaSoft