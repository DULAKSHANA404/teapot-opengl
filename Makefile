CXX = g++

TARGET = app

SOURCES = main.cpp draw.cpp mainwindow.cpp buffers.cpp vertex.cpp camera.cpp glad/src/glad.c 

INCLUDES = -Iglad/include -Iglm

LIBS = -lglfw -lGL -ldl -lassimp


$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(INCLUDES) $(LIBS) -o $(TARGET)


run: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(TARGET)