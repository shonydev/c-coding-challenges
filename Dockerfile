FROM gcc:latest

# Instalar cmake y mingw-w64 para compilación cruzada
RUN apt-get update && apt-get install -y \
    cmake \
    build-essential \
    mingw-w64 \
    && rm -rf /var/lib/apt/lists/*

# Establecer el directorio de trabajo dentro del contenedor.
WORKDIR /app