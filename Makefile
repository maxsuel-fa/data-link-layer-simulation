CC		:= g++
OUT		:= prog
SRCDIR	:= src
OBJDIR	:= obj
MAIN	:= main.cpp

SRCFILES:=${shell find ${SRCDIR} -type f -iname '*.hpp'}
OBJFILESWPATH:=${patsubst ${SRCDIR}/%.cpp,${OBJDIR}/%.o,${SRCFILES}}
OBJFILESWOUTPATH:=${addprefix ${OBJDIR}/,${notdir ${patsubst %.cpp,%.o,${SRCFILES}}}}

run: all
	./${OUT}

all: ${OBJFILESWPATH}
	${CC} -o ${OUT} ${OBJFILESWOUTPATH}  ${MAIN}

clean:
	rm -rf ${OBJDIR}/* && rm ${OUT}

${OBJDIR}/%.o: ${SRCDIR}/%.cpp
	${CC} -c -o ${addprefix ${OBJDIR}/,${notdir $@}}
