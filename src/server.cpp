#include "server.h"
#include <boost/asio.hpp>
#include <iostream>

HTTPServer::HTTPServer(const std::string& address, int port)
    : acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(address), port)) {}

void HTTPServer::start() {
    while (true) {
        boost::asio::ip::tcp::socket socket(io_context);
        acceptor.accept(socket);  // Accept a new client connection
        std::thread(&HTTPServer::session, this, std::move(socket)).detach();  // Handle each session in a new thread
    }
}

void HTTPServer::session(boost::asio::ip::tcp::socket socket) {
    try {
        std::string request;
        boost::asio::read_until(socket, boost::asio::dynamic_buffer(request), "\r\n\r\n");  // Read HTTP request
        std::cout << "Received request:\n" << request << std::endl;

        std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        response += "<html><body><h1>Hello, World!</h1></body></html>";
        send_response(socket, response);
    } catch (const std::exception& e) {
        std::cerr << "Error in session: " << e.what() << std::endl;
    }
}

void HTTPServer::send_response(boost::asio::ip::tcp::socket& socket, const std::string& message) {
    boost::asio::write(socket, boost::asio::buffer(message));  // Send HTTP response to client
}

// Add the main function
int main() {
    try {
        std::string address = "127.0.0.1";  // Address to bind to
        int port = 8080;                   // Port to listen on

        HTTPServer server(address, port);
        std::cout << "Server started at " << address << ":" << port << std::endl;
        server.start();  // Start accepting client connections
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;  // Exit the program
}