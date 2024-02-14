MAKEFLAGS += --no-print-directory
PROGRAM_NAME = SmartCalc

COV_DIR = coverage_info/
COV_INFO = coverage_info/coverage.info
COV_REPORT = coverage_info/coverage.html

CALC_CORE = src/Services/CalculatorCore
CALC_CORE_LIB = build/Services/CalculatorCore/libCalculatorCore.a

INSTALLATION_PATH = $(HOME)/Desktop


all: build

build:
	cmake -S ./src -B build
	cmake --build ./build
	@echo "Successfully built."

rebuild: clean build
	./build/SmartCalc

clean:
	@rm -rf build
	@rm -rf test
	@rm -rf *.a
	@rm -rf *.gc*
	@rm -rf calc.tar.gz
	@echo "Successfully cleaned!"

install: build
	@mkdir $(INSTALLATION_PATH)/${PROGRAM_NAME}
	@mkdir $(INSTALLATION_PATH)/${PROGRAM_NAME}/build
	@cp -rf build/ ${INSTALLATION_PATH}/${PROGRAM_NAME}/build
	@cp -rf resources/ ${INSTALLATION_PATH}/${PROGRAM_NAME}/resources
	@echo "${PROGRAM_NAME} installed to '${INSTALLATION_PATH}/'"

uninstall: clean
	@rm -rf ${INSTALLATION_PATH}/${PROGRAM_NAME}
	@echo "${PROGRAM_NAME} deleted"

dvi:
	open src/DVI.html

dist:
	@open src/DVI.html
	@rm -rf calc.tar.gz
	@git archive --format=tar.gz -o calc.tar.gz --prefix=my-repo/ develop

test: build
	@cp build/Services/CalculatorCore/libCalculatorCore.a ./
	@cp build/Services/CalculatorCore/InternalCore/libInternalCore.a ./
	@gcc src/Tests/test.c -I build/Services/CalculatorCore/ -I build/Services/CalculatorCore/InternalCore libCalculatorCore.a libInternalCore.a -lcheck -o test
	@rm -rf *.a
	@./test
	@echo "Successfully tested!"

rebuild_test: 
	@rm -rf test
	@make test

gcov_report: test
	@-./test
	@lcov -q -c -d $(COV_DIR) -o $(COV_INFO) --exclude "$(TEST_DIR)*"
	@genhtml -q $(COV_INFO) -o $(COV_DIR)
	@open $(COV_REPORT)
	@rm -rf *.gc*

style-check:
	@clang-format -n src/*.c*
	@clang-format -n src/Services/*.c*
	@clang-format -n src/Services/*.h
	@clang-format -n src/Services/CalculatorCore/*.c*
	@clang-format -n src/Services/CalculatorCore/*.h
	@clang-format -n src/Services/CalculatorCore/InternalCore/*.c*
	@clang-format -n src/Services/CalculatorCore/InternalCore/*.h
	@clang-format -n src/Models/*.c*
	@clang-format -n src/Models/*.h
	@clang-format -n src/Controllers/*.c*
	@clang-format -n src/Controllers/*.h
	@echo "Successfully checked!"

style-fix:
	@clang-format -i src/*.c*
	@clang-format -i src/Services/*.c*
	@clang-format -i src/Services/*.h
	@clang-format -i src/Services/CalculatorCore/*.c*
	@clang-format -i src/Services/CalculatorCore/*.h
	@clang-format -i src/Services/CalculatorCore/InternalCore/*.c*
	@clang-format -i src/Services/CalculatorCore/InternalCore/*.h
	@clang-format -i src/Models/*.c*
	@clang-format -i src/Models/*.h
	@clang-format -i src/Controllers/*.c*
	@clang-format -i src/Controllers/*.h
	@echo "Successfully fixed style!"


