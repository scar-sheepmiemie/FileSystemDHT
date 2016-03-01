THRIFT_DIR=/usr/local/include/thrift
LIB_DIR=/usr/local/lib

GEN_SRC=./*.cpp

default: Node

Node:
	g++ -g -DHAVE_NETINET_IN_H -I${THRIFT_DIR} -L${LIB_DIR} ${GEN_SRC} -o Node -lthriftnb -levent -lthrift -lrt

clean:
	$(RM) *.o Node
