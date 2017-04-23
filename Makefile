# Macros

MAIN = main/
MAIN_FILE = $(MAIN)main.cpp
SRC = src/
SRC_FILES = $(SRC)*.cpp
OUT = bin/
OUT_FILE = $(OUT)ordenacion


# Reglas explícitas

default:
	g++ -std=c++11 $(MAIN_FILE) $(SRC_FILES) -o $(OUT_FILE)

app:
	$(OUT_FILE)

run: default app
