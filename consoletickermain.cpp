#include "rxcpp/rx.hpp"
#include <chronos>
int main()
{
    auto scheduler = std::make_shared<rxcpp::EventLoopScheduler<>();
    
    auto ticker = rxcpp::Interval( std::chronos::milliseconds(250),scheduler);
    
    
    rxcpp::from(ticker)
    .where([](int val) { return val % 2 == 0; })
    .take(10)
    .subscribe([](int val) {
        std::cout << "tick " << val << std::endl;
    });
    
    std::cout << "starting to tick" << std::endl;
}
