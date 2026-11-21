open a designate folder  e.g. D:\llama.cpp
```
git clone https://github.com/ggml-org/llama.cpp 
```
open cmd check your avaliable cuda version and download into llama.cpp/cu133, then add its bin to environment;

open→ x64 Native Tools Command Prompt for VS 2022

D:

cd D:\llama.cpp\llama.cpp

cmake -B build -DGGML_CUDA=ON

cmake --build build --config Release -j
