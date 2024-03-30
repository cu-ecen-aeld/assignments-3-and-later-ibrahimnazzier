# Variable assigned with wildcard to compile all .c files at once
src_files := $(wildcard *.c)
# Checking if cross-compilation is valid
# I used C_CROSS as an alias for aarch64-none-linux-gnu-gcc

ifndef CROSS_COMPILE
    executable := aesdsocket
    COMP := gcc
else
 executable := aesdsocket.nat
    COMP := $(CROSS_COMPILE)
endif
default: $(executable)

$(executable): $(src_files)
	$(COMP) $^ -o $@

.PHONY: clean

clean:
	rm -rf $(executable) $(executable).exe