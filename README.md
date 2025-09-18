# [Child Debugging](https://github.com/albertziegenhagel/childdebugger-vscode) Minimum Repro

While working with [this excellent plugin](https://marketplace.visualstudio.com/items?itemName=albertziegenhagel.childdebugger), I discovered that natvis files are not carried over to the newly-debugged child process. Minimum steps to reproduce:

1. Clone this repo (recurse submodules)
2. `mkdir build && cd build` at the repo root
3. `cmake ..`
4. `cmake --build .`
5. Open the repo folder in VS Code
6. Ensure [Child Debugger](https://marketplace.visualstudio.com/items?itemName=albertziegenhagel.childdebugger) is enabled
7. Open [`child/main.cpp`](child/main.cpp) and add a breakpoint at line 9
8. Launch `child` in the "Run and Debug" panel
9. When the program breaks, ensure the natvis file has been properly loaded
    - To verify, expand `doc` in "Variables/Locals" in the debugger panel
    - If the natvis file is loaded correctly, it will show something like:
    ```
    [size] = 1
    [capacity] = 1
    [0] = {name="key" value=3 }
    ```
    - If the natvis file is not loaded, it will show the raw struct fields like:
    ```
    rapidjson::GenericValue<...> = ...
    allocator_ = 0x... {...}
    ownAllocator_ = 0x... {...}
    stack_ = {allocator=0x... {...} ...}
    parseResult_ = {code_=kParseErrorNone (0) offset_=0 }
    ```
10. Stop the process
11. Launch the `parent` configuration
12. When the program breaks in `child/main.cpp`, verify the natvis file is not being used
