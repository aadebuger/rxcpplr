#include "rxcpp/rx.hpp"
#include <rxcpp/rx-lite.hpp>
#include <rxcpp/operators/rx-take.hpp>

#include <rxcpp/rx-coroutine.hpp>
namespace Rx {
using namespace rxcpp;
using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::util;
}
using namespace Rx;

#include <regex>
#include <random>

using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::util;

using namespace std;
using namespace std::chrono;


using namespace std;
using namespace std::chrono;



int main()
{
    
    
    auto values = rxcpp::observable<>::range(1, 1000).window_with_time_or_count(std::chrono::seconds(1), 100);
  
 //   std::cout<<"values="<<values<<std::endl;
    
  //  values.Subcribe( )
    // just(std::vector<std::string>{"11","22"})
    /*
    rxcpp::observable<>::just(std::vector<int>{11,22}).flat_map([](int i) {
        return rxs::range(1, i)
        .as_dynamic();
    },
                                                                            [](int i, int j) {
                                                                                std::cout << "# " << i << ", " << j << std::endl;
                                                                                return i;
                                                                            }        ).
    subscribe([](int i) {
        std::cout << "subscribe: " << i << std::endl;
    });
    */
    auto values1 = rxcpp::observable<>::just("1","2");
    values1.
    subscribe(
              [](string  v){printf("OnNext: %s\n", v.c_str());},
              [](){printf("OnCompleted\n");});
    printf("//! [just sample]\n");
    
    
    rxcpp::observable<>::range(1, 3).flat_map(
                     [](int i) {
                         return rxs::range(1, i)
                         .as_dynamic();
                     },
                     [](int i, int j) {
                         std::cout << "# " << i << ", " << j << std::endl;
                         return i;
                     }
                     )
    .subscribe(
               [](int i) {
                   std::cout << "subscribe: " << i << std::endl;
               }
               );
    
}
