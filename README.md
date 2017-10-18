# C# vs. C++ Compile Time Benchmarks

## Test Environment

* 2.3 Ghz Intel Core i7-3615QM
* Mac OS X 10.12.5
* Unity 2017.2.0f3
* Ninja 1.8.2
* Apple LLVM version 8.1.0 (clang-802.0.42)
* CMake 3.9.1

## Compiled Sources

C++ sources consist of 1000 `.cpp` and `.h` files plus a `Main.cpp` consisting of a stub `main` function. Each `.cpp` file references its corresponding `.h` file with `#include`. Each `.h` file contains a `struct` definition with 100 `int` fields and 100 `void Foo()` methods. Each `.cpp` file contains the 100 method definitions for the corresponding `.h` file's `struct`.

C# sources consist of 1000 `.cs` files. Each contains a `public class` with 100 `public int` fields and 100 `public void Foo()` methods.

Each file starts with a one-line comment containing the timestamp. Each `struct`, `class`, field, and method is prefaced with a one-line comment. Indentation with tabs is present as with "normally"-formatted code.

## Code Generator

A code generator written in C writes all of the source files to their appropriate directories. Running it updates all the files' timestamps so is a good way to force all source files to be recompiled.

To run the code generator, compile with `clang -o Generator Generator.c` then run it with `./Generator`.

## Compiling C# #

C# code is placed in an otherwise empty Unity project's `Assets` directory by the code generator. The project is then opened so all assets can be imported by Unity.

To do a full compile, run the code generator and switch to the Unity editor.

To compile just one file, add an "a" to the end of one `.cs` file's timestamp comment and switch to the Unity editor.

The Unity editor does not report compile times. To measure how long a compilation takes, start a stopwatch when either the "Importing Assets" dialog or the spinner in the bottm-right corner of the window appear. Stop the stopwatch when the spinner disappears.

## Compiling C++

C++ code is placed in the `CppSource` directory by the code generator. A `CMakeLists.txt` file is already present in that directory. Run `cmake -GNinja /path/to/CppSource` to build the Ninja build configuration.

To do a full compile, run the code generator and then run `time ninja` to compile.

To compile just one file, add an "a" to the end of one `.h` file's timestamp comment then run `time ninja` to compile.

## Results

| Language        | Full Compile  | Compile One File |
|-----------------|---------------|------------------|
| C#              | 7 seconds     | 3.5 seconds      |
| C++             | 5.360 seconds | 0.223 seconds    |
| **C++ Speedup** | **1.31x**     | **15.70x**       |

## Conclusion

A full compile of C++ is only marginally faster than C#, but incremental compiles are dramatically faster.
