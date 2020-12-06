#include "nacre.h"

void _1(){ std::cout << "_1()" << std::endl; }
void _2(){ std::cout << "_2()" << std::endl; }

int main(int argc, char** argv)
{
    nacre::environment env;

    auto& default_app = env.apps.add("_");

    default_app.routes.add("/api/test/", {
        { "GET",  _1 },
        { "POST", _2 }
    });

    env.apps.get("_").routes.get("/api/test/").get(nacre::http_method::GET).run();
    env.apps.get("_").routes.get("/api/test/").get(nacre::http_method::POST).run();

    return 0;
}
