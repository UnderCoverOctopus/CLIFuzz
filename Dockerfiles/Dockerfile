FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

# installs all necessary packages and set up environment
RUN <<EOF
apt-get update
apt-get install -y build-essential
apt-get -y install git
echo "Pacific/Auckland" > /etc/timezone && \
    ln -fs /usr/share/zoneinfo/Pacific/Auckland /etc/localtime
apt-get -y install afl++ 
git clone https://github.com/google/AFL.git || { echo 'Git clone failed'; exit 1; }
apt-get install -y git
apt-get install -y vim
mkdir in
mkdir out
EOF
RUN echo "add 5 7\nadd 10 100\nadd 11 23\nadd 1 -1\nadd 3434 3243" > /in/tests.txt
RUN git clone https://github.com/UnderCoverOctopus/CLIFuzz.git || { echo 'Git clone failed'; exit 1; }
WORKDIR /
CMD ["/bin/bash"]
