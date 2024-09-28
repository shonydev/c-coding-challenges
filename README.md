# C Coding Challenges

## **Welcome to the C Challenges repository!**

This project contains solutions to various coding challenges proposed by [MoureDev](https://github.com/mouredev) using the C programming language. Each challenge is implemented as a standalone program, demonstrating different algorithms, data structures, and problem-solving techniques.

## Project Structure

- **Challenges Directory:** Each challenge is organized in its own directory containing:
  - A `main.c` file with the solution.
  - A `README.md` with a brief description of the challenge and the solution approach.
  - Additional files or folders as needed for each challenge.

## How to Run

To compile and run a specific challenge, navigate to the corresponding directory and use the following commands:
```bash
gcc -o build/main ./src/main.c && ./build/main
```

## Docker

You can build image from Dockerfile use the folowing command:

### Build:

```bash
docker build -t main .
```
That way you will have a development environment for c inside your container without having to configure anything on the main system.

### Run:
```bash
docker run -v "C:\Users\jonat\Documents\proyects\C:\app" -it main
```
### How to develop

You can then use devcontainers to program inside the container.

[![Author](https://img.shields.io/badge/Author-%40shonydev-green)](https://github.com/shonydev)
