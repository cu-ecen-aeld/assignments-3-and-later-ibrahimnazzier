#variable assigned with wild card to compile all .c files at onec.
src_files = *.c
#checking if Cross compilation is valid
#I used C_CROSS as an alias for aarch64-none-linux-gnu-gcc
ifndef CROSS
executable = writer
COMP = gcc
else
executable = writer_cross
COMP = aarch64-none-linux-gnu-gcc
endif

default:$(executable)

$(executable):$(src_files)
	$(COMP) $< -o $@
ifdef CROSS
	@touch ../assignments/assignment2/filetype.txt && file $(executable) 1> ../assignments/assignment2/fileresult.txt
endif
.PHONY: clean
clean:
	rm -rf $(executable)
