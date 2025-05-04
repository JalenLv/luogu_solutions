BUILD_DIR:=build
TARGET:=my_app
CMAKE_OPTS:=-DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
# CMAKE_GENERATOR:=-G Ninja

.PHONY: all configure build run clean

all: build

configure: $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	cmake -B $(BUILD_DIR) -S . $(CMAKE_OPTS) $(CMAKE_GENERATOR)

build: configure
	cmake --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/src/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf .cache

