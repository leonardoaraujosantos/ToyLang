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
	
# Build our toyCompiler ($@ means the target, and $^ means the dependencies)
toyLang: parser.gen.cpp scanner.gen.cpp main.cpp CodeGenContext.cpp Ast/NVariableDeclaration.cpp Ast/NMethodCall.cpp Ast/NInteger.cpp Ast/NIdentifier.cpp Ast/NFunctionDeclaration.cpp Ast/NExpressionStatement.cpp Ast/NDouble.cpp Ast/NBlock.cpp Ast/NBinaryOperator.cpp Ast/NAssignment.cpp
	g++ -o $@ $^ $(CPPFLAGS) $(LDFLAGS) $(LIBS)

doc:
	doxygen docs/doxygen.conf

# Clean deleted files
clean:
	rm *.gen.*
	rm toyLang
	
