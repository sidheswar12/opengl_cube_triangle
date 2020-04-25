NVXX :=nvcc
CXX :=g++
SRCS :=src/main.cc
OBJ :=build
FLAG :=-lglut -lGLU -lGL
CVFLAG :=`pkg-config --cflags --libs opencv`

cuda:
	rm -rf $(OBJ)
	mkdir build
	$(NVXX) $(SRCS) $(FLAG) $(CVFLAG) -o $(OBJ)/project

gpp:
	rm -rf $(OBJ)
	mkdir build
	$(CXX) $(SRCS) $(FLAG) $(CVFLAG) -o $(OBJ)/project