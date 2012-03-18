# Makefile ToyLang project
# please refer to the tutorial on http://gnuu.org/2009/09/18/writing-your-own-toy-compiler/all/1/

# Some enviroment variables
LIBS = `llvm-config --libs core jit native`
LDFLAGS = `llvm-config --ldflags`
CPPFLAGS = `llvm-config --cppflags`

# Build all components
all:	parser_scanner toyLang

# Ask flex and bison to create our parser and scanner
parser_scanner:	scanner.l parser.y
	bison -d -o parser.gen.cpp parser.y
	flex -o scanner.gen.cpp scanner.l
	
# Build our toyCompiler ($@ means the target)
toyLang: main.cpp
	g++ -o $@ parser.gen.cpp scanner.gen.cpp main.cpp

doc:
	doxygen docs/doxygen.conf

# Clean deleted files
clean:
	rm *.gen.*
	rm toyLang
	
