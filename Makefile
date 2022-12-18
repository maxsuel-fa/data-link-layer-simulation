CC		:= g++
OUT		:= prog
SRCDIR	:= src
INC     := include
OBJDIR	:= obj
FLAGS	:= -std=c++17
MAIN	:= main.cpp

SRCFILES:=${shell find ${SRCDIR} -type f -iname '*.cpp'}
DEPS:=${shell find ${INC} -type f -iname '*.hpp'}
OBJFILESWPATH:=${patsubst ${SRCDIR}/%.cpp,${OBJDIR}/%.o,${SRCFILES}}
OBJFILESWOUTPATH:=${addprefix ${OBJDIR}/,${notdir ${patsubst %.cpp,%.o,${SRCFILES}}}}

run: all
	./${OUT}

all: ${OBJFILESWPATH}
	${CC} -o ${OUT} ${OBJFILESWOUTPATH} ${FLAGS} ${MAIN}

clean:
	rm -rf ${OBJDIR}/* && rm ${OUT}

${OBJDIR}/%.o: ${SRCDIR}/%.cpp $(DEPS)
	${CC} -c -o ${addprefix ${OBJDIR}/,${notdir $@}} $<
