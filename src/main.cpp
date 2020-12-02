#include "nacre.h"

void _1(){ std::cout << "_1()" << std::endl; }
void _2(){ std::cout << "_2()" << std::endl; }

int main(int argc, char** argv)
{
    nacre::environment env;

    auto& default_app = env.apps.add("_");

    default_app.routes.add("/api/test/", {
        { nacre::http_method::GET,  _1 },
        { nacre::http_method::POST, _2 }
    });

    auto& x = env.apps.get("_").routes.get("/api/test/").get(nacre::http_method::GET);
    x.run();

    return 0;
}
