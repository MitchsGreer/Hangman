# ==============================================================================
# This dockerfile is for a c implementation of hangman.
# ==============================================================================
FROM ubuntu:jammy-20231004

# ------------------------------------------------------------------------------
# Add any ENV variables and arguments.
# ------------------------------------------------------------------------------
ARG USERNAME=uhangman \
    USER_UID=1000 \
    USER_GID=1000 \
    HOMEDIR=/home/uhangman

# ------------------------------------------------------------------------------
# Update and install packages.
# ------------------------------------------------------------------------------
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install --no-install-recommends -y \
        cmake \
        gcc \
        make \
        git \
        ca-certificates \
        libc6-dev && \
    rm -rf /var/lib/apt/lists/*

# ------------------------------------------------------------------------------
# Add a non root user.
# ------------------------------------------------------------------------------
RUN groupadd --gid "$USER_GID" "$USERNAME" && \
    useradd --uid "$USER_UID" --gid "$USER_GID" -m "$USERNAME" && \
    chown "$USER_UID":"$USER_GID" "$HOMEDIR"

WORKDIR $HOMEDIR
USER $USERNAME

# ------------------------------------------------------------------------------
# Clone down the repository.
#
# Need to grab the github certs since we are on WSL here.
# ------------------------------------------------------------------------------
RUN git clone https://github.com/MitchsGreer/Hangman.git

# ------------------------------------------------------------------------------
# Move into the c implementation directory and build.
# ------------------------------------------------------------------------------
WORKDIR $HOMEDIR/Hangman/c
RUN cmake -S . -B build -G "Unix Makefiles" && \
    cd build && \
    make

WORKDIR $HOMEDIR/Hangman/c/build

# ------------------------------------------------------------------------------
# Make the new executable the entry point.
# ------------------------------------------------------------------------------
ENTRYPOINT [ "/bin/bash", "-l", "-c", "./Hangman" ]
