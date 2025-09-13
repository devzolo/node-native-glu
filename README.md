# @devzolo/node-native-glu

Native OpenGL Utility Library (GLU) bindings for Node.js (with TypeScript typings).

[![npm](https://img.shields.io/npm/v/%40devzolo%2Fnode-native-glu)](https://www.npmjs.com/package/@devzolo/node-native-glu)
[![node](https://img.shields.io/node/v/%40devzolo%2Fnode-native-glu)](https://www.npmjs.com/package/@devzolo/node-native-glu)
[![license](https://img.shields.io/github/license/devzolo/node-native-glu)](./LICENSE)
[![os](https://img.shields.io/badge/OS-Windows%2010%2B%20%7C%20Linux%20%7C%20macOS-blue)](https://github.com/devzolo/node-native-glu)

This package exposes GLU (OpenGL Utility Library) functions directly to Node.js via N-API, with full IntelliSense using `src/types/index.d.ts`. It provides utility functions for OpenGL applications including matrix operations, quadric objects, tessellation, and NURBS.

Note: this package requires an existing OpenGL context. Use libraries like GLFW, SDL, or GLUT to create and make a context current before using the GLU API.

## Installation

Prerequisites:

- Node.js 16+ (LTS recommended)
- pnpm, npm, or yarn

If you use GitHub Packages, add to your `.npmrc`:

```env
@devzolo:registry=https://npm.pkg.github.com
//npm.pkg.github.com/:_authToken=${GITHUB_TOKEN}
```

Install:

```bash
# pnpm
pnpm add @devzolo/node-native-glu

# npm
npm install @devzolo/node-native-glu

# yarn
yarn add @devzolo/node-native-glu
```

The package attempts to download prebuilt binaries. If a binary is not available for your platform, it will build from source (requires a C++ toolchain).

## Quick start

TypeScript / ESM:

```ts
import GLU from '@devzolo/node-native-glu';

// Set up perspective projection
GLU.perspective(45.0, 1.0, 1.0, 100.0);

// Set up orthographic projection
GLU.ortho2D(-1.0, 1.0, -1.0, 1.0);

// Set up viewing transformation
GLU.lookAt(0.0, 0.0, 5.0,  // eye position
           0.0, 0.0, 0.0,  // center position
           0.0, 1.0, 0.0); // up vector
```

JavaScript (CommonJS):

```js
const GLU = require('@devzolo/node-native-glu').default;

GLU.perspective(45.0, 1.0, 1.0, 100.0);
GLU.ortho2D(-1.0, 1.0, -1.0, 1.0);
```

## API

- Constants and functions mirror the GLU API, exposed under the `GLU` namespace with TypeScript types.
- Type reference: see `src/types/index.d.ts` in this repository.
- Examples of available symbols:
  - Constants: `GLU.VERSION_1_1`, `GLU.VERSION_1_2`, `GLU.SMOOTH`, `GLU.FLAT`, `GLU.FILL`.
  - Functions: `GLU.perspective()`, `GLU.ortho2D()`, `GLU.lookAt()`, `GLU.build2DMipmaps()`, and many more.

Typing: the default export is a `GLU` object containing all typed members (TypeScript).

## Platforms and binaries

- **Supported platforms**: Windows (x64/x86), Linux (x64), macOS (x64/ARM64)
- **GLU implementation**: System GLU library
- Prebuilt binaries are downloaded automatically when available.
- Fallback: local build with `node-pre-gyp`/`node-gyp` (requires a C++ toolchain). See next section.

### Platform-specific requirements

#### Windows
- **OpenGL libraries**: `glu32.lib` (system)
- **Build tools**: Visual Studio Build Tools 2019/2022 with C++ (MSVC)
- **Python**: 3.x in PATH

#### Linux
- **OpenGL libraries**: `libGL.so`, `libGLU.so` (system packages)
- **Installation** (Ubuntu/Debian):
  ```bash
  sudo apt update
  sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev
  ```
- **Installation** (CentOS/RHEL/Fedora):
  ```bash
  sudo yum install -y mesa-libGL-devel mesa-libGLU-devel
  # or for newer versions:
  sudo dnf install -y mesa-libGL-devel mesa-libGLU-devel
  ```
- **Build tools**: `gcc`, `g++`, `make`, `python3`

#### macOS
- **OpenGL libraries**: `OpenGL.framework` (system)
- **Build tools**: Xcode Command Line Tools
- **Installation**:
  ```bash
  xcode-select --install
  ```

## Build from source

### Prerequisites by platform

#### Windows
- Visual Studio Build Tools 2019/2022 with C++ (MSVC)
- Python 3.x in PATH
- Compatible `node-gyp` (pulled by the ecosystem as needed)

#### Linux
- GCC/G++ compiler
- Make
- Python 3.x
- OpenGL development libraries (see installation commands above)

#### macOS
- Xcode Command Line Tools
- Python 3.x

### Build steps

```bash
# Install dependencies
pnpm install
# or
npm install

# Build the native module
pnpm build
# or
npm run build
```

Other useful scripts:

```bash
pnpm test        # run tests
pnpm dist        # compile TypeScript to ./dist
pnpm package     # build addon + tests + package
pnpm check-deps  # check system dependencies (Linux)
```

## Troubleshooting

### Common issues

- **Missing context**: GLU call failures usually indicate there is no current OpenGL context. Create/make one current before using the API.
- **Missing build tools**: if binary download fails, a local build requires platform-specific tools. Install the required tools and retry.
- **Unsupported Node**: for N-API errors, upgrade to Node 16+ or a recent LTS.

### Platform-specific issues

#### Windows
- **Missing build tools**: Install Visual Studio Build Tools 2019/2022 with C++ (MSVC)
- **Python 3.12: 'distutils' missing**: If you hit `ModuleNotFoundError: No module named 'distutils'` with Python 3.12, run:
  ```powershell
  py -3 -m ensurepip --upgrade
  py -3 -m pip install --upgrade pip
  py -3 -m pip install "setuptools<70" packaging wheel
  pnpm build
  ```

#### Linux
- **Missing OpenGL libraries**: Install the required development packages:
  ```bash
  # Ubuntu/Debian
  sudo apt update
  sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev

  # CentOS/RHEL/Fedora
  sudo yum install -y mesa-libGL-devel mesa-libGLU-devel
  # or for newer versions:
  sudo dnf install -y mesa-libGL-devel mesa-libGLU-devel
  ```
- **Missing build tools**: Install GCC, Make, and Python:
  ```bash
  # Ubuntu/Debian
  sudo apt install -y build-essential python3-dev

  # CentOS/RHEL/Fedora
  sudo yum groupinstall -y "Development Tools"
  sudo yum install -y python3-devel
  ```

#### macOS
- **Missing Xcode tools**: Install Xcode Command Line Tools:
  ```bash
  xcode-select --install
  ```
- **Python issues**: Ensure Python 3.x is available and in PATH

## Technical details

### Cross-platform compatibility

This package is designed to work across Windows, Linux, and macOS with the following considerations:

#### Windows
- Uses `glu32.lib` (system GLU library)
- Requires Windows 10+ for optimal OpenGL support
- Supports both x64 and x86 architectures
- Uses Windows-specific headers conditionally (`windows.h`, `tchar.h`)

#### Linux
- Uses system OpenGL and GLU libraries
- Compatible with Mesa drivers (software and hardware acceleration)
- Supports major distributions (Ubuntu, Debian, CentOS, RHEL, Fedora)
- Uses Linux-specific headers (`unistd.h`, `dlfcn.h`)

#### macOS
- Uses `OpenGL.framework`
- Compatible with both Intel and Apple Silicon (ARM64)
- Requires macOS 10.14+ for optimal OpenGL support
- Uses macOS-specific OpenGL headers

### Build system

The package uses `node-gyp` with platform-specific configurations:

- **Windows**: MSVC compiler with Windows SDK
- **Linux**: GCC/G++ with system OpenGL libraries
- **macOS**: Clang with Xcode Command Line Tools

### GLU configuration

- **Cross-platform**: Uses system GLU library for consistent behavior
- **Platform-specific**: Different linking strategies for Windows (static), Linux (dynamic), and macOS (framework)

## Contributing

Contributions are welcome! Please open issues and pull requests. Keep the project style and ensure tests pass.

## License

MIT © devzolo. See `LICENSE`.

## Acknowledgements

- OpenGL Utility Library (GLU) for providing essential OpenGL utility functions.
