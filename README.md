# Overview

A simple multi-threaded HTTP server implementation using C++ and Boost.Asio, with Python-based performance monitoring.

## Project Structure

Project/
├── src/
│   ├── server.cpp
│   └── server.h
├── python/
│   ├── monitor.py
│   └── requirements.txt
├── CMakeLists.txt
└── build/

## Features
- Multi-threaded HTTP server implementation
- Basic HTTP request handling
- Performance monitoring with Python scripts
- CPU usage visualization

## Prerequisites
- CMake (3.10 or higher)
- C++17 compatible compiler
- Boost libraries (1.70 or higher)
- Python 3.x
- Python packages (install via requirements.txt)

## Building the Project
1. Create and enter the build directory:

```
cd Project
mkdir build
cd build
```
2. Generate build files and compile:
```
cmake ..
make
```

## Running the Server
Execute the compiled binary:
./server

The server will start listening on `127.0.0.1:8080.

## Performance Monitoring

To monitor server performance:

1. Install Python dependencies:

```
cd python
pip install -r requirements.txt
```

2. Run the monitoring script:

```
python monitor.py
```

This will generate a CPU usage graph over time.

## Usage
- Open a web browser and go to http://127.0.0.1:8080 to see the server response.
- The Python script will plot CPU usage, giving insights into the server’s performance.
