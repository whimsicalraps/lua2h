#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

void Lua_Error( lua_State* L, char* err )
{
    printf("Lua error: %s, %s\n"
          , err
          , lua_tostring(L, -1)
          );
}

int main( int argc, char* argv[] )
{
    if( argc != 2 ){
        printf("bad args: send just one arg which is the input filename\n");
        return 0;
    }

    lua_State* L;         // pointer to store lua state
    L = luaL_newstate();  // create a new lua state & save pointer
    luaL_openlibs(L);     // give our lua state access to lua libs

    // lua hello-world as a string
    if( luaL_loadfile(L, argv[1]) ){ Lua_Error(L,"loadfile "); }
    lua_close(L);

    return 1;
}
