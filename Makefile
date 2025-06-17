CXX = g++
CXXFLAGS = -std=c++17 -Wall -fPIC
INCLUDES = `pkg-config --cflags Qt5Widgets`
LIBS = `pkg-config --libs Qt5Widgets` -lpcap
MOC = moc

# Archivos fuente y objeto
SRC = src/main.cpp src/gui.cpp src/sniffer.cpp
OBJ = $(SRC:.cpp=.o)

# Para Qt: generar moc_gui.cpp a partir de gui.hpp
MOC_SRC = include/gui.hpp
MOC_OUT = src/moc_gui.cpp
MOC_OBJ = src/moc_gui.o

TARGET = sniffer_app

# Regla principal
all: $(TARGET)

# Enlace final del ejecutable
$(TARGET): $(OBJ) $(MOC_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compilar archivos .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regla para generar el archivo moc_gui.cpp desde gui.hpp
$(MOC_OUT): $(MOC_SRC)
	$(MOC) $< -o $@

# Compilar el archivo moc_gui.cpp
$(MOC_OBJ): $(MOC_OUT)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f src/*.o src/moc_gui.cpp $(TARGET)
