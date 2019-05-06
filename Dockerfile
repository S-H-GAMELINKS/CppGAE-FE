FROM gcc:latest
COPY . /cpp-gae-fe
WORKDIR /cpp-gae-fe
EXPOSE 8080
RUN g++ main.cpp cpp-httplib/httplib.h -std=c++17 -pthread 
CMD ["./a.out"]