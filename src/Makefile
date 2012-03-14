# Makefile ToyLang project
# please refer to the tutorial on http://gnuu.org/2009/09/18/writing-your-own-toy-compiler/all/1/

# Some enviroment variables
LIBS = `llvm-config --libs core jit native`
LDFLAGS = `llvm-config --ldflags`
CPPFLAGS = `llvm-config --cppflags $(LLVM_MODULES)`

# Build all components
all:	toyLang

# Ask flex and bison to create our parser and scanner
parser_scanner:	scanner.l parser.y
	bison -d -o parser.gen.cpp parser.y
	flex -o scanner.gen.cpp scanner.l


doc:
	doxygen docs/doxygen.conf

clean:
	rm *.gen.*
	
