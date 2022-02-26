FROM gitpod/workspace-full

RUN sudo apt-get update && sudo apt install -y valgrind cppcheck libcmocka-dev cmocka-doc libcmocka0
# RUN sudo apt install valgrind cppcheck
RUN pip3 install lizard flawfinder
# RUN pip3 install lizard
# RUN pip3 install flawfinder
RUN make