FROM ubuntu:24.04 AS main-ci

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    clang \
    gcc \
    git \
    make \
    build-essential \
    cmake \
    sudo \
    && apt-get clean -y

FROM main-ci AS main-dev

ARG USERNAME=main-dev
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Remove any existing user/group with the target UID/GID and create new user for devcontainer
RUN (getent passwd $USER_UID && userdel -r $(getent passwd $USER_UID | cut -d: -f1)) || true \
    && (getent group $USER_GID && groupdel $(getent group $USER_GID | cut -d: -f1)) || true \
    && groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME -s /bin/bash \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

WORKDIR /home/$USERNAME
