FROM ubuntu:20.04 AS dev

ENV DEBIAN_FRONTEND=noninteractive TZ=TZ=Etc/UTC
RUN apt-get update; \
    apt-get install -y \
        build-essential \
        cmake \
        git \
        gdb \
        valgrind \
        uuid-dev \
        libssl-dev \
        automake \
        autoconf \
        autogen \
        libtool \
        pkgconf \
        libssh-dev \
        lcov \
        python3 \
        doxygen \
        graphviz \
        wget \
        vim \
        nano \
        # Installed for dependencies
        curl \
        wget \
        # Only Present for Debugging - can be removed when we have multi container test env
        socat \
        iputils-ping \
        iproute2 \
        rlwrap \
        netcat \
        git-lfs \
        # Welcome message
        figlet; \
    apt-get clean