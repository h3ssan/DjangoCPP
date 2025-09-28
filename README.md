# 🚀 DjangoCPP

A Django-inspired C++ web framework for educational purposes

[![C++](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)](#building)

## 📖 Overview

DjangoCPP is a lightweight, educational web framework written in modern C++23 that brings Django-like concepts to C++ development. It's designed to help developers understand web framework architecture while exploring the power of modern C++ features.

### ✨ Features

- 🎯 **Django-inspired Architecture**: Familiar patterns for web developers
- 🛣️ **URL Routing**: Clean and simple route definitions
- 🔧 **Middleware System**: Extensible request/response processing pipeline
- 🏗️ **Modern C++23**: Leverages latest C++ standards and features
- 🚀 **High Performance**: Compiled C++ performance for web applications
- 📦 **Single Binary**: No external dependencies at runtime
- 🧪 **Educational Focus**: Clean, readable code for learning purposes

## 🚀 Quick Start

### Prerequisites

- C++23 compatible compiler (GCC 12+ or Clang 15+)
- cmake 3.10+
- make
- httplib.h (included in the project)

### Building

#### Static Linking (default)

```bash
# Clone the repository
git clone https://github.com/h3ssan/DjangoCPP.git
cd DjangoCPP

# Create a build directory
mkdir build && cd build

cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF ..

# Build the project
make -j$(nproc)

# Install the library and headers
sudo make install
```

#### Dynamic Linking

```bash
# Clone the repository
git clone https://github.com/h3ssan/DjangoCPP.git
cd DjangoCPP

# Create a build directory
mkdir build && cd build

# Configure the project
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..

# Build the project
make -j$(nproc)

# Install the library and headers
sudo make install
```

### Example Application

```cpp
#include "djangocpp/http.h"

int main() {
    run_server();

    return EXIT_SUCCESS;
}
```

```cmake
cmake_minimum_required(VERSION 3.10)

project(myapp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -s")

add_executable(myapp main.cc)

target_link_libraries(myapp PRIVATE djangocpp)
```

### Testing

```bash
# Test the default route
curl http://127.0.0.1:8000/

# Test the whoami endpoint
curl http://127.0.0.1:8000/whoami
```

## 🏗️ Architecture

### Core Components

```
┌─────────────────┐    ┌──────────────┐    ┌─────────────┐
│   HTTP Server   │ -> │ Application  │ -> │   Router    │
│   (httplib)     │    │              │    │             │
└─────────────────┘    └──────────────┘    └─────────────┘
                              │                     │
                              v                     │
                       ┌─────────────┐              │
                       │ Middleware  │              │
                       │  Pipeline   │              │
                       └─────────────┘              │
                                                    v
                                            ┌─────────────┐
                                            │   Handler   │
                                            │ (Lambda)    │
                                            └─────────────┘
```

### Request Flow

1. **HTTP Request** arrives at the httplib server
2. **Request Conversion** transforms httplib request to internal format
3. **Application** processes the request through:
   - **Middleware Pipeline** for cross-cutting concerns
   - **Router** for URL matching and handler dispatch
4. **Handler** generates the response
5. **Response Conversion** transforms internal response to httplib format

## 📝 Usage Examples

### Defining Routes

Routes are defined in `routes.hpp`:

```cpp
std::map<std::pair<std::string, std::string>, Handler> routes = {
    {{"GET", "/"}, [](std::shared_ptr<Request> req) {
        return std::make_shared<Response>(Response{
            .status = 200,
            .headers = {{"Content-Type", "text/plain"}},
            .body = "Hello, World!"
        });
    }},
    
    {{"POST", "/users"}, [](std::shared_ptr<Request> req) {
        // Handle user creation
        return std::make_shared<Response>(Response{
            .status = 201,
            .headers = {{"Content-Type", "application/json"}},
            .body = R"({"message": "User created"})"
        });
    }}
};
```

### Creating Middleware

Extend the `Middleware` class in `middleware.hpp`:

```cpp
class AuthMiddleware : public Middleware {
public:
    std::shared_ptr<Response> process_request(std::shared_ptr<Request> req) override {
        // Check for authentication token
        if (req->headers.find("Authorization") == req->headers.end()) {
            return std::make_shared<Response>(Response{
                .status = 401,
                .headers = {{"Content-Type", "text/plain"}},
                .body = "Unauthorized"
            });
        }
        return nullptr; // Continue processing
    }
};

// Register middleware
const std::vector<std::shared_ptr<Middleware>> middlewares = {
    std::make_shared<LoggingMiddleware>(),
    std::make_shared<AuthMiddleware>(),
};
```

### Configuration

Server settings are configured in `settings.h`:

```cpp
namespace Settings {
    namespace Server {
        const string HOST = "127.0.0.1";
        const int PORT = 8000;
    }
}
```

## 📁 Project Structure

```
DjangoCPP/
├── 📄 main.cc              # Application entry point
├── 🌐 http.h/http.cc       # HTTP server and request handling
├── 🏗️ app.h/app.cc         # Application core with middleware support
├── 🛣️ router.h/router.cc   # URL routing system
├── 📝 routes.hpp           # Route definitions
├── 🔧 middleware.hpp       # Middleware system and implementations
├── ⚙️ settings.h           # Configuration settings
├── 📚 httplib.h            # HTTP library (header-only)
├── 🔨 Makefile             # Build configuration
└── 📖 README.md            # This file
```

## 🎯 Educational Goals

This project demonstrates:

- **Web Framework Architecture**: Understanding how web frameworks work internally
- **Modern C++ Features**: C++23 syntax, smart pointers, lambdas, and more
- **Design Patterns**: Middleware pattern, factory pattern, and functional composition
- **HTTP Protocol**: Low-level HTTP request/response handling
- **Memory Management**: Safe memory handling with smart pointers
- **Modular Design**: Clean separation of concerns

## 🔧 Development

### Adding New Features

1. **New Route**: Add to `routes.hpp`
2. **New Middleware**: Extend `Middleware` class in `middleware.hpp`
3. **Configuration**: Modify `settings.h`
4. **Build**: Run `make` to rebuild

### Code Style

- Modern C++23 features preferred
- Smart pointers for memory safety
- Functional programming patterns where appropriate
- Clear, educational code structure

## 🤝 Contributing

This is an educational project! Contributions are welcome:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request

## 📚 Learning Resources

- [C++23 Features](https://en.cppreference.com/w/cpp/23)
- [Django Documentation](https://docs.djangoproject.com/) (for architectural inspiration)
- [HTTP/1.1 Specification](https://tools.ietf.org/html/rfc2616)
- [Modern C++ Best Practices](https://isocpp.github.io/CppCoreGuidelines/)

## 🐛 Known Limitations

- Basic routing (no URL parameters yet)
- Simple middleware system
- No database integration
- No template engine
- Educational focus over production readiness

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- [httplib](https://github.com/yhirose/cpp-httplib) for the HTTP server implementation
- Django framework for architectural inspiration
- The C++ community for continuous language improvements

---

**Note**: This is an educational project designed for learning web framework concepts with modern C++. It's not intended for production use.

---

<div align="center">
  Made with ❤️ for learning C++ and web development
</div>
