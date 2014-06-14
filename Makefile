CC=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=-lcrypto
CLIENTSOURCES=main.cpp\
		user.cpp\
		response.cpp\
		request.cpp\
		parse.cpp\
		socket.cpp\

ifeq ($(shell uname), SunOS)
	LDFLAGS += -lsocket -lnsl
endif


SOURCES=$(CLIENTSOURCES)

CLIENTOBJECTS=$(CLIENTSOURCES:.cpp=.o)
	CLIENT=client

all: $(SOURCES) $(CLIENT)
		
$(CLIENT): $(CLIENTOBJECTS) 
		$(CC) $(CLIENTOBJECTS) $(LDFLAGS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

clean :
	rm *.o
	rm client

%.P : %.c
	$(MAKEDEPEND)
	@sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' < $*.d > $@; \
	  rm -f $*.d; [ -s $@ ] || rm -f $@

include $(SRCS:.c=.P)
