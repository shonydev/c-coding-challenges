# Usar una imagen base con herramientas para C, por ejemplo, gcc.
FROM gcc:latest


# Instalar cmake
RUN apt-get update && apt-get install -y \
cmake \
build-essential \
&& rm -rf /var/lib/apt/lists/*

# Establecer el directorio de trabajo dentro del contenedor.
WORKDIR /app