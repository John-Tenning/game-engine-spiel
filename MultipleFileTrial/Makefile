# Name of the project
PROJECT_NAME = Calculator
 
# Output directory
BUILD = build
 
# All source code files
SRC = ElectricityBill.c\
MainElectricityBill.c
 
# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).exe
 
# Default target built
$(PROJECT_NAME):all
 
# Run the target even if the matching name exists
.PHONY: run clean test doc all
 
all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).exe
 
# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).exe
 
# Document the code using Doxygen
#doc:
#   make -C ./documentation
 
# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
#Coverage
coverageCheck:$(BUILD)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
 
# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)
 
# Create new build folder if not present
$(BUILD):
	mkdir build