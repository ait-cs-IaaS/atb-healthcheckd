# HEALTHCHECKD - A buggy healthcheck service

This is a vulnerable healthcheck service that can be exploited by 
overwriting the memory. It reads servername and status and writes
it to a logfile.

# Compile

```
make install
```

or build a debian package:
```
$ git clone https://github.com/ait-cs-IaaS/atb-healthcheckd.git
$ mkdir build
$ docker run --rm -it -v $PWD/atb-healthcheckd:/app -v $PWD/build:/build debian:bookworm /bin/bash -c "/app/scripts/build_debian.sh healthcheckd 1.0"
```

_Hint: compile it under Debian instead of Ubuntu to avoid counter measures_

# Run 

```
./healthcheckd server.log
Enter Servername: localhost
localhost status: OK
```

# Exploit Formatstring:

```
./healthcheckd server.log
Enter Servername: %p%p%p%p
0xa(nil)0x7f1a3a5cbaa0(nil) status:
```

# Exploit Bufferoverflow:

```
Enter Servername: %p%p%p%p
0xa(nil)0x7f769f480aa0(nil) status: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
*** stack smashing detected ***: terminated
[1]    61519 IOT instruction (core dumped)  ./healthcheckd server.log
```

# Author

Wolfgang Hotwagner(Austrian Institute of Technology)
