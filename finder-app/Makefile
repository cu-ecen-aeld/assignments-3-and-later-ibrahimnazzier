#variable assigned with wild card to compile all .c files at onec.
src_files = *.c
#checking if Cross compilation is valid
#I used C_CROSS as an alias for aarch64-none-linux-gnu-gcc
ifndef CROSS_COMPILE
executable = writer_nat
COMP = gcc
else
executable = writer
COMP = $(CROSS_COMPILE)
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
	rm -rf $(executable)_nat
	rm -rf writer