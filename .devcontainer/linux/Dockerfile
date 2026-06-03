FROM ubuntu:24.04 AS main-ci

ARG USERNAME=main-dev
ARG USER_UID=1000
ARG USER_GID=$USER_UID

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    gcc \
    git \
    gpg \
    make \
    build-essential \
    cmake \
    cppcheck \
    clang \
    clang-format \
    clang-tools \
    libclang-rt-dev \
    llvm \
    net-tools \
    sudo \
    jq \
    yamllint \
    python3-autopep8 \
    markdownlint \
    && apt-get clean -y\
    && update-alternatives --install /usr/bin/python python /usr/bin/python3 50


FROM main-ci AS main-dev

# Accomodate the user for devcontainer
RUN (userdel -r $USERNAME ; userdel -r `id -nu $USER_UID` ; groupdel `id -ng $USER_GID`) || true \
    && groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME -s /bin/bash \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

WORKDIR /home/$USERNAME
