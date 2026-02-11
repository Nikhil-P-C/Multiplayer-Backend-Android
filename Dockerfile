# Use a lightweight Linux image
FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential cmake git libenet-dev \
    && rm -rf /var/lib/apt/lists/*

# Set working directory inside container
WORKDIR /app

# Copy your server source code
COPY . /app

# Create build directory
RUN mkdir -p build
WORKDIR /app/build

# Build the server
RUN cmake .. && make

# Expose UDP port 7777 for ENet
EXPOSE 7777/udp

# Command to run server
CMD ["./server"]
