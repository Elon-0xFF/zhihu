你这个报错是因为还在普通 CMD 里跑 cmake，没有激活 MSVC 环境变量。不用改 cmake 指令，改终端就行。
正确做法
方法一：打开正确的终端（推荐）
开始菜单搜索 → x64 Native Tools Command Prompt for VS 2022

D:
cd D:\llama.cpp\llama.cpp
cmake -B build -DGGML_CUDA=ON
cmake --build build --config Release -j


cmake -B build -DGGML_CUDA=ON
cmake --build build --config Release
