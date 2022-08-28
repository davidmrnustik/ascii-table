# ASCII Table

Build and export:

```
mkdir build
cd build
emcc -lembind ../main.cpp ../ascii_table.cpp -o ascii_table -Os -s MODULARIZE=1
```
