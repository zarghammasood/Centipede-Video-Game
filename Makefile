CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =		Board.o util.o Position.o GameObject.o MoveableObject.o Mushroom.o ScoreBoard.o Player.o MagicSeg.o LazySeg.o Centipede.o Bomb.o Flea.o Spider.o Scorpions.o Main.o game.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	game


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
