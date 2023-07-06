# Definindo variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++14 -Iheaders
SOURCES = User.cpp Board.cpp Task.cpp TaskManager.cpp DataStorage.cpp Menu.cpp main.cpp
OBJECTS = $(addprefix build/,$(SOURCES:.cpp=.o))
TARGET = taskufmanager

TEST_SOURCES = test/BoardTest.cpp test/TaskTest.cpp test/UserTest.cpp
TEST_OBJECTS = $(addprefix build/,$(TEST_SOURCES:.cpp=.o))
TEST_TARGET = build/runtests

# Criação do diretório para os testes
$(shell mkdir -p build/test)

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para gerar os objetos
build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST_OBJECTS) $(TEST_TARGET)

# Regra para executar testes
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Regra para compilar os testos
$(TEST_TARGET): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@