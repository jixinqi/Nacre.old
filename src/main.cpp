#include "nacre.h"

int main(int argc, char ** argv)
{
    nacre::environment env;

    auto& default_app = env.apps.create("_");

    default_app.routes.create("/api/user/");

    return 0;
}
