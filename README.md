
A configuration file is provided to build this project with CMake. This allows to build the project
in the terminal but also provides the option to use Jetbrains CLion or Microsoft Visual Studio and other
IDEs.

Building from Terminal:
Start in the project directory.
```
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
make
```

This creates the binaries test_all, bench and main.


