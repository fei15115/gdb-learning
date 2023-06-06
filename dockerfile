FROM ubuntu:20.04
RUN \
      apt-get update && apt-get install -y \
      # general tools
      cmake \
      gcc \
      vim \
      gdb

CMD ["/bin/bash"]