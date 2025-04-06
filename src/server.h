#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <boost/asio.hpp>
#include <thread>

class HTTPServer {
public:
    HTTPServer(const std::string& address, int port);
    void start();  // Start the server and accept incoming connections

private:
    void session(boost::asio::ip::tcp::socket socket);  // Handle a single session
    void send_response(boost::asio::ip::tcp::socket& socket, const std::string& message);  // Send an HTTP response

    boost::asio::io_context io_context;  // Changed from io_service to io_context
    boost::asio::ip::tcp::acceptor acceptor;  // TCP acceptor for listening to connections
};

#endif