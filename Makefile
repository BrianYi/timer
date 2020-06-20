INC_DIR=./include
BIN_DIR=./bin
SRC_DIR=./src
OBJ_DIR=./obj
LIB_DIR=./lib
ALL_DIR=${INC_DIR} ${BIN_DIR} ${OBJ_DIR} ${LIB_DIR}

LIB_DIR=./lib

$(shell mkdir ${ALL_DIR})

SRC_FILES=${wildcard ${SRC_DIR}/*.cpp}
INC_FILES=${wildcard ${INC_DIR}/*.cpp}

OBJ=${patsubst %.cpp,${OBJ_DIR}/%.o, ${notdir ${SRC_FILES}}} \
	${patsubst %.cpp,${OBJ_DIR}/%.o, ${notdir ${INC_FILES}}}

TARGET=main 
BIN_TARGET=${BIN_DIR}/${TARGET}

CC=g++
CFLAGS=-g -Wall -L${LIB_DIR} -I${INC_DIR} 

${BIN_TARGET}: ${OBJ}
	${CC} ${OBJ} -o $@ -lpthread

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	${CC} ${CFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${INC_DIR}/%.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${BIN_TARGET} ${OBJ_DIR}/*.o
