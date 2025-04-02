### Build using g++
```g++ static_memfun.cpp main.cpp -o <Name of exe>```

### Build using CMake and Make
#### Windows
```
cmake -B build -G "MinGW Makefiles"
cd build && mingw32-make
```

#### Linux
```
cmake -B build -G "Unix Makefiles"
make -C build
```

### Run application
```<Path of exe>.exe```