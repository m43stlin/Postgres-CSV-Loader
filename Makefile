# Makefile to build Postgres-CSV-Loader

CFLAGS := -Wall -pedantic-errors

# Rules
parseTest: main.o link_list.o get_col_names.o
	$(CC) $(CFLAGS) -o parseTest main.o link_list.o get_col_names.o