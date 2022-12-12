rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CSRC := $(call rwildcard, src, *.c)

COBJ := $(patsubst src/%.c, out/%.c.o, $(CSRC))

LIBS := 
CFLAGS := 

.PHONY: clean

tool: $(COBJ)
	@gcc $(COBJ) $(LIBS) -lncurses -g -o 68kfs

out/%.c.o: src/%.c
	@gcc $(CFLAGS)  -g -c $^ -o $@
