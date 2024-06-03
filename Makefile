CXX = g++-14
CXXFLAGS = -std=c++11 -I/opt/homebrew/Cellar/opencv/4.9.0_8/include/opencv4
LDFLAGS = -L/opt/homebrew/Cellar/opencv/4.9.0_8/lib
LDLIBS = -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio

SRCS = testing.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = MyProject

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
