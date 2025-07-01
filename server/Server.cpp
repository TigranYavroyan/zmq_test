#include <iostream>
#include <zmq.hpp>
#include <config.h>

int main () {
    const std::size_t iothread_count = std::stoi(config["iothread_count"]);
    zmq::context_t context(iothread_count);

    zmq::socket_t socket (context, zmq::socket_type::rep);
    std::string response = "Hello this is my server";



    const std::string path = config["connection_type"] + "://" + "*:" + config["port"];
;
    socket.bind(path);
    std::cout << "Listening on " << path << std::endl;
    while (true) {
        zmq::message_t message;

        auto res = socket.recv(message);

        if (!res || res.value_or(0) == 0) {
            std::cout << "Empty message" << std::endl;
            continue;
        }

        std::string parsed_msg = message.to_string();
        std::cout << "Came message: " << parsed_msg << std::endl;

        zmq::message_t to_send(response.begin(), response.end());
        socket.send(to_send, zmq::send_flags::none);
    }
}