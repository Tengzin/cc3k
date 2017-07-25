CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD -g
EXEC = cc3k
OBJECTS = main.o interactable.o potion.o decoratePC.o boostatk.o boostdef.o woundatk.o wounddef.o player.o character.o shade.o drow.o vampire.o troll.o goblin.o enemy.o dragon.o human.o dwarf.o elf.o orc.o merchant.o halfling.o mapdisplay.o maplayout.o subject.o tile.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
