# Definindo variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iheaders -fprofile-arcs -ftest-coverage
SOURCES = User.cpp Board.cpp Task.cpp TaskManager.cpp DataStorage.cpp Menu.cpp
OBJECTS = $(addprefix build/,$(SOURCES:.cpp=.o))
MAIN_OBJECT = build/main.o
TARGET = taskufmanager

TEST_SOURCES = test/Test.cpp
TEST_OBJECTS = $(addprefix build/,$(TEST_SOURCES:.cpp=.o))
TEST_TARGET = build/runtests

# Criação do diretório para os testes
$(shell mkdir -p build/test)

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS) $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para gerar os objetos
build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST_OBJECTS) $(TEST_TARGET) $(MAIN_OBJECT)

# Regra para executar testes
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Regra para compilar os testes
$(TEST_TARGET): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)
