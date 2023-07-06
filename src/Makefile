# Definindo variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++14
SOURCES = src/User.cpp src/Board.cpp src/Task.cpp src/TaskManager.cpp src/DataStorage.cpp src/Menu.cpp src/main.cpp
OBJECTS = $(patsubst src/%.cpp,build/%.o,$(SOURCES))
TARGET = taskufmanager

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para gerar os objetos
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET)
