# Build llama.cpp on Windows 11 with an NVIDIA GPU: A Complete Beginner's Guide

This guide walks a complete beginner through building [llama.cpp](https://github.com/ggml-org/llama.cpp) from source on Windows 11 using an NVIDIA GPU (CUDA). All downloads are kept inside a single working folder to keep everything tidy.

## Step 1: Create a Working Folder and Clone the Repository

1. Create a dedicated folder, for example `D:\llama.cpp\`.
2. In that folder, right-click and choose **"Open in Terminal"**.
3. Clone the llama.cpp source:

```bash
git clone https://github.com/ggml-org/llama.cpp
```

## Step 2: Prepare the CUDA Toolkit

1. Still in the terminal, check the latest supported CUDA version (e.g., 13.3):

```bash
nvidia-smi
```

2. On the [NVIDIA official website](https://developer.nvidia.com/cuda-toolkit-download), search for the matching CUDA toolkit installer, for example:

```text
cuda_13.3.0_windows.exe
```

3. Download it into the working folder, for example `D:\llama.cpp\cuda\`.
4. Run the installer in **Custom** install mode and check **only** the three necessary components:
   - **Development**
   - **Runtime**
   - **Visual Studio Integration**
5. Choose the installation path:

```text
D:\llama.cpp\cuda\cu133
```

6. Add its bin directory to your **user** `PATH` environment variable:

```text
D:\llama.cpp\cuda\cu133\bin
```

## Step 3: Download the Visual Studio 2022 Build Tools

1. Create a folder inside the working folder, for example `D:\llama.cpp\vs22buildtools\`.
2. From that folder in the terminal, download the installer with curl:

```bash
curl -L -o vs_buildtools.exe "https://aka.ms/vs/17/release/vs_buildtools.exe"
```

3. Run the installer and select the **"Desktop development with C++"** workload.
4. Choose the installation path:

```text
D:\llama.cpp\vs22buildtools\VS2022BuildTools
```

## Step 4: Copy the CUDA MSBuild Extensions

Copy all files from:

```text
C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v13.3\extras\visual_studio_integration\MSBuildExtensions
```

to:

```text
D:\llama.cpp\vs22buildtools\VS2022BuildTools\MSBuild\Microsoft\VC\v170\BuildCustomizations
```

## Step 5: Build llama.cpp

1. Open the **x64 Native Tools Command Prompt for VS 2022**.
2. Change to the llama.cpp directory:

```bat
cd /d D:\llama.cpp\llama.cpp
```

3. Configure the build with CUDA enabled:

```bat
cmake -B build -DGGML_CUDA=ON
```

4. Build the project (this command takes longer, so be patient):

```bat
cmake --build build --config Release -j
```

5. If the following executables are produced with no error reported, the build succeeded 🎉:
   - `llama-cli.exe`
   - `llama.exe`

🎉🎉🎉

> [!TIP]
> If a build fails, clear the build cache before rebuilding:
>
> ```bat
> rmdir /s /q build
> ```
