# Choose basisimage (Ubuntu 20.04)
FROM ubuntu:20.04
# Avoid interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive
# Commands that will be ran on the devcontainer, this lists installs everything neccesary to use autograde.py
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    cmake \
    valgrind \
    build-essential \
    && rm -rf /var/lib/apt/lists/*
# Choose workdirectory
WORKDIR /workspace
# Copy files from project to workspace
COPY . /workspace