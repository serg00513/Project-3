#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>

namespace http = boost::beast::http;

int main()
{


       //io context
       boost::asio::io_context ioc;

       // Resolver for determinate endpoint
       boost::asio::ip::tcp::resolver resolver(ioc);
       //create socket for con
       boost::asio::ip::tcp::socket socket(ioc);


       const std::string host = "site.com";
       const std::string target = "echo/getrequest?=test";

       boost::asio::connect(socket, resolver.resolve(host, "80"));

       // create GET request
       http::request<http::string_body> req(http::verb::get, target, 11);
       // base http property
       req.set(http::field::host, host);
       req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);


       http::write(socket, req);

       /** it` may be callback function , or class method , any way we can take input data  */
       {
           boost::beast::flat_buffer buffer;
           http::response<http::dynamic_body> res;
           http::read(socket, buffer, res);

           /** here we can use any json parser */
           //std::cout << res << std::endl;
       }

       socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);

       return 0;
}
