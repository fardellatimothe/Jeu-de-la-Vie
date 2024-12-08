all: jeu_de_la_vie

CXX = clang++

override CXXFLAGS += -std=c++17 -IInclude -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -g -Wmost

SRC_DIR = Source
INC_DIR = Include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
MAIN = main.cpp
HEADERS = $(wildcard $(INC_DIR)/*.h)

TARGET = jeu_de_la_vie

all: $(TARGET)

$(TARGET): $(SRCS) $(MAIN) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(MAIN) -o $@

debug: $(SRCS) $(MAIN) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) $(MAIN) -o $(TARGET)-debug

clean:
	rm -f $(TARGET) $(TARGET)-debug
