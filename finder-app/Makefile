all: writer

writer.o: writer.c
	$(CC) $(CCFLAGS) -c $^

writer: writer.o
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LDFLAGS)
clean :
	rm -f writer writer.o