# Usar una imagen base con herramientas para C, por ejemplo, gcc.
FROM gcc:latest

# Establecer el directorio de trabajo dentro del contenedor.
WORKDIR /app

# Copiar el archivo de código fuente al contenedor.
COPY . /app