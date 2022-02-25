FROM gitpod/workspace-full

RUN sudo apt-get update && sudo apt-get install -y valgrind libcmocka-dev cmocka-doc libcmocka0 clang-tidy-9
RUN make