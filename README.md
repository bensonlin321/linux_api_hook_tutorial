# linux_api_hook_tutorial
Demo: replace getuid

# Compile the demo code
```
./compile.sh
```

# Explain

- What is `gcc src/*.c -ldl -o main` in compile.sh?
```
-ldl means "include dlopen(), dlclose(), dlerror(), dlsym(), the Base Definitions volume of IEEE Std 1003.1-2001, <dlfcn.h>"

Just like -lpthread when you want to use thread function
```

- What is `dlsym(RTLD_NEXT, "getuid")`?
```
Use to get the original address of getuid function

Def of dlsym:
There are two special pseudo-handles, RTLD_DEFAULT and RTLD_NEXT. The former will find the first occurrence of the desired symbol using the default library search order. The latter will find the next occurrence of a function in the search order after the current library. This allows one to provide a wrapper around a function in another shared library.

For this demo code:
If you use RTLD_DEFAULT, you will get your customized getuid function.
If you use RTLD_NEXT, you will get the getuid function in libc.so. 
```

