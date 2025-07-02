#include <iostream>
#include <zmq.hpp>
#include <config.hpp>

int main () {
    const int iothread_count = config.get<int>("iothread_count");
    zmq::context_t context(iothread_count);

    zmq::socket_t socket (context, zmq::socket_type::req);
    std::string response = "Hello this is from client";
    
    const std::string path = config["connection_type"] + "://" + "localhost:" + config["port"];
    socket.connect(path);

    zmq::message_t message(response.begin(), response.end());

    socket.send(message, zmq::send_flags::none);

    zmq::message_t get;
    auto res = socket.recv(get);

    if (!res || res.value_or(0) == 0) {
        std::cout << "Empty message" << std::endl;
        return 1;
    }

    std::string parsed_msg = get.to_string();
    std::cout << "Came message: " << parsed_msg << std::endl;

}