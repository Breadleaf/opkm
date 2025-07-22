# Open Package Manager

Open Package Manager is a hackable open source package manager that wraps a
system's underlying package manager. It also supplies an interface to define
custom packages via git repositories.

## Building

A [posix](https://en.wikipedia.org/wiki/POSIX) system is expected.

- A `C` language compiler, ideally `clang` or `gcc`
- `cmake`
- `libcurl`
- `libgit2`

To build run `cmake -B build .` then `cd build && make`

## Dev Dependencies

If you wish to contribute, you will also need these packages available

- `clang-format` (use `make format`)