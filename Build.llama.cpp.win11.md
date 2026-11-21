# Full Guide on Build llama.cpp on Windows 11 with nvidia gpu for Rookie

## Step 1. Choose and Open a designate folder  e.g. D:\llama.cpp
#### Go to D:\llama.cpp, Right click and choose "Open in Terminal" and enter:
```
git clone https://github.com/ggml-org/llama.cpp 
```
---
## Step 2. Prepare CUDA TOOlKits:
#### Stay in Terminal, enter⬇️to check your lastest CUDA version, e.g. 13.3,
```
nvidia-smi
```
Search and find your cuda toolkit like ⬇️ on nvidia offical website,
```
cuda_13.3.0_windows.exe
```
and download into :
```
llama.cpp/cuda;
```

#### run it in Custom install, and ONLY Check 3 nessessary Components marks including :
```
Development / Runtime / Visual Studio Integration
```
#### choose to install at :
```
D:\llama.cpp\cuda\cu133
```
#### then add its bin to Path in user Environment:
```
D:\llama.cpp\cuda\cu133\bin
```
---

## Step 3. Download Visual Studio Build Tools 2022:
#### Create a Folder in llama.cpp: , e.g. ⬇️ and RUN curl command:
```
D:\llama.cpp\vs22buildtools
curl -L -o vs_buildtools.exe "https://aka.ms/vs/17/release/vs_buildtools.exe"
```
#### Choose 'C++ development for pc' at Workload section, install at:
```
D:\llama.cpp\vs22buildtools\VS2022BuildTools
```
---
## Step 4. copy all files  (if they were not there):
from 
```
C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v13.3\extras\visual_studio_integration\MSBuildExtensions
```
to 
```
D:\llama.cpp\vs22buildtools\VS2022BuildTools\MSBuild\Microsoft\VC\v170\BuildCustomizations
```
---
## Step 5. open x86 Native Tools Command Prompt for VS 2022
```
D:
cd D:\llama.cpp\llama.cpp
```
#### Build llama.cpp:
```
cmake -B build -DGGML_CUDA=ON
```

#### and be patient with the later one which takes more time
```
cmake --build build --config Release -j
```
#### If the following ⬇️  are observed with no error report, then it means Rookie has successfully build the llama.cpp on windows system 🎉
> llama-cli.exe
> llama.exe
🎉🎉🎉

> [!TIP]
> if errors, use it to clear build cache before another rebuild:
```
rmdir /s /q build
```
---
