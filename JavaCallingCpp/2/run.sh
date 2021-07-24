
export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64

javac -h . PrintName.java

gcc -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libname.so PrintName.c

java -Djava.library.path=. PrintName