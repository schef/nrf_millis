CXX = g++

PROJ_DIR := .
LIB_DIR := ..

CXXFLAGS += -g -Wall
CXXFLAGS += -std=c++11
CXXFLAGS += -m32
CXXFLAGS += -DTESTS

SRC_FILES += \
  $(LIB_DIR)/nrf_millis.cpp \
  $(PROJ_DIR)/tests-nrf_millis.cpp \

INC_FOLDERS += \
  $(PROJ_DIR)/ \
  $(LIB_DIR)/ \

INC_PARAMS=$(foreach d, $(INC_FOLDERS), -I$d)

default:
	$(CXX) $(CXXFLAGS) tests-main.o $(SRC_FILES) $(INC_PARAMS) -o tests
	./tests -r compact

main:
	$(CXX) $(CXXFLAGS) tests-main.cpp -c
