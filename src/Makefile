###############
## Makefile
###############

BIN=../bin/gameEngineCpp
BOOST_INSTALL_ROOT=/Users/ankithbti/Development/Cpp/boost
HTTP_SERVER_BASE=/Users/ankithbti/Development/Cpp/httpServer
GLFW_BASE=/Users/ankithbti/Development/glfw
GLEW_BASE=/Users/ankithbti/Development/glew

ARCH = $(shell uname -m)	# ARCH becomes the output from the uname -m command.
CXX=/usr/bin/g++
CXXFLAGS=-g -O2 -Wall $(INCS)

SRCS =  Window.cpp WindowManager.cpp
MAIN_SRC = Main.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))
MAIN_OBJ = $(patsubst %.cpp, %.o, $(MAIN_SRC))

INCS = -I../include \
       -I$(BOOST_INSTALL_ROOT)/include \
       -I$(HTTP_SERVER_BASE)/include \
       -I${GLFW_BASE}/include \
       -I${GLEW_BASE}/include \

LIBS = \
        -L${BOOST_INSTALL_ROOT}/lib -lboost_thread \
        -L${BOOST_INSTALL_ROOT}/lib -lboost_system \
	-L$(HTTP_SERVER_BASE)/lib -lHttpServer \
	${GLFW_BASE}/lib/libglfw3.a \
	${GLEW_BASE}/lib/libGLEW.a \
	-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
	-lpthread
	
$(BIN): $(OBJS) $(MAIN_OBJ)
	$(CXX) -o $(BIN) $(OBJS) $(MAIN_OBJ) $(LIBS)

all: $(BIN)

run:
	@echo "----------------------------"
	@echo "Running the programme. "
	@echo "----------------------------"
	$(BIN)
	@echo "----------------------------"

clean:
	rm -rf $(BIN) *.o
